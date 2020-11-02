/**
 * header per la gestione di una struttura dati per simulare un processo
 **/
#pragma once

typedef enum {CPU=0, IO=1} ResourceType;

typedef enum {RUN=0, NOTRUN=1} IsRunningType; //tipo di dato per poter verificare facilmente se un processo è in stato di running o meno

typedef struct {
	int pid;
	int time_arrive;
	int duration;
	ResourceType resource;
	IsRunningType is_runnning;
} ProcessType;

ProcessType* create_process(int pid, int time_arrive, int duration, ResourceType resource);
void print_process(ProcessType* process);
void destroy_process(ProcessType* process);
void append_process_onFile(ProcessType* process, const char* nameFile);
