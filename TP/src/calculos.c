#include "calculos.h"
#include "input.h"

float CalcularPromedio(int sumaDeNumeros, int cantidadDeNumeros){
	float aux;
	if(sumaDeNumeros != 0){
		aux = (float)sumaDeNumeros / cantidadDeNumeros;
	}else{
		aux = 0;
	}
	return aux;
}

float CalcularAumento(float montoBruto, float aumento){
	float retorno;
	float aux;
	aux = aumento*montoBruto;
	retorno = aux/100;
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
