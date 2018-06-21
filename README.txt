
This is the README file of “Search Tree” type developed by
Sevak Martirosyan and Sevak Sahakyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. BUILD
        5. DIRECTORY STRUCTURE
        6. USAGE
        7. DOCUMENTATION
        

1. AUTHOR
Sevak Martirosyan, Sevak Sahakyan.
E-mail: sevak.sahakyan29@gmail.com
		sevak707@gmail.com

Project Maintainer
	Sevak Martirosyan, Sevak Sahakyan.
	sevak.sahakyan29@gmail.com
	sevak707@gmail.com
	
2. INTRODUCTION


3. PREREQUISITES
The following third party tools should be installed before the
compilation.

Tools:
g++
doxygen

4. BUILD
See the following commands in the project root directory.
Build the project
	make
	
Delete secondary files
	make clean

5. DIRECTORY STRUCTURE
- battleShip – the top directory
	- src – should contain the source code of the project
	- makefile – the top makefile for building the project
	- docs -  for containing documentations
		Product requirements document
		Functional specification document
		Development specification document
		/doxygen_config should contain file for doxygen configuration file

After building, the following directories should be created:
	- deps – should contain dependency files
	- obj – should contain oject files
	- bin – should contain executable file
	
	
6. USAGE


7. DOCUMENTATION
"make docs" command generates doxygen documentation.

Doxygen also generates documentation from C/C++ code comments.

To see the generated documentation use ./docs/doxygen/html/index.html.
