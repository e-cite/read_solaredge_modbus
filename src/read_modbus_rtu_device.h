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
