CC = gcc
CFLAGS = -Wall -w -O1
exe = process_list_main
my_libraries = ../utility/macro.h ../processo/process.h ../processo/process.c process_list.h process_list.c ../setting/setting.h ../setting/setting.c ../utility/utility.h ../utility/utility.c ../statistics/stat.h ../statistics/stat.c process_list_main.c

all:
	$(CC) -o $(exe) $(my_libraries) $(CFLAGS)

run:
	./$(exe)

clean:
	rm $(exe)
