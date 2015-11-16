# DVB SI Parser

DVB SI Parser is an opensource code published under **LGPL v2.1** license. Please refer to **License.txt** file for more information about the terms and conditions.

This code comprises of 2 modules.

* DVB section parser
* DVB storage.

## DVB Section parser

This module comprise of code to parse the DVB tables such as 
* EIT
* BAT
* TDT
* SDT
* UDT
etc...

Along with this it also comprises of different descriptor parsers such as.

* Cable Delivery System Descriptor.
* Component Descriptor.
* Content Descriptor.
* Parental Rating Descriptor.
etc...

## DVB Storage

This module facilitates to store the parsed data in db file. You are free to use this DB or some other DB of your choice. To give user more flexibility on his/her Data Base of choice, we have kept Storage and Section parser as separate module. You can build both DVB Storage and DVB Section parser independently and use it based on your needs :+1:.

### How to build?
Run the ".build.sh" script to do a build. Or you can go to individual modules and run the make command.

Run the ".clean.sh" script to do the clean.


### Other opensource Dependencies

 * Boost libs.
 * Sqlite3pp libs.
 * jansson libs
 
 All these source code/libs are bundled as part of this code, which builds/linked when you do a make on the source code by running build.sh script.
 
 ### Change Log
