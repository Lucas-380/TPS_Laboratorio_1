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

#endif /* CALCULOS_H_ */
