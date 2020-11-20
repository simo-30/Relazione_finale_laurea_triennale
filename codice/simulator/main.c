#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include FCFS_H
#include RR_H
#include SJF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

int main() {
	int i;
	printf("FCFS, RR & SJF in esecuzione\n");
	for (i=0; i<NUM_CICLI; i++) {
		fcfs_running(SET_1, RES_FCFS_1);
		fcfs_running(SET_2, RES_FCFS_2);
		fcfs_running(SET_3, RES_FCFS_3);
		fcfs_running(SET_4, RES_FCFS_4);
		fcfs_running(SET_5, RES_FCFS_5);
		fcfs_running(SET_6, RES_FCFS_6);
		fcfs_running(SET_7, RES_FCFS_7);
		fcfs_running(SET_8, RES_FCFS_8);
		fcfs_running(SET_9, RES_FCFS_9);
		fcfs_running(SET_10, RES_FCFS_10);
		fcfs_running(SET_11, RES_FCFS_11);
		fcfs_running(SET_12, RES_FCFS_12);
		rr_running(SET_1, RES_RR_1);
		rr_running(SET_2, RES_RR_2);
		rr_running(SET_3, RES_RR_3);
		rr_running(SET_4, RES_RR_4);
		rr_running(SET_5, RES_RR_5);
		rr_running(SET_6, RES_RR_6);
		rr_running(SET_7, RES_RR_7);
		rr_running(SET_8, RES_RR_8);
		rr_running(SET_9, RES_RR_9);
		rr_running(SET_10, RES_RR_10);
		rr_running(SET_11, RES_RR_11);
		rr_running(SET_12, RES_RR_12);
		sjf_running(SET_1, RES_SJF_1);
		sjf_running(SET_2, RES_SJF_2);
		sjf_running(SET_3, RES_SJF_3);
		sjf_running(SET_4, RES_SJF_4);
		sjf_running(SET_5, RES_SJF_5);
		sjf_running(SET_6, RES_SJF_6);
		sjf_running(SET_7, RES_SJF_7);
		sjf_running(SET_8, RES_SJF_8);
		sjf_running(SET_9, RES_SJF_9);
		sjf_running(SET_10, RES_SJF_10);
		sjf_running(SET_11, RES_SJF_11);
		sjf_running(SET_12, RES_SJF_12);
		printf(".");
	}
	printf("\nFINE\n");
	return 0;
}
