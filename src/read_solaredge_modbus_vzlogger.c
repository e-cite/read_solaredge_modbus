/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: read_solaredge_modbus_vzlogger.c
 * Function: Reads SolarEdge SE3000 inverter via modbus and writes current data in a file, so vzlogger can read it
 * Comment: First implementation
 * Requires:
 * Parameters:
 * Return values:
 * Name: Andreas Dolp
 * Date: 13.11.2014
 * Version: 1.0
 * --------------------------- */

#include <stdio.h>
#include <curl/curl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#include "read_solaredge_modbus_vzlogger.h"
#include "sunspec_modbus_mappings_solaredge.h"

extern int errno;

/*
 * @brief Generates a POST request in volkszaehler format to transmit cur_power to volkszaehler middleware
 * @param int cur_power = value to transmit, char *vz_uuid = volkszaehler channel uuid
 * @return Returns always the curl_easy_perform return value, CURLE_OK = 0 if successfull
 */
int vz_post_value(int cur_power, char *vz_uuid)
{
	char vz_url[255];
	char vz_postfields[50];
	CURL *curl;
	CURLcode res;

	sprintf(vz_url,"%s/data/%s.json",VZ_MIDDLEWARE_URL,vz_uuid);
	sprintf(vz_postfields,"value=%d",cur_power);

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl,CURLOPT_URL,vz_url);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,vz_postfields);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			fprintf(stderr,"Error while transmitting to POST request: %s",curl_easy_strerror(res));
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
	return (int)res;
}


int main()
{
	int I_AC_Power_calculated = 0;
	uint16_t I_Status_before = 0;
	struct sunspec_modbus_mappings_solaredge *inv1 = malloc(MB_REG_COUNT*sizeof(uint16_t));
	if ((void*)inv1 <= NULL) {
		fprintf(stderr, "Error while allocating memory for sunspec_modbus_mappings_solaredge inv1: %s\n",strerror(errno));
		return -1;
	}

	while(1) {
		if (read_modbus_rtu_device((uint16_t *)inv1,MB_SLAVE_ADDRESS,MB_REG_ADDRESS,sizeof(struct sunspec_modbus_mappings_solaredge)/2) <= 0) {
			fprintf(stderr, "Error while reading modbus device: %s\n",strerror(errno));
			fprintf(stderr, "Retrying in %d seconds...\n", SE_NORMAL_READ_CYCLE_SECONDS);
			sleep(SE_NORMAL_READ_CYCLE_SECONDS);
			continue;
		}

		I_AC_Power_calculated = inv1->I_AC_Power*pow(10,inv1->I_AC_Power_SF);
		
		if(inv1->I_Status == 4 || I_Status_before == 4) {
			printf("Received the values listed below:\n");
			printf("AC Power: %d\n",I_AC_Power_calculated);
			printf("AC Voltage: %d\n",inv1->I_AC_VoltageAB);
			printf("AC Current: %d\n",inv1->I_AC_Current);
			printf("Heatsink temperature: %d\n",inv1->I_Temp_Heatsink);
			if(vz_post_value(I_AC_Power_calculated, VZ_UUID) != 0)
				continue;
		} else {
			printf("Nightmode or OFF detected, retrying in %d seconds...\n", SE_NIGHTMODE_READ_CYCLE_SECONDS);
			sleep(SE_NIGHTMODE_READ_CYCLE_SECONDS);
		}

		I_Status_before = inv1->I_Status;
		printf("\n====================================================\n");		
		sleep(SE_NORMAL_READ_CYCLE_SECONDS);
	}

	free(inv1);

	return 0;
}
