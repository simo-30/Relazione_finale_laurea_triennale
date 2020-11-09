/**
 * gestione delle statistiche createsi durante i vari scheduling 
 **/
#pragma once

typedef struct {
	int num_proc; //il processo con pid i corrisponde a (num_proc - 1) 
	int num_core;
	int* waiting_time; //per ogni processo sarà assegnato un tempo totale di attesa prima di essere stato schedulato
	int* completing_time; //per ogni processo sarà assegnato un tempo totale di completamento
	char* name_scheduling; //tipo di politica di scheduling adottata, verrà anche usato come nome del file in cui verrano salavati i dati finali
	float medium_wait_time; //tempo medio di attesa
	float medium_complete_time; //tempo medio di completamento
} StatisticsType;

StatisticsType* new_statisticsType(int num_proc, int num_core, const char* name_scheduling);
void print_waiting_time(int n, int* waiting_time);
void print_completing_time(int n, int* completing_time);
void print_statistics(StatisticsType* stat);
void update_medium_waiting_time(StatisticsType* stat); 
void update_medium_completing_time(StatisticsType* stat);
