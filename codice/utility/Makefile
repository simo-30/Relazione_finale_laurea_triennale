CC = gcc
CFLAGS = -Wall -w -O1
exe = utility_main
my_libraries = utility.h utility.c utility_main.c

all:
	$(CC) -o $(exe) $(my_libraries) $(CFLAGS)

run:
	./$(exe)

clean:
	rm $(exe)
