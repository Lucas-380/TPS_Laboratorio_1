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

/**
 * Esta funcion carga un contador tantas veces como le indique.
 * @param contador Este puntero es donde se va a guardar el contador.
 * @param condicionNumerica Este parametro determina hasta que número se va a poder contar.
 * @param mensajeError Es el mensaje de error que mostrará en caso de que el contador ya este completo.
 * @return Esta funcion retorna un 0 si se cargo el contador correctamente y un -1 si hubo algun error.
 */
int CargarContador(int* contador, int condicionNumerica, char* mensajeError);

/**
 * Esta funcion se encarga de cargar los costos de manera acumulable.
 * @param costoAcumulable Este puntero es donde se van a guardar los costos ingresados.
 * @param mensaje Este es el mensaje que será mostrado.
 * @param mensajeError Este es el mensaje de error que se mostrará en caso de que la condicion no se cumpla.
 * @param reintentos Este parametro determina el número de reintentos que tendra el usuario de ingresar el costo pedido de forma correcta.
 * @return Esta funcion retorna un 0 si se cargo el contador correctamente y un -1 si hubo algun error.
 */
int CargarCosto(float* costoAcumulable, char* mensaje, char* mensajeError, int reintentos);

#endif /* INPUT_H_ */
