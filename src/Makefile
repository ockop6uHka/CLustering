CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
SRC = main.c clustering.c
OBJ = main.o clustering.o
TARGET = clustering

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c clustering.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clustering.o: clustering.c clustering.h
	$(CC) $(CFLAGS) -c clustering.c -o clustering.o

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
