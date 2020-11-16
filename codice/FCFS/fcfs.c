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

void fcfs_scheduler(SettingType* setting, const char* result) {
	ListProcess* list=generate_listProcess_from_setting(setting);
	StatisticsType* stat=new_statisticsType(setting->pid, setting->core);
	int timing;
	int* pid_proc=new_array_negative_inizialized(setting->pid);
	for (timing=0; timing<=setting->max_time; timing++) {
		/**Implementazione vera e propria della politica**/
		fcfs_to_ready_proc(list, timing, pid_proc, setting->pid);
		if (count_is_running(list) < setting->core) {
			//processo va in running
			fcfs_to_running_proc(list, timing, pid_proc, setting->pid, setting->core);
		}
		else {
			//processo va in waiting
			fcfs_to_waiting_proc(list, timing, pid_proc, setting->pid);
		}
		fcfs_run_proc(list);
		fcfs_to_burst_proc(list, pid_proc, setting->pid);
		fcfs_new_burst_proc(list, timing, setting->max_time, setting->avg_time);
		update_statistics(list, stat);
	}
	while (count_state_to_terminated(list) != 0) {
		fcfs_to_ready_proc(list, timing, pid_proc, setting->pid);
		if (count_is_running(list) < setting->core) {
			//processo va in running
			fcfs_to_running_proc(list, timing, pid_proc, setting->pid, setting->core);
		}
		else {
			//processo va in waiting
			fcfs_to_waiting_proc(list, timing, pid_proc, setting->pid);
		}
		fcfs_run_proc(list);
		fcfs_to_terminated_proc(list, pid_proc, setting->pid);
		update_statistics(list, stat);
	}
	write_on_file(stat, result);
	return;
}

void fcfs_running(const char* name_setting, const char* result) {
	SettingType* setting=read_setting(name_setting);
	if (setting->core == 0 || setting->pid == 0) {
		printf("Errore nel file di setting %s, numero di core o numero di processi NON valido\n", name_setting);
		return;
	}
	fcfs_scheduler(setting, result);
	return;
}

void fcfs_to_ready_proc(ListProcess* list, int timing, int* proc, int dim) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (aux->info->time_arrive == timing) {
			if (aux->info->state == NOT_STATE) {
				//processo nuovo appena arrivato
				to_ready(aux->info);
				insert_first_possible(proc, dim, aux->info->pid);
			}
			if (aux->info->state == BURST) {
				to_ready(aux->info);
				insert_first_possible(proc, dim, aux->info->pid);
			}
		}
		aux=aux->next;
	}
	return;
}

void fcfs_to_waiting_proc(ListProcess* list, int timing, int* proc, int dim) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_ready(aux->info) == 1) {
			to_wait(aux->info);
		}
		aux=aux->next;
	}
	return;
}

void fcfs_to_running_proc(ListProcess* list, int timing, int* proc, int dim, int core) {
	int i;
	for (i=0; i<dim; i++) {
		ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
		aux=list->first;
		int j;
		if (proc[i]==-1) {
			return;
		}
		for (j=0; j<list->size; j++) {
			if (aux->info->pid==proc[i]) {
				if (is_waiting(aux->info)==1) {
					to_run(aux->info);
					if (count_is_running(list)==core) {
						fcfs_to_waiting_proc(list, timing, proc, dim);
						return;
					}
				}
				if (is_ready(aux->info)==1) {
					to_run(aux->info);
					if (count_is_running(list)==core) {
						fcfs_to_waiting_proc(list, timing, proc, dim);
						return;
					}
				}
			}
			aux=aux->next;
		}
	}
	return;
}

void fcfs_run_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info) == 1) {
			aux->info->duration-=1;
		}
		aux=aux->next;
	}
	return;
}

void fcfs_to_burst_proc(ListProcess* list, int* proc, int dim) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info) == 1) {
			if (aux->info->duration == 0) {
				to_burst(aux->info);
				scaling_array(proc, dim, aux->info->pid);
			}
		}
		aux=aux->next;
	}
	return;
}

void fcfs_new_burst_proc(ListProcess* list, int min_time, int max_time, int avg_time) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_burst(aux->info) == 1) {
			new_burst_for_process(aux->info, min_time, max_time, avg_time);
		}
		aux=aux->next;
	}
	return;
}

int count_state_to_terminated(ListProcess* list) {
	int state;
	state=count_is_not_state(list) + count_is_ready(list) + count_is_running(list) + count_is_waiting(list);
	if (state > 0) {
		return 1;
	}
	return 0;
}

void fcfs_to_terminated_proc(ListProcess* list, int* proc, int dim) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info) == 1) {
			if (aux->info->duration == 0) {
				to_terminated(aux->info);
				scaling_array(proc, dim, aux->info->pid);
			}
		}
		aux=aux->next;
	}
	return;
}
