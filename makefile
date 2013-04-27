#Compiler
cc = g++

#Flags
cflags = -c 

#Files in the project
files = Object.o ADTList.o FSArray.o DSArray.o Main.o

#Classes
classes = Object.o ADTList.o FSArray.o DSArray.o

clean : Test
	rm $(files)

Test : Main.o
	$(cc) $(files) -o Test

Main.o : $(classes)
	$(cc) $(cflags) Main.cpp

FSArray.o : ADTList.o Object.o
	$(cc) $(cflags) FSArray.cpp

DSArray.o : ADTList.o Object.o
	$(cc) $(cflags) DSArray.cpp

ADTList.o : Object.o
	$(cc) $(cflags) ADTList.cpp

Object.o :
	$(cc) $(cflags) Object.cpp