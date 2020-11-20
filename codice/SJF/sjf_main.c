#include "../utility/macro.h"
#include PROCESS_H
#include PROCESS_LIST_H
#include UTILITY_H
#include SETTING_H
#include STAT_H
#include "sjf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma once

int main() {
	sjf_running(SET_TEST, RESULT_TEST);
	return 0;
}
