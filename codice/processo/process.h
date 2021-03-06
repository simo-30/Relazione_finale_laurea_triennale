/**
 * header per la gestione di una struttura dati per simulare un processo
 **/
#pragma once

typedef enum {CPU=0, IO=1} ResourceType;

typedef enum {NOT_STATE=0, RUNNING=1, WAITING=2, READY=3, TERMINATED=4, BURST=5} StateType; /* tipo di dato per poter verificare in quale stato sia il processo
	* NOT_STATE significa che il processo è in lista ma deve ancora arrivare
	* RUNNING significa che il processo è in esecuzione
	* WAITING significa che il processo è in attesa della risorsa da utilizzare, è già stato schedulato 
	* READY significa che il processo è arrivato e sta aspettando di essere schedulato
	* TERMINATED significa che il processo ha terminato la sua esecuzione e non richiederà nuove risorse
	* BURST significa che il processo ha terminato la sua esecuzione e sta aspettando per avere un nuovo burst*/

typedef struct {
	int pid;
	int time_arrive;
	int duration;
	ResourceType resource;
	StateType state;
} ProcessType;

ProcessType* create_process(int pid, int time_arrive, int duration, ResourceType resource);
void print_process(ProcessType* process);
void destroy_process(ProcessType* process);
void append_process_onFile(ProcessType* process, const char* nameFile);
int is_not_state(ProcessType* proc); //ritorna 1 se è in NOT_STATE, 0 altrimenti
int is_running(ProcessType* proc); //ritorna 1 se è in RUNNING, 0 altrimenti
int is_waiting(ProcessType* proc); //ritorna 1 se è in WAITING, 0 altrimenti
int is_ready(ProcessType* proc); //ritorna 1 se è in READY, 0 altrimenti
int is_terminated(ProcessType* proc); //ritorna 1 se è in TERMINATED, 0 altrimenti
int is_burst(ProcessType* proc); //ritorna 1 se è in BURST, 0 altrimenti
void to_run(ProcessType* proc);
void to_wait(ProcessType* proc);
void to_ready(ProcessType* proc);
char* state_to_string(ProcessType* proc);
void to_burst(ProcessType* proc);
void new_burst_for_process(ProcessType* proc, int min_time, int max_time, int avg_time);
void to_terminated(ProcessType* proc);
char* resource_to_string(ProcessType* proc);
int resource_is_CPU(ProcessType* proc); //torna 1 se la risorsa richiesta è CPU, 0 altrimenti
int resource_is_IO(ProcessType* proc); //torna 1 se la risorsa richiesta è IO, 0 altrimenti
