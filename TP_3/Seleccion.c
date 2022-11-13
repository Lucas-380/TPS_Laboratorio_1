#include "Seleccion.h"

Seleccion* selec_new(){
	Seleccion* auxSeleccion;
	auxSeleccion = (Seleccion*)malloc(sizeof(Seleccion));
	return auxSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* auxSeleccion;

	if(idStr!=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{
		auxSeleccion = selec_new();
		auxSeleccion->id = atoi(idStr);
		strcpy(auxSeleccion->pais, paisStr);
		strcpy(auxSeleccion->confederacion, confederacionStr);
		auxSeleccion->convocados = atoi(convocadosStr);
	}

	return auxSeleccion;
}

/**
 * @brief La funcion imprime a una seleccion determinada
 *
 * @param unaSeleccion Es la seleccion que se quiere imprimir
 */
void selec_printOneSeleccion(Seleccion* unaSeleccion){
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	if(selec_getId(unaSeleccion, &auxId) &&
	   selec_getPais(unaSeleccion, auxPais) &&
	   selec_getConfederacion(unaSeleccion, auxConfederacion) &&
	   selec_getConvocados(unaSeleccion, &auxConvocados))
	{
		printf("\t| %-2d | %-30s | %-14s | %-10d |\n", auxId, auxPais, auxConfederacion, auxConvocados);
	}

}

/**
 * @brief La funcion busca al mayor id dentro de la lista
 *
 * @param pArrayListSeleccion Es el puntero a la lista de selecciones
 * @return la funcion retorna el mayor id en la lista, en caso que la lista sea NULL o este vacia retorna -1
 */
int selec_buscarMayorId(LinkedList* pArrayListSeleccion)
{
	int len;
	int id;
	int mayorId = -1;
	len = ll_len(pArrayListSeleccion);
	Seleccion* unaSeleccion;
	if(pArrayListSeleccion != NULL && !ll_isEmpty(pArrayListSeleccion))
	{
		for(int i = 0; i < len; i++)
		{
			unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getId(unaSeleccion, &id);
			if(i == 0 || id > mayorId)
			{
				mayorId = id;
			}
		}
	}
	return mayorId;
}

/**
 * @brief La funcion permite al usuario buscar una seleccion a traves de un id y devolver por parametros su indice
 *
 * @param pArrayListSeleccion Es el puntero a la lista de Selecciones
 * @param indice Es donde se guardara el indice de la seleccion que se haya seleccionado
 * @return la funcion retorna 1 si encontro la seleccion, caso contrario retorna 0
 */
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int* indice)
{
	int idSeleccionado;
	int idAux;
	int idEncontrado = 0;
	int mayorId = selec_buscarMayorId(pArrayListSeleccion);

	Seleccion* unaSeleccion;
	utn_getNumero(&idSeleccionado, "\nIngrese el id de la seleccion: ", "\nID No encontrado\n", 1, mayorId);

	do{
		for(int i=0; i<ll_len(pArrayListSeleccion); i++)
		{
			unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(selec_getId(unaSeleccion, &idAux) == 1 && idAux == idSeleccionado)
			{
				idEncontrado = 1;
				*indice = i;
				break;
			}
		}
		if(idEncontrado == 0){
			printf("\nID SELECCION No encontrado\n");
		}
	}while(idEncontrado == 0);
	return idEncontrado;
}

/**
 * @brief La funcion libera el espacio en memoria de la seleccion
 *
 * @param this hace referencia la seleccion que se va a eliminar
 */
void selec_delete(Seleccion* this)
{
	if(this != NULL){
		free(this);
	}
}

/**
 * @brief obtiene un id de una seleccion
 *
 * @param this hace referencia a la seleccion
 * @param id Es donde se guardara el id
 * @return Retorna 1 en caso de que se haya obtenido de manera correcta, caso contrario retorna 0
 */
int selec_getId(Seleccion* this,int* id)
{
	int retorno = 0;
	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief obtiene un pais de una seleccion
 *
 * @param this hace referencia a la seleccion
 * @param pais Es donde se guardara el pais
 * @return Retorna 1 en caso de que se haya obtenido de manera correcta, caso contrario retorna 0
 */
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 0;
	if(this != NULL)
	{
		if(isValidString(pais, 30))
		{
			strncpy(pais, this->pais,30);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief obtiene una confederacion de una seleccion
 *
 * @param this hace referencia a la seleccion
 * @param confederacion Es donde se guardara la confederacion
 * @return Retorna 1 en caso de que se haya obtenido de manera correcta, caso contrario retorna 0
 */
int selec_getConfederacion(Seleccion* this, char* confederacion)
{
	int retorno = 0;
	if(this != NULL)
	{
		if(isValidString(confederacion, 30))
		{
			strncpy(confederacion, this->confederacion,30);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Asigna a una seleccion los convocados
 *
 * @param this hace referencia a la seleccion
 * @param convocados Son los convocados que se le asignaran a la seleccion
 * @return Retorna 1 en caso de que se hayan asignado de manera correcta, caso contrario retorna 0
 */
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 0;
	if(this != NULL && convocados > -1)
	{
		this->convocados = convocados;
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief obtiene los convocados de una seleccion
 *
 * @param this hace referencia a la seleccion
 * @param convocados Es donde se guardaran los convocados
 * @return Retorna 1 en caso de que se hayan obtenido de manera correcta, caso contrario retorna 0
 */
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 0;
	if(this != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}


//FUNCION CRITERIO
int selec_CompararPorConfederacion(void* unaSeleccion, void* otraSeleccion)
{
	int compara;
	char auxConfederacionUno[30];
	char auxConfederacionDos[30];
    Seleccion* selec_auxUno;
    Seleccion* selec_auxDos;

	if(unaSeleccion != NULL && otraSeleccion != NULL)
	{
		selec_auxUno = (Seleccion*)unaSeleccion;
		selec_auxDos = (Seleccion*)otraSeleccion;

	    if(selec_getConfederacion(selec_auxUno, auxConfederacionUno) && selec_getConfederacion(selec_auxDos, auxConfederacionDos))
	    {
			strlwr(auxConfederacionUno);
			strlwr(auxConfederacionDos);
	    	compara = strcmp(auxConfederacionUno, auxConfederacionDos);
	    }
	}
    return compara;
}

int selec_CompararPorId(void* unaSeleccion, void* otraSeleccion)
{
    int compara;
	int auxIdUno;
	int auxIdDos;
    Seleccion* selec_auxUno;
    Seleccion* selec_auxDos;

	if(unaSeleccion != NULL && otraSeleccion != NULL)
	{
		selec_auxUno = (Seleccion*)unaSeleccion;
		selec_auxDos = (Seleccion*)otraSeleccion;
		if(selec_getId(selec_auxUno, &auxIdUno) && selec_getId(selec_auxDos, &auxIdDos))
		{
			if(auxIdUno > auxIdDos){
				compara = 1;
			}
			else{
				if(auxIdUno < auxIdDos){
					compara = -1;
				}
			}
		}
	}
    return compara;
}


