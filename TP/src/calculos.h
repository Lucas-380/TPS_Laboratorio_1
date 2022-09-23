/*
 * calculos.h
 *
 *  Created on: 19 sept 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * Esta funcion se utiliza para obtener un promedio.
 * @param sumaDeNumeros Este parametro son la suma total de números enteros a promediar.
 * @param cantidadDeNumeros Este parametro son la cantidad de números a promediar.
 * @return Retorna el promedio siendo un número flotante.
 */
float CalcularPromedio(int sumaDeNumeros, int cantidadDeNumeros);

/**
 * Esta función sirve para calcular un aumento.
 * @param montoBruto Este parametro es el número el cual recibira el aumento.
 * @param aumento Este parametro es el el porcentaje que se aumentara (representado en un número flotante).
 * @return Retorna SOLO el aumento que le corresponde a dicho monto.
 */
float CalcularAumento(float montoBruto, float aumento);

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

#endif /* CALCULOS_H_ */
