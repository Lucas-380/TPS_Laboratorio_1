#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "inputs.h"
#include "Seleccion.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

// Setters y getters
int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

// Funciones de asignacion
int jug_asignarNombreCompleto(Jugador* this);
int jug_asignarEdad(Jugador* this);
int jug_asignarPosicion(LinkedList* pArrayListJugador, Jugador* this);
int jug_asignarNacionalidad(LinkedList* pArrayListJugador, Jugador* this);

// Funciones Auxiliares
void jug_printOneJugador(Jugador* unJugador, LinkedList* pArrayListSeleccion);
int jug_obtenerUltimaId(int* ultimaId);
int jug_guardarUltimaId(int id);
int jug_buscarPorId(LinkedList* pArrayListJugador, int* indice);

// Funciones criterio
int jug_CompararPorNombre(void* unJugador, void* otroJugador);
int jug_CompararPorNacionalidad(void* unJugador, void* otroJugador);
int jug_CompararPorEdad(void* unJugador, void* otroJugador);
int jug_CompararPorId(void* unJugador, void* otroJugador);


#endif // jug_H_INCLUDED
