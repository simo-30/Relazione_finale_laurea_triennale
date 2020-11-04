#include "../processo/process.h"
#include "process_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once

int main() {
	ProcessType* p1=create_process(2, 4, 5, 0);
	ListProcess* list=new_listProcess("Lista 1");
	print_listProcess(list);
	insert_head(list, p1);
	print_listProcess(list);
	ProcessType* p2=create_process(4, 3, 2, 1);
	insert_head(list, p2);
	print_listProcess(list);
	list=generate_listProcess("lista2", "../setting/setting.txt");
	print_listProcess(list);
	destroy_listProcess(list);
	return 0;
}
