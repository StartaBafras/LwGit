CC = gcc
CFLAGS = -Wall -Wextra 

all: lwgit 


main.o: main.c
	$(CC) $(CFLAGS) -g -c main.c

	
lwgit: main.o 
	$(CC) $(CFLAGS) -o lwgit main.o 


clean:
	rm -f test *.o
	rm -f *.s
	rm lwgit