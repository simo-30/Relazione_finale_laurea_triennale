CC = gcc
CFLAGS = -Wall -w -O1
exe = process_main
my_libraries = process.h process.c process_main.c

all:
	$(CC) -o $(exe) $(my_libraries) $(CFLAGS)

run:
	./$(exe)

clean:
	rm $(exe)
