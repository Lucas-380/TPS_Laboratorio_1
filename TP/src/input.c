#include "input.h"

int GetInt(char* mensaje, char* mensajeError, int minimo, int maximo){
	int retorno = 0;
	int bufferInt;
	do{
		printf("%s", mensaje);
		scanf("%d", &bufferInt);
		if(bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = bufferInt;
			break;
		}else{
			printf("%s", mensajeError);
			system("pause");
		}
	}while(retorno == 0);

	return retorno;
}

int getFloatPositivo(float* pResultado, char* mensaje, char* mensajeError, float minimo, int reintentos){
	int retorno = -1;
	float bufferInt;

	for(int i = 0; i <= reintentos; i++){
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
		{
			printf("%s", mensaje);
			scanf("%f", &bufferInt);
			if(bufferInt > minimo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				system("pause");
			}
		}
	}
	return retorno;
}

int CargarContador(int* contador, int condicionNumerica, char* mensajeError){
	int retorno;

	if(*contador < condicionNumerica){
		*contador = *contador+1;
		retorno = 0;
	}else{
		printf(mensajeError);
		system("pause");
		retorno = -1;
	}
	return retorno;
}

int CargarCosto(float* costoAcumulable, char* mensaje, char* mensajeError, int reintentos){
	int retorno = -1;
	int respuesta;
	float costo;
	respuesta = getFloatPositivo(&costo, mensaje, mensajeError, 0, reintentos);

	if(respuesta == 0){
		*costoAcumulable += costo;
		retorno = 0;
	}else{
		printf("\nSe acabaron los reintentos, ingrese los datos nuevamente. ");
		system("pause");
	}
	return retorno;
}
