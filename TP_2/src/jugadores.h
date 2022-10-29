
#ifndef JUGADORES_H_
#define JUGADORES_H_

#define VACIO -1
#define OCUPADO 0

#include "confederaciones.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/**
 * @fn int inicializarEstados(eJugador*, int)
 * @brief Se utiliza para inicializar los estados en -1 del array de estructuras eJugador
 * @param jugadores Es el puntero que va a ser recorrido para inicializarlo en -1
 * @param len Es la longitud del array
 * @return La funcion va a retornar 0 en caso que falte pasar algun parametro, en caso contrario retorna 1
 */
int inicializarEstadosJugador(eJugador* jugadores, int len);

/**
 * @fn int buscarEspacioLibre(eJugador*, int, int*)
 * @brief Esta funcion busca un espacio libre dentro del array de estructura de eJugador
 * @param jugadores Este es el puntero que va a ser recorrido para buscar el espacio libre
 * @param len Es la longitud del array
 * @param pIndex Este puntero es donde va a guardar el indice o posicion vacia del array
 * @return La funcion va a retornar 0 en caso que falte pasar algun parametro, en caso contrario retorna 1
 */
int buscarEspacioLibreJugador(eJugador* jugadores, int len, int* pIndex);

/**
 * @fn int buscarJugadorPorId(eJugador*, int, int*)
 * @brief Esta funcion busca mediante un id a un determinado jugador
 * @param jugador Es el puntero que va a ser recorrido para comparar los actores que tenga guardado
 * @param len Es la longitud del array
 * @param indice Es el puntero donde se guarda la posicion que coincide con el id que se buscaba
 * @return La funcion va a retornar -1 en caso que falte pasar algun parametro o no encuentre el id que esperaba, en caso contrario retorna 0
 */
int buscarJugadorPorId(eJugador* jugador, int len, int* indice);

/**
 * @fn int altaJugador(eJugador*, int, eConfederacion*, int, int*)
 * @brief Esta funcion da el alta a un nuevo jugador estableciendolo en una posicion del array eJugador
 * @param jugadores Es el puntero que conecta al array en donde se va a guardar el nuevo jugador
 * @param lenJugador Es la longitud del array de tipo eJugador
 * @param confederaciones Es el puntero que conecta con la entidad eConfederacion
 * @param lenConfederaciones el la longitud del array de tipo eConfederacion
 * @param idActual Este puntero conecta con una variable que almacena las ids ingresadas y las va sumando
 * @return La funcion retorna 1 si las asignaciones son completadas, caso contrario retorna 0
 */
int altaJugador(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederaciones, int idActual);

/**
 * @fn int modificarJugador(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion permite modificar cualquier campo de un jugador con estructura eJugador
 * @param jugadores Es el puntero que conecta al array en donde se encuentra el jugador a modificar
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederaciones Es puntero que conecta con la entidad eConfederacion
 * @param lenConfederacion Es la longitud del array de tipo eConfederacion
 * @return La funcion retorna 1 si la o las modificaciones son completadas, caso contrario retorna 0
 */
int modificarJugador(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion);

/**
 * @fn int bajaJugador(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion cambia el estado de un determinado jugador a traves de su id
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugadores Es la longitud del array del tipo eJugador
 * @param confederacion Es puntero que conecta con la entidad eConfederacion
 * @param lenConfederacion Es la longitud del array de tipo eConfederacion
 * @return La funcion retorna 1 en caso que el jugador sea dado de baja correctamente, caso contrario retorna 0
 */
int bajaJugador(eJugador* jugadores, int lenJugadores, eConfederacion* confederacion, int lenConfederacion);

/**
 * @fn int asignarId(eJugador*, int, int)
 * @brief Esta funcion me permite asignar un id a un nuevo jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del nuevo jugador dentro del array de tipo ejugador
 * @param idActual Esta variable representara el id que tomara el nuevo jugador
 * @return La funcion retorna 1 en caso de que se haya asignado el id de manera correcta, caso contrario retornara 0
 */
int asignarId(eJugador* jugadores, int indice, int idActual);

/**
 * @fn int asignarNombre(eJugador*, int)
 * @brief Esta funcion me permite asignar o reemplazar un nombre a un jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del jugador dentro del array de tipo ejugador
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarNombre(eJugador* jugadores, int indice);

/**
 * @fn int asignarPosicion(eJugador*, int)
 * @brief Esta funcion me permite asignar o reemplazar la posicion del jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del jugador dentro del array de tipo ejugador
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarPosicion(eJugador* jugadores, int indice);

/**
 * @fn int validarPosicion(char[])
 * @brief Esta funcion compara el texto que ingreso el usuario con las posiciones validas
 * @param posicion Sera la cadena que ingreso el usuario
 * @return La funcion retorna 1 en caso de que la cadena ingresada sea igual a alguna de las posiciones validas, en caso de que sean diferente retorna 0
 */
int validarPosicion(char posicion[]);

/**
 * @fn int asignarNumeroCamiseta(eJugador*, int)
 * @brief Esta funcion me permite asignar o reemplazar el numero de camista de jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del jugador dentro del array de tipo ejugador
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarNumeroCamiseta(eJugador* jugadores, int indice);

/**
 * @fn int asignarConfederacion(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion me permite asignar o reemplazar una confederacion al jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del jugador dentro del array de tipo ejugador
 * @param confederaciones Es el puntero que conecta con el array en donde se guardan las confederaciones
 * @param lenConfederaciones Es la longitud del array de tipo eConfederacion
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarConfederacion(eJugador* jugadores, int indice, eConfederacion* confederaciones, int lenConfederaciones);

/**
 * @fn int asignarSalario(eJugador*, int)
 * @brief Esta funcion me permite asignar o reemplazar el salario del jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del jugador dentro del array de tipo ejugador
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarSalario(eJugador* jugadores, int indice);

/**
 * @fn int asignarAniosContrato(eJugador*, int)
 * @brief Esta funcion me permite asignar los años de contrato del jugador
 * @param jugadores Es el puntero que conecta con el array en donde se guardara el jugador
 * @param indice Este es el indice que indica la posicion del jugador dentro del array de tipo ejugador
 * @return La funcion retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retornara 0
 */
int asignarAniosContrato(eJugador* jugadores, int indice);

/**
 * @fn void MostrarUnJugador(eJugador, eConfederacion*, int)
 * @brief Esta funcion hace un printf() sobre todos los datos de un jugador especifico que se pasa por parametro
 * @param jugadores Hace referencia al jugador al que se le imprimiran los datos
 * @param confederacion Es puntero que conecta con la entidad eConfederacion
 * @param lenConfederacion Es la longitud del array de tipo eConfederacion
 */
void MostrarUnJugador(eJugador jugadores, eConfederacion* confederacion, int lenConfederacion);

/**
 * @fn int listarJugadores(eJugador*, int, eConfederacion*, int)
 * @brief Esta funcion crea una tabla listando a los jugadores disponibles
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param lenJugador Es la longitud del array del tipo eJugador
 * @param confederacion Es puntero que conecta con la entidad eConfederacion
 * @param lenConfederacion Es la longitud del array de tipo eConfederacion
 * @return
 */
int listarJugadores(eJugador* jugadores, int lenJugador, eConfederacion* confederacion, int lenConfederacion);

/**
 * @fn int ComprobarEstadoJugadores(eJugador*, int)
 * @brief Esta funcion comprueba si hay almenos un jugador disponible
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @return La funcion retorna 1 si hay al menos un jugador disponible, en caso que no haya ningun jugador disponible retorna 0
 */
int ComprobarEstadoJugadores(eJugador* jugadores, int len);

/**
 * @fn int contadorDeJugadores(eJugador*, int)
 * @brief Esta funcion cuenta cuantos jugadores disponibles hay
 * @param jugadores Es el puntero que conecta al array en donde se encuentran los jugadores
 * @param len Es la longitud del array del tipo eJugador
 * @return La funcion retorna la cantidad de jugadores disponibles
 */
int contadorDeJugadores(eJugador* jugadores, int len);

#endif /* JUGADORES_H_ */
