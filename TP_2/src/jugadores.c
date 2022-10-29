
#include "jugadores.h"

int inicializarEstadosJugador(eJugador* jugadores, int len){
	int retorno = 0;
	if(jugadores != NULL && len > 0){
		for (int i = 0; i<len; i++) {
			jugadores[i].isEmpty = VACIO;
		}
		retorno = 1;
	}
	return retorno;
}

int buscarEspacioLibreJugador(eJugador* jugadores, int len, int* pIndex){
    int retorno = 0;
    if(jugadores != NULL && len > 0 && pIndex != NULL){
        *pIndex = -1;
        for(int i=0; i<len; i++){
            if(jugadores[i].isEmpty){
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}


int buscarJugadorPorId(eJugador* jugador, int len, int* indice){
	int retorno = -1;
	if(jugador != NULL && len > 0 && indice != NULL){
		int idIngresado;
		utn_getNumero(&idIngresado, "Ingrese el id del jugador: ", "\nError, ingrese un id valido\n", 1, len);
		if(jugador != NULL && len > 0 && indice != NULL){
			for(int i = 0 ; i < len ; i++){
				if(jugador[i].id == idIngresado){
					*indice = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int altaJugador(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederaciones, int idActual){
	int retorno = 0;
	int indice;
	int asignacionesCompletadas = 0;
	int confirmar;

	if(jugadores != NULL && lenJugador > 0){
		printf("    *** Alta de Jugador ***\n\n");
		buscarEspacioLibreJugador(jugadores, lenJugador, &indice);
		if(indice == -1){
			printf("No hay lugar en el sistema\n");
		}else{
			if(asignarNombre(jugadores, indice)){
				asignacionesCompletadas++;
			}
			if(asignarPosicion(jugadores, indice)){
				asignacionesCompletadas++;
			}
			if(asignarNumeroCamiseta(jugadores, indice)){
				asignacionesCompletadas++;
			}
			if(asignarConfederacion(jugadores, indice, confederaciones, lenConfederaciones)){
				asignacionesCompletadas++;
			}
			if(asignarSalario(jugadores, indice)){
				asignacionesCompletadas++;
			}
			if(asignarAniosContrato(jugadores, indice)){
				asignacionesCompletadas++;
			}

			confirmar = confirmarFuncion("Esta seguro de cargar estos datos ('s' para si, 'n' para no) ");

			if(asignacionesCompletadas == 6 && confirmar == 1){
				asignarId(jugadores, indice, idActual);
				jugadores[indice].isEmpty = OCUPADO;
				retorno = 1;
			}
		}
	}
	return retorno;
}


int asignarId(eJugador* jugadores, int indice, int idActual){
	int retorno = 0;
	if(jugadores != NULL && indice > -1 && idActual > 0){
		jugadores[indice].id = idActual;
		retorno = 1;
	}
	return retorno;
}


int asignarNombre(eJugador* jugadores, int indice){
	int retorno = 0;
	char nombre[50];
	int retornoGetName;
	if(jugadores != NULL && indice > -1){
		retornoGetName = utn_getName(nombre, "Ingrese el Nombre del Jugador: \n", "\nError, ingrese correctamente el Nombre\n", 50);
		if(retornoGetName == 0){
			strcpy(jugadores[indice].nombre, nombre);
			retorno = 1;
		}
	}
	return retorno;
}

int asignarPosicion(eJugador* jugadores, int indice){
	int retorno = 0;
	char posicion[50];
	int retornoGetName;
	if(jugadores != NULL && indice > -1){
		do{
			retornoGetName = utn_getName(posicion, "\tPosiciones\n-Delantero\n-Defensor\n-Mediocampista\n-Arquero\nIngrese la posicion del Jugador: \n", "\nError, ingrese una posicion correcta\n", 50);
		}while(validarPosicion(posicion) != 1);
		if(retornoGetName == 0){
			strcpy(jugadores[indice].posicion, posicion);
			retorno = 1;
		}
	}
	return retorno;
}

int validarPosicion(char posicion[]){
	int retorno = 0;
	if(posicion != NULL){
		int delantero = strcmp(posicion, "Delantero");
		int defensor = strcmp(posicion, "Defensor");
		int arquero = strcmp(posicion, "Arquero");
		int mediocampista = strcmp(posicion, "Mediocampista");
		if(delantero == 0 || defensor == 0|| arquero == 0 || mediocampista == 0){
			retorno = 1;
		}else{
			printf("Ingrese una posicion valida\n");
		}
	}
	return retorno;
}

int asignarNumeroCamiseta(eJugador* jugadores, int indice){
	int retorno = 0;
	int retornoGetShort;
	short numeroCamiseta;
	if(jugadores != NULL && indice > -1){
		retornoGetShort = utn_getShort(&numeroCamiseta, "\nIngrese el numero de camiseta del jugador\n", "\n*** El numero de camiseta es valido ***\n", 1, 32767);
		if(retornoGetShort == 0){
			jugadores[indice].numeroCamiseta = numeroCamiseta;
			retorno = 1;
		}
	}
	return retorno;
}

int asignarConfederacion(eJugador* jugadores, int indice, eConfederacion* confederaciones, int lenConfederaciones){
	int retorno = 0;
	int indiceConfederacion;
	if(confederaciones != NULL && lenConfederaciones > 0 && jugadores != NULL && indice > -1){
		while(retorno == 0 && listarConfederaciones(confederaciones, lenConfederaciones) == 0){
			if(buscarConfederacionPorId(confederaciones, lenConfederaciones, &indiceConfederacion) == 0){
				jugadores[indice].idConfederacion = confederaciones[indiceConfederacion].id;
				printf("*** El jugador se asigno a la confederacion |%s| correctamente.***\n", confederaciones[indiceConfederacion].nombre);
				retorno = 1;
			}else{
				printf("*** Rol no se encunetra en el sistema - Vuelva a intentar ***\n");
			}
		}
	}
	return retorno;
}

int asignarSalario(eJugador* jugadores, int indice){
	int retorno = 0;
	float salario;
	int retornoGetFloat;
	if(jugadores != NULL && indice > -1){
		retornoGetFloat = utn_getFloat(&salario, "Ingrese el Salario del Jugador:\n", "Error, ingrese correctamente el Salario\n", 1, 99999999);
		if(retornoGetFloat == 0){
			jugadores[indice].salario = salario;
			retorno = 1;
		}
	}
	return retorno;
}

int asignarAniosContrato(eJugador* jugadores, int indice){
	int retorno = 0;
	int retornoGetShort;
	short aniosContrato;
	if(jugadores != NULL && indice > -1){
		retornoGetShort = utn_getShort(&aniosContrato, "\nIngrese los años de contrato del jugador\n", "\nIngrese un numero valido\n", 1, 30);
		if(retornoGetShort == 0){
			jugadores[indice].aniosContrato = aniosContrato;
			retorno = 1;
		}
	}
	return retorno;
}

int modificarJugador(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion){
	int retorno;
	int indice;
	int condicion;
	char mensajeExitoso[60] = "\n** La modificacion se realizo de manera correcta **\n";
	char mensajeError[60] = "\n** La modificacion no se pudo realizar **\n";

	retorno = 0;
	if(jugadores != NULL && lenJugador > 0 && confederaciones != NULL && lenConfederacion > 0){
		if(buscarJugadorPorId(jugadores, lenJugador, &indice) == 0 && jugadores[indice].isEmpty == OCUPADO){
			printf("Jugador encontrado.\n");
			do{
				switch(utn_pedirOpcion("	Modificar datos del jugador\n\n"
						"1) Modificar Nombre\n"
						"2) Modificar Posicion\n"
						"3) Modificar Numero de camiseta\n"
						"4) Modificar Confederacion\n"
						"5) Modificar Salario\n"
						"6) Modificar Años de contrato\n"
						"7) Volver\n"
						"Ingrese una opcion: ", 1, 8)){
					case 1:
						if(asignarNombre(jugadores, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 2:
						if(asignarPosicion(jugadores, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 3:
						if(asignarNumeroCamiseta(jugadores, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 4:
						if(asignarConfederacion(jugadores, indice, confederaciones, lenConfederacion)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 5:
						if(asignarSalario(jugadores, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 6:
						if(asignarAniosContrato(jugadores, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 7:
						condicion = 0;
						break;
				}
				condicion = confirmarFuncion("Desea volver al menu principal? ('s' para si, 'n' para no)");

			}while(condicion == 0);
			retorno = 1;
		}else{
			printf("No se encontro al Jugador\n");
		}
	}
	return retorno;
}

int bajaJugador(eJugador* jugadores, int lenJugadores, eConfederacion* confederacion, int lenConfederacion){
	int retorno = 0;
	int indice;
	if(jugadores != NULL && confederacion != NULL && lenJugadores > 0 && lenConfederacion > 0){
		listarJugadores(jugadores, lenJugadores, confederacion, lenConfederacion);
		if(buscarJugadorPorId(jugadores, lenJugadores, &indice) == 0 && jugadores[indice].isEmpty == OCUPADO){
			jugadores[indice].isEmpty = VACIO;
			printf("***BAJA COMPLETADA***\n");
			retorno = 1;
		}else{
			printf("***ID no encontrada.***\n");
		}
	}
	return retorno;
}


void MostrarUnJugador(eJugador jugadores, eConfederacion* confederacion, int lenConfederacion){
	for(int i=0; i<lenConfederacion; i++){
		if(confederacion[i].id == jugadores.idConfederacion){
			printf("\t| %-4d | %-25s | %-13s |     %-3d     | %-12.2f | %-8s\t|  \t%-10d |\n"
					, jugadores.id, jugadores.nombre, jugadores.posicion, jugadores.numeroCamiseta, jugadores.salario, confederacion[i].nombre, jugadores.aniosContrato);
		}
	}
}

int listarJugadores(eJugador* jugadores, int lenJugador, eConfederacion* confederacion, int lenConfederacion){
	int retorno = -1;
	if(jugadores != NULL && lenJugador > 0){
		printf( "\t====================================================================================================================\n"
				"\t|  ID  |          NOMBRE           |   POSICION    | Nº CAMISETA | SUELDO       | CONFEDERACION | AÑOS de CONTRATO |\n"
				"\t--------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < lenJugador; i++ ){
			if(jugadores[i].isEmpty == OCUPADO){
				MostrarUnJugador(jugadores[i], confederacion, lenConfederacion);
			}
		}
		printf( "\t====================================================================================================================\n");
		retorno = 0;
	}
	return retorno;
}

int ComprobarEstadoJugadores(eJugador* jugadores, int len){
	int retorno = 0;
	if(jugadores != NULL && len > 0){
		for(int i=0; i<len; i++){
			if(jugadores[i].isEmpty == OCUPADO){
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int contadorDeJugadores(eJugador* jugadores, int len){
	int cantidadDeJugadores = 0;
	if(jugadores != NULL && len > 0){
		for(int i=0; i<len; i++){
			if(jugadores[i].isEmpty == OCUPADO){
				cantidadDeJugadores++;
			}
		}
	}
	return cantidadDeJugadores;
}


