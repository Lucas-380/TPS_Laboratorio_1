
#define LEN_JUGADORES 3000
#define LEN_CONFEDERACIONES 6

#include "inputs.h"
#include "jugadores.h"
#include "confederaciones.h"
#include "informes.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int idActual = 1;

	eJugador jugadores[LEN_JUGADORES];
	inicializarEstadosJugador(jugadores, LEN_JUGADORES);

	eConfederacion confederaciones[LEN_CONFEDERACIONES] = {
			{100, "CONMEBOL", "SUDAMERICA", 1916, 0},
			{101, "UEFA", "EUROPA", 1954, 0},
			{102, "AFC", "ASIA", 1954, 0},
			{103, "CAF", "AFRICA", 1957, 0},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, 0},
			{105, "OFC", "OCEANIA", 1966, 0}
	};

	do{
		switch(utn_pedirOpcion("\n\t*** Administracion de jugadores ***\n\n1) ALTA DE JUGADOR\n2) BAJA DE JUGADOR\n3) MODIFICACION DE JUGADOR\n4) INFORMES\n5) SALIR\n\nIngrese una opcion: ", 1, 5)){
			case 1:
				if(altaJugador(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES, idActual)){
					printf("\n	*** Carga de JUGADOR completa ***\n");
					idActual++;
				}else{
					printf("\nNo se pudo cargar el Jugador\n");
				}
				break;
			case 2:
				if(ComprobarEstadoJugadores(jugadores, LEN_JUGADORES)){
					bajaJugador(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES);
				}else{
					printf("\n\t** Para acceder a esta opcion debe cargar al menos 1 jugador **\n");
				}
				break;
			case 3:
				if(ComprobarEstadoJugadores(jugadores, LEN_JUGADORES)){
					modificarJugador(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES);
				}else{
					printf("\n\t** Para acceder a esta opcion debe cargar al menos 1 jugador **\n");
				}
				break;
			case 4:
				switch(utn_pedirOpcion("\t\nINFORMES: \n"
							"1-Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n"
							"2-Listado de confederaciones con sus jugadores.\n"
							"3-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n"
							"4-Informar la confederación con mayor cantidad de años de contratos total.\n"
							"5-Informar porcentaje de jugadores por cada confederación.\n"
							"6-Informar cual es la región con más jugadores y el listado de los mismos.\n"
							"7-Volver al menu principal.\n"
							"\nIngrese su opcion: ", 1, 7)){
						case 1:
							if(!jugadores_listarAlfabeticamentePorConfederacion(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES)){
								printf("\n\t  ** ERROR, primero cargue algun jugador **\n");
							}
							break;
						case 2:
							if(!confederacion_listarConSusJugadores(confederaciones, LEN_CONFEDERACIONES, jugadores, LEN_JUGADORES)){
								printf("\n\t  ** ERROR, primero cargue algun jugador **\n");
							}
							break;
						case 3:
							if(!ImprimirInformeDeSalarios(jugadores, LEN_JUGADORES)){
								printf("\n\t ** ERROR, primero cargue algun jugador **\n");
							}
							break;
						case 4:
							if(!imprimirInformeDeAniosContrato(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES)){
								printf("\n\t ** ERROR, primero cargue algun jugador **\n");
							}
							break;
						case 5:
							if(!imprimirPorcentajePorConfederacion(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES)){
								printf("\n\t ** ERROR, primero cargue algun jugador **\n");
							}
							break;
						case 6:
							if(!imprimirLaRegionConMasJugadores(jugadores, LEN_JUGADORES, confederaciones, LEN_CONFEDERACIONES)){
								printf("\n\t ** ERROR, primero cargue algun jugador **\n");
							}
							break;
						case 7:
							printf("\n** Volviendo al menú principal **\n");
							break;
					}
				break;
			case 5:
				printf("Finaliza el programa");
				opcion = -1;
				break;
			}
	}while(opcion != -1);
}

