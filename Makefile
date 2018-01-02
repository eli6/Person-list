CC=g++
CFLAGS=-c -Wall -std=c++11
INC := -I include

bin/programMenu: build/main.o build/mainFunctions.o build/listFunctions.o
	$(CC) build/main.o build/mainFunctions.o build/listFunctions.o -o bin/ProgramMenu

build/main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp -o build/main.o

build/mainFunctions.o: src/mainFunctions.cpp
	$(CC) $(CFLAGS) src/mainFunctions.cpp -o build/mainFunctions.o

build/listFunctions.o: src/listFunctions.cpp
	$(CC) $(CFLAGS) src/listFunctions.cpp -o build/listfunctions.o

clean:
	rm -rf *o bin/programMenu
