#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

//programma di prova per testare le funzioni di process.h

int main () {
	printf("Programma di prova per testare le funzioni di gestione di un processo\n");
	ResourceType res=1;
	ProcessType* proc=create_process(2, 3, 5, res);
	print_process(proc);
	append_process_onFile(proc, "file.txt");
	destroy_process(proc);
	return 0;
}
