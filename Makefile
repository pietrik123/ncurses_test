CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lncurses
SRC = src/main.cpp
TARGET = app

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)