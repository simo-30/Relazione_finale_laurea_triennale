#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include FCFS_H
#include RR_H
#include SJF_H
#include SRJF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

char set[18][50]={SET_1, SET_2, SET_3, SET_4, SET_5, SET_6, SET_7, SET_8, SET_9, SET_10, SET_11, SET_12, SET_13, SET_14, SET_15, SET_16, SET_17, SET_18};

char fcfs_res[18][50]={RES_FCFS_1, RES_FCFS_2, RES_FCFS_3, RES_FCFS_4, RES_FCFS_5, RES_FCFS_6, RES_FCFS_7, RES_FCFS_8, RES_FCFS_9, RES_FCFS_10,
	RES_FCFS_11, RES_FCFS_12, RES_FCFS_13, RES_FCFS_14, RES_FCFS_15, RES_FCFS_16, RES_FCFS_17, RES_FCFS_18};

char rr_res[18][50]={RES_RR_1, RES_RR_2, RES_RR_3, RES_RR_4, RES_RR_5, RES_RR_6, RES_RR_7, RES_RR_8, RES_RR_9, RES_RR_10, RES_RR_11, RES_RR_12,
	RES_RR_13, RES_RR_14, RES_RR_15, RES_RR_16, RES_RR_17, RES_RR_18};

char sjf_res[18][50]={RES_SJF_1, RES_SJF_2, RES_SJF_3, RES_SJF_4, RES_SJF_5, RES_SJF_6, RES_SJF_7, RES_SJF_8, RES_SJF_9, RES_SJF_10, RES_SJF_11,
	RES_SJF_12, RES_SJF_13, RES_SJF_14, RES_SJF_15, RES_SJF_16, RES_SJF_17, RES_SJF_18};

char srjf_res[18][50]={RES_SRJF_1, RES_SRJF_2, RES_SRJF_3, RES_SRJF_4, RES_SRJF_5, RES_SRJF_6, RES_SRJF_7, RES_SRJF_8, RES_SRJF_9, RES_SRJF_10,
	RES_SRJF_11, RES_SRJF_12, RES_SRJF_13, RES_SRJF_14, RES_SRJF_15, RES_SRJF_16, RES_SRJF_17, RES_SRJF_18};

int main() {
	int i, j;
	printf("Simulatore in esecuzione\n");
	for (i=0; i<NUM_CICLI; i++) {
		for (j=0; j<NUM_SET; j++) {
			fcfs_running(set[j], fcfs_res[j]);
			rr_running(set[j], rr_res[j]);
			sjf_running(set[j], sjf_res[j]);
			srjf_running(set[j], srjf_res[j]);
		}
		float perc = ((i+1)*100)/NUM_CICLI; 
		printf("%.2f %\n", perc);
	}
	printf("\nFINE\n");
	return 0;
}
