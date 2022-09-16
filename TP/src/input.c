/*
 * input.c
 *
 *  Created on: 16 sept 2022
 *      Author: Lucas
 */
#include "input.h"

int PedirEntero(char mensaje[]){
	int entero;
	printf(mensaje);
	scanf("%d", &entero);
	return entero;
}

float PedirFlotante(char mensaje[]){
	float flotante;
	printf(mensaje);
	scanf("%f", &flotante);
	return flotante;
}
