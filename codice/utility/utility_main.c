#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

int main() {
	TwoNumberType nums=desired_media(25, 10);
	printf("num1: %d\n", nums.number1);
	printf("num2: %d\n", nums.number2);
	printf("random num: %d\n", random_number(20));
	printf("random resource: %d\n", random_resource());
	int* n=desired_n_media(15, 5, 15);
	int i;
	printf("numeri di desiderata media:\n");
	for (i=0; i<15; i++) {
		printf("%d\n", n[i]);
	}
	int* rn=n_random_number(20, 10);
	printf("numeri casuali:\n");
	for (i=0; i<10; i++) {
		printf("%d\n", rn[i]);
	}
	return 0;
}
