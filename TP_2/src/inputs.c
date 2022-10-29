

#include "inputs.h"

int utn_pedirOpcion(char menu[], int min, int max){
	int opcion = -1;
	do{
		printf("%s", menu);
		getInt(&opcion);
	}while(opcion < min || opcion > max);

	return opcion;
}

int myGets(char* cadena, int longitud){
	int retorno = -1;
	if (cadena != NULL && longitud > 0){
		fflush(stdin);
		fgets(cadena, longitud, stdin);
		if (cadena[strlen(cadena) - 1] == '\n'){
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int esNumerica(char* cadena){
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0){
		while (cadena[i] != '\0'){
			if (isalpha(cadena[i]) != 0){
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getInt(int* pResultado){
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int getShort(short* pResultado){
	int retorno = -1;
	char buffer[8];
	int numero = 0;
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
			numero = atoi(buffer);
			if(numero > -32769 && numero < 32768){
				*pResultado = atoi(buffer);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int getFloat(float *pResultado){
	int retorno = -1;
	char buffer[4096];
	if (pResultado != NULL){
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo){
	int retorno = -1;
	float buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo){
		do{
			printf(mensaje);
			if(getFloat(&buffer) == 0 && buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
		}while(retorno != 0);
	}
	return retorno;
}

int utn_getShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo){
	int retorno = -1;
	short buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo){
		do{
			printf(mensaje);
			if(getShort(&buffer) == 0 && buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
		}while(retorno != 0);
	}
	return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo){
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo){
		do{
			printf(mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
		}while(retorno != 0);
	}
	return retorno;
}

int utn_getName(char* cadena, char* mensaje, char* mensajeError, int len){
	int retorno = -1;
	if(cadena != NULL && strlen(cadena) < len){
		do{
			printf(mensaje);
			fflush(stdin);
			gets(cadena);
			for (int i = 0; i < strlen(cadena); i++){
				if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0){
					retorno = -1;
					printf(mensajeError);
					break;
				}
				retorno = 0;
			}
		}while(retorno != 0);
	}
	utn_corregirMayus(cadena);
	return retorno;
}

void utn_corregirMayus(char* cadena){
	strlwr(cadena);
	cadena[0] = toupper(cadena[0]);
	for(int i = 0; i < strlen(cadena); i++){
		if (cadena[i] == ' '){
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}

int confirmarFuncion(char* mensaje){
	char letra;
	do{
		printf("%s", mensaje);
		fflush(stdin);
		letra=toupper(getchar());
	}while(!((letra=='S')||(letra=='N')));
	return (letra=='S');
}
