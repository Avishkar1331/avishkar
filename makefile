CC=gcc
CXX=g++
CFLAGS=-Iinclude

all: app

app: inventory.o InventoryManager.o main.o
	$(CXX) -o app inventory.o InventoryManager.o main.o

inventory.o:
	$(CC) -c src/inventory.c $(CFLAGS)

InventoryManager.o:
	$(CXX) -c src/InventoryManager.cpp $(CFLAGS)

main.o:
	$(CXX) -c src/main.cpp $(CFLAGS)

clean:
	rm -f *.o app