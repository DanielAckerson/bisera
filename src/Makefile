# Compiler options
CC=clang++
CFLAGS=-c -Wall -std=c++11
INC=-I../include
LDFLAGS=-lglfw -lGL -lGLEW
TARGET=../bin/bisera-client

OBJS=bisera.o game.o

%.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) $(INC) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(INC) $^
