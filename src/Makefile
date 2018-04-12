# Compiler options
CC=clang++
CFLAGS=-c -Wall -std=c++14 -g
INC=-I../include
LDFLAGS=-lglfw -lGL -lGLEW
TARGET=../bin/bisera-client

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) $(INC) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(INC) $^
