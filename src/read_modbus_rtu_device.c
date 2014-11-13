/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: read-modbus-rtu-device.c
 * Function: Reads a modbus RTU device's registers in an uint16_t array
 * Comment: First implementation
 * Requires: modbus.h
 * Parameters:
 * Return values: Number of uint16_t registers read, -1 if error
 * Name: Andreas Dolp
 * Date: 13.11.2014
 * Version: 1.0
 * --------------------------- */

#include <modbus.h>
#include "read_modbus_rtu_device.h"

/*
 * @brief Reads a modbus RTU device's registers in an uint16_t array
 * @param const uint16_t *tab_reg, const unsigned int mb_slave_address, const unsigned int mb_reg_address, const unsigned int mb_reg_count
 * @return Number of uint16_t registers read, -1 if error
 */
int read_modbus_rtu_device(uint16_t tab_reg[],
	const unsigned int mb_slave_address,
	const unsigned int mb_reg_address,
	const unsigned int mb_reg_count)
{
	int rc = 0;
	int ret = -1;
	if (tab_reg <= 0)
		return -1;

	modbus_t *ctx;
	ctx = modbus_new_rtu(MB_DEVICE_NAME,
		MB_BITRATE,
		MB_PARITY,
		MB_DATABITS,
		MB_STOPBITS);

	if (ctx == 0)
		goto ERROR_DATA;

	if (modbus_set_slave(ctx,mb_slave_address) != 0)
		goto ERROR_DATA;

	if (modbus_connect(ctx) != 0)
		goto ERROR_CONNECTION;

	/* since here the modbus connection is established successfully */

	rc = modbus_read_registers(ctx,mb_reg_address,mb_reg_count,tab_reg);
	if (rc > 0)
		ret = rc;

ERROR_CONNECTION:
	modbus_close(ctx);
ERROR_DATA:
	modbus_free(ctx);

	return ret;
}
