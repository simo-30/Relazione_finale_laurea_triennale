#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stat.h"
#pragma once

StatisticsType* new_statisticsType(int num_proc, int num_core, const char* name_scheduling) {
	StatisticsType* stat=(StatisticsType*)malloc(sizeof(StatisticsType));
	stat->num_proc=num_proc;
	stat->num_core=num_core;
	stat->name_scheduling=malloc((strlen(name_scheduling) + 1)*sizeof(char));
	strcpy(stat->name_scheduling, name_scheduling);
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
