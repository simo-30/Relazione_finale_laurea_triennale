#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#pragma once

void fcfs_running(const char* name_setting);
void fcfs_scheduler(SettingType* setting); 
void scheduling_fcfs(ListProcess* list, int timing, int* pid_proc, int dim_pid_proc);
void run_process(ListProcess* list, int* pid_proc, int dim_pid_proc, int core);
