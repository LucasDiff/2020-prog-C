# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -g
LDLIBS=- lm -lcurses
OUTPUT=$@

#targets
%: %.c
		$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $(OUTPUT)
		
all: $(OUTPUT)

$(OUTPUT): playfair.o main.o bmp.o
		cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
		$(CC) $(CFLAGS) playfair.o bmp.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
		$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o
		
playfair.o: playfair.c playfair.h
		$(CC) $(CFLAGS) -c playfair.c $(LDLIBS) -o playfair.o

bmp.o: bmp.c bmp.h
		$(CC) $(CFLAGS) -c bmp.c $(LDLIBS) -o bmp.o
		
# remove compiled files
clean: 
		rm -rf $(OUTPUT) *.o