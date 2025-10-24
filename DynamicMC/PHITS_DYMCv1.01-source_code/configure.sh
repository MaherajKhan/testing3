#!/bin/sh
cd program_files
make clean
qmake
make
make -f Makefile.gen
cd ScriptShowCode
make clean
qmake
make
cd ..
cp ./ScriptShowCode/ScriptShow ./
cd positionplotter
make clean
qmake
make
cd ..
cp ./positionplotter/CyricPositionPlotter ./
cd ../TallyPlot/
./configure.sh
