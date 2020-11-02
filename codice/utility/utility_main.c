#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

int main() {
	TwoNumberType nums=desired_media(25, 10);
	printf("num1: %d\n", nums.number1);
	printf("num2: %d\n", nums.number2);
	printf("random num: %d\n", random_number(20));
	return 0;
}
