#include <stdio.h>
#include <stdlib.h>
#include "stat.h"
#pragma once

StatisticsType* new_statisticsType(int num_proc, int num_core) {
	StatisticsType* stat=(StatisticsType*)malloc(sizeof(StatisticsType));
	stat->num_proc=num_proc;
	stat->num_core=num_core;
	stat->medium_wait_time=0;
	stat->medium_complete_time=0;
	stat->waiting_time=malloc(num_proc * sizeof(int));
	stat->completing_time=malloc(num_proc * sizeof(int));
	int i;
	for (i=0; i<num_proc; i++) {
		stat->waiting_time[i]=0;
		stat->completing_time[i]=0;
	}
	return stat;
}

void print_waiting_time(int n, int* waiting_time) {
	int i;
	printf("Tempi di attesa:\n");
	for (i=0; i<n; i++) {
		printf("pid[%d]: %d\n", i+1, waiting_time[i]);
	}
	printf("\n");
	return;
}

void print_completing_time(int n, int* completing_time) {
	int i;
	printf("Tempi di completamento:\n");
	for (i=0; i<n; i++) {
		printf("pid[%d]: %d\n", i+1, completing_time[i]);
	}
	printf("\n");
	return;
}

void print_statistics(StatisticsType* stat) {
	printf("Statistiche della politica di scheduling\n");
	printf("Numero di core: %d\n", stat->num_core);
	printf("Numero di processi: %d\n", stat->num_proc);
	printf("Tempo medio di attesa: %d\n", stat->medium_wait_time);
	printf("Tempo medio di completamento: %d\n", stat->medium_complete_time);
	return;
}

void update_medium_waiting_time(StatisticsType* stat) {
	int tot_waiting, i;
	tot_waiting=0;
	for (i=0; i<stat->num_proc; i++) {
		tot_waiting+=stat->waiting_time[i];
	}
	stat->medium_wait_time= tot_waiting / stat->num_proc;
	return;
}

void update_medium_completing_time(StatisticsType* stat) {
	int tot_compl, i;
	tot_compl=0;
	for (i=0; i<stat->num_proc; i++) {
		tot_compl+=stat->completing_time[i];
	}
	stat->medium_complete_time= tot_compl /stat->num_proc;
	return;
}

void write_on_file(StatisticsType* stat, const char* filename) {
	//i dati saranno salvati in un file csv, nel seguente ordine:
	//numero di core, numero di processi, tempo medio di attesa, tempo medio di completamento
	FILE* fd=fopen(filename, "a");
	if (fd == NULL) {
		printf("Errore nell'apertura del file %s\n", filename);
		return;
	}
	fprintf(fd, "%d,%d,%d,%d\n", stat->num_core, stat->num_proc, stat->medium_wait_time, stat->medium_complete_time);
	fclose(fd);
	return;
}
