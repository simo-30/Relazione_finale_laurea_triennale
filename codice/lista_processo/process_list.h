/**
 * header per la gestione di una lista di processi
 **/
#include "../utility/macro.h" 
#include PROCESS_H
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
ListProcess* extract_process_by_time(ListProcess* list, int timing); /*data la lista dei processi e il tempo attuale (timing)
	viene creata e restituita una lista dei processi i quali hanno tempo di arrivo uguale a quello attuale*/
void new_burst_for_list(ListProcess* list, int median_duration, int min_time); /*ai processi nella lista assegna un nuovo tempo di arrivo,
	maggiore di min_time, ed anche una nuova durata, sempre nella media voluta, della nuova risorsa richiesta*/ 
int count_is_not_state(ListProcess* list);
int count_is_running(ListProcess* list);
int count_is_waiting(ListProcess* list);
int count_is_ready(ListProcess* list);
int count_is_terminated(ListProcess* list);
