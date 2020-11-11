#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include "fcfs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

void fcfs_scheduler(SettingType* setting) {
	ListProcess* list=generate_listProcess_from_setting(setting);
	StatisticsType* stat=new_statisticsType(setting->pid, setting->core);
	int timing;
	int* pid_proc=new_array_negative_inizialized(setting->pid);
	for (timing=0; timing<=setting->max_time; timing++) {
		
	}
	//write_on_file(stat, "stat.txt");
	return;
}

void fcfs_running(const char* name_setting) {
	SettingType* setting=read_setting(name_setting);
	if (setting->core == 0 || setting->pid == 0) {
		printf("Errore nel file di setting, numero di core o numero di processi NON valido\n");
		return;
	}
	fcfs_scheduler(setting);
	return;
}
