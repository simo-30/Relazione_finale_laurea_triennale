#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include "fcfs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

int main() {
	fcfs_running(SET_1, "stat.txt");
	return 0;
}
