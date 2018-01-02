#CC :=g++ #compiler
#CC := clang --analyze
#SRCDIR := src
#BUILDDIR := build
#TARGET := bin/runner

#SRCTEXT := cpp
#SOURCES := $(SRCDIR)/main.cpp, $(SRCDIR)/listFunctions.cpp, $(SRCDIR)/mainFunctions.cpp
#OBJECTS := $(BUILDDIR)/main.o, $(BUILDDIR)/listFunctions.o, $(BUILDDIR)/mainFunctions.o
#CFLAGS=-c -Wall -std=c++11
#INC := -I include

#$(TARGET): $(OBJECTS)
	#$(CC) $(OBJECTS) -o $(TARGET)

#$(OBJECTS): $(SOURCES)
	#$mkdir -p $(BUILDDIR)
	#$(CC) $(CFLAGS) -o $(SOURCES)

#clean:
	#$(RM) -r $(BUILDDIR) $(TARGET)

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
