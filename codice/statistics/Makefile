CC = gcc
CFLAGS = -Wall -w -O1
exe = statistics_main
my_libraries = stat.h stat.c stat_main.c

all:
	$(CC) -o $(exe) $(my_libraries) $(CFLAGS)

run:
	./$(exe)

clean:
	rm $(exe) *.csv
