#Compiler
cc = g++

#Flags
cflags = -c 

#Files in the project
#Lists implementations with ADTList
lists = ADTList.o FSArray.o DSArray.o SLNode.o SLList.o DLNode.o DLList.o
#Stacks implementations with ADTStack
stacks = ADTStack.o SLStack.o
#Queues implementations with ADTQueue 
queues = ADTQueue.o SLQueue.o 
#Other files in the project
files = Object.o $(lists) $(stacks) $(queues) Main.o

#Classes
classes = Object.o $(lists) $(stacks) $(queues)

#Remove all the *.o files
clean: Test
	rm $(files)

#Creates executable file
Test: Main.o
	$(cc) $(files) -o Test

#Compiling Main funcion with Nombre class
Main.o: $(classes)
	$(cc) $(cflags) Main.cpp

#ADTQueue ans its implementatios
ADTQueue.o: Object.o
	$(cc) $(cflags) ADTQueue.cpp

SLQueue.o: ADTQueue.o SLNode.o Object.o
	$(cc) $(cflags) SLQueue.cpp

#ADTStack and its implementations
ADTStack.o: Object.o
	$(cc) $(cflags) ADTStack.cpp

SLStack.o: ADTStack.o Object.o
	$(cc) $(cflags) SLStack.cpp

#ADTList and its implementations
ADTList.o: Object.o
	$(cc) $(cflags) ADTList.cpp

SLList.o: ADTList.o SLNode.o Object.o
	$(cc) $(cflags) SLList.cpp

SLNode.o: Object.o
	$(cc) $(cflags) SLNode.cpp

DLList.o: ADTList.o DLNode.o Object.o
	$(cc) $(cflags) DLList.cpp

DLNode.o: Object.o
	$(cc) $(cflags) DLNode.cpp

FSArray.o: ADTList.o Object.o
	$(cc) $(cflags) FSArray.cpp

DSArray.o: ADTList.o Object.o
	$(cc) $(cflags) DSArray.cpp

#Object class
Object.o:
	$(cc) $(cflags) Object.cpp