#! /bin/sh
### BEGIN INIT INFO
# Provides:          Starts service read_solaredge_modbus
# Required-Start:    
# Required-Stop:     
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Reads SolarEdge modbus device
# Description:       Reads SolarEdge SE3000 inverter via modbus and writes current data in a file, so vzlogger can read it
### END INIT INFO
# Author: Andreas Dolp <dev@andreas-dolp.de>


strFilePath=/home/emlogger/read_solaredge_modbus/bin
strFilePathPID=/var/run/read_solaredge_modbus.pid
strUSER=emlogger 

echo "Read SolarEdge modbus device"

case "$1" in
	start)		echo "starting read_solaredge_modbus..."
			su - $strUSER -c "'$strFilePath/rsm.bin' > /dev/null 2>&1 &"'
				echo "$!"' > $strFilePathPID
			;;
	stop)		echo "stopping read_solaredge_modbus..."
			kill `cat $strFilePathPID`
			rm $strFilePathPID
			;;
			
	*)		echo "USAGE: start | stop"
			;;
esac

exit 0
