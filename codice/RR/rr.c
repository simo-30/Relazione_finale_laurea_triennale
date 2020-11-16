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
		rr_to_ready_proc(list, timing, pid_proc, setting->pid);
		if (count_is_running(list) < setting->core) {
			//processo in running
			rr_to_running_proc(list, timing, pid_proc, setting->pid, core_list, setting->core);
		}
		else {
			//processo in waiting
			rr_to_waiting_proc(list, timing, pid_proc, setting->core);
		}
		rr_run_proc(list, core_list, setting->core, pid_proc, setting->pid);
		rr_to_burst_proc(list);
		rr_new_burst_proc(list, timing, setting->max_time, setting->avg_time);
		update_statistics(list, stat);
		print_listProcess(list);
	}
	while (count_state_to_terminated(list) != 0) {
		rr_to_ready_proc(list, timing, pid_proc, setting->pid);
		if (count_is_running(list) < setting->core) {
			//processo in running
			rr_to_running_proc(list, timing, pid_proc, setting->pid, core_list, setting->core);
		}
		else {
			//processo in waiting
			rr_to_waiting_proc(list, timing, pid_proc, setting->core);
		}
		rr_run_proc(list, core_list, setting->core, pid_proc, setting->pid);
		rr_to_terminated_proc(list);
		print_listProcess(list);
		update_statistics(list, stat);
	}
	write_on_file(stat, result);
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

void rr_to_ready_proc(ListProcess* list, int timing, int* proc, int dim) {
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

void rr_to_running_proc(ListProcess* list, int timing, int* proc, int dim_proc, CoreType* core, int dim_core) {
	int i;
	for (i=0; i<dim_proc; i++) {
		if (proc[i] == -1) {
			return;
		}
		ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
		aux=list->first;
		int j;
		for (j=0; j<list->size; j++) {
			if (proc[i] == aux->info->pid) {
				if (is_waiting(aux->info) == 1) {
					to_run(aux->info);
					scaling_array(proc, dim_proc, aux->info->pid);
					insert_into_cores(core, aux->info->pid, dim_core);
					if (count_is_running(list) == dim_core) {
						rr_to_waiting_proc(list, timing, proc, dim_proc);
						return;
					}
				}
				if (is_ready(aux->info) == 1) {
					to_run(aux->info);
					scaling_array(proc, dim_proc, aux->info->pid);
					insert_into_cores(core, aux->info->pid, dim_core);
					if (count_is_running(list) == dim_core) {
						rr_to_waiting_proc(list, timing, proc, dim_proc);
						return;
					}
				}
			}
			aux=aux->next;
		}
	}
	return;
}

void rr_to_waiting_proc(ListProcess* list, int timing, int* proc, int dim) {
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

void rr_run_proc(ListProcess* list, CoreType* core, int dim_core, int* proc, int dim_proc) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info) == 1) {
			aux->info->duration-=1;
			int j;
			for (j=0; j<dim_core; j++) {
				if (core[j].pid == aux->info->pid) {
					core[j].core_time-=1;
					if (core[j].core_time == 0) {
						scaling_core_list(core, dim_core, aux->info->pid);
						to_wait(aux->info);
						insert_first_possible(proc, dim_proc, aux->info->pid);
					}
				}
			}
		}
		aux=aux->next;
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

void rr_to_burst_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		//if (is_running(aux->info) == 1) {
			if (aux->info->duration == 0) {
				to_burst(aux->info);
			}
		//}
		aux=aux->next;
	}
	return;
}

void rr_new_burst_proc(ListProcess* list, int min_time, int max_time, int avg_time) {
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
	state=count_is_not_state(list) + count_is_ready(list) + count_is_running(list) + count_is_waiting(list) + count_is_burst(list);
	if (state > 0) {
		return 1;
	}
	return 0;
}

void rr_to_terminated_proc(ListProcess* list) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_running(aux->info) == 1) {
			if (aux->info->duration == 0) {
				to_terminated(aux->info);
			}
		}
		aux=aux->next;
	}
	return;
}
