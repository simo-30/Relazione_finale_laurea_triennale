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
	proc->state=NOT_STATE;
	return proc;
}

void print_process(ProcessType* process) {
	printf("******************************\n");
	printf("**** process pid	%d ****\n", process->pid);
	printf("     time arriving	%d\n", process->time_arrive);
	printf("     duration		%d\n", process->duration);
	printf("     resource		%d\n", process->resource);
	//printf("     state	        %d\n", process->state);
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

int is_not_state(ProcessType* proc) {
	if (proc->state == NOT_STATE) {
		return 1;
	}
	return 0;
}

int is_running(ProcessType* proc) {
	if (proc->state == RUNNING) {
		return 1;
	}
	return 0;
}

int is_waiting(ProcessType* proc) {
	if (proc->state == WAITING) {
		return 1;
	}
	return 0;
}

int is_ready(ProcessType* proc) {
	if (proc->state == READY) {
		return 1;
	}
	return 0;
}

int is_terminated(ProcessType* proc) {
	if (proc->state == TERMINATED) {
		return 1;
	}
	return 0;
}

int is_burst(ProcessType* proc) {
	if (proc->state == BURST) {
		return 1;
	}
	return 0;
}
