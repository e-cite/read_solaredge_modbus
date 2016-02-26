#read_solaredge_modbus

## Functionality
Software reads a SolarEdge inverter via its RS485 modbus interface, interprets the data received and writes it to a buffer file, so [vzlogger](http://volkszaehler.org/) could read it.

## Installation on Debian / Ubuntu
1. Create the user emlogger: ```sudo adduser emlogger```
2. Login as user emlogger: ```sudo su emlogger```
3. Download git repository: ```git clone https://github.com/e-cite/read_solaredge_modbus.git```
4. Install modbus development library: ```sudo apt-get install libmodbus-dev```
5. Open folder: ```cd read_solaredge_modbus```
6. Create new folder for binary files: ```mkdir bin```
7. Compile it (Please ignore the warnings): ```gcc src/*.c -lmodbus -lm -I /usr/include/modbus -o bin/rsm.bin```
8. The start-script "init.d/read_solaredge_modbus.sh" can be installed to "/etc/init.d/" to provide a global startscript

## Start / Stop 
**Start** it with: ```sudo -u emlogger ~emlogger/read_solaredge_modbus/init.d/read_solaredge_modbus.sh start```

**Stop** it with: ```sudo -u emlogger ~emlogger/read_solaredge_modbus/init.d/read_solaredge_modbus.sh stop```

## TODO:
- [ ] Create a makefile
- [ ] Fix the open bugs
- [ ] Remove the warnings by proper casts / referencing
- [ ] Write a better documentation
