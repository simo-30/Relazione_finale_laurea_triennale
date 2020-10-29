/**
 * header per la gestione di una struttura dati per simulare un processo
 **/
#pragma once

typedef enum {CPU=0, IO=1} ResourceType;

typedef struct {
	int pid;
	int time_arrive;
	int duration;
	ResourceType resource;
} ProcessType;

ProcessType* create_process(int pid, int time_arrive, int duration, ResourceType resource);
void print_process(ProcessType* process);
void destroy_process(ProcessType* process);
void append_process_onFile(ProcessType* process, const char* nameFile);
