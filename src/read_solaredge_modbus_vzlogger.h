/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: read_solaredge_modbus_vzlogger.h
 * Function: Header for read_solaredge_modbus_vzlogger.c, Reads SolarEdge SE3000 inverter via modbus and writes current data in a file, so vzlogger can read it
 * Comment: Changes due to uploading data via vzlogger and not directly anymore
 * Requires:
 * Parameters:
 * Return values:
 * Name: Andreas Dolp
 * Date: 01.05.2015
 * Version: 2.0
 * --------------------------- */

#ifndef READ_SOLAREDGE_MODBUS_VZLOGGER_H_
#define READ_SOLAREDGE_MODBUS_VZLOGGER_H_

#define MB_SLAVE_ADDRESS 1

#define SE_NORMAL_READ_CYCLE_SECONDS 2

#endif /* READ_SOLAREDGE_MODBUS_VZLOGGER_H_ */
