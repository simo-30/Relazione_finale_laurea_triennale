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
int random_number(int max); //calcola un numero randomico fra 1 e max
int random_resource(); 
