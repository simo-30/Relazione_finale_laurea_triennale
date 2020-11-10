#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#pragma once

int main() {
	TwoNumberType nums=desired_media(25, 10);
	printf("num1: %d\n", nums.number1);
	printf("num2: %d\n", nums.number2);
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
	int* neg=new_array_negative_inizialized(10);
	insert_first_possible(neg, 10, 23);
	insert_first_possible(neg, 10, 990);
	scaling_array(neg, 10, 23);
	printf("Array di '-1'\n");
	for (i=0; i<10; i++) {
		printf("%d\n", neg[i]);
	}
	return 0;
}
