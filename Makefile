PROGRAM = main
OBJS = main.o chap01.o
CC = gcc
CFLAGS = -Wall -O2
LIB = -lm

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $^ $(LIB)

main.o: main.c
	$(CC) $(CFLAGS) -c $<

chap01.o: chap01.c
	$(CC) $(CFLAGS) -c $< 

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)