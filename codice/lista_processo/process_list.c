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

ListProcess* new_listProcess(const char* name) {
	ListProcess* list=(ListProcess*)malloc(sizeof(ListProcess));
	list->first=NULL;
	list->size=0;
	list->name=malloc((strlen(name) + 1)*sizeof(char));
	strcpy(list->name, name);
	return list;
}

void print_listProcess(ListProcess* list) {
	if (list->size == 0) {
		printf("La lista %s è vuota\n", list->name);
		return;
	}
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	printf("%s\n", list->name);
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
	free(list->name);
	free(list->first);
	free(list);
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

ListProcess* generate_listProcess(const char* name_list, const char* file_setting) {
	ListProcess* list=new_listProcess(name_list);
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

ListProcess* extract_process_by_time(ListProcess* list, int timing) {
	ListProcess* arriving_list=new_listProcess("Processi in arrivo");
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	int i;
	for (i=0; i<list->size; i++) {
		if (aux->info->time_arrive == timing) {
			insert_head(arriving_list, aux->info);
		}
		aux=aux->next;
	}
	return arriving_list;
}

void new_burst_for_list(ListProcess* list, int median_duration, int min_time) {
	int* time_duration=desired_n_media(median_duration, (median_duration / 2), list->size);
	int* res=n_random_number(2, list->size);
	int* time_arrive=n_random_number((min_time * 2), list->size);
	int i;
	ProcessItem* aux=(ProcessItem*)malloc(sizeof(ProcessItem));
	aux=list->first;
	for (i=0; i<list->size; i++) {
		aux->info->duration=time_duration[i];
		aux->info->resource=res[i];
		aux->info->time_arrive=time_arrive[i] + min_time + 1;
	}
	return;
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
