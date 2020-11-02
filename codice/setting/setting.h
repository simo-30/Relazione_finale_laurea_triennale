/**
 * header per la gestione dei dati letti da file per le direttive generali quali:
 * numero di core
 * numero di processi
 * tempo medio di durata di un processo
 * tempo massimo di arrivo dei processi
 **/
#pragma once

typedef struct {
	int core; //numero di core
	int pid; //numero di processi
	int avg_time; //tempo medio
	int max_time; //tempo massimo di arrivo
} SettingType;

SettingType* read_setting(const char* namefile);
void destroy_setting(SettingType* setting);
