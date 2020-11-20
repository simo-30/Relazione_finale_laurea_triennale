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

int* new_array_negative_inizialized(int n) {
	int* arr=(int*)malloc(n*sizeof(int));
	int i;
	for (i=0; i<n; i++) {
		arr[i]=-1;
	}
	return arr;
}

void insert_first_possible(int* arr, int dim_arr, int val) {
	int i;
	for (i=0; i<dim_arr; i++) {
		if (arr[i]==-1) {
			arr[i]=val;
			return;
		}
	}
	printf("Errore: array pieno\n");
	return;
}

void scaling_array(int* arr, int dim, int val) {
	int i;
	for (i=0; i<dim; i++) {
		if (arr[i]==val) {
			while (i<dim) {
				if ((i+1)==dim) {
					arr[i]=-1;
					return;
				}
				arr[i]=arr[i+1];
				i+=1;
			}
			return;
		}
	}
}

void print_array_int(int* arr, int dim) {
	int i;
	for (i=0; i<dim; i++) {
		printf("%d\n", arr[i]);
	}
	return;
}

int is_in_array(int* arr, int dim, int val) {
	int i;
	for (i=0; i<dim; i++) {
		if (arr[i]==val) {
			return 1;
		}
	}
	return 0;
}

void insert_ordering_crescent(int* arr, int dim, int val) {
	int i, j=0;
	int aux[dim];
	for (i=0; i<dim; i++) {
		if (val < arr[i]) {
			aux[i]=val;
		}
		else {
			aux[i]=arr[j];
			j+=1;
		}
	}
	for (i=0; i<dim; i++) {
		arr[i]=aux[i];
	}
	return;
}
