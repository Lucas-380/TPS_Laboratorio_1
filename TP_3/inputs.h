
#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * Esta función permite la realizacion de un menu y pedir la opcion dentro de un rango de numeros
 * @param menu Esta cadena de chars sera el menu que se mostrara
 * @param min Este entero será el numero minimo para seleccionar como opcion
 * @param max Este entero será el numero maximo para seleccionar como opcion
 * @return La funcion nos retorna el entero que el usuario ingrese siempre que cumpla con las condiciones, en caso de no cumplirla devuelve -1
 */
int utn_pedirOpcion(char menu[], int min, int max);

/**
 * Esta funcion permite al usuario el ingrese de cualquier dato (numeros, letra, simbolo, etc)
 * @param cadena Este es un puntero en donde se guardara lo ingresado por el usuario
 * @param longitud Este parametro indica la longitud del puntero cadena
 * @return La funcion nos retorna 0 si la operacion salio correctamente, caso contrario retorna -1
 */
int myGets(char* cadena, int longitud);

/**
 * Este funcion determina si la cadena que le pasamos es numerica o no
 * @param cadena Este puntero es la cadena que le pasamos para hacer la comprobacion
 * @return Retorna 1 en caso que sea una cadena numerica, en caso contrario devuelve 0
 */
int esNumerica(char *cadena);

/**
 * Esta funcion se utiliza para guardar un numero tipo int que ingrese el usuario
 * @param pResultado Este parametro es un puntero en donde se guardara el numero ingresado
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int getInt(int* pResultado);

/**
 * Esta funcion se utiliza para guardar un numero tipo short que ingrese el usuario
 * @param pResultado Este parametro es un puntero en donde se guardara el numero ingresado
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int getShort(short* pResultado);

/**
 * Esta funcion se utiliza para guardar un numero flotante que ingrese el usuario
 * @param pResultado Este parametro es un puntero en donde se guardara el numero ingresado
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int getFloat(float *pResultado);

/**
 * @fn int utn_getFloat(float*, char*, char*, float, float)
 * @brief Esta funcion se utiliza para pedir al usuario un flotante
 * @param pResultado Este sera el puntero en donde se guardara el dato ingresado por el usuario
 * @param mensaje Sera el mensaje que se mostrara en pantalla
 * @param mensajeError Sera el mensaje que mostrara en caso de error
 * @param minimo Es una condicion que tendra que cumplir a la hora de ingresar el usuario
 * @param maximo Es una condicion que tendra que cumplir a la hora de ingresar el usuario
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);

/**
 * @fn int utn_getShort(short*, char*, char*, int, int)
 * @brief Esta funcion se utiliza para pedir al usuario un entero de tipo short
 * @param mensaje Sera el mensaje que se mostrara en pantalla
 * @param mensajeError Sera el mensaje que mostrara en caso de error
 * @param minimo Es una condicion que tendra que cumplir a la hora de ingresar el usuario
 * @param maximo Es una condicion que tendra que cumplir a la hora de ingresar el usuario
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int utn_getShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/**
 * @fn int utn_getNumero(int*, char*, char*, int, int)
 * @brief Esta funcion se utiliza para pedir al usuario un entero de tipo int
 * @param pResultado Este sera el puntero en donde se guardara el dato ingresado por el usuario
 * @param mensaje Sera el mensaje que se mostrara en pantalla
 * @param mensajeError Sera el mensaje que mostrara en caso de error
 * @param minimo Es una condicion que tendra que cumplir a la hora de ingresar el usuario
 * @param maximo Es una condicion que tendra que cumplir a la hora de ingresar el usuario
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/**
 * @fn int utn_getName(char*, char*, char*, int)
 * @brief Esta funcion se utiliza para pedir al usuario una cadena de caracteres
 * @param cadena Sera el puntero donde se guardara la o las palabras ingresadas por el usuario
 * @param mensaje Sera el mensaje que se mostrara en pantalla
 * @param mensajeError Sera el mensaje que mostrara en caso de error
 * @param len Es la longitud del array en donde se guardara la cadena ingresada
 * @return La funcion retorna 0 en caso que la operacion salga bien, caso contrario -1
 */
int utn_getName(char* cadena, char* mensaje, char* mensajeError, int len);

/**
 * @fn void utn_corregirMayus(char*)
 * @brief Esta funcion corrige las mayusculas y minusculas dandole un formato mas limpio y ordenado
 * @param cadena
 */
void utn_corregirMayus(char* cadena);

/**
 * @fn int confirmarFuncion(char*)
 * @brief Esta funcion se utiliza para confirmar una accion
 * @param mensaje
 * @return La funcion retorna 1 si se confirma, en caso contrario retorna 0
 */
int confirmarFuncion(char* mensaje);

/**
 * Verifica si la cadena ingresada es un nombre valido
 * @param cadena Cadena de caracteres a ser analizada
 * @param longitud
 * @return Retorna 1 si la cadena es valida y 0 si no lo es
*/
int isValidString(char* cadena, int longitud);

#endif /* INPUTS_H_ */
