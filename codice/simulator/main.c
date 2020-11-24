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

char set[NUM_SET][50]={SET_1, SET_2, SET_3, SET_4, SET_5, SET_6, SET_7, SET_8, SET_9, SET_10, SET_11, SET_12, SET_13, SET_14, SET_15, SET_16, SET_17,
	SET_18, SET_19, SET_20, SET_21, SET_22, SET_23, SET_24};

char fcfs_res[NUM_SET][50]={RES_FCFS_1, RES_FCFS_2, RES_FCFS_3, RES_FCFS_4, RES_FCFS_5, RES_FCFS_6, RES_FCFS_7, RES_FCFS_8, RES_FCFS_9, RES_FCFS_10,
	RES_FCFS_11, RES_FCFS_12, RES_FCFS_13, RES_FCFS_14, RES_FCFS_15, RES_FCFS_16, RES_FCFS_17, RES_FCFS_18, RES_FCFS_19, RES_FCFS_20, RES_FCFS_21,
	RES_FCFS_22, RES_FCFS_23, RES_FCFS_24};

char rr_res[NUM_SET][50]={RES_RR_1, RES_RR_2, RES_RR_3, RES_RR_4, RES_RR_5, RES_RR_6, RES_RR_7, RES_RR_8, RES_RR_9, RES_RR_10, RES_RR_11, RES_RR_12,
	RES_RR_13, RES_RR_14, RES_RR_15, RES_RR_16, RES_RR_17, RES_RR_18, RES_RR_19, RES_RR_20, RES_RR_21, RES_RR_22, RES_RR_23, RES_RR_24};

char sjf_res[NUM_SET][50]={RES_SJF_1, RES_SJF_2, RES_SJF_3, RES_SJF_4, RES_SJF_5, RES_SJF_6, RES_SJF_7, RES_SJF_8, RES_SJF_9, RES_SJF_10, RES_SJF_11,
	RES_SJF_12, RES_SJF_13, RES_SJF_14, RES_SJF_15, RES_SJF_16, RES_SJF_17, RES_SJF_18, RES_SJF_19, RES_SJF_20, RES_SJF_21, RES_SJF_22, RES_SJF_23,
	RES_SJF_24};

char srjf_res[NUM_SET][50]={RES_SRJF_1, RES_SRJF_2, RES_SRJF_3, RES_SRJF_4, RES_SRJF_5, RES_SRJF_6, RES_SRJF_7, RES_SRJF_8, RES_SRJF_9, RES_SRJF_10,
	RES_SRJF_11, RES_SRJF_12, RES_SRJF_13, RES_SRJF_14, RES_SRJF_15, RES_SRJF_16, RES_SRJF_17, RES_SRJF_18, RES_SRJF_19, RES_SRJF_20, RES_SRJF_21,
	RES_SRJF_22, RES_SRJF_23, RES_SRJF_24};

int main() {
	int i, j;
	float p;
	printf("Simulatore in esecuzione\n");
	for (i=0; i<NUM_CICLI; i++) {
		for (j=0; j<NUM_SET; j++) {
			fcfs_running(set[j], fcfs_res[j]);
			rr_running(set[j], rr_res[j]);
			sjf_running(set[j], sjf_res[j]);
			srjf_running(set[j], srjf_res[j]);
		}
		p=i;
		float perc = ((p+1)*100)/NUM_CICLI; 
		printf("%.2f %\n", perc);
	}
	printf("\nCalcolo delle statistiche finali\n");
	for (i=0; i<NUM_SET; i++) {
		calculate_final_result(fcfs_res[i], FCFS_FINAL_RES);
		calculate_final_result(rr_res[i], RR_FINAL_RES);
		calculate_final_result(sjf_res[i], SJF_FINAL_RES);
		calculate_final_result(srjf_res[i], SRJF_FINAL_RES);
		p=i;
		float perc = ((p+1)*100)/NUM_SET; 
		printf("%.2f %\n", perc);
	}
	printf("\nFINE\n");
	return 0;
}
