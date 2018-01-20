CC=g++
CFLAGS= -Wall -std=c++11 -Wpedantic -pedantic-errors -Wextra -Wmisleading-indentation -Wtraditional -Weverything -Wconversion
INC := -I include

bin/programMenu: build/main.o build/generalFunctions.o build/addSearchRemove.o build/sortingRandomizing.o build/fileIO.o build/constants.o
	$(CC) $(CFLAGS) build/main.o build/generalFunctions.o build/addSearchRemove.o build/sortingRandomizing.o build/fileIO.o build/constants.o -o bin/ProgramMenu

build/main.o: src/main.cpp src/constants.h
	$(CC) -c $(CFLAGS) src/main.cpp -o build/main.o

build/constants.o: src/constants.cpp
	$(CC) -c $(CFLAGS) src/constants.cpp -o build/constants.o

build/generalFunctions.o: src/generalFunctions.cpp src/generalFunctions.h
	$(CC) -c $(CFLAGS) src/generalFunctions.cpp -o build/generalFunctions.o

build/addSearchRemove.o: src/addSearchRemove.cpp src/addSearchRemove.h src/constants.h src/generalFunctions.h
	$(CC) -c $(CFLAGS) src/addSearchRemove.cpp -o build/addSearchRemove.o

build/sortingRandomizing.o: src/sortingRandomizing.cpp src/addSearchRemove.h src/constants.h src/generalFunctions.h
	$(CC) -c $(CFLAGS) src/sortingRandomizing.cpp -o build/sortingRandomizing.o

build/fileIO.o: src/fileIO.cpp src/fileIO.h src/constants.h src/generalFunctions.h
	$(CC) -c $(CFLAGS) src/fileIO.cpp -o build/fileIO.o

clean:
	rm -rf *o bin/programMenu
