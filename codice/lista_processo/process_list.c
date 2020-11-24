#include "../utility/macro.h"
#include PROCESS_H
#include "process_list.h"
#include SETTING_H
#include UTILITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

ListProcess* new_listProcess() {
	ListProcess* list=(ListProcess*)malloc(sizeof(ListProcess));
	list->first=NULL;
	list->size=0;
	return list;
}

void print_listProcess(ListProcess* list) {
	if (list->size == 0) {
		printf("La lista è vuota\n");
		return;
	}
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i;
	for (i=0; i<list->size; i++) {
		print_process(aux->info);
		aux=aux->next;
	}
	return;
}

void destroy_listProcess(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i;
	for (i=0; i<list->size; i++) {
		destroy_process(aux->info);
		aux=aux->next;
	}
	free(list->first);
	free(list);
	free(aux);
	return;
}

ProcessItem* new_processItem(ProcessType* proc) {
	ProcessItem* p_item=(ProcessItem*)malloc(sizeof(ProcessItem));
	p_item->next=(ProcessItem*)malloc(sizeof(ProcessItem));
	p_item->info=(ProcessType*)malloc(sizeof(ProcessType));
	p_item->info=proc;
	return p_item;
}

void insert_head(ListProcess* list, ProcessType* proc) {
	ProcessItem* p_item=new_processItem(proc);
	p_item->next=list->first;
	list->first=p_item;
	list->size+=1;
	return;
}

ListProcess* generate_listProcess(const char* file_setting) {
	ListProcess* list=new_listProcess();
	SettingType* setting=read_setting(file_setting);
	/* devo creare un numero di processi datomi da setting->pid
	 * con tempo medio di durata setting->avg_time
	 * tempi di arrivo fra 1 e setting->max_time
	 * e tipo di risorsa richiesta variabile e casuale fra CPU ed I/O 
	 */
	int* time_duration=desired_n_media(setting->avg_time, (setting->avg_time / 2), setting->pid);
	int* time_arriving=n_random_number(setting->max_time, setting->pid);
	int* res=n_random_number(2, setting->pid);
	int i;
	for (i=0; i<setting->pid; i++) {
		if (time_arriving[i] == 0) {
			time_arriving[i]=1;
		}
		ProcessType* p_type=create_process(i, time_arriving[i], time_duration[i], res[i]);
		insert_head(list, p_type);
	}
	return list;
}

int count_is_not_state(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i, num;
	num=0;
	for (i=0; i<list->size; i++) {
		num+=is_not_state(aux->info);
		aux=aux->next;
	}
	return num;
}

int count_is_ready(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i, num;
	num=0;
	for (i=0; i<list->size; i++) {
		num+=is_ready(aux->info);
		aux=aux->next;
	}
	return num;
}

int count_is_running(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i, num;
	num=0;
	for (i=0; i<list->size; i++) {
		num+=is_running(aux->info);
		aux=aux->next;
	}
	return num;
}

int count_is_terminated(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i, num;
	num=0;
	for (i=0; i<list->size; i++) {
		num+=is_terminated(aux->info);
		aux=aux->next;
	}
	return num;
}

int count_is_waiting(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i, num;
	num=0;
	for (i=0; i<list->size; i++) {
		num+=is_waiting(aux->info);
		aux=aux->next;
	}
	return num;
}

int count_is_burst(ListProcess* list) {
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i, num;
	num=0;
	for (i=0; i<list->size; i++) {
		num+=is_burst(aux->info);
		aux=aux->next;
	}
	return num;
}

void new_burst_for_list(ListProcess* list, int min_time, int max_time) {
	srand(time(NULL));
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (aux->info->state == BURST) {
			aux->info->duration = ( rand() % aux->info->duration ) +1;
			aux->info->resource = rand() % 2;
			aux->info->time_arrive = ( rand() % (max_time*2) ) + min_time + 1;
			aux->info->state = NOT_STATE;
		}
		aux=aux->next;
	}
	return;
}

ListProcess* generate_listProcess_from_setting(SettingType* setting) {
	ListProcess* list=new_listProcess();
	/* devo creare un numero di processi datomi da setting->pid
	 * con tempo medio di durata setting->avg_time
	 * tempi di arrivo fra 1 e setting->max_time
	 * e tipo di risorsa richiesta variabile e casuale fra CPU ed I/O 
	 */
	int* time_duration=desired_n_media(setting->avg_time, (setting->avg_time / 2), setting->pid);
	int* time_arriving=n_random_number(setting->max_time, setting->pid);
	int* res=n_random_number(2, setting->pid);
	int i;
	for (i=0; i<setting->pid; i++) {
		if (time_arriving[i] == 0) {
			time_arriving[i]=1;
		}
		ProcessType* p_type=create_process(i, time_arriving[i], time_duration[i], res[i]);
		insert_head(list, p_type);
	}
	return list;
}

void adding_waiting_time_in_stat(ListProcess* list, StatisticsType* stat) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_waiting(aux->info)==1) {
			stat->waiting_time[i]+=1;
		}
		aux=aux->next;
	}
	update_medium_waiting_time(stat);
	return;
}

void adding_completing_time_in_stat(ListProcess* list, StatisticsType* stat) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		if (is_not_state(aux->info)==0 || is_terminated(aux->info)==0) {
			stat->completing_time[i]+=1;
		}
		aux=aux->next;
	}
	update_medium_completing_time(stat);
	return;
}

void write_listProcess_on_file(ListProcess* list, const char* filename) {
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		append_process_onFile(aux->info, filename);
		aux=aux->next;
	}
	return;
}

void update_statistics(ListProcess* list, StatisticsType* stat) {
	adding_completing_time_in_stat(list, stat);
	adding_waiting_time_in_stat(list, stat);
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

int count_resource_CPU(ListProcess* list) {
	int i, tot;
	tot=0;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		tot+=resource_is_CPU(aux->info);
		aux=aux->next;
	}
	return tot;
}

int count_resource_IO(ListProcess* list) {
	int i, tot;
	tot=0;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		tot+=resource_is_IO(aux->info);
		aux=aux->next;
	}
	return tot;
}
