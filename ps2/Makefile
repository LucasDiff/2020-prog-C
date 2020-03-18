# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -g
LDLIBS=- lm -lcurses
OUTPUT=$@

#targets
%: %.c
		$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $(OUTPUT)
		
all: $(OUTPUT)

$(OUTPUT): hof.o k.o main.o ui.o
		cppcheck --enable=performance, unusedFunction --error-exitcode=1 *.c
		$(CC) $(CFLAGS) hof.o k.o ui.o main.o $(LDLIBS) -o $(OUTPUT)
        
main.o: main.c
		$(CC) $(CFLAGS) -c mainc $(LDLIBS) -o main.o
		
ui.o: ui.c ui.h
		$(CC) $(CFLAGS) -c ui.c $(LDLIBS) -o ui.o
		
hof.o: hof.c hof.h
		$(CC) $(CFLAGS) -c hof.c $(LDLIBS) -o hof.o
		
k.o: k.c k.h
		$(CC) $(CFLaGS) -c k.c $(LDLIBS) -o k.o
		
# remove compiled files 
clean:
		rm -rf $(OUTPUT) *.o
