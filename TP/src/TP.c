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

int main(void) {
	setbuf(stdout,NULL);

	int i = 0;
	int opcion;
	int costoHospedaje = 0;
	int costoComida = 0;
	int costoTransporte = 0;
	int costoMantenimiento = 0;
	//Jugadores
	int arqueros = 1;
	int defensores = 2;
	int mediocampistas = 3;
	int delanteros = 4;

	do{
		printf("\n\n\tMenu principal\n");
		printf("\n1. Ingreso de los costos de Mantenimiento");
		printf("\n Costo hospedaje -> %d$", costoHospedaje);
		printf("\n Costo de comida -> %d$", costoComida);
		printf("\n Costo de transporte %d$", costoTransporte);
		printf("\n2. Carga de jugadores");
		printf("\n Arqueros -> %d", arqueros);
		printf("\n Defensores -> %d", defensores);
		printf("\n Mediocampistas -> %d", mediocampistas);
		printf("\n Delanteros -> %d", delanteros);
		printf("\n3. Realizar todos los calculos");
		printf("\n4. Informar todos los resultados");
		printf("\n5. Salir");
		opcion = PedirEntero("\nSu opcion: ");

		switch(opcion){
			case 1:
				for(int i = 0; i<3; i++){
					int opcionCostos;
					int valorCosto;

					printf("\n\n\tElija el tipo de costo que desea ingresar");
					printf("\n1.Costo hospedaje");
					printf("\n2.Costo de comida");
					printf("\n3.Costo de transporte");
					opcionCostos = PedirEntero("\nSu opcion: ");
					//Actualizo el mantenimiento cada vez que ingresa un valor a cualquier tipo de costo.
					//costoMantenimiento+=valorCosto;
						switch(opcionCostos){
							case 1:
								printf("OPCION 1");
								costoHospedaje += PedirEntero("\n Ingrese el monto del costo: ");
								break;
							case 2:
								printf("OPCION 2");
								costoComida+= PedirEntero("\n Ingrese el monto del costo: ");
								break;
							case 3:
								printf("OPCION 3");
								costoTransporte+= PedirEntero("\n Ingrese el monto del costo: ");
								break;
							default:
								printf("OPCION INVALIDA");
								i--;
								break;
						}

				}
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
				printf("Finaliza el programa");
				opcion = 5;
				break;
			default:
				printf("Opcion invalida");
				break;
		}

		i++;
	}while(i<23 && opcion != 5);//Sumar la opcion de salir.



	return EXIT_SUCCESS;
}








