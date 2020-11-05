#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma once

TwoNumberType desired_media(int media, int gap) {
	TwoNumberType two_number;
	srand(time(NULL));
	two_number.number1=media - ((rand() % gap)+1);
	two_number.number2=(2*media) - two_number.number1;
	/*if ((two_number.number1 + two_number.number2)/2 == media) {
		printf("media calcolata correttamente\n");
	}
	else {
		printf("errore nel calcolo della media\n");
	}*/
	return two_number;
}

int random_number(int max) {
	srand(time(NULL));
	int r_num=(rand() % max)+1;
	return r_num;
}

int random_resource() {
	srand(time(NULL));
	int r_num=(rand() % 2);
	return r_num;
}

int* desired_n_media(int media, int gap, int num) {
	int* med=(int*)malloc(num*sizeof(int));
	int i=0;
	if ((num % 2) != 0) {
		//num è dispari
		med[i]=media;
		i+=1;
	}
	while (i<num) {
		med[i]=media - (i % gap);
		med[i+1]=media + (i % gap);
		i+=2;
	}
	return med;
}

int* n_random_number(int max, int n) {
	int* n_rand=(int*)malloc(n*sizeof(int));
	srand(time(NULL));
	int i;
	for (i=0; i<n; i++) {
		n_rand[i]=rand() % max;
	}
	return n_rand;
}
