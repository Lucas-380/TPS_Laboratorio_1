
#include "calculos.h"

int calcularSalariosTotal(eJugador* jugadores, int len, float *resultado){
	int retorno = 0;
	if(jugadores != NULL && len>0 && ComprobarEstadoJugadores(jugadores, len)){
		for(int i=0; i<len; i++){
			if(jugadores[i].isEmpty == OCUPADO){
				*resultado += jugadores[i].salario;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int promedioDeSalarios(eJugador* jugadores, int len, float* promedio){
	int retorno = 0;
	float totalDeSalarios = 0;
	int totalJugadores;
	if(jugadores != NULL && len>0 && ComprobarEstadoJugadores(jugadores, len)){
		totalJugadores = contadorDeJugadores(jugadores, len);
		if(calcularSalariosTotal(jugadores, len, &totalDeSalarios) && totalJugadores != 0){
			*promedio = totalDeSalarios / totalJugadores;
			retorno = 1;
		}
	}
	return retorno;
}

int salariosConMasDelPromedio(eJugador* jugadores, int len){
	float salarioPromedio;
	int contadorDeSalariosMayorAlPromedio = 0;
	if(jugadores != NULL && len>0 && ComprobarEstadoJugadores(jugadores, len)){
		promedioDeSalarios(jugadores, len, &salarioPromedio);
		for(int i=0; i<len; i++){
			if(jugadores[i].isEmpty == OCUPADO && jugadores[i].salario > salarioPromedio){
				contadorDeSalariosMayorAlPromedio++;
			}
		}
	}
	return contadorDeSalariosMayorAlPromedio;
}


int acumuladorDeAniosContrato(eJugador* jugadores, int len, int idConfederacion){
	int aniosDeContrato = 0;
	for(int i=0; i<len; i++){
		if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == idConfederacion){
			aniosDeContrato += jugadores[i].aniosContrato;
		}
	}
	return aniosDeContrato;
}

int CalcularMayorContrato(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion, int*aniosTotalesDeContrato, int*	idConMasAniosContrato){
	int retorno = 0;
	if(jugadores != NULL && lenJugador > 0 && confederaciones != NULL && lenConfederacion > 0 && aniosTotalesDeContrato != NULL && idConMasAniosContrato != NULL){
		int idConfederacion;
		int auxAniosDeContrato;

		for(int i=0; i<lenConfederacion; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				idConfederacion = confederaciones[i].id;
				auxAniosDeContrato = acumuladorDeAniosContrato(jugadores, lenJugador, idConfederacion);
				if(*aniosTotalesDeContrato < auxAniosDeContrato || i == 0){
					*aniosTotalesDeContrato = auxAniosDeContrato;
					*idConMasAniosContrato = idConfederacion;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

int contarJugadorPorConfederacion(eJugador* jugadores, int len, int idConfederacion){
	int retorno = 0;
	int contadorDeJugador = 0;
	if(jugadores != NULL && len > 0){
		for(int i=0; i<len; i++){
			if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == idConfederacion){
				contadorDeJugador++;
			}
		}
		retorno = contadorDeJugador;
	}
	return retorno;
}

float calcularPorcentajeJugadoresPorConfederacion(eConfederacion* confederaciones, int lenConfederacion, eJugador* jugadores, int lenJugador, int idConfederacion){
	float promedioConfederacion = 0;
	int jugadoresEnConfederacion;
	int jugadoresTotales;
	if(confederaciones != NULL && lenConfederacion > 0){
		if(confederaciones[idConfederacion].isEmpty == OCUPADO){
			jugadoresEnConfederacion = contarJugadorPorConfederacion(jugadores, lenJugador, idConfederacion);
			jugadoresTotales = contadorDeJugadores(jugadores, lenJugador);
			promedioConfederacion = (float)(jugadoresEnConfederacion*100)/jugadoresTotales;
		}
	}
	return promedioConfederacion;
}

int CalcularRegionConMasJugadores(eJugador* jugadores, int lenJugador, eConfederacion* confederaciones, int lenConfederacion, int*jugadoresPorConfederacion, int*	idRegionConMasJugadores){
	int retorno = 0;
	if(jugadores != NULL && lenJugador > 0 && confederaciones != NULL && lenConfederacion > 0 && jugadoresPorConfederacion != NULL && idRegionConMasJugadores != NULL){
		int idConfederacion;
		int auxJugadores;

		for(int i=0; i<lenConfederacion; i++){
			if(confederaciones[i].isEmpty == OCUPADO){
				idConfederacion = confederaciones[i].id;
				auxJugadores = contarJugadorPorConfederacion(jugadores, lenJugador, idConfederacion);
				if(*jugadoresPorConfederacion < auxJugadores || i == 0){
					*jugadoresPorConfederacion = auxJugadores;
					*idRegionConMasJugadores = idConfederacion;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

