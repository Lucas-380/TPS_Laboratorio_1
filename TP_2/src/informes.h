
#ifndef INFORMES_H_
#define INFORMES_H_

#include "confederaciones.h"
#include "jugadores.h"
#include "calculos.h"

/**
 * @fn int jugadores_listarAlfabeticamentePorConfederacion(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion realiza lista alfabeticamente por nombre de confederacion y en caso de que los nombres sean iguales compara los nombres de los jugadores
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @return La funcion retornara 1 en caso de que la lista se pueda imprimir de manera correcta, caso contrario un 0
 */
int jugadores_listarAlfabeticamentePorConfederacion(eJugador* jugadores, int lenJugador, eConfederacion* confederacion, int lenConfederacion);

/**
 * @fn int confederacion_listarConSusJugadores(eConfederacion*, int, eJugador*, int)
 * @brief Esta funcion realiza una lista de las confederacion con sus jugadores
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @return La funcion retornara 1 en caso de que la lista se pueda imprimir de manera correcta, caso contrario un 0
 */
int confederacion_listarConSusJugadores(eConfederacion* confederaciones, int lenConfederaciones, eJugador* jugadores, int lenJugador);

/**
 * @fn void confederacion_OrdenarAlfabeticamente(eConfederacion*, int)
 * @brief Esta funcion ordena alfabeticamente a las confederaciones por su nombre
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param len Es la longitud del array del tipo eConfederacion
 */
void confederacion_OrdenarAlfabeticamente(eConfederacion* confederaciones, int len);

/**
 * @fn void confederacion_intercambiarPosicion(eConfederacion*, int, int)
 * @brief Esta funcion realiza un intercambio de posicionamientos de dos confederaciones
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param posicionA representara el indice del array de una de las confederaciones
 * @param posicionB representara el indice del array de una de las confederaciones
 */
void confederacion_intercambiarPosicion(eConfederacion* confederaciones, int posicionA, int posicionB);

/**
 * @fn void jugadores_OrdenarAlfabeticamente(eJugador*, int)
 * @brief Esta funcion ordena alfabeticamente a los jugadores por su nombre
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 */
void jugadores_OrdenarAlfabeticamente(eJugador* jugadores, int len);

/**
 * @fn void jugadores_intercambiarPosicion(eJugador*, int, int)
 * @brief Esta funcion realiza un intercambio de posicionamientos de dos jugadores
 * @param jugadores jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param posicionA representara el indice del array de uno de los jugadores
 * @param posicionB representara el indice del array de uno de los jugadores
 */
void jugadores_intercambiarPosicion(eJugador* jugadores, int posicionA, int posicionB);

/**
 * @fn int ImprimirInformeDeSalarios(eJugador*, int)
 * @brief Esta funcion imprime el informe de los salarios
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @return La funcion retornara 1 en caso de que la lista se pueda imprimir de manera correcta, caso contrario un 0
 */
int ImprimirInformeDeSalarios(eJugador* jugadores, int len);

/**
 * @fn int imprimirInformeDeAniosContrato(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion imprime la confederacion con mayor cantidad de años de contratos total
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @return La funcion retornara 1 en caso de que la lista se pueda imprimir de manera correcta, caso contrario un 0
 */
int imprimirInformeDeAniosContrato(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion);

/**
 * @fn int imprimirPorcentajePorConfederacion(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion imprime los porcentajes de los jugadores por cada confederacion
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @return La funcion retornara 1 en caso de que la lista se pueda imprimir de manera correcta, caso contrario un 0
 */
int imprimirPorcentajePorConfederacion(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion);

/**
 * @fn int imprimirLaRegionConMasJugadores(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion imprime La region con más jugadores por cada confederacion
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es el puntero que apunta al array donde se encuentran las confederaciones
 * @param lenConfederacion Es la longitud del array del tipo eConfederacion
 * @return La funcion retornara 1 en caso de que la lista se pueda imprimir de manera correcta, caso contrario un 0
 */
int imprimirLaRegionConMasJugadores(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion);

#endif /* INFORMES_H_ */
