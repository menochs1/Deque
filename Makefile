CC = g++
TARGET = run
CFLAGS = -g -Wall -Wextra

all: $(TARGET)

$(TARGET): main.o Deque.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Deque.o

Deque.o: Deque.cpp Deque.h
	$(CC) -c -Wall -Wextra Deque.cpp

main.o: main.cpp Deque.h
	$(CC) -c -Wall -Wextra main.cpp

clean:
	$(RM) $(TARGET) *.o *~
