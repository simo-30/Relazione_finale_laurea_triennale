CC = gcc
CFLAGS = -Wall -w -O1
exe = simulator_main
my_libraries = ../utility/macro.h ../processo/process.h ../processo/process.c ../lista_processo/process_list.h ../lista_processo/process_list.c ../setting/setting.h ../setting/setting.c ../utility/utility.h ../utility/utility.c ../statistics/stat.h ../statistics/stat.c ../FCFS/fcfs.h ../FCFS/fcfs.c ../RR/rr.h ../RR/rr.c ../SJF/sjf.h ../SJF/sjf.c ../SRJF/srjf.h ../SRJF/srjf.c main.c

all:
	$(CC) -o $(exe) $(my_libraries) $(CFLAGS)

run:
	./$(exe)
	rm ../file/result/*.txt

clean:
	rm $(exe)
