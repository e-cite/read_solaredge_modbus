/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: read-modbus-rtu-device.h
 * Function: Header for read_modbus_rtu_device.c, Reads a modbus RTU device's registers in an uint16_t array
 * Comment: First implementation
 * Requires:
 * Parameters:
 * Return values:
 * Name: Andreas Dolp
 * Date: 13.11.2014
 * Version: 1.0
 * --------------------------- */

#ifndef READ_MODBUS_RTU_DEVICE_H_
#define READ_MODBUS_RTU_DEVICE_H_

#define MB_DEVICE_NAME "/dev/ttyUSB0"
#define MB_BITRATE 9600
#define MB_DATABITS 8
#define MB_STOPBITS 1
#define MB_PARITY 'N'

int read_modbus_rtu_device(uint16_t tab_reg[],
	const unsigned int mb_slave_address,
	const unsigned int mb_reg_address,
	const unsigned int mb_reg_count);

#endif /* READ_MODBUS_RTU_DEVICE_H_ */
