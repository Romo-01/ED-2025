CC = gcc
CFLAGS = -I. -Wall
DEPS = list.h stack.h converter.h
OBJ = list.o stack.o converter.o calc.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm

clean:
	rm -f *.o calc historial.txt