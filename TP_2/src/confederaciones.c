
#include "confederaciones.h"

int buscarEspacioLibreConfederacion(eConfederacion* confederaciones, int len, int* pIndex){
    int retorno = 0;
    if(confederaciones != NULL && pIndex != NULL){
        *pIndex = -1;
        for(int i=0; i<len; i++){
            if(confederaciones[i].isEmpty){
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}

int buscarConfederacionPorId(eConfederacion* confederaciones, int len, int* indice){
	int retorno = -1;
	int idIngresado;
	utn_getNumero(&idIngresado, "\nIngrese el id de la confederacion: \n", "Error, ingrese un id disponible", 100, 105);
	if(confederaciones != NULL && len > 0 && indice != NULL){
		for(int i = 0 ; i < len ; i++){
			if(confederaciones[i].id == idIngresado){
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

void MostrarUnaConfederacion(eConfederacion confederacion){
    printf("\t| %-3d | %-8s | %-22s |     %-4d     |\n"
    		, confederacion.id, confederacion.nombre, confederacion.region, confederacion.anioCreacion);
}


int listarConfederaciones(eConfederacion* confederaciones, int len){
	int retorno = -1;
	if(confederaciones != NULL && len > 0){
		printf( "\t==========================================================\n"
				"\t| ID  |  NOMBRE  |         REGION         | AÑO CREACION |\n"
				"\t----------------------------------------------------------\n");
		for(int i = 0; i < len; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				MostrarUnaConfederacion(confederaciones[i]);
			}
		}
		retorno = 0;
		printf( "\t==========================================================\n");
	}
	return retorno;
}

int altaConfederacion(eConfederacion* confederacion, int len){
	int retorno = 0;
	int indice;
	int asignacionesCompletadas = 0;
	int condicion;

	if(confederacion != NULL && len > 0){
		printf("    *** Alta de Confederacion ***\n\n");
		buscarEspacioLibreConfederacion(confederacion, len, &indice);
		if(indice == -1){
			printf("No hay lugar en el sistema\n");
		}else{
			if(asignarId_confederacion(confederacion, indice)){
				asignacionesCompletadas++;
			}
			if(asignarNombre_confederacion(confederacion, indice)){
				asignacionesCompletadas++;
			}
			if(asignarRegion_confederacion(confederacion, indice)){
				asignacionesCompletadas++;
			}
			if(asignarAnioCreacion_confederacion(confederacion, indice)){
				asignacionesCompletadas++;
			}

			condicion = confirmarFuncion("Desea volver al menu principal? ('s' para si, 'n' para no)");

			if(asignacionesCompletadas == 7 && condicion == 1){
				confederacion[indice].isEmpty = OCUPADO;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int asignarId_confederacion(eConfederacion* confederacion, int indice){
	int retorno = 0;
	if(confederacion != NULL && indice > -1){
		if(indice == 0){
			confederacion[indice].id = 1;
		}else{
			confederacion[indice].id = (confederacion[indice-1].id)+1;
		}
		retorno = 1;
	}
	return retorno;
}


int asignarNombre_confederacion(eConfederacion* confederacion, int indice){
	int retorno = 0;
	char nombre[50];
	int retornoGetName;
	if(confederacion != NULL && indice > -1){
		retornoGetName = utn_getName(nombre, "Ingrese el Nombre de la confederacion: \n", "\nError, ingrese correctamente el Nombre\n", 50);
		if(retornoGetName == 0){
			strcpy(confederacion[indice].nombre, nombre);
			retorno = 1;
		}
	}
	return retorno;
}

int asignarRegion_confederacion(eConfederacion* confederacion, int indice){
	int retorno = 0;
	char region[50];
	int retornoGetName;
	if(confederacion != NULL && indice > -1){
		retornoGetName = utn_getName(region, "Ingrese la region de la confederacion: \n", "\nError, ingrese correctamente la region\n", 50);
		if(retornoGetName == 0){
			strcpy(confederacion[indice].region, region);
			retorno = 1;
		}
	}
	return retorno;
}

int asignarAnioCreacion_confederacion(eConfederacion* confederacion, int indice){
	int retorno = 0;
	int retornoGetShort;
	int anioCreacion;
	if(confederacion != NULL && indice > -1){
		retornoGetShort = utn_getNumero(&anioCreacion, "Ingrese el año de creacion de la confederacion: \n", "\nError, ingrese un año valido\n", 1800, 2022);
		if(retornoGetShort == 0){
			confederacion[indice].anioCreacion = anioCreacion;
			retorno = 1;
		}
	}
	return retorno;
}


int modificarConfederacion(eConfederacion* confederacion, int len){
	int retorno;
	int indice;
	int condicion;
	char mensajeExitoso[60] = "\n** La modificacion se realizo de manera correcta **\n";
	char mensajeError[60] = "\n** La modificacion no se pudo realizar **\n";

	retorno = 0;
	if(confederacion != NULL && len > 0){
		if(buscarConfederacionPorId(confederacion, len, &indice) == 0 && confederacion[indice].isEmpty == OCUPADO){
			printf("CONFEDERACION ENCONTRADA.\n");
			do{
				switch(utn_pedirOpcion("	Modificar datos del jugador\n\n"
						"1) Modificar Nombre\n"
						"2) Modificar Region\n"
						"3) Modificar Año de creacion\n"
						"4) Volver\n"
						"Ingrese una opcion: ", 1, 4)){
					case 1:
						if(asignarNombre_confederacion(confederacion, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 2:
						if(asignarRegion_confederacion(confederacion, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 3:
						if(asignarAnioCreacion_confederacion(confederacion, indice)){
							printf("%s", mensajeExitoso);
						}else{
							printf("%s", mensajeError);
						}
						break;
					case 4:
						condicion = 'n';
						break;
				}
				utn_getNumero(&condicion, "Desea seguir modificando datos? ('1' para si, '0' para no) ", "\nError\n", 0, 1);
			}while(condicion == 1);
			retorno = 1;
		}else{
			printf("No se encontro ninguna confederacion con el id ingresado\n");
		}
	}
	return retorno;
}


int bajaConfederacion(eConfederacion* confederacion, int len){
	int retorno = 0;
	int indice;
	listarConfederaciones(confederacion, len);
	if(buscarConfederacionPorId(confederacion, len, &indice) == 0){
		confederacion[indice].isEmpty = VACIO;
		retorno = 1;
	}else{
		printf("***ID no encontrada.***\n");
	}
	return retorno;
}
