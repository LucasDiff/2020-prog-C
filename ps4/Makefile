CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
TARGET=app
MODULES = transformations.o bmp.o

all:$(TARGET)

clean:
	rm *.o $(TARGET)

$(TARGET): main.o $(MODULES)

main.o: main.c bmp.h transformations.h
bmp.o: bmp.c bmp.h
transformations.o: transformations.c transformations.h

$(TARGET): bmp.o transformations.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) main.o transformations.o bmp.o -o $(TARGET) $(LDLIBS)

main.o: main.c
	$(CC) -c $(CFLAGS) $(LDLIBS) main.c -o main.o
bmp.o: bmp.c
	$(CC) -c $(CFLAGS) $(LDLIBS) bmp.c -o bmp.o
transformations.o: transformations.c
	$(CC) -c $(CFLAGS) $(LDLIBS) transformations.c -o transformations.o