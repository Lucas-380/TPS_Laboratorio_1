
#ifndef CALCULOS_H_
#define CALCULOS_H_

#include "jugadores.h"

/**
 * @fn int calcularSalariosTotal(eJugador*, int, float*)
 * @brief Esta funcion suma todos los salarios de los jugadores
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @param resultado Este sera el puntero que apuntara a la variable donde se guardara el resultado de la suma
 * @return La funcion retornara 1 en caso de que el calculo salga de manera correcta, en caso de que no haya jugadores cargados o haya error en los parametros retorna 0
 */
int calcularSalariosTotal(eJugador* jugadores, int len, float *resultado);

/**
 * @fn int promedioDeSalarios(eJugador*, int, float*)
 * @brief Esta funcion realiza el calculo de promedio de los salarios
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @param promedio Este sera el puntero que apuntara a la variable en donde se guardara el promedio
 * @return La funcion retornara 1 en caso de que el calculo salga de manera correcta, en caso de que no haya jugadores cargados o haya error en los parametros retorna 0
 */
int promedioDeSalarios(eJugador* jugadores, int len, float* promedio);

/**
 * @fn int salariosConMasDelPromedio(eJugador*, int)
 * @brief Esta funcion contara a los jugadores que tengan un salario mayor al promedio de salarios
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @return La funcion retornara la cantidad de jugadores con un salario mayor al promedio
 */
int salariosConMasDelPromedio(eJugador* jugadores, int len);

/**
 * @fn int contadorDeAniosContrato(eJugador*, int, int)
 * @brief Esta funcion acumulara los años de contrato de los jugadores de una confederacion en especifico
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @param idConfederacion Este entero representara al id de la confederacion que se quiere realizar la acumulacion de años
 * @return La funcion retornara 1 en caso de que el calculo salga de manera correcta, caso contratio un 0
 */
int acumuladorDeAniosContrato(eJugador* jugadores, int len, int idConfederacion);

/**
 * @fn int CalcularContratosTotal(eJugador*, int, eConfederacion*, int, int*, int*)
 * @brief Esta funcion mediante punteros devolvera la cantidad de años de contrato mas alta y el id de la confederacion al que pertenezca dichos contratos
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @param aniosTotalesDeContrato Este puntero sera donde se guardara la cantidad de años de contrato mas alta
 * @param idConMasAniosContrato Este puntero sera donde se guardara el id de la confederacion que tenga la cantidad de años de contrato mas alta
 * @return La funcion retornara 1 en caso de que el calculo salga de manera correcta, caso contratio un 0
 */
int CalcularMayorContrato(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion, int*aniosTotalesDeContrato, int*	idConMasAniosContrato);

/**
 * @fn int contarJugadorPorConfederacion(eJugador*, int, int)
 * @brief Esta funcion cuenta a los jugadores de una especifica confederacion
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @param idConfederacion Esta variable sera el id de la confederacion a la cual se le realizara el conteo de jugadores
 * @return la funcion retorna la cantidad de jugadores que hayan en la confederacion especifica
 */
int contarJugadorPorConfederacion(eJugador* jugadores, int len, int idConfederacion);

/**
 * @fn float calcularPorcentajeJugadoresPorConfederacion(eConfederacion*, int, eJugador*, int, int)
 * @brief Esta funcion calcula el porcentaje de jugadores en una confederacion
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param idConfederacion Esta variable sera el id de la confederacion a la cual se le realizara el calculo
 * @return La funcion retorna el porcentaje correspondiente
 */
float calcularPorcentajeJugadoresPorConfederacion(eConfederacion* confederaciones, int lenConfederacion, eJugador* jugadores, int lenJugador, int idConfederacion);

/**
 * @fn int CalcularRegionConMasJugadores(eJugador*, int, eConfederacion*, int, int*, int*)
 * @brief Esta funcion calcula la region con mas jugadores y devuelve por punteros la mayor cantidad de jugadores en la region y el id de la confederacion de dicha region
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @param jugadoresPorConfederacion Este puntero sera donde se guardara la mayor cantidad de jugadores de la region
 * @param idRegionConMasJugadores Este puntero sera donde se guardara el id de la confederacion de la region con mas jugadores
 * @return La funcion retornara 1 en caso de que el calculo salga de manera correcta, caso contratio un 0
 */
int CalcularRegionConMasJugadores(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion, int*jugadoresPorConfederacion, int*	idRegionConMasJugadores);

#endif /* CALCULOS_H_ */
