#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#pragma once

void fcfs_running(const char* name_setting);
void fcfs_scheduler(SettingType* setting); 
void fcfs_to_ready_proc(ListProcess* list, int timing, int* proc, int dim);
void fcfs_to_waiting_proc(ListProcess* list, int timing, int* proc, int dim);
void fcfs_to_running_proc(ListProcess* list, int timing, int* proc, int dim, int core);
void fcfs_run_proc(ListProcess* list);
void fcfs_to_burst_proc(ListProcess* list, int* proc, int dim);
void fcfs_new_burst_proc(ListProcess* list, int min_time, int max_time, int avg_time);
void fcfs_to_terminated_proc(ListProcess* list, int* proc, int dim);
int count_state_to_terminated(ListProcess* list); //conta il numero dei processi che non sono terminated o in burst
