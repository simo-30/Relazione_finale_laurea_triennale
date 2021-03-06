#include "../utility/macro.h"
#include PROCESS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	printf("     resource		%s\n", resource_to_string(process));
	printf("     state	        %s\n", state_to_string(process));
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
		printf("Errore nell'apertura del file\n");
		return;
	}
	fprintf(fd, "**** process pid	%d ****\n", process->pid);
	fprintf(fd, "     time arriving	%d\n", process->time_arrive);
	fprintf(fd, "     duration		%d\n", process->duration);
	fprintf(fd, "     resource		%s\n", resource_to_string(process));
	fprintf(fd, "     state	        %s\n", state_to_string(process));
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

void to_run(ProcessType* proc) {
	proc->state=RUNNING;
	return;
}

void to_wait(ProcessType* proc) {
	proc->state=WAITING;
	return;
}

void to_ready(ProcessType* proc) {
	proc->state=READY;
	return;
}

char* state_to_string(ProcessType* proc) {
	switch (proc->state) {
		case 0:
			return "NOT_STATE";
		case 1:
			return "RUNNING";
		case 2:
			return "WAITING";
		case 3:
			return "READY";
		case 4:
			return "TERMINATED";
		case 5:
			return "BURST";
		}
}

void to_burst(ProcessType* proc) {
	proc->state=BURST;
	return;
}

void new_burst_for_process(ProcessType* proc, int min_time, int max_time, int avg_time) {
	srand(time(NULL));
	proc->duration = ( rand() % avg_time ) +1;
	proc->resource = rand() % 2;
	proc->time_arrive = ( rand() % (max_time*2) ) + min_time + 1;
	return;
}

void to_terminated(ProcessType* proc) {
	proc->state=TERMINATED;
	return;
}

char* resource_to_string(ProcessType* proc) {
	switch (proc->resource) {
		case 0:
			return "CPU";
		case 1:
			return "I/O";
		}
}

int resource_is_CPU(ProcessType* proc) {
	if (proc->resource == CPU) {
		return 1;
	}
	return 0;
}

int resource_is_IO(ProcessType* proc) {
	if (proc->resource == IO) {
		return 1;
	}
	return 0;
}
