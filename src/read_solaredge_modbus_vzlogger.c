/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: read_solaredge_modbus_vzlogger.c
 * Function: Reads SolarEdge SE3000 inverter via modbus and writes current data in a file, so vzlogger can read it
 * Comment: Implements communication to vzlogger using a tmp buffer file
 * Requires:
 * Parameters:
 * Return values:
 * Name: Andreas Dolp
 * Date: 02.05.2015
 * Version: 2.0
 * --------------------------- */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

#include "read_solaredge_modbus_vzlogger.h"
#include "sunspec_modbus_mappings_solaredge.h"

#define MAXLEN 16

extern int errno;

int main()
{
	int I_AC_Power_calculated = 0;
	/* Structs for the involved inverters */
	struct sunspec_modbus_mappings_solaredge *inv1 = malloc(MB_REG_COUNT*sizeof(uint16_t));
	if ((void*)inv1 <= NULL) {
		fprintf(stderr, "Error while allocating memory for sunspec_modbus_mappings_solaredge inv1: %s\n",strerror(errno));
		return -1;
	}
	int inv1_ID = 1;

	/* Create fifo buffer file */
	int fd = NULL;
	char *path = "/tmp/vzloggerfifo";
	mkfifo(path, 0666);
	char buffer[MAXLEN];


	while(1) {
		if (read_modbus_rtu_device((uint16_t *)inv1,MB_SLAVE_ADDRESS,MB_REG_ADDRESS,sizeof(struct sunspec_modbus_mappings_solaredge)/2) <= 0) {
			fprintf(stderr, "Error while reading modbus device: %s\n",strerror(errno));
			fprintf(stderr, "Retrying in %d seconds...\n", SE_NORMAL_READ_CYCLE_SECONDS);
			sleep(SE_NORMAL_READ_CYCLE_SECONDS);
			continue;
		}

		I_AC_Power_calculated = inv1->I_AC_Power*pow(10,inv1->I_AC_Power_SF);
		
		printf("Received the values listed below:\n");
		printf("AC Power: %d\n",I_AC_Power_calculated);
		printf("AC Voltage: %d\n",inv1->I_AC_VoltageAB);
		printf("AC Current: %d\n",inv1->I_AC_Current);
		printf("Heatsink temperature: %d\n",inv1->I_Temp_Heatsink);
		printf("\n====================================================\n");		


		fd = open(path, O_WRONLY); /* Open the fifo buffer file */
		if (fd<=NULL) {
			fprintf(stderr, "Error while opening file fd: %s\n",strerror(errno));
		} else {
			/* Create buffer content as spcified in vzlogger.conf */
			if ( snprintf(buffer,sizeof(buffer),"%d %d",inv1_ID,I_AC_Power_calculated) < 0 ) {
				fprintf(stderr, "Error while creating buffer: %s\n",strerror(errno));
			} else {
				printf("Buffer: %s\n",buffer);
				if ( write(fd,buffer,sizeof(buffer)) < 0 ) {
					fprintf(stderr, "Error while writing fifo buffer: %s\n",strerror(errno));
				}
			}
		}
		close(fd); /* Close the fifo buffer file */

		sleep(SE_NORMAL_READ_CYCLE_SECONDS);
	}

	unlink(path); /* Free the buffer */

	free(inv1);

	return 0;
}
