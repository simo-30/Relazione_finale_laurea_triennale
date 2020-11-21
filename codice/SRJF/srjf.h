#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#pragma once

void srjf_running(const char* name_setting, const char* result);
void srjf_scheduler(SettingType* setting, const char* result);
void srjf_to_ready_proc(ListProcess* list, int timing);
int srjf_is_job_minimun(ListProcess* list, ProcessType* proc); //torna 1 se la durata di proc è la minima in list, 0 altrimenti
void srjf_to_running_proc(ListProcess* list, int num_core);
void srjf_to_waiting_proc(ListProcess* list);
void srjf_run_proc(ListProcess* list);
void srjf_new_burst_proc(ListProcess* list, int min_time, int max_time, int avg_time);
void srjf_to_terminated_proc(ListProcess* list);
