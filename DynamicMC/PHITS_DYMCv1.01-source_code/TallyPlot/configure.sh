#!/bin/sh
make clean
qmake
make
g++ -O2 -Wall -Wextra --verbose searchtally.cpp -o searchtally.exe
gfortran -O2 --verbose sumtallyparser.f90 -o sumtallyparser.exe
