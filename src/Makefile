# Compiler options
CC=clang++
CFLAGS=-c -Wall
INC=-I../include
LDFLAGS=
TARGET=bisera-client

OBJS=bisera.o game.o

%.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) $(INC) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(INC) $^
