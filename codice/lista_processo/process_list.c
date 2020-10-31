#include "../processo/process.h"
#include "process_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once

ListProcess* new_listProcess(const char* name) {
	ListProcess* list=(ListProcess*)malloc(sizeof(ListProcess));
	list->first=NULL;
	list->size=0;
	list->name=malloc((strlen(name) + 1)*sizeof(char));
	strcpy(list->name, name);
	return list;
}
