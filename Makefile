#Makefile for Assignment 4
#Alexander Zimmermann ZMMALE001

CC=g++

LDFLAGS = -lm -lstdc++fs
CCFLAGS=-std=c++17 $(LDFLAGS)

SRC = $(wildcard src/*.cpp *.h)
OBJ = $(SRC:.cpp=.o)

PROG = clusterer

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o clusterer
	
.cpp.o:
	$(CC) $(CCFLAGS) -c $< -o $@

depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f clusterer
