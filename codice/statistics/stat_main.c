#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stat.h"
#pragma once

int main() {
	printf("Programma di prova per testare le funzioni per le statistiche\n");
	StatisticsType* stat=new_statisticsType(11, 4, "Statistiche");
	print_waiting_time(11, stat->waiting_time);
	print_completing_time(11, stat->completing_time);
	return 0;
}
