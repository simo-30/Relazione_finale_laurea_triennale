#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stat.h"
#pragma once

#define N_PROC 15
#define N_CORE 4

int main() {
	printf("Programma di prova per testare le funzioni per le statistiche\n");
	StatisticsType* stat=new_statisticsType(N_PROC, N_CORE);
	print_statistics(stat);
	write_on_file(stat, "statistiche.csv");
	return 0;
}
