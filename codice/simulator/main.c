#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include FCFS_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

int main() {
	int i;
	printf("FCFS in esecuzione\n");
	for (i=0; i<NUM_CICLI; i++) {
		printf(".");
		fcfs_running(SET_1, RES_FCFS_1);
		fcfs_running(SET_2, RES_FCFS_2);
		fcfs_running(SET_3, RES_FCFS_3);
	}
	printf("\nFINE\n");
	return 0;
}
