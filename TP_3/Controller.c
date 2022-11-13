#include "Controller.h"

static int cantidadDeConvocados(LinkedList* pArrayListSeleccion);

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return int retorna 1 en caso de que haya cargado los jugadores, caso contrario 0
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(path != NULL && pArrayListJugador != NULL){
		FILE* jArchivo;
		jArchivo = fopen(path, "r");
		if(jArchivo != NULL && parser_JugadorFromText(jArchivo, pArrayListJugador)){
			retorno = 1;
		}
		fclose(jArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return int retorna 1 en caso de que haya cargado los jugadores, caso contrario 0
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(path != NULL && pArrayListJugador != NULL){
		FILE* jArchivoB;
		jArchivoB = fopen(path, "rb");
		if(jArchivoB != NULL && parser_JugadorFromBinary(jArchivoB, pArrayListJugador)){
			retorno = 1;
		}
		fclose(jArchivoB);
	}
    return retorno;
}

/** \brief Alta de jugadores agrega a un jugador con los datos ingresados por el usuario
 *
 * \param pArrayListJugador LinkedList*
 * \return int retorna 1 en caso de que hayan guardado los jugadores, caso contrario 0
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno;
	int idActual;
	int setCompletado = 0;
	retorno = 0;

	Jugador* unJugador;
	unJugador = jug_new();

	if(pArrayListJugador != NULL && unJugador != NULL)
	{
		if(jug_obtenerUltimaId(&idActual)){
			idActual = idActual+1;
			if(jug_setId(unJugador, idActual)){
				setCompletado++;
			}else{
				printf("\nError en la carga de ids\n");
			}
		}else{
			printf("\nError al obtener la ultima id\n");
		}

		if(jug_asignarNombreCompleto(unJugador)){
			setCompletado++;
		}

		if(jug_asignarEdad(unJugador)){
			setCompletado++;
		}

		if(jug_asignarPosicion(pArrayListJugador, unJugador)){
			setCompletado++;
		}

		if(jug_asignarNacionalidad(pArrayListJugador, unJugador)){
			setCompletado++;
		}

		if(jug_setIdSeleccion(unJugador, 0)){
			setCompletado++;
		}

		if(setCompletado == 6){
			ll_add(pArrayListJugador, unJugador);
			jug_guardarUltimaId(idActual);
			retorno = 1;
		}else{
			printf("\nEl jugador no se pudo guardar\n");
		}
	}
    return retorno;
}


/** \brief Modificar datos del jugador - El usuario podra modificar determinados campos
 * \param pArrayListJugador LinkedList*
 * \return int retorna 1 en caso de que haya modificado a los jugadores correctamente, caso contrario 0
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int indice;
	int retorno;
	int salir;

	retorno = 0;
	salir = 0;
	char mensajeExitoso[60] = "\n** La modificacion se realizo de manera correcta **\n";
	char mensajeError[60] = "\n** La modificacion no se pudo realizar **\n";

	Jugador* unJugador;

	if(jug_buscarPorId(pArrayListJugador, &indice)){
		unJugador = (Jugador*)ll_get(pArrayListJugador, indice);
		do{
			switch(menu_editarJugador()){
				case 1:
					//EDITAR NOMBRE
					if(jug_asignarNombreCompleto(unJugador)){
						printf("%s", mensajeExitoso);
					}else{
						printf("%s", mensajeError);
					}
					break;
				case 2:
					//EDITAR EDAD
					if(jug_asignarEdad(unJugador)){
						printf("%s", mensajeExitoso);
					}else{
						printf("%s", mensajeError);
					}
					break;
				case 3:
					//EDITAR POSICION
					if(jug_asignarPosicion(pArrayListJugador, unJugador)){
						printf("%s", mensajeExitoso);
					}else{
						printf("%s", mensajeError);
					}
					break;
				case 4:
					//EDITAR NACIONALIDAD
					if(jug_asignarNacionalidad(pArrayListJugador, unJugador)){
						printf("%s", mensajeExitoso);
					}else{
						printf("%s", mensajeError);
					}
					break;
				case 5:
					printf("Volviendo al menu principal");
					retorno = 1;
					salir = 1;
					break;
			}
		}while(salir != 1);
	}

    return retorno;
}

/** \brief Realiaza la Baja del jugador
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int retorna 1 en caso de que la operacion se realizara correctamente, caso contrario 0
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int indice;

	Jugador* unJugador;
	int jug_idSeleccion;

	Seleccion* unaSeleccion;
	int selec_id;
	int selec_Convocados;

	if(pArrayListJugador != NULL)
	{
		if(jug_buscarPorId(pArrayListJugador, &indice))
		{
			unJugador = (Jugador*)ll_get(pArrayListJugador, indice);
			jug_getIdSeleccion(unJugador, &jug_idSeleccion);
			if(jug_idSeleccion > 0){
				for(int i=0; i<ll_len(pArrayListSeleccion); i++)
				{
					unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
					selec_getId(unaSeleccion, &selec_id);
					if(selec_id == jug_idSeleccion)
					{
						selec_getConvocados(unaSeleccion, &selec_Convocados);
						selec_Convocados -= 1;
						selec_setConvocados(unaSeleccion, selec_Convocados);
					}
				}
			}
			ll_remove(pArrayListJugador, indice);
			retorno = 1;
		}
	}
    return retorno;
}

/** \brief Realiza una Lista de jugadores
 *
 * \param pArrayListSeleccion LinkedList*
 * \param pArrayListJugador LinkedList*
 * \return int int La funcion retorna 0 en caso de error, caso contrario retorna 1
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int retorno = 0;
	int cantidad;
	int isEmpty;

	isEmpty = ll_isEmpty(pArrayListJugador);
	cantidad = ll_len(pArrayListJugador);
	Jugador* jug_aux;

	if(pArrayListJugador != NULL && isEmpty != 1){
		printf( "\t+======+================================+======+======================+======================+==============+\n"
				"\t|  ID  |         NOMBRE COMPLETO        | EDAD |       POSICION       |     NACIONALIDAD     |   SELECCION  |\n"
				"\t+======+================================+======+======================+======================+==============+\n");
		for(int i=0; i<cantidad; i++){
			jug_aux = (Jugador*)ll_get(pArrayListJugador, i);
			jug_printOneJugador(jug_aux, pArrayListSeleccion);
		}
		printf( "\t+------+--------------------------------+------+----------------------+----------------------+--------------+\n");
		retorno = 1;
	}
    return retorno;
}


/** \brief Lista los jugadores convocados
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int La funcion retorna 0 en caso de error, caso contrario retorna 1
 *
 */
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int cantidad;
	int isEmpty;
	int idSeleccion;

	isEmpty = ll_isEmpty(pArrayListJugador);
	cantidad = ll_len(pArrayListJugador);
	Jugador* jug_aux;

	if(pArrayListJugador != NULL && isEmpty != 1 && cantidadDeConvocados(pArrayListSeleccion) > 0){
		printf( "\t+======+================================+======+======================+======================+==============+\n"
				"\t|  ID  |         NOMBRE COMPLETO        | EDAD |       POSICION       |     NACIONALIDAD     |   SELECCION  |\n"
				"\t+======+================================+======+======================+======================+==============+\n");
		for(int i=0; i<cantidad; i++)
		{
			jug_aux = (Jugador*)ll_get(pArrayListJugador, i);
			if(jug_getIdSeleccion(jug_aux, &idSeleccion) && idSeleccion > 0)
			{
				jug_printOneJugador(jug_aux, pArrayListSeleccion);
			}
		}
		printf( "\t+------+--------------------------------+------+----------------------+----------------------+--------------+\n");
		retorno = 1;
	}
    return retorno;
}

/** \brief La funcion cuenta la cantidad de convocados en total
 *
 * \param pArrayListJugador LinkedList*
 * \return int retorna la totalidad de convocados
 */
static int cantidadDeConvocados(LinkedList* pArrayListSeleccion)
{
	int cantidad;
	int convocadosTotal = 0;
	Seleccion* selec_aux;
	for(int i=0; i<ll_len(pArrayListSeleccion); i++)
	{
		selec_aux = (Seleccion*)ll_get(pArrayListSeleccion, i);
		if(selec_getConvocados(selec_aux, &cantidad))
		{
			convocadosTotal += cantidad;
		}
	}
	return convocadosTotal;
}



/** \brief Ordenar jugadores
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return int La funcion retorna 1 si los ordeno correctamente, caso contrario retorna 0
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, char criterio[])
{
	int retorno = 0;
	int criterioOrdenamiento;
	if(pArrayListJugador != NULL && criterio != NULL)
	{
		if(strcmp(criterio, "nacionalidad") == 0)
		{
			criterioOrdenamiento = 1;
		}else{
			if(strcmp(criterio, "edad") == 0){
				criterioOrdenamiento = 2;
			}else{
				if(strcmp(criterio, "nombre") == 0){
					criterioOrdenamiento = 3;
				}
			}
		}

		switch(criterioOrdenamiento)
		{
			case 1:
				ll_sort(pArrayListJugador, jug_CompararPorNacionalidad, 1);
				retorno = 1;
				break;
			case 2:
				ll_sort(pArrayListJugador, jug_CompararPorEdad, 1);
				retorno = 1;
				break;
			case 3:
				ll_sort(pArrayListJugador, jug_CompararPorNombre, 1);
				retorno = 1;
				break;
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListSeleccion LinkedList*
 * \return int La funcion retorna 0 en caso de error, caso contrario retorna 1
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    int retorno = 0;
    if(path != NULL && pArrayListJugador != NULL)
    {
    	FILE* jArchivo = NULL;
    	jArchivo = fopen(path, "w");
    	if(jArchivo != NULL && parser_JugadorToText(jArchivo, pArrayListJugador)){
			retorno = 1;
    	}
		fclose(jArchivo);
    }
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return int La funcion retorna 0 en caso de error, caso contrario retorna 1
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListConvocados)
{
    int retorno = 0;

    if(path != NULL && pArrayListConvocados != NULL){
    	FILE* convocadosArchivo = NULL;
    	convocadosArchivo = fopen(path, "wb");
    	if(convocadosArchivo != NULL && parser_JugadorToBinary(convocadosArchivo, pArrayListConvocados)){
    		retorno = 1;
    	}
		fclose(convocadosArchivo);
    }
    return retorno;
}

/** \brief Genera y guarda los jugadores convocados de cierta confederacion a una lista
 *
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de Jugadores
 * \param pArrayListConvocados LinkedList* Es el puntero a la lista de Convocados
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lista de selecciones
 * \param confederacion char* Hace referencia a la confederacion la cual querra generar sus lista de convocados
 * \return int La funcion retorna 1 en caso de que la operacion se haya realizado de manera correcta, caso contrario retorna 0
 *
 */
int controller_generarListaConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListConvocados, LinkedList* pArrayListSeleccion, char* confederacion)
{
	int retorno = 0;
	int selec_idAux;
	char selec_confederacionAux[30];
	int idSeleccion;

	Jugador* jug_aux;
	Seleccion* selec_aux;

    if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && pArrayListConvocados != NULL)
	{
    	ll_clear(pArrayListConvocados);
		for(int i = 0; i<ll_len(pArrayListSeleccion);i++){
			selec_aux = (Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getConfederacion(selec_aux, selec_confederacionAux);

			if(strcmp(selec_confederacionAux, confederacion) == 0 && selec_getId(selec_aux, &selec_idAux))
			{
				for(int j=0; j<ll_len(pArrayListJugador);j++){
					jug_aux = (Jugador*)ll_get(pArrayListJugador, j);
					if(jug_getIdSeleccion(jug_aux, &idSeleccion) && idSeleccion == selec_idAux)
					{
						ll_add(pArrayListConvocados, jug_aux);
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* Es la ruta del archivo
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lista de selecciones
 * \return int La funcion retorna 1 en caso de que se haya cargado los datos correctamente, caso contrario retorna 0
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	if(path != NULL && pArrayListSeleccion != NULL){
		FILE* sArchivo;
		sArchivo = fopen(path, "r");
		if(sArchivo != NULL && parser_SeleccionFromText(sArchivo, pArrayListSeleccion)){
			retorno = 1;
		}
		fclose(sArchivo);
	}
    return retorno;
}

/** \brief La funcion Agrega los datos de un jugador convocado
 *
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de jugadores
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lista de selecciones
 * \return int
 */
int controller_agregarConvocado(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int jug_indice;
	int selec_indice;
	int jug_idSeleccion;
	int idSeleccion;
	int convocados;
	int confirmar;

	Jugador* unJugador;
	Seleccion* unaSeleccion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do{
			if(jug_buscarPorId(pArrayListJugador, &jug_indice)){
				unJugador = (Jugador*)ll_get(pArrayListJugador, jug_indice);
				if(jug_getIdSeleccion(unJugador, &jug_idSeleccion) == 1 && jug_idSeleccion == 0)
				{
					do{
						if(controller_listarSelecciones(pArrayListSeleccion) && selec_buscarPorId(pArrayListSeleccion, &selec_indice))
						{
							unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, selec_indice);
							if(selec_getConvocados(unaSeleccion, &convocados) == 1 && convocados < 22)
							{
								convocados = convocados + 1;
								selec_setConvocados(unaSeleccion, convocados);
								selec_getId(unaSeleccion, &idSeleccion);
								jug_setIdSeleccion(unJugador, idSeleccion);
								retorno = 1;
								confirmar = 0;
							}else{
								printf("\nLA SELECCION ALCANZO EL MAXIMO DE JUGADORES CONVOCADOS\n");
								confirmar = confirmarFuncion("\n¿Quiere buscar otra seleccion? ('s' para Si 'n' para No) : ");
							}
						}
					}while(confirmar != 0);
				}else{
					printf("\nEL JUGADOR YA FUE CONVOCADO EN UNA SELECCION\n");
					confirmar = confirmarFuncion("\n¿Quiere buscar otro jugador? ('s' para Si 'n' para No) : ");
				}
			}
		}while(confirmar != 0);
	}
    return retorno;
}

/** \brief la funcion remueve los datos de un jugador convocado
 *
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lis ta de selecciones
 * \param pArrayListJugador LinkedList* Es el puntero a la lista de Jugadores
 * \return int la funcion retorna 0 en caso de error, caso contrario retorna 1
 */
int controller_removerConvocado(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int jug_indice;
	int jug_idSeleccion;

	int selecLen;
	int selecId;
	int convocados;

	Jugador* unJugador;
	Seleccion* auxSeleccion;

	selecLen = ll_len(pArrayListSeleccion);

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL && selecLen > 0)
	{
		if(jug_buscarPorId(pArrayListJugador, &jug_indice))
		{
			unJugador = (Jugador*)ll_get(pArrayListJugador, jug_indice);
			jug_getIdSeleccion(unJugador, &jug_idSeleccion);
			jug_setIdSeleccion(unJugador, 0);
			for(int i=0; i<selecLen; i++)
			{
				auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
				if(selec_getId(auxSeleccion, &selecId) && selecId == jug_idSeleccion)
				{
					selec_getConvocados(auxSeleccion, &convocados);
					convocados = convocados - 1;
					selec_setConvocados(auxSeleccion, convocados);
					retorno = 1;
					break;
				}
			}
		}

	}

    return retorno;
}


/** \brief la funcion imprime una lista de las selecciones
 *
 * \param pArrayListSeleccion LinkedList* Es el puntero a la lista de selecciones
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int cantidad;
	int isEmpty;
	Seleccion* auxSelec;

	isEmpty = ll_isEmpty(pArrayListSeleccion);
	cantidad = ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion != NULL && isEmpty != 1){
		printf( "\t+====+================================+================+============+\n"
				"\t| ID |              PAIS              | CONFEDERACION  | CONVOCADOS |\n"
				"\t+====+================================+================+============+\n");
		for(int i=0; i<cantidad; i++){
			auxSelec = (Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_printOneSeleccion(auxSelec);
		}
		printf( "\t+----+--------------------------------+----------------+------------+\n");
		retorno = 1;
	}

    return retorno;
}

/** \brief La funcion ordena selecciones por confederacion
 *
 * \param pArrayListSeleccion LinkedList* Es la lista de selecciones
 * \return int la funcion retorna 1 en caso de la lista se haya ordenado correctamente, caso contrario retorna 0
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	if(pArrayListSeleccion != NULL)
	{
		if(ll_sort(pArrayListSeleccion, selec_CompararPorConfederacion, 1) == 0)
		{
			printf("\n*** Lista ordenada ***\n");
			retorno = 1;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char* Es la ruta donde se guardara
 * \param pArrayListSeleccion LinkedList* Es la lista de selecciones
 * \return int la funcion retorna 1 en caso que se hayan guardado correctamente los datos, caso contrario retorna 0
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    int retorno = 0;
    if(path != NULL && pArrayListSeleccion != NULL){
    	FILE* selecArchivo = NULL;
    	selecArchivo = fopen(path, "w");
    	if(selecArchivo != NULL && parser_SeleccionToText(selecArchivo, pArrayListSeleccion)){
			retorno = 1;
    	}
		fclose(selecArchivo);
    }
    return retorno;
}


