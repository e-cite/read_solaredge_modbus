/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: read_solaredge_modbus_vzlogger.h
 * Function: Header for read_solaredge_modbus_vzlogger.c, Reads SolarEdge SE3000 inverter via modbus and writes current data in a file, so vzlogger can read it
 * Comment: First implementation
 * Requires:
 * Parameters:
 * Return values:
 * Name: Andreas Dolp
 * Date: 13.11.2014
 * Version: 1.0
 * --------------------------- */

#ifndef READ_SOLAREDGE_MODBUS_VZLOGGER_H_
#define READ_SOLAREDGE_MODBUS_VZLOGGER_H_

#define VZ_MIDDLEWARE_URL "http://demo.volkszaehler.org/middleware.php"
#define VZ_UUID "91538d20-60db-11e4-a8c9-b14bcf9d6cf1"

#define MB_SLAVE_ADDRESS 1

#define SE_NORMAL_READ_CYCLE_SECONDS 2
#define SE_NIGHTMODE_READ_CYCLE_SECONDS 60

#endif /* READ_SOLAREDGE_MODBUS_VZLOGGER_H_ */
