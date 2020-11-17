#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#pragma once

typedef struct {
	int pid;
	int core_time;
} CoreType;

void rr_running(const char* name_setting, const char* result);
CoreType* new_CoreType_list(int dim, int quantum_time);
void rr_scheduler(SettingType* setting, const char* result); 
void print_CoreType_list(CoreType* core, int dim);
void insert_into_cores(CoreType* core, int pid, int dim);
void scaling_core_list(CoreType* core, int dim, int val);
int count_state_to_terminated(ListProcess* list); //conta il numero dei processi che non sono terminated o in burst
