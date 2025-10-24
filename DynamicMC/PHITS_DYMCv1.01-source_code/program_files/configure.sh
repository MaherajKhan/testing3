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
