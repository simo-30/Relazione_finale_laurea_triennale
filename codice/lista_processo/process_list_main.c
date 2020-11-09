#include "../utility/macro.h"
#include PROCESS_H
#include "process_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once

int main() {
	ProcessType* p1=create_process(2, 4, 5, 0);
	ListProcess* list=new_listProcess();
	print_listProcess(list);
	insert_head(list, p1);
	print_listProcess(list);
	ProcessType* p2=create_process(4, 3, 2, 1);
	insert_head(list, p2);
	print_listProcess(list);
	destroy_process(p1);
	destroy_process(p2);
	list=generate_listProcess("../setting/setting.txt");
	print_listProcess(list);
	int i;
	printf("\nCount not state: %d\n", count_is_not_state(list));
	destroy_listProcess(list);
	return 0;
}
