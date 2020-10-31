/**
 * header per la gestione dei dati letti da file per le direttive generali quali:
 * numero di core
 * numero di processi
 * tempo medio di durata di un processo
 * tempo massimo durata di uno scheduling, ossia il tempo entro il quale vengo generati nuovi burst ai processi già conclusisi e rimessi in coda
 **/
#pragma once

typedef struct {
	int core; //numero di core
	int pid; //numero di processi
	int avg_time; //tempo medio
	int max_time; //tempo massimo
} SettingType;

SettingType* read_setting(const char* namefile);
