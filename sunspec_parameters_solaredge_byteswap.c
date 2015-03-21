/* ---------------------------
 * Project: 2014p03_stromzaehler-auswertung-SE3000
 * Filename: sunspec_modbus_mappings_solaredge_byteswap.c
 * Function: Can be used to bytewap all the relevant variables in the struct sunspec_modbus_mappings_solaredge
 * Comment: First implementation
 * Requires: byteswap.h, sunspec_modbus_mappings_solaredge.h
 * Parameters: struct sunspec_modbus_mappings_solaredge *
 * Return values: void
 * Name: Andreas Dolp
 * Date: 12.11.2014
 * Version: 1.0
 * --------------------------- */

#include <byteswap.h>

#include "sunspec_modbus_mappings_solaredge.h"

/*
 * @brief Can be used to bytewap all the relevant variables in the struct sunspec_modbus_mappings_solaredge
 * @param struct sunspec_modbus_mappings_solaredge *
 * @return void
 */
void sunspec_modbus_mappings_solaredge_byteswap(struct sunspec_modbus_mappings_solaredge *val)
{
	val->C_SunSpec_ID = __bswap_constant_32(val->C_SunSpec_ID);
	val->C_SunSpec_DID1 = __bswap_constant_16(val->C_SunSpec_DID1);
	val->C_SunSpec_Length1 = __bswap_constant_16(val->C_SunSpec_Length1);
	val->C_Slaveaddress = __bswap_constant_16(val->C_Slaveaddress);
	val->C_SunSpec_DID2 = __bswap_constant_16(val->C_SunSpec_DID2);
	val->C_SunSpec_Length2 = __bswap_constant_16(val->C_SunSpec_Length2);
	val->I_AC_Current = __bswap_constant_16(val->I_AC_Current);
	val->I_AC_CurrentA = __bswap_constant_16(val->I_AC_CurrentA);
	val->I_AC_CurrentB = __bswap_constant_16(val->I_AC_CurrentB);
	val->I_AC_CurrentC = __bswap_constant_16(val->I_AC_CurrentC);
	val->I_AC_Current_SF = __bswap_constant_16(val->I_AC_Current_SF);
	val->I_AC_VoltageAB = __bswap_constant_16(val->I_AC_VoltageAB);
	val->I_AC_VoltageBC = __bswap_constant_16(val->I_AC_VoltageBC);
	val->I_AC_VoltageCA = __bswap_constant_16(val->I_AC_VoltageCA);
	val->I_AC_VoltageAN = __bswap_constant_16(val->I_AC_VoltageAN);
	val->I_AC_VoltageBN = __bswap_constant_16(val->I_AC_VoltageBN);
	val->I_AC_VoltageCN = __bswap_constant_16(val->I_AC_VoltageCN);
	val->I_AC_Voltage_SF = __bswap_constant_16(val->I_AC_Voltage_SF);
	val->I_AC_Power = __bswap_constant_16(val->I_AC_Power);
	val->I_AC_Power_SF = __bswap_constant_16(val->I_AC_Power_SF);
	val->I_AC_Frequency = __bswap_constant_16(val->I_AC_Frequency);
	val->I_AC_Frequency_SF = __bswap_constant_16(val->I_AC_Frequency_SF);
	val->I_AC_VA = __bswap_constant_16(val->I_AC_VA);
	val->I_AC_VA_SF = __bswap_constant_16(val->I_AC_VA_SF);
	val->I_AC_VAR = __bswap_constant_16(val->I_AC_VAR);
	val->I_AC_VAR_SF = __bswap_constant_16(val->I_AC_VAR_SF);
	val->I_AC_PF = __bswap_constant_16(val->I_AC_PF);
	val->I_AC_PF_SF = __bswap_constant_16(val->I_AC_PF_SF);
	val->I_AC_Energy_WH = __bswap_constant_32(val->I_AC_Energy_WH);
	val->I_AC_Energy_WH_SF = __bswap_constant_16(val->I_AC_Energy_WH_SF);
	val->I_DC_Current = __bswap_constant_16(val->I_DC_Current);
	val->I_DC_Current_SF = __bswap_constant_16(val->I_DC_Current_SF);
	val->I_DC_Voltage = __bswap_constant_16(val->I_DC_Voltage);
	val->I_DC_Voltage_SF = __bswap_constant_16(val->I_DC_Voltage_SF);
	val->I_DC_Power = __bswap_constant_16(val->I_DC_Power);
	val->I_DC_Power_SF = __bswap_constant_16(val->I_DC_Power_SF);
	val->I_Temp_Heatsink = __bswap_constant_16(val->I_Temp_Heatsink);
	val->I_Temp_SF = __bswap_constant_16(val->I_Temp_SF);
	val->I_Status = __bswap_constant_16(val->I_Status);
	val->I_Status_Vendor = __bswap_constant_16(val->I_Status_Vendor);
}
