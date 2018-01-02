CC=g++
CFLAGS=-c -Wall -std=c++11


programMenu: main.o mainFunctions.o listFunctions.o
	$(CC) main.o mainFunctions.o listFunctions.o -o ProgramMenu

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

mainFunctions.o: mainFunctions.cpp
	$(CC) $(CFLAGS) mainFunctions.cpp

listFunctions.o: listFunctions.cpp
	$(CC) $(CFLAGS) listFunctions.cpp

clean:
	rm -rf *o programMenu
