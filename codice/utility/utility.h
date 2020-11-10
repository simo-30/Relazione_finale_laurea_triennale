/**
 * funzioni per varie utility di vario utilizzo
 **/
#pragma once

typedef struct {
	/* struttura dati per poter tornare due interi insieme */
	int number1;
	int number2;
} TwoNumberType;

TwoNumberType desired_media(int media, int gap); //calcola 2 numeri la cui media è quella richiesta passata come parametro, e con un gap dalla media prestabilito
int* desired_n_media(int media, int gap, int num); //torna un array di int di dimensione n, la cui media è 'media' 
													//e la distanza massima fra dui int è 'gap'
int* n_random_number(int max, int n); //calcola un'array di n numeri casuale fra 0 e max-1
int* new_array_negative_inizialized(int n); //crea ed inizializza a -1 un array di n interi
void insert_first_possible(int* arr, int dim_arr, int val); //inserisce nell'arry il valore val nel primo posto negativo
void scaling_array(int* arr, int dim, int val); //scala tutti i valori dell'array di una posizione avanti partendo dalla posizione in cui si trova val 
void print_array_int(int* arr, int dim);
