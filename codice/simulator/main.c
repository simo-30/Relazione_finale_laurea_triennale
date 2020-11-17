#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include FCFS_H
#include RR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

int main() {
	int i;
	printf("FCFS & RR in esecuzione\n");
	for (i=0; i<NUM_CICLI; i++) {
		printf(".");
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
	}
	printf("\nFINE\n");
	return 0;
}
