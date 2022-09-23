/*
 ============================================================================
 Name        : TP.c
 Author      : Lucas Dure
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "input.h"
#include "calculos.h"
#define REINTENTOS 2
#define TOTAL_JUGADORES 22

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int respuesta;
	int errorAlCargar;
	//Costos
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	float costoMantenimientoBruto = 0;
	int opcionCostos;
	//Jugadores
	int opcionPosicion;
	int jugadoresCargados = 0;
	int arqueros = 0;
	int defensores = 0;
	int mediocampistas = 0;
	int delanteros = 0;
	int camiseta;
	//Confederacion
	int opcionConfederacion;
	int afc = 0;
	int caf = 0;
	int concacaf = 0;
	int conmebol = 0;
	int uefa = 0;
	int ofc = 0;
	//Variables de calculos
	float promedioAfc;
	float promedioCaf;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;
	float aumentoUefa;
	float costoMantenimientoFinal;
	int calculosCargados = 0;

	do{
		printf("\n\tMenu principal\n"
				"\n1. Ingreso de los costos de Mantenimiento"
				"\n Costo hospedaje -> %.2f$"
				"\n Costo de comida -> %.2f$"
				"\n Costo de transporte -> %.2f$"
				"\n2. Carga de jugadores"
				"\n Arqueros -> %d"
				"\n Defensores -> %d"
				"\n Mediocampistas -> %d"
				"\n Delanteros -> %d"
				"\n3. Realizar todos los calculos"
				"\n4. Informar todos los resultados"
				"\n5. Salir", costoHospedaje, costoComida, costoTransporte, arqueros, defensores, mediocampistas, delanteros);
		opcion = GetInt("\n\nSu opcion: ", "Opcion invalida intente nuevamente: ", 1, 5);

		switch(opcion){
			case 1:
				//Submenu para seleccionar los tipos de costo
				do{
					printf("\n\n\tElija el tipo de costo que desea ingresar\n"
							"\n1.Costo hospedaje -> %.2f$"
							"\n2.Costo de comida -> %.2f$"
							"\n3.Costo de transporte -> %.2f$"
							"\n4. Volver al menu principal", costoHospedaje, costoComida, costoTransporte);
					opcionCostos = GetInt("\n\nSu opcion: ", "Opcion invalida intente nuevamente: ", 1, 4);
					switch(opcionCostos){
						case 1:
							respuesta = CargarCosto(&costoHospedaje, "\n Ingrese el monto del costo de hospedaje: ", "El monto ingresado esta por debajo del minimo. Vuelva a intentar: ",REINTENTOS);
							if(respuesta != 0){
								printf("El costo no se ha podido cargar");
							}
							break;
						case 2:
							respuesta = CargarCosto(&costoComida, "\n Ingrese el monto del costo de comida: ", "El monto ingresado esta por debajo del minimo. Vuelva a intentar: ",REINTENTOS);
							if(respuesta != 0){
								printf("El costo no se ha podido cargar");
							}
							break;
						case 3:
							respuesta = CargarCosto(&costoTransporte, "\n Ingrese el monto del costo de transporte: ", "El monto ingresado esta por debajo del minimo. Vuelva a intentar: ",REINTENTOS);
							if(respuesta != 0){
								printf("El costo no se ha podido cargar");
							}
							break;
					}
				}while(opcionCostos != 4);
				break;

			case 2:
				//Ingreso de posicion - Verifico si los jugadores cargados no superan el número maximo de jugadores
				if(jugadoresCargados < TOTAL_JUGADORES){
					//Submenu para seleccionar la posicion del jugador
					do{
						printf("\n\n\t¿Que posicion del jugador quiere ingresar?\n"
								"\n1.Arquero"
								"\n2.Defensor"
								"\n3.Mediocampista"
								"\n4.Delantero");
						opcionPosicion = GetInt("\n\nSu opcion: ", "Opcion invalida intente nuevamente: ", 1, 4);
						switch(opcionPosicion){
							case 1:
								errorAlCargar = CargarContador(&arqueros, 2, "Esta posición ya esta completa");
								break;
							case 2:
								errorAlCargar = CargarContador(&defensores, 8, "Esta posición ya esta completa");
								break;
							case 3:
								errorAlCargar = CargarContador(&mediocampistas, 8, "Esta posición ya esta completa");
								break;
							case 4:
								errorAlCargar = CargarContador(&delanteros, 4, "Esta posición ya esta completa");
								break;
						}
					}while(errorAlCargar != 0);
					//Ingreso de nº de camiseta
					camiseta = GetInt("\n\nIngrese el numero de camiseta del jugador (no mayor a 99) : ", "Opcion invalida intente nuevamente\n", 1, 99);
					printf("la camiseta nº%d se ingreso correctamente\n", camiseta);
					system("pause");
					//Ingreso de la confederacion
					do{
						printf("\n\n\tIngrese la confederacion del jugador\n"
								"\n1.AFC -> %d"
								"\n2.CAF -> %d"
								"\n3.CONCACAF -> %d"
								"\n4.CONMEBOL -> %d"
								"\n5.UEFA -> %d"
								"\n6.OFC -> %d", afc, caf, concacaf, conmebol, uefa,ofc);
						opcionConfederacion = GetInt("\n\nSu opcion: ", "Opcion invalida intente nuevamente: ", 1, 6);
						switch(opcionConfederacion){
							case 1:
								errorAlCargar = CargarContador(&afc, TOTAL_JUGADORES, "Maximo de jugadores alcanzado");
								break;
							case 2:
								errorAlCargar = CargarContador(&caf, TOTAL_JUGADORES, "Maximo de jugadores alcanzado");
								break;
							case 3:
								errorAlCargar = CargarContador(&concacaf, TOTAL_JUGADORES, "Maximo de jugadores alcanzado");
								break;
							case 4:
								errorAlCargar = CargarContador(&conmebol, TOTAL_JUGADORES, "Maximo de jugadores alcanzado");
								break;
							case 5:
								errorAlCargar = CargarContador(&uefa, TOTAL_JUGADORES, "Maximo de jugadores alcanzado");
								break;
							case 6:
								errorAlCargar = CargarContador(&ofc, TOTAL_JUGADORES, "Maximo de jugadores alcanzado");
								break;
						}
					}while(errorAlCargar != 0);
				}else{
					printf("\n\tYa se cargaron todos los jugadores.\n");
					system("pause");
				}
				jugadoresCargados = afc + caf + concacaf + conmebol + uefa + ofc;
				break;

			case 3:
				//Realizo la condicion para que el usuario puede ingresar solo si cargo por lo menos a un jugador y que esten todos los costos cargados
				if(jugadoresCargados > 0 && costoHospedaje > 0 && costoComida > 0 && costoTransporte > 0){
					//Calcular el promedio de los jugadores de cada mercado
					promedioAfc = CalcularPromedio(afc, jugadoresCargados);
					promedioCaf = CalcularPromedio(caf, jugadoresCargados);
					promedioConcacaf = CalcularPromedio(concacaf, jugadoresCargados);
					promedioConmebol = CalcularPromedio(conmebol, jugadoresCargados);
					promedioUefa = CalcularPromedio(uefa, jugadoresCargados);
					promedioOfc = CalcularPromedio(ofc, jugadoresCargados);

					//Calcular el costo de mantenimiento
					costoMantenimientoBruto = costoHospedaje + costoComida + costoTransporte;

					//Si la Mayoria son de la confederacion europea el costo de mantenimiento aumenta un 35%
					if(promedioUefa > promedioAfc && promedioUefa > promedioCaf && promedioUefa > promedioConcacaf && promedioUefa > promedioConmebol && promedioUefa > promedioOfc){
						aumentoUefa = CalcularAumento(costoMantenimientoBruto, 35);
						costoMantenimientoFinal = costoMantenimientoBruto + aumentoUefa;
					}else{
						costoMantenimientoFinal = costoMantenimientoBruto;
					}

					calculosCargados = 1;
					printf("\tLos calculos se realizaron correctamente.\n");
					system("pause");
				}else{
					printf("\n\tDebe cargar todos los costos y por lo menos un jugadores para acceder esta opcion.\n\n");
					system("pause");
				}
				break;
			case 4:
				//Verifico que se hayan realizado los calculos para poder imprimirlos
				if(calculosCargados == 1){
					printf("\n\tInformar todos los Resultados\n"
							"Promedio Uefa %.2f\n"
							"Promedio Conmebol %.2f\n"
							"Promedio Concacaf %.2f\n"
							"Promedio Afc %.2f\n"
							"Promedio Ofc %.2f\n"
							"Promedio Caf %.2f\n",promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);

					//Depende si el costo tiene o no un aumento muestro un mensaje diferente
					if(costoMantenimientoFinal != costoMantenimientoBruto){
						printf("El costo de mantenimiento era de %.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n\n",
								costoMantenimientoBruto, aumentoUefa, costoMantenimientoFinal);
					}else{
						printf("El costo final de mantenimiento es: $%.2f\n\n", costoMantenimientoFinal);
					}

					calculosCargados = 0;
					system("pause");
				}else{
					printf("\n\tDebe realizar todos los calculos (opcion 3) para acceder a esta opcion.\n\n");
					system("pause");
				}
				break;
			case 5:
				printf("\tFinaliza el programa");
				break;
			default:
				printf("Opcion invalida");
				break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}








