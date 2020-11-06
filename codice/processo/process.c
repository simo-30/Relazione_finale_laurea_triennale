#include "../utility/macro.h"
#include PROCESS_H
#include <stdio.h>
#include <stdlib.h>
#pragma once

ProcessType* create_process(int pid, int time_arrive, int duration, ResourceType resource) {
	ProcessType* proc=(ProcessType*)malloc(sizeof(ProcessType));
	proc->pid=pid;
	proc->time_arrive=time_arrive;
	proc->duration=duration;
	proc->resource=resource;
	proc->is_runnning=NOTRUN;
	return proc;
}

void print_process(ProcessType* process) {
	printf("******************************\n");
	printf("**** process pid	%d ****\n", process->pid);
	printf("     time arriving	%d\n", process->time_arrive);
	printf("     duration		%d\n", process->duration);
	printf("     resource		%d\n", process->resource);
	/*if (process->is_runnning==RUN) {
		printf("     is running     \n");
	}
	else {
		printf("     is not running	\n");
	}*/
	printf("******************************\n\n");
	return;
}

void destroy_process(ProcessType* process) {
	free(process);
	return;
}

void append_process_onFile(ProcessType* process, const char* nameFile) {
	FILE* fd=fopen(nameFile, "a");
	if (fd==NULL) {
		perror("Errore nell'apertura del file\n");
		return;
	}
	fprintf(fd, "**** process pid	%d ****\n", process->pid);
	fprintf(fd, "     time arriving	%d\n", process->time_arrive);
	fprintf(fd, "     duration		%d\n", process->duration);
	fprintf(fd, "     resource		%d\n", process->resource);
	fprintf(fd, "******************************\n");
	fclose(fd);
	return;
}
