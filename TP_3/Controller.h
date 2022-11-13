#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "menu.h"

// Controllers Jugador
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador, char criterio[]);
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListConvocados);

// Controllers Seleccion
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

// Controllers de listas en conjunto
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_agregarConvocado(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);
int controller_removerConvocado(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);
int controller_generarListaConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListConvocados, LinkedList* pArrayListSeleccion, char* confederacion);




