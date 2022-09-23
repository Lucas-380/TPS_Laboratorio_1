#include "calculos.h"

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

