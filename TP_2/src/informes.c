
#include "informes.h"

void confederacion_OrdenarAlfabeticamente(eConfederacion* confederaciones, int len){
    if(confederaciones !=NULL && len > 0){
    	for(int i=0; i<len-1; i++){
    		for(int j=i+1; j<len; j++){
    			if(strcmp(confederaciones[i].nombre, confederaciones[j].nombre) > 0 ){
    				confederacion_intercambiarPosicion(confederaciones, i, j);
				}
			}
		}

	}
}

void confederacion_intercambiarPosicion(eConfederacion* confederaciones, int posicionA, int posicionB){
	eConfederacion auxConfederacion;
	auxConfederacion=confederaciones[posicionA];
	confederaciones[posicionA]=confederaciones[posicionB];
	confederaciones[posicionB]=auxConfederacion;
}

void jugadores_OrdenarAlfabeticamente(eJugador* jugadores, int len){
    if(jugadores !=NULL && len > 0){
    	for(int i=0; i<len-1; i++){
    		for(int j=i+1; j<len; j++){
    			if(strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0 ){
    				jugadores_intercambiarPosicion(jugadores, i, j);
				}
			}
		}

	}
}

void jugadores_intercambiarPosicion(eJugador* jugadores, int posicionA, int posicionB){
	eJugador auxJugador;
	auxJugador=jugadores[posicionA];
	jugadores[posicionA]=jugadores[posicionB];
	jugadores[posicionB]=auxJugador;
}


int jugadores_listarAlfabeticamentePorConfederacion(eJugador* jugadores, int lenJugador, eConfederacion* confederacion, int lenConfederacion){
	int retorno = 0;
	if(jugadores != NULL && lenJugador > 0 && confederacion != NULL && lenConfederacion > 0 && ComprobarEstadoJugadores(jugadores, lenJugador)){
		jugadores_OrdenarAlfabeticamente(jugadores, lenJugador);
		confederacion_OrdenarAlfabeticamente(confederacion, lenConfederacion);
		printf( "\t====================================================================================================================\n"
				"\t|  ID  |          NOMBRE           |   POSICION    | Nº CAMISETA | SUELDO       | CONFEDERACION | AÑOS de CONTRATO |\n"
				"\t--------------------------------------------------------------------------------------------------------------------\n");
		for(int j = 0; j < lenConfederacion; j++ ){
			for(int i = 0; i < lenJugador; i++ ){
				if(jugadores[i].idConfederacion == confederacion[j].id && jugadores[i].isEmpty == OCUPADO){
					MostrarUnJugador(jugadores[i], confederacion, lenConfederacion);
				}
			}
		}
		printf( "\t====================================================================================================================\n");
		retorno = 1;
	}
	return retorno;
}

int confederacion_listarConSusJugadores(eConfederacion* confederaciones, int lenConfederaciones, eJugador* jugadores, int lenJugador){
	int i;
	int retorno = 0;
	int jugadorCargado;
	if(confederaciones != NULL && lenConfederaciones > 0 && jugadores != NULL && lenJugador > 0 && ComprobarEstadoJugadores(jugadores, lenJugador)){
		for(i=0; i < lenConfederaciones; i++ ){
			jugadorCargado = 0;
			if(confederaciones[i].isEmpty == OCUPADO){
				printf( "\t\t\t\t\t==========================================================\n"
						"\t\t\t\t\t| ID  |  NOMBRE  |         REGION         | AÑO CREACION |\n"
						"\t\t\t\t\t----------------------------------------------------------\n"
						"\t\t\t\t");
				MostrarUnaConfederacion(confederaciones[i]);
				printf( "\t====================================================================================================================\n"
						"\t|  ID  |          NOMBRE           |   POSICION    | Nº CAMISETA | SUELDO       | CONFEDERACION | AÑOS de CONTRATO |\n"
						"\t--------------------------------------------------------------------------------------------------------------------\n");
				for(int j = 0; j < lenJugador; j++){
					if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederaciones[i].id){
						MostrarUnJugador(jugadores[j], confederaciones, lenConfederaciones);
						jugadorCargado = 1;
					}
				}
			}
			if(jugadorCargado == 0){
				printf("\t|                                *** NO HAY NINGUN JUGADOR EN ESTA CONFEDERACION ***                               |\n");
			}
			printf("\t--------------------------------------------------------------------------------------------------------------------\n\n\n\n");
		}
		retorno=1;
	}
	return retorno;
}

int ImprimirInformeDeSalarios(eJugador* jugadores, int len){
	int retorno = 0;
	float totalDeSalarios = 0;
	float promedio;
	int salariosMayorAlPromedio;
	if(jugadores != NULL && len>0){
		if(calcularSalariosTotal(jugadores, len, &totalDeSalarios) && promedioDeSalarios(jugadores, len, &promedio))
		{
			salariosMayorAlPromedio = salariosConMasDelPromedio(jugadores, len);
			printf(	"\n\tTOTAL DE LOS SALARIOS => %.2f\n"
					"\n\tPROMEDIO DE SALARIOS => %.2f\n"
					"\n\tCANTIDAD DE JUGADORES CON UN SALARIO MAYOR AL PROMEDIO => %d\n",
					totalDeSalarios, promedio, salariosMayorAlPromedio);
			retorno = 1;
		}
	}
	else{
		printf("\nError en los parametros de la funcion\n");
	}
	return retorno;
}


int imprimirInformeDeAniosContrato(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion){
	int retorno = 0;
	int aniosTotalesDeContrato;
	int idConMasAniosContrato;
	if(jugadores != NULL && lenJugador > 0 && confederaciones != NULL && lenConfederacion > 0){
		if(CalcularMayorContrato(jugadores, lenJugador, confederaciones, lenConfederacion, &aniosTotalesDeContrato, &idConMasAniosContrato)){
			for(int i=0; i<lenConfederacion; i++){
				if(confederaciones[i].id == idConMasAniosContrato && aniosTotalesDeContrato != 0){
					printf( "\n\t*** La Confederacion con mayor cantidad de años de contratos total ***\n"
							  "\t+-----------------------------+--------------------------------------+\n"
							  "\t|        CONFEDERACION        |             AÑOS TOTALES             |\n"
							  "\t+--------------------------------------------------------------------+\n"
							  "\t| %-27s | %-36d |\n"
							  "\t+-----------------------------+--------------------------------------+\n", confederaciones[i].nombre, aniosTotalesDeContrato);
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

//informe 5

int imprimirPorcentajePorConfederacion(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion){
	int retorno = 0;
	float porcentaje;
	int idConfederacion;
	if(jugadores != NULL && lenJugador > 0 && confederaciones != NULL && lenConfederacion > 0 && ComprobarEstadoJugadores(jugadores, lenJugador)){
		printf("\n\t+------------+---------------+\n"
				 "\t| PORCENTAJE | CONFEDERACION |\n"
				 "\t+------------+---------------+\n");
		for(int i=0; i<lenConfederacion; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				idConfederacion = confederaciones[i].id;
				porcentaje = calcularPorcentajeJugadoresPorConfederacion(confederaciones, lenConfederacion, jugadores, lenJugador, idConfederacion);
				if(porcentaje != 0){
					printf(	 "\t|   %-5.2f    | %-13s |\n"
							 "\t+------------+---------------+\n", porcentaje, confederaciones[i].nombre);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

//informe 6

int imprimirLaRegionConMasJugadores(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion){
	int retorno = 0;
	int jugadoresPorConfederacion;
	int idRegionConMasJugadores;
	if(jugadores != NULL && lenJugador > 0 && confederaciones != NULL && lenConfederacion > 0){
		if(CalcularRegionConMasJugadores(jugadores, lenJugador, confederaciones, lenConfederacion, &jugadoresPorConfederacion, &idRegionConMasJugadores)){
			for(int i=0; i<lenConfederacion; i++){
				if(confederaciones[i].id == idRegionConMasJugadores && jugadoresPorConfederacion > 0){
					printf("\n\t*** La región con más jugadores ***\n\n"
							"\t+==================================================================================================================+\n"
							"\t|                                            %-70s|\n"
							"\t+------------------------------------------------------------------------------------------------------------------+\n"
							"\t|  ID  |          NOMBRE           |   POSICION    | Nº CAMISETA | SUELDO       | CONFEDERACION | AÑOS de CONTRATO |\n"
							"\t--------------------------------------------------------------------------------------------------------------------\n",
							confederaciones[i].region);
					for(int i = 0; i < lenJugador; i++ ){
						if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == idRegionConMasJugadores){
							MostrarUnJugador(jugadores[i], confederaciones, lenConfederacion);
						}
					}
					printf("\t+==================================================================================================================+\n");
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}


