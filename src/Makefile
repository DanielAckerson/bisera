# Compiler options
CC=g++
CFLAGS=-c -Wall -std=c++11
INC=-I../include
LDFLAGS=-lglfw -lgl -lGLEW
TARGET=bisera-client

OBJS=bisera.o game.o

%.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) $(INC) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(INC) $^
