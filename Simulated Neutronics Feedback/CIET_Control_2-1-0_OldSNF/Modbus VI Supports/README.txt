These are all of the VIs and supporting materials I've developed for this project (Spring 2016 ME235: CIET Control System)

Pump_Test.lvproj : The main LV project file to run the VIs developed for this project (Control Panel.vi and 
GS1 Communication.vi) that also houses supporting LV libraries (GS1 Variables.lvlib and Modbus_GS1.lvlib).

Control Panel.vi : High-level VI that the user uses to send control commands to the GS1s (variable speed controllers for 
the three motors in the system) across local variables with FIFO enabled.

GS1 Communication.vi : The control VI for the GS1s, taking control commands from the Control Panel.vi in the form of local
variables with FIFO enabled.

GS1 Variables.lvlib : The local variables used to communicate with the GS1s. 

Modbus_GS1.lvlib : I/O library that should work with Modbus control but currently does not. 

"Modbus VI Supports" Folder : This folder contains the support pieces that allow the use of Modbus-specific VIs with LV. To
use these, the implementation is: 
 - Close LabVIEW.
 - If you have version NI-MODBUS Library 1.1 on your system, it is recommended to uninstall it by going to Control Panel -> 
    Add Remove Programs -> National Instruments Software and select NI Modbus 1.1 from the list.
 - Copy NI Modbus.llb from the ##\vi.lib folder to the LabVIEW_ROOT\vi.lib directory where ## is your LabVIEW version 
    (example 86 for 8.6) and is the root folder where you installed LabVIEW.
 - Copy lvmodbus.chm and lvmodbus.txt from ##\help to the LabVIEW_ROOT\help directory.
 - Copy nimodbus.mnu from ##\user.lib to the LabVIEW_ROOT\user.lib directory.
 - Restart LabVIEW. You should see the NI Modbus palette in the User Libraries palette.