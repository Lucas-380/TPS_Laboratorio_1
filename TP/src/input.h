/*
 * input.h
 *
 *  Created on: 16 sept 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef INPUT_H_
#define INPUT_H_

/**
 * Solicita un número entero que el usuario ingrese dentro de un rango de valores.
 * @param mensaje Este es el mensaje que sera mostrado.
 * @param mensajeError Este es el mensaje de error en caso de que la condicion no se cumpla.
 * @param minimo Este parametro determina el numero entero minimo que tendra la condicion.
 * @param maximo Este parametro determina el numero entero maximo que tendra la condicion.
 * @return Retorna el numero que ingreso el usuario de acuerdo con las condiciones pedidas.
 */
int GetInt(char* mensaje, char* mensajeError, int minimo, int maximo);

/**
 * Solicita un número flotante al usuario estableciendo un minimo.
 * @param pResultado Es el puntero donde se va a guardar el número ingresado.
 * @param mensaje Este es el mensaje que sera mostrado.
 * @param mensajeError Este es el mensaje de error en caso de que la condicion no se cumpla.
 * @param minimo Este parametro determina el numero entero minimo que tendra la condicion.
 * @param reintentos Este parametro determina el número de reintentos que tendra el usuario de ingresar el numero pedido de forma correcta.
 * @return Esta funcion retorna un 0 si se guardo el número correctamente y un -1 si hubo algun error.
 */
int getFloatPositivo(float* pResultado, char* mensaje, char* mensajeError, float minimo, int reintentos);


#endif /* INPUT_H_ */
