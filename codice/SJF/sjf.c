#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include "sjf.h"
#pragma once

void sjf_running(const char* name_setting, const char* result) {
	SettingType* setting=read_setting(name_setting);
	if (setting->core == 0 || setting->pid == 0) {
		printf("Errore nel file di setting %s, numero di core o numero di processi NON valido\n", name_setting);
		return;
	}
	sjf_scheduler(setting, result);
	return;
}

void sjf_scheduler(SettingType* setting, const char* result) {
	ListProcess* list=generate_listProcess_from_setting(setting);
	StatisticsType* stat=new_statisticsType(setting->pid, setting->core);
	int timing; 
	for (timing=0; timing<=setting->max_time; timing++) {
		/**Implementazione vera e propria della politica**/
		sjf_to_ready_proc(list, timing);
		if (count_is_running(list) < setting->core) {
			sjf_to_running_proc(list, setting->core);
		}
		sjf_to_waiting_proc(list);
		sjf_run_proc(list);
		sjf_to_burst_proc(list);
		sjf_new_burst_proc(list, timing, setting->max_time, setting->avg_time);
		update_statistics(list, stat);
	}
	while (count_state_to_terminated(list) != 0) {
		sjf_to_ready_proc(list, timing);
		if (count_is_running(list) < setting->core) {
			sjf_to_running_proc(list, setting->core);
		}
		sjf_to_waiting_proc(list);
		sjf_run_proc(list);
		sjf_to_terminated_proc(list);
		timing+=1;
		update_statistics(list, stat);
	}
	write_on_file(stat, result);
	return;
}

void sjf_to_ready_proc(ListProcess* list, int timing) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i;
	for (i=0; i<list->size; i++) {
		if (aux->info->time_arrive==timing) {
			if (is_not_state(aux->info)==1 || is_burst(aux->info)==1) {
				to_ready(aux->info);
			}
		}
		aux=aux->next;
	}
	return;
}

int sjf_is_job_minimun(ListProcess* list, ProcessType* proc) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if ((is_ready(aux->info)==1 || is_waiting(aux->info)==1) && aux->info->pid != proc->pid) {
			if (aux->info->duration < proc->duration) {
				return 0;
			}
		}
		aux=aux->next;
	}
	return 1;
}

void sjf_to_running_proc(ListProcess* list, int num_core) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_ready(aux->info)==1 || is_waiting(aux->info)==1) {
			if (sjf_is_job_minimun(list, aux->info)==1) {
			to_run(aux->info);
			if (count_is_running(list) == num_core) {
				return;
			}
		}
		}
		aux=aux->next;
	}
	return;
}

void sjf_to_waiting_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_ready(aux->info)==1) {
			to_wait(aux->info);
		}
		aux=aux->next;
	}
	return;
}

void sjf_run_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info)==1) {
			aux->info->duration-=1;
		}
		aux=aux->next;
	}
	return;
}

void sjf_to_burst_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info)==1) {
			if (aux->info->duration==0) {
				to_burst(aux->info);
			}
		}
		aux=aux->next;
	}
	return;
}

void sjf_new_burst_proc(ListProcess* list, int min_time, int max_time, int avg_time) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (aux->info->duration == 0) {
			new_burst_for_process(aux->info, min_time, max_time, avg_time);
		}
		aux=aux->next;
	}
	return;
}

void sjf_to_terminated_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (aux->info->duration == 0) {
			to_terminated(aux->info);
		}
		aux=aux->next;
	}
	return;
}
