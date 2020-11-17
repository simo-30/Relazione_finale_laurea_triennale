/**
 * header per la gestione di una lista di processi
 **/
#include "../utility/macro.h" 
#include PROCESS_H
#include SETTING_H
#include STAT_H
#pragma once

typedef struct item{
	struct item* next;
	ProcessType* info;
} ProcessItem;

typedef struct {
	ProcessItem* first;
	int size;
} ListProcess;

ListProcess* new_listProcess();
void print_listProcess(ListProcess* list);
void destroy_listProcess(ListProcess* list);
void insert_head(ListProcess* list, ProcessType* proc);
ProcessItem* new_processItem(ProcessType* proc);
ListProcess* generate_listProcess(const char* file_setting); //genera una lista dei processi completa
void new_burst_for_list(ListProcess* list, int min_time, int max_time); /*ai processi nella lista assegna un nuovo tempo di arrivo,
	maggiore di min_time, ed anche una nuova durata, della nuova risorsa richiesta*/ 
int count_is_not_state(ListProcess* list);
int count_is_running(ListProcess* list);
int count_is_waiting(ListProcess* list);
int count_is_ready(ListProcess* list);
int count_is_terminated(ListProcess* list);
int count_is_burst(ListProcess* list);
ListProcess* generate_listProcess_from_setting(SettingType* setting);
void adding_waiting_time_in_stat(ListProcess* list, StatisticsType* stat);
void adding_completing_time_in_stat(ListProcess* list, StatisticsType* stat);
void write_listProcess_on_file(ListProcess* list, const char* filename);
void update_statistics(ListProcess* list, StatisticsType* stat);
int count_state_to_terminated(ListProcess* list);
