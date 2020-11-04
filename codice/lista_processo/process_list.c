#include "../processo/process.h"
#include "process_list.h"
#include "../setting/setting.h"
#include "../utility/utility.h"
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
	if ((setting->pid % 2) != 0) {
		//numero di processi dispari
		ProcessType* proc=create_process((setting->pid - 1), random_number(setting->max_time), setting->avg_time, random_resource());
		insert_head(list, proc); 
	}
	int i;
	for (i=0; i<(setting->pid - 1); i+=2) {
		TwoNumberType nums=desired_media(setting->avg_time, (setting->avg_time / 2));
		ProcessType* p1=create_process(i, random_number(setting->max_time), nums.number1, random_resource());
		insert_head(list, p1);
		ProcessType* p2=create_process(i+1, random_number(setting->max_time), nums.number2, random_resource());
		insert_head(list, p2);
	}
	return list;
}
