#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

TwoNumberType desired_media(int media, int gap) {
	TwoNumberType two_number;
	time_t t;
	srand((unsigned) time(&t));
	two_number.number1=media - ((rand() % gap)+1);
	two_number.number2=media + two_number.number1;
	return two_number;
}

int random_number(int max) {
	time_t t;
	srand((unsigned) time(&t));
	int r_num=(rand() % max)+1;
	return r_num;
}
