
CC = g++
CFLAGS = -g -Wall
SFML_LINKS = -lsfml-graphics -lsfml-window -lsfml-system

# TODO: Link to these in external folder
INC = -I./external/SFML-2.5.1/include
LIB = -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC = ./src
BUILD = ./build
BIN = ./bin

TARGET = main

default: all

all: $(TARGET)

$(TARGET):$(TARGET).o Game.o
	$(CC) $(CFLAGS) -o $(BIN)/$(TARGET) $(BUILD)/*.o $(SFML_LINKS)

$(TARGET).o: $(SRC)/$(TARGET).cpp
	$(CC) $(CFLAGS) -c $(SRC)/$(TARGET).cpp -o $(BUILD)/$(TARGET).o

Game.o: $(SRC)/Game.cpp $(SRC)/Game.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Game.cpp -o $(BUILD)/Game.o

clean:
	rm $(BUILD)/*
	rm $(BIN)/*

run: $(BIN)/$(TARGET)
	$(BIN)/$(TARGET)