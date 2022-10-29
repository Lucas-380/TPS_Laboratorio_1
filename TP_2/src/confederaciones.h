
#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

#define VACIO -1
#define OCUPADO 0

#include "inputs.h"

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

	short isEmpty;
}eConfederacion;

/**
 * @fn int buscarEspacioLibreConfederacion(eConfederacion*, int, int*)
 * @brief Esta funcion busca un espacio libre dentro del array de estructura de eConfederacion
 * @param confederaciones Este es el puntero que va a ser recorrido para buscar el espacio libre
 * @param len Es la longitud del array
 * @param pIndex Este puntero es donde va a guardar el indice o posicion vacia del array
 * @return La funcion va a retornar 0 en caso que falte pasar algun parametro, en caso contrario retorna 1
 */
int buscarEspacioLibreConfederacion(eConfederacion* confederaciones, int len, int* pIndex);

/**
 * @fn int buscarConfederacionPorId(eConfederacion*, int, int*)
 * @brief Esta funcion busca mediante un id a una determinada confederacion
 * @param confederaciones Es el puntero que va a ser recorrido para comparar los actores que tenga guardado
 * @param len Es la longitud del array
 * @param indice Es el puntero donde se guarda la posicion que coincide con el id que se buscaba
 * @return La funcion va a retornar -1 en caso que falte pasar algun parametro o no encuentre el id que esperaba, en caso contrario retorna 0
 */
int buscarConfederacionPorId(eConfederacion* confederaciones, int len, int* indice);

/**
 * @fn int altaConfederacion(eConfederacion*, int)
 * @brief Esta funcion da el alta a una nueva confederacion estableciendolo en una posicion del array eConfederacion
 * @param confederaciones Es el puntero que va a ser recorrido para comparar los actores que tenga guardado
 * @param len Es la longitud del array
 * @return La funcion retorna 1 si las asignaciones son completadas, caso contrario retorna 0
 */
int altaConfederacion(eConfederacion* confederacion, int len);

/**
 * @fn int asignarId_confederacion(eConfederacion*, int)
 * @brief Esta funcion asigna un id a la nueva confederacion
 * @param confederaciones Es el puntero que va a ser recorrido para comparar los actores que tenga guardado
 * @param indice Este es el indice que indica la posicion de la confederacion dentro del array de tipo eConfederacion
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarId_confederacion(eConfederacion* confederacion, int indice);

/**
 * @fn int asignarNombre_confederacion(eConfederacion*, int)
 * @brief Esta funcion me permite asignar o reemplazar un nombre a una confederacion
 * @param confederacion Es el puntero que conecta con el array en donde se guardara la confederacion
 * @param indice Este es el indice que indica la posicion de la confederacion dentro del array de tipo eConfederacion
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarNombre_confederacion(eConfederacion* confederacion, int indice);

/**
 * @fn int asignarRegion_confederacion(eConfederacion*, int)
 * @brief Esta funcion me permite asignar o reemplazar una region a una confederacion
 * @param confederacion Es el puntero que conecta con el array en donde se guardara la confederacion
 * @param indice Este es el indice que indica la posicion de la confederacion dentro del array de tipo eConfederacion
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarRegion_confederacion(eConfederacion* confederacion, int indice);

/**
 * @fn int asignarAnioCreacion_confederacion(eConfederacion*, int)
 * @brief Esta funcion me permite asignar o reemplazar un año de creacion a una confederacion
 * @param confederacion Es el puntero que conecta con el array en donde se guardara la confederacion
 * @param indice Este es el indice que indica la posicion de la confederacion dentro del array de tipo eConfederacion
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarAnioCreacion_confederacion(eConfederacion* confederacion, int indice);

/**
 * @fn int modificarConfederacion(eConfederacion*, int)
 * @brief Esta funcion permite modificar cualquier campo de una confederacion con estructura eConfederacion
 * @param confederacion Es el puntero que conecta con el array en donde se guardara la confederacion
 * @param len Es la longitud del array de confederacion
 * @return La funcion retorna 1 en caso de que se haya modificado de manera correcta, caso contrario retornara 0
 */
int modificarConfederacion(eConfederacion* confederacion, int len);

/**
 * @fn int bajaConfederacion(eConfederacion*, int)
 * @brief Esta funcion cambia el estado de una determinada confederacion a traves de su id
 * @param confederacion Es el puntero que conecta con el array en donde se guardara la confederacion
 * @param len Es la longitud del array de confederacion
 * @return La funcion retorna 1 en caso de que se haya cambiado el estado de manera correcta, caso contrario retornara 0
 */
int bajaConfederacion(eConfederacion* confederacion, int len);

/**
 * @fn void MostrarUnaConfederacion(eConfederacion)
 * @brief Esta funcion me permite imprimir una confederacion especifica
 * @param confederacion Sea la confederacion que se quiera imprimir
 */
void MostrarUnaConfederacion(eConfederacion confederacion);

/**
 * @fn int listarConfederaciones(eConfederacion*, int)
 * @brief Esta funcion me permite imprimir una confederacion especifica
 * @param confederacion Es el puntero que conecta con el array en donde se guardara la confederacion
 * @param len Es la longitud del array de confederacion
 * @return La funcion retorna 0 en caso de que se haya asignado de manera correcta, caso contrario retornara -1
 */
int listarConfederaciones(eConfederacion* confederaciones, int len);

#endif /* CONFEDERACIONES_H_ */
