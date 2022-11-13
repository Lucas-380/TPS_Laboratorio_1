#include "Jugador.h"

static int validarPosicion(LinkedList* pArrayListJugador, char* posicion);
static int validarNacionalidad(LinkedList* pArrayListJugador, char* nacionalidad);

Jugador* jug_new()
{
	Jugador* unJugador;
	unJugador = (Jugador*)malloc(sizeof(Jugador));
	return unJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador;

	if(idStr!=NULL && nombreCompletoStr!=NULL && edadStr!=NULL && posicionStr!=NULL && nacionalidadStr!=NULL && idSelccionStr!=NULL)
	{
		unJugador = jug_new();
		unJugador->id = atoi(idStr);
		strcpy(unJugador->nombreCompleto, nombreCompletoStr);
		unJugador->edad = atoi(edadStr);
		strcpy(unJugador->posicion, posicionStr);
		strcpy(unJugador->nacionalidad, nacionalidadStr);
		unJugador->idSeleccion = atoi(idSelccionStr);
	}

	return unJugador;
}

/**
 * @brief La funcion imprime a un jugador determinado
 * @param unJugador Es jugador que se quiere imprimir
 * @param pArrayListSeleccion Hace referencia a la lista de selecciones
 */
void jug_printOneJugador(Jugador* unJugador, LinkedList* pArrayListSeleccion)
{
	int jug_auxId;
	char jug_auxNombreCompleto[100];
	int jug_auxEdad;
	char jug_auxPosicion[30];
	char jug_auxNacionalidad[30];
	int jug_auxIdSeleccion;

	int lenListSelec;
	int selec_auxId;
	char selec_auxPais[30] = "NO CONVOCADO";
	Seleccion* auxSeleccion;

	if( jug_getId(unJugador, &jug_auxId) &&
		jug_getNombreCompleto(unJugador, jug_auxNombreCompleto) &&
		jug_getEdad(unJugador, &jug_auxEdad) &&
		jug_getPosicion(unJugador, jug_auxPosicion) &&
		jug_getNacionalidad(unJugador, jug_auxNacionalidad) &&
		jug_getIdSeleccion(unJugador, &jug_auxIdSeleccion))
	{

		lenListSelec = ll_len(pArrayListSeleccion);

		if(jug_auxIdSeleccion > 0)
		{
			for(int i=0; i<lenListSelec; i++)
			{
				auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
				if(selec_getId(auxSeleccion, &selec_auxId) == 1 && selec_auxId == jug_auxIdSeleccion )
				{
					selec_getPais(auxSeleccion, selec_auxPais);
					break;
				}
			}
		}
		printf("\t| %-4d | %-30s | %-4d | %-20s | %-20s | %-12s |\n",
				jug_auxId, jug_auxNombreCompleto, jug_auxEdad, jug_auxPosicion, jug_auxNacionalidad, selec_auxPais);
	}
}

/**
 * @brief La funcion libera el espacio en memoria del jugador
 * @param this hace referencia el jugador que se va a eliminar
 */
void jug_delete(Jugador* this)
{
	if(this != NULL){
		free(this);
	}
}

/**
 * @brief La funcion guarda el ultimo id ingresado
 * @param idManual hace referencia al id que se guardara
 * @return Retorna 1 en caso de que haya guardado el id de manera correcta, caso contrario retorna 0
 */
int jug_guardarUltimaId(int idManual)
{
	FILE* pFileId;
	int idActual;
	int retorno = 0;
	if(idManual > 0){
		idActual = idManual;
		pFileId = fopen("ultimoIdJugador.bin", "wb");
		fwrite(&idActual, sizeof(idActual), 1, pFileId);
		fclose(pFileId);
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief La funcion obtiene mediante un archivo binario el ultimo id ingresado
 * @param ultimaId Es donde se guardara el ultimo id
 * @return Retorna 1 en caso de que haya guardado el id de manera correcta, caso contrario retorna 0
 */
int jug_obtenerUltimaId(int* ultimaId)
{
	FILE* pFileId;
	int idActual;
	int retorno = 0;
	if(ultimaId != NULL){
		pFileId = fopen("ultimoIdJugador.bin", "rb");
		fread(&idActual, sizeof(idActual), 1, pFileId);
		*ultimaId = idActual;
		fclose(pFileId);
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief La funcion busca a un jugador mediante un id ingresado por el usuario
 * @param pArrayListJugador Es el puntero a la lista de jugadores
 * @param indice Es donde se va a guardar el indice del jugador que se buscaba
 * @return Retorna 1 en caso de que se encuentre el id, caso contrario retorna 0
 */
int jug_buscarPorId(LinkedList* pArrayListJugador, int* indice)
{
	int idSeleccionado;
	int ultimoId;
	int idAux;
	int idEncontrado = 0;

	Jugador* unJugador;
	jug_obtenerUltimaId(&ultimoId);
	do{
		utn_getNumero(&idSeleccionado, "\nIngrese el id del jugador: ", "\nID No encontrado\n", 1, ultimoId);
		for(int i=0; i<ll_len(pArrayListJugador); i++)
		{
			unJugador = (Jugador*)ll_get(pArrayListJugador, i);
			if(jug_getId(unJugador, &idAux) == 1 && idAux == idSeleccionado)
			{
				idEncontrado = 1;
				*indice = i;
				break;
			}
		}
		if(idEncontrado == 0){
			printf("\nID No encontrado\n");
		}
	}while(idEncontrado == 0);

	return idEncontrado;
}

/**
 * @brief asigna a un jugador un id
 * @param this hace referencia al jugador
 * @param id Es el id que se le asignara
 * @return Retorna 1 en caso de que se haya asignado de manera correcta, caso contrario retorna 0
 */
int jug_setId(Jugador* this, int id)
{
	int retorno = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

 /**
  * @brief Obtiene a un id mediante un Jugador
  * @param this hace referencia al jugador
  * @param id Es donde se guardara el id
  * @return Retorna 1 en caso de que se obtenga el id de manera correcta, caso contrario retorna 0
  */
int jug_getId(Jugador* this,int* id)
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
 * @brief La funcion asiganara un nombre completo ingresado por un usuario a un jugador
 * @param this hace referencia al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_asignarNombreCompleto(Jugador* this){
	int retorno = 0;
	int retornoGets;
	char nombreEdit[100];

	if(this != NULL){
		retornoGets = utn_getName(nombreEdit, "-Ingrese el nombre del jugador: ", "ERROR - Ingrese un nombre valido\n", 100);
		if(retornoGets == 0 && jug_setNombreCompleto(this, nombreEdit)){
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Asigna un nombre a un jugador
 * @param this hace referencia al jugador
 * @param nombreCompleto Es la cadena que se le asignara como nombre al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;
	if(this != NULL && nombreCompleto != NULL)
	{
		if(isValidString(nombreCompleto, 100))
		{
			strncpy(this->nombreCompleto, nombreCompleto,100);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Obtiene un nombre de un jugador
 * @param this hace referencia a un jugador
 * @param nombreCompleto es donde se guardara el nombre obtenido
 * @return Retorna 1 en caso de que se obtenga de manera correcta, caso contrario retorna 0
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;
	if(this != NULL && nombreCompleto != NULL)
	{
		if(isValidString(nombreCompleto, 100))
		{
			strncpy(nombreCompleto, this->nombreCompleto,100);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief La funcion asiganara una posicion ingresada por un usuario a un jugador
 * @param pArrayListJugador Es el puntero a la lista de jugadores
 * @param this hace referencia al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_asignarPosicion(LinkedList* pArrayListJugador, Jugador* this){
	int retorno = 0;
	int retornoGet;
	int retornoValidacion = 0;
	char posicion[30];

	if(this != NULL){
		do{
			retornoGet = utn_getName(posicion, "-Ingrese la posicion del jugador: ", "ERROR - Ingrese una posicion valida\n", 100);
			if(validarPosicion(pArrayListJugador, posicion))
			{
				retornoValidacion = 1;
			}else{
				printf("\nERROR - Ingrese una posicion valida\n(LAS POSICIONES DEBEN SER IGUALES A LAS POSICIONES QUE ESTEN EN EL SISTEMA)\n");
			}
		}while(retornoValidacion == 0);

		if(retornoGet == 0 && jug_setPosicion(this, posicion)){
			retorno = 1;
		}
	}
	return retorno;
}


/**
 * @brief Esta funcion compara las posiciones que tengan los jugadores guardados en el .cvs y los compara por el que ingresa el usuario para validar
 * @param pArrayListJugador Es el puntero a la lista de jugadores
 * @param posicion Es la posicion que ingresa el usuario
 * @return La funcion retorna 1 en caso de que la posicion sea valida, caso contrario retorna 0
 */
static int validarPosicion(LinkedList* pArrayListJugador, char* posicion)
{
	int retorno = 0;
	int lenListJugador = ll_len(pArrayListJugador);

	Jugador* jugAux;
	char posicionAux[30];

	if(pArrayListJugador != NULL && posicion != NULL)
	{
		for(int i=0; i < lenListJugador; i++)
		{
			jugAux = (Jugador*)ll_get(pArrayListJugador, i);
			if(jug_getPosicion(jugAux, posicionAux) && stricmp(posicion, posicionAux) == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/**
 * @brief Asigna una posicion a un jugador
 * @param this hace referencia al jugador
 * @param posicion Es la cadena que se le asignara como posicion al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;
	if(this != NULL && posicion != NULL)
	{
		if(isValidString(posicion, 30))
		{
			strncpy(this->posicion, posicion,30);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Obtiene una posicion de un jugador
 * @param this hace referencia a un jugador
 * @param posicion es donde se guardara la posicion obtenida
 * @return Retorna 1 en caso de que se obtenga de manera correcta, caso contrario retorna 0
 */
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;
	if(this != NULL && posicion != NULL)
	{
		if(isValidString(posicion, 30))
		{
			strncpy(posicion, this->posicion, 30);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief La funcion asiganara una nacionalidad ingresada por un usuario a un jugador
 * @param this hace referencia al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_asignarNacionalidad(LinkedList* pArrayListJugador, Jugador* this)
{
	int retorno = 0;
	int retornoGet;
	int retornoValidacion = 0;
	char nacionalidad[30];

	if(this != NULL){
		do{
			retornoGet = utn_getName(nacionalidad, "-Ingrese la nacionalidad del jugador: ", "\nERROR - Ingrese una nacionalidad valida\n", 100);
			if(validarNacionalidad(pArrayListJugador, nacionalidad)){
				retornoValidacion = 1;
			}else{
				printf("\nERROR - Ingrese una nacionalidad valida\n(LAS NACIONALIDADES DEBEN SER IGUALES A LAS NACIONALIDADES QUE ESTEN EN EL SISTEMA)\n");
			}
		}while(retornoValidacion == 0);

		if(retornoGet == 0 && jug_setNacionalidad(this, nacionalidad)){
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Esta funcion compara las posiciones que tengan los jugadores guardados en el .cvs y los compara por el que ingresa el usuario para validar
 * @param pArrayListJugador Es el puntero a la lista de jugadores
 * @param posicion Es la posicion que ingresa el usuario
 * @return La funcion retorna 1 en caso de que la posicion sea valida, caso contrario retorna 0
 */
static int validarNacionalidad(LinkedList* pArrayListJugador, char* nacionalidad)
{
	int retorno = 0;
	int lenListJugador = ll_len(pArrayListJugador);

	Jugador* jugAux;
	char nacionalidadAux[30];

	if(pArrayListJugador != NULL && nacionalidad != NULL)
	{
		for(int i=0; i < lenListJugador; i++)
		{
			jugAux = (Jugador*)ll_get(pArrayListJugador, i);
			if(jug_getNacionalidad(jugAux, nacionalidadAux) && stricmp(nacionalidad, nacionalidadAux) == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/**
 * @brief Asigna una nacionalidad a un jugador
 * @param this hace referencia al jugador
 * @param posicion Es la cadena que se le asignara como nacionalidad al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;
	if(this != NULL && nacionalidad != NULL)
	{
		if(isValidString(nacionalidad, 30))
		{
			strncpy(this->nacionalidad,nacionalidad,30);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Obtiene una nacionalidad de un jugador
 * @param this hace referencia a un jugador
 * @param posicion es donde se guardara la nacionalidad obtenida
 * @return Retorna 1 en caso de que se obtenga de manera correcta, caso contrario retorna 0
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;
	if(this != NULL && nacionalidad != NULL)
	{
		if(isValidString(nacionalidad, 30))
		{
			strncpy(nacionalidad, this->nacionalidad, 30);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief La funcion asiganara una edad ingresada por un usuario a un jugador
 * @param this hace referencia al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_asignarEdad(Jugador* this)
{
	int retorno = 0;
	int retornoGet;
	int edad;

	if(this != NULL){
		retornoGet = utn_getNumero(&edad, "-Ingrese la edad del jugador\n", "ERROR - Ingrese una edad valida\n", 18, 55);
		if(retornoGet == 0 && jug_setEdad(this, edad)){
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * @brief Asigna una edad a un jugador
 * @param this hace referencia al jugador
 * @param edad Es la edad que se le asignara al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = 0;
	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief Obtiene una edad de un jugador
 * @param this hace referencia a un jugador
 * @param edad es donde se guardara la edad obtenida
 * @return Retorna 1 en caso de que se obtenga de manera correcta, caso contrario retorna 0
 */
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = 0;
	if(this != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief Asigna una idSeleccion a un jugador
 * @param this hace referencia al jugador
 * @param idSeleccion Es el idSeleccion que se le asignara al jugador
 * @return Retorna 1 en caso de que se asigne de manera correcta, caso contrario retorna 0
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = 0;
	if(this != NULL && idSeleccion > -1)
	{
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief Obtiene una idSeleccion de un jugador
 * @param this hace referencia a un jugador
 * @param idSeleccion es donde se guardara el idSeleccion obtenida
 * @return Retorna 1 en caso de que se obtenga de manera correcta, caso contrario retorna 0
 */
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = 0;
	if(this != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}

//FUNCION CRITERIO

int jug_CompararPorNacionalidad(void* unJugador, void* otroJugador)
{
	int compara;
	char auxNacionalidadUno[30];
	char auxNacionalidadDos[30];
    Jugador* jug_auxUno;
    Jugador* jug_auxDos;

	if(unJugador != NULL && otroJugador != NULL)
	{
	    jug_auxUno = (Jugador*)unJugador;
	    jug_auxDos = (Jugador*)otroJugador;

	    if(jug_getNacionalidad(jug_auxUno, auxNacionalidadUno) && jug_getNacionalidad(jug_auxDos, auxNacionalidadDos))
	    {
			strlwr(auxNacionalidadUno);
			strlwr(auxNacionalidadDos);
	    	compara = strcmp(auxNacionalidadUno, auxNacionalidadDos);
	    }
	}
    return compara;
}

int jug_CompararPorNombre(void* unJugador, void* otroJugador)
{
    int compara;
	char auxNombreUno[100];
	char auxNombreDos[100];
    Jugador* jug_auxUno;
    Jugador* jug_auxDos;

	if(unJugador != NULL && otroJugador != NULL)
	{
		jug_auxUno = (Jugador*)unJugador;
		jug_auxDos = (Jugador*)otroJugador;
		if(jug_getNombreCompleto(jug_auxUno, auxNombreUno) && jug_getNombreCompleto(jug_auxDos, auxNombreDos))
		{
			strlwr(auxNombreUno);
			strlwr(auxNombreDos);
			compara = strcmp(auxNombreUno, auxNombreDos);
		}
	}
    return compara;
}

int jug_CompararPorEdad(void* unJugador, void* otroJugador)
{
    int compara;
	int auxEdadUno;
	int auxEdadDos;
    Jugador* jug_auxUno;
    Jugador* jug_auxDos;

	if(unJugador != NULL && otroJugador != NULL)
	{
		jug_auxUno = (Jugador*)unJugador;
		jug_auxDos = (Jugador*)otroJugador;
		if(jug_getEdad(jug_auxUno, &auxEdadUno) && jug_getEdad(jug_auxDos, &auxEdadDos))
		{
			if(auxEdadUno > auxEdadDos){
				compara = 1;
			}
			else{
				if(auxEdadUno < auxEdadDos){
					compara = -1;
				}
			}
		}
	}
    return compara;
}

int jug_CompararPorId(void* unJugador, void* otroJugador)
{
    int compara;
	int auxIdUno;
	int auxIdDos;
    Jugador* jug_auxUno;
    Jugador* jug_auxDos;

	if(unJugador != NULL && otroJugador != NULL)
	{
		jug_auxUno = (Jugador*)unJugador;
		jug_auxDos = (Jugador*)otroJugador;
		if(jug_getId(jug_auxUno, &auxIdUno) && jug_getId(jug_auxDos, &auxIdDos))
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



