#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include "rr.h"
#pragma once

void rr_running(const char* name_setting, const char* result) {
	SettingType* setting=read_setting(name_setting);
	if (setting->core == 0 || setting->pid == 0) {
		printf("Errore nel file di setting %s, numero di core o numero di processi NON valido\n", name_setting);
		return;
	}
	rr_scheduler(setting, result);
	return;
}

void rr_scheduler(SettingType* setting, const char* result) {
	ListProcess* list=generate_listProcess_from_setting(setting);
	StatisticsType* stat=new_statisticsType(setting->pid, setting->core);
	int timing;
	int* pid_proc=new_array_negative_inizialized(setting->pid);
	CoreType* core_list=new_CoreType_list(setting->core, QUANTUM); 
	for (timing=0; timing<=setting->max_time; timing++) {
		/**Implementazione vera e propria della politica**/
	}
	//while (count_state_to_terminated(list) != 0) {
	//}
	//write_on_file(stat, result);
	return;
}

CoreType* new_CoreType_list(int dim, int quantum_time) {
	CoreType* core=(CoreType*)malloc(dim*sizeof(CoreType));
	int i;
	for (i=0; i<dim; i++) {
		core[i].pid=-1;
		core[i].core_time=quantum_time;
	}
	return core;
}

void print_CoreType_list(CoreType* core, int dim) {
	int i;
	printf("Situazione core:\n");
	for (i=0; i<dim; i++) {
		printf("Core: %d\n", i);
		if (core[i].pid==-1) {
			printf("core libero\n");
		}
		else {
			printf("Pid: %d\n", core[i].pid);
			printf("Tempo rimanente: %d\n", core[i].core_time);
		}
	}
	return;
}

void insert_into_cores(CoreType* core, int pid, int dim) {
	int i;
	for (i=0; i<dim; i++) {
		if (core[i].pid == -1) {
			core[i].pid=pid;
			core[i].core_time=QUANTUM;
			return;
		}
	}
	return;
}

void scaling_core_list(CoreType* core, int dim, int val) {
	int i;
	for (i=0; i<dim; i++) {
		if (core[i].pid==val) {
			while (i<dim) {
				if ((i+1)==dim) {
					core[i].pid=-1;
					core[i].core_time=QUANTUM;
					return;
				}
				core[i].pid=core[i+1].pid;
				core[i].core_time=core[i+1].core_time;
				i+=1;
			}
		}
	}
	return;
}

int count_state_to_terminated(ListProcess* list) {
	int state;
	state=count_is_not_state(list) + count_is_ready(list) + count_is_running(list) + count_is_waiting(list) + count_is_burst(list);
	if (state > 0) {
		return 1;
	}
	return 0;
}
