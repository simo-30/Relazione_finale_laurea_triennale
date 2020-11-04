/**
 * header per la gestione di una lista di processi
 **/
#include "../processo/process.h"
#pragma once

typedef struct item{
	struct item* next;
	ProcessType* info;
} ProcessItem;

typedef struct {
	ProcessItem* first;
	int size;
	char* name;
} ListProcess;

ListProcess* new_listProcess(const char* name);
void print_listProcess(ListProcess* list);
void destroy_listProcess(ListProcess* list);
void insert_head(ListProcess* list, ProcessType* proc);
ProcessItem* new_processItem(ProcessType* proc);
ListProcess* generate_listProcess(const char* name_list, const char* file_setting); //genera una lista dei processi completa
