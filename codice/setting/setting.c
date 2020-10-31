#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

SettingType* read_setting(const char* namefile) {
	FILE* fd=fopen(namefile, "r");
	if (fd==NULL) {
		printf("Non è stato possibile aprire il file %s\n", namefile);
		return NULL;
	}
	char* buffer=NULL;
	size_t line_len=0;
	if (getline(&buffer, &line_len, fd) <= 0) {
		printf("errore di lettura dal file %s\n", namefile);
		return NULL;
	}
	SettingType* setting=(SettingType*)malloc(sizeof(SettingType));
	int core, pid, avg_time, max_time;
	int num_tokens=0;
	num_tokens=sscanf(buffer, "SET CORE %d PID %d AVG %d MAX %d", &core, &pid, &avg_time, &max_time);
	setting->core=core;
	setting->pid=pid;
	setting->avg_time=avg_time;
	setting->max_time=max_time;
	return setting;
}
