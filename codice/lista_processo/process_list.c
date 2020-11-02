#include "../processo/process.h"
#include "process_list.h"
#include "../setting/setting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	return;
}
