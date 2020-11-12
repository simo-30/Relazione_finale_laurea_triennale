CC = gcc
CFLAGS = -Wall -w -O1
exe = fcfs_main
my_libraries = ../utility/macro.h ../processo/process.h ../processo/process.c ../lista_processo/process_list.h ../lista_processo/process_list.c ../setting/setting.h ../setting/setting.c ../utility/utility.h ../utility/utility.c ../statistics/stat.h ../statistics/stat.c fcfs.h fcfs.c fcfs_main.c

all:
	$(CC) -o $(exe) $(my_libraries) $(CFLAGS)

run:
	./$(exe)

clean:
	rm $(exe) *.txt *.csv
