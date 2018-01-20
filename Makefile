CC=g++
CFLAGS= -Wall -std=c++11 -Wpedantic -pedantic-errors -Wextra -Wmisleading-indentation -Wtraditional -Weverything -Wconversion
INC := -I include

bin/programMenu: build/main.o build/mainFunctions.o build/listFunctions.o build/constants.o
	$(CC) $(CFLAGS) build/main.o build/mainFunctions.o build/listFunctions.o build/constants.o -o bin/ProgramMenu

build/main.o: src/main.cpp #src/constants.h
	$(CC) -c $(CFLAGS) src/main.cpp -o build/main.o

build/constants.o: src/constants.cpp
	$(CC) -c $(CFLAGS) src/constants.cpp -o build/constants.o

build/mainFunctions.o: src/mainFunctions.cpp src/mainFunctions.h #src/constants.h
	$(CC) -c $(CFLAGS) src/mainFunctions.cpp -o build/mainFunctions.o

build/listFunctions.o: src/listFunctions.cpp src/listFunctions.h src/constants.h src/mainFunctions.h
	$(CC) -c $(CFLAGS) src/listFunctions.cpp -o build/listfunctions.o

clean:
	rm -rf *o bin/programMenu
