#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* Es la ruta del archivos
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de jugadores
 * \return int La funcion retorna 1 en caso de que se haya parseado los datos de manera correcta, caso contrario la funcion retorna 0
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;

	Jugador* unJugador;
	char id[10];
	char nombreCompleto[100];
	char edad[10];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[15];
	int cantidadLeida;

	if(pFile != NULL && pArrayListJugador != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
				,id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
		while(!feof(pFile))
		{
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
					,id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			if(cantidadLeida == 6){
				unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
				ll_add(pArrayListJugador, unJugador);
			}else{
				printf("\nError - alguna de las variables no fue leida correctamente\n");
			}
		}
		retorno = 1;
	}
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el programa a el archivo jugadores.csv (modo texto).
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de jugadores
 * \return int La funcion retorna 1 en caso de que se haya parseado los datos de manera correcta, caso contrario la funcion retorna 0
 */
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;

    Jugador* unJugador;
	int jug_auxId;
	char jug_auxNombreCompleto[100];
	int jug_auxEdad;
	char jug_auxPosicion[30];
	char jug_auxNacionalidad[30];
	int jug_auxIdSeleccion;
    int i;

    if(pFile != NULL && pArrayListJugador != NULL)
    {
    	if(!ll_isEmpty(pArrayListJugador))
    	{
			fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
			for(i = 0; i < ll_len(pArrayListJugador); i++)
			{
				unJugador = (Jugador*)ll_get(pArrayListJugador, i);
		    	if(jug_getId(unJugador, &jug_auxId) && jug_getNombreCompleto(unJugador, jug_auxNombreCompleto) &&
		    	   jug_getEdad(unJugador, &jug_auxEdad) && jug_getPosicion(unJugador, jug_auxPosicion) &&
				   jug_getNacionalidad(unJugador, jug_auxNacionalidad) && jug_getIdSeleccion(unJugador, &jug_auxIdSeleccion))
		    	{
		    		fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", jug_auxId, jug_auxNombreCompleto, jug_auxEdad, jug_auxPosicion, jug_auxNacionalidad, jug_auxIdSeleccion);
					retorno = 1;
		    	}
			}
    	}
    }
    return retorno;
}


/** \brief Parsea los datos de las selecciones desde el archivo seleccion.csv (modo texto).
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lista de Selecciones
 * \return int La funcion retorna 1 en caso de que se haya parseado de manera correcta, caso contrario retorna 0
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	Seleccion* auxSeleccion;

	char id[10];
	char pais[30];
	char confederacion[30];
	char convocados[10];

	int cantidadLeida;

	if(pFile != NULL && pArrayListSeleccion != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n"
				,id,pais,confederacion,convocados);
		while(!feof(pFile))
		{
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n"
					,id,pais,confederacion,convocados);
			if(cantidadLeida == 4){
				auxSeleccion = selec_newParametros(id, pais,confederacion,convocados);
				ll_add(pArrayListSeleccion, auxSeleccion);
			}else{
				printf("\nError - alguna de las variables no fue leida correctamente\n");
			}
		}
		retorno = 1;
	}

    return retorno;
}


/** \brief Parsea los datos de las selecciones desde el programa a selecciones.csv (modo texto).
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lista de Selecciones
 * \return int La funcion retorna 1 en caso de que se haya parseado de manera correcta, caso contrario retorna 0
 */
int parser_SeleccionToText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
    int i;
    Seleccion* unaSeleccion;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

    if(pFile != NULL && pArrayListSeleccion != NULL)
    {
    	if(!ll_isEmpty(pArrayListSeleccion))
    	{
			fprintf(pFile, "id,pais,confederacion,convocados\n");
			for(i = 0; i < ll_len(pArrayListSeleccion); i++)
			{
				unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
				if(selec_getId(unaSeleccion, &auxId) && selec_getPais(unaSeleccion, auxPais) &&
				   selec_getConfederacion(unaSeleccion, auxConfederacion) && selec_getConvocados(unaSeleccion, &auxConvocados))
		    	{
		    		fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxPais, auxConfederacion, auxConvocados);
					retorno = 1;
		    	}
			}
    	}
    }
    return retorno;
}


/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de Jugadores
 * \return int La funcion retorna 1 en caso de que se haya parseado de manera correcta, caso contrario retorna 0
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
    Jugador* unJugador;

    if(pFile != NULL && pArrayListJugador != NULL)
    {
        while(!feof(pFile))
        {
			unJugador = jug_new();
			fread((Jugador*)unJugador, sizeof(Jugador), 1, pFile);
            if(!feof(pFile))
            {
            	if(ll_contains(pArrayListJugador, unJugador) == 0)
            	{
            		ll_add(pArrayListJugador, unJugador);
            		retorno = 1;
            	}
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el programa a un archivo binario.
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de Jugadores
 * \return int La funcion retorna 1 en caso de que se haya parseado de manera correcta, caso contrario retorna 0
 */
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int cantidad;
	Jugador* aux;
	cantidad = ll_len(pArrayListJugador);

	if(pFile != NULL && pArrayListJugador  != NULL)
	{
		for(int i=0; i<cantidad; i++){
			aux = (Jugador*)ll_get(pArrayListJugador, i);
			fwrite(aux, sizeof(Jugador), 1, pFile);
		}
		retorno = 1;
	}
    return retorno;
}
