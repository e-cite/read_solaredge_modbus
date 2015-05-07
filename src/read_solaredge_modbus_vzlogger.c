/*
 * Read Solaredge Modbus - Reads data from Solaredge inverter via MODBUS TCP
 * Copyright (C) 2015 Andreas Dolp <dev@andreas-dolp.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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

int main(int argc, char *argv[])
{
	int I_AC_Power_calculated = 0;
	/* Structs for the involved inverters */
	struct sunspec_modbus_mappings_solaredge *inv1 = malloc(sizeof(struct sunspec_modbus_mappings_solaredge));
	if ((void*)inv1 <= NULL) {
		fprintf(stderr, "Error while allocating memory for sunspec_modbus_mappings_solaredge inv1: %s\n",strerror(errno));
		return -1;
	}
	int inv1_ID = 1;

	/* Create fifo buffer file */
	int fd = (int)NULL;
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

		if(argc == 2 && *argv[1] == 1) {
			printf("Received the values listed below:\n");
			printf("AC Power: %d\n",I_AC_Power_calculated);
			printf("AC Voltage: %d\n",inv1->I_AC_VoltageAB);
			printf("AC Current: %d\n",inv1->I_AC_Current);
			printf("Heatsink temperature: %d\n",inv1->I_Temp_Heatsink);
			printf("\n====================================================\n");
		}

		fd = open(path, O_WRONLY); /* Open the fifo buffer file */
		if (fd <= (int)NULL) {
			fprintf(stderr, "Error while opening file fd: %s\n",strerror(errno));
		} else {
			/* Create buffer content as spcified in vzlogger.conf */
			if (snprintf(buffer,sizeof(buffer),"%d %d",inv1_ID,I_AC_Power_calculated) < 0) {
				fprintf(stderr, "Error while creating buffer: %s\n",strerror(errno));
			} else {
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
