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

void scheduling_fcfs(ListProcess* list, int timing, int* pid_proc, int dim_pid_proc) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (aux->info->state==NOT_STATE && aux->info->time_arrive==timing) {
			to_ready(aux->info);
			insert_first_possible(pid_proc, dim_pid_proc, aux->info->pid);
		}
		aux=aux->next;
	}
	return;
}

void fcfs_scheduler(SettingType* setting) {
	ListProcess* list=generate_listProcess_from_setting(setting);
	StatisticsType* stat=new_statisticsType(setting->pid, setting->core);
	int timing;
	int* pid_proc=new_array_negative_inizialized(setting->pid);
	print_listProcess(list);
	for (timing=0; timing<=setting->max_time; timing++) {
		scheduling_fcfs(list, timing, pid_proc, setting->pid);
		run_process(list, pid_proc, setting->pid, setting->core);
		new_burst_for_list(list, timing, setting->max_time);
		update_statistics(list, stat);
		write_listProcess_on_file(list, "esecuzione.txt");	
	}
	write_on_file(stat, "stat.txt");
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

void run_process(ListProcess* list, int* pid_proc, int dim_pid_proc, int core) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	i=0;
	while (i<dim_pid_proc && pid_proc[i]!=-1) {
		for (int j=0; j<list->size; j++) {
			if (aux->info->pid == pid_proc[i]) {
				switch (aux->info->state) {
					case 1:
						aux->info->duration-=1;
						if (aux->info->duration==0) {
							to_burst(aux->info);
						}
						break;
					case 3:
						if (count_is_running(list) < core) {
							to_run(aux->info);
							aux->info->duration-=1;
							if (aux->info->duration==0) {
								to_burst(aux->info);
							}
						}
						else {
							to_wait(aux->info);
							insert_first_possible(pid_proc, dim_pid_proc, aux->info->pid);
						}
						break;
					default:
						break;
				}
			}
			aux=aux->next;
		}
		i+=1;
	}
	return;
}
