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

#ifndef SUNSPEC_MODBUS_MAPPINGS_SOLAREDGE_H_
#define SUNSPEC_MODBUS_MAPPINGS_SOLAREDGE_H_

#include <stdint.h>

#define MB_REG_ADDRESS 40000	/* Register address for base 0 */
#define MB_REG_COUNT 109	/* Number of registers to read */

/*
 * @brief Declares a struct to match the read inverter data
 */
struct sunspec_modbus_mappings_solaredge
{
	uint32_t C_SunSpec_ID;	/* Should always be "SunS" = 0x53756e53, this is a SunSpec-Modbus-Message */
	uint16_t C_SunSpec_DID1;	/* SunSpec "Common Block" */
	uint16_t C_SunSpec_Length1;	/* Length of Block, 65 16-bit registers */
	char C_Manufacturer[32];	/* Manufacturer, "SolarEdge" */
	char C_Model[32];	/* Type of SolarEdge inverter */
	char dummy1[16];	/* empty */
	char C_Version[16];	/* CPU revision of the inverter */
	char C_Serialnumber[32];	/* The inverter's serial number */
	uint16_t C_Slaveaddress;	/* The inverter's slave address (could be set in the inverter) */
	uint16_t C_SunSpec_DID2;	/* 101 = one phase, 102 = two phases (only in japan or north corea), 103 = three phases */
	uint16_t C_SunSpec_Length2;	/* Length of Block, 50 16-bit registers */
	uint16_t I_AC_Current;	/* AC-current over all phases */
	uint16_t I_AC_CurrentA;	/* L1-AC-current */
	uint16_t I_AC_CurrentB;	/* L2-AC-current */
	uint16_t I_AC_CurrentC;	/* L3-AC-current */
	int16_t I_AC_Current_SF;	/* AC-current scale factor */
	uint16_t I_AC_VoltageAB;	/* AC-voltage between L1 and L2 */
	uint16_t I_AC_VoltageBC;	/* AC-voltage between L2 and L3 */
	uint16_t I_AC_VoltageCA;	/* AC-voltage between L3 and L1 */
	uint16_t I_AC_VoltageAN;	/* AC-voltage between L1 and N */
	uint16_t I_AC_VoltageBN;	/* AC-voltage between L1 and N */
	uint16_t I_AC_VoltageCN;	/* AC-voltage between L1 and N */
	int16_t I_AC_Voltage_SF;	/* AC-voltage scale factor */
	int16_t I_AC_Power;	/* AC-power */
	int16_t I_AC_Power_SF;	/* AC-power scale factor */
	uint16_t I_AC_Frequency;	/* AC-frequency */
	int16_t I_AC_Frequency_SF;	/* AC-frequency scale factor */
	int16_t I_AC_VA;	/* AC-apparent-power */
	int16_t I_AC_VA_SF;	/* AC-apparent-power scale factor */
	int16_t I_AC_VAR;	/* AC-reactive-power */
	int16_t I_AC_VAR_SF;	/* AC-reactive-power scale factor */
	int16_t I_AC_PF;	/* AC-power-factor cos phi (only used with 3-phase-inverters) */
	int16_t I_AC_PF_SF;	/* AC-power-factor cos phi scale factor */
	uint32_t I_AC_Energy_WH;	/* AC-energy-production over all time */
	uint16_t I_AC_Energy_WH_SF;	/* AC-energy-production over all time scale factor */
	uint16_t I_DC_Current;	/* DC-current */
	int16_t I_DC_Current_SF;	/* DC-current scale factor */
	uint16_t I_DC_Voltage;	/* DC-voltage */
	int16_t I_DC_Voltage_SF;	/* DC-voltage scale factor */
	int16_t I_DC_Power;	/* DC-power */
	int16_t I_DC_Power_SF;	/* DC-power scale factor */
	int16_t dummy2;	/* empty */
	int16_t I_Temp_Heatsink;	/* Temperature on the inverter's heatsink*/
	int16_t dummy3;	/* empty */
	int16_t dummy4;	/* empty */
	int16_t I_Temp_SF;	/* Temperature on the inverter's heatsink*/
	uint16_t I_Status;	/* Inverter status (1 = OFF, 2 = standy / night mode, 4 = ON) */
	uint16_t I_Status_Vendor;	/* Specific error codes, see the instruction manual for error codes */
}__attribute__((packed));

#endif /* SUNSPEC_MODBUS_MAPPINGS_SOLAREDGE_H_ */
