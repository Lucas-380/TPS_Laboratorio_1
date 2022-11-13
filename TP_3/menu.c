#include "menu.h"

/**
 * @brief La funcion imprime un menu y pide una opcion al jugador
 *
 * @param opcion es donde se guardara la opcion seleccionada del usuario
 * @return la funcion retorna 1 en caso de que la operacion se haya realizado de manera correcta, caso contrario retorna 0
 */
int menu_principal(int* opcion)
{
    int retorno = 0;

    printf(	"\n\n\t+=======================================================================+\n"
    			"\t|              ***    Administracion de Jugadores    ***                |\n"
    			"\t+=======================================================================+\n"
    			"\t|  1) Cargar los archivos de csv de jugadores y selecciones             |\n"
    			"\t|  2) Alta de Jugador                                                   |\n"
    			"\t|  3) Modificacion de Jugador                                           |\n"
    			"\t|  4) Baja de Jugador                                                   |\n"
    			"\t|  5) Listados                                                          |\n"
    			"\t|  6) Convocar Jugadores                                                |\n"
    			"\t|  7) Ordenar y listar                                                  |\n"
    			"\t|  8) Generar un archivo binario de los jugadores ingresados            |\n"
    			"\t|  9) Cargar archivo binario de los jugadores ingresados                |\n"
    			"\t| 10) Guardar Archivos                                                  |\n"
    			"\t| 11) Salir                                                             |\n"
    			"\t+-----------------------------------------------------------------------+\n\n");

    if(utn_getNumero(opcion, "Elija una opcion: ", "\nError - Elija una opcion valida\n", 1, 11) == 0){
		retorno = 1;
    }

    return retorno;
}

/**
 * @brief  La funcion imprime un menu y pide una opcion al jugador
 *
 * @return Retorna la opcion seleccionado por el usuario
 */
int menu_editarJugador(void)
{
    int retorno = 0;

    printf(	"\n\n\t+========================================+\n"
    			"\t|      ***    Editar Jugador    ***      |\n"
    			"\t+========================================+\n"
    			"\t|  1) Editar Nombre del jugador          |\n"
    			"\t|  2) Editar Edad del jugador            |\n"
    			"\t|  3) Editar Posicion del jugador        |\n"
    			"\t|  4) Editar Nacionalidad del jugador    |\n"
    			"\t|  5) Salir                              |\n"
    			"\t+----------------------------------------+\n\n");

    utn_getNumero(&retorno, "Elija una opcion: ", "Error - Elija una opcion valida", 1, 5);

    return retorno;
}

/**
 * @brief  La funcion imprime un menu y pide una opcion al jugador
 *
 * @return Retorna la opcion seleccionado por el usuario
 */
int menu_Listados(void)
{
    int retorno = 0;

    printf(	"\n\n\t+========================================+\n"
    			"\t|         ***    Listados    ***         |\n"
    			"\t+========================================+\n"
    			"\t|  1) Todos los jugadores                |\n"
    			"\t|  2) Todas las selecciones              |\n"
    			"\t|  3) Jugadores convocados               |\n"
    			"\t|  4) Volver al menu principal           |\n"
    			"\t+----------------------------------------+\n\n");

    utn_getNumero(&retorno, "Elija una opcion: ", "Error - Elija una opcion valida", 1, 3);

    return retorno;
}

/**
 * @brief  La funcion imprime un menu y pide una opcion al jugador
 *
 * @return Retorna la opcion seleccionado por el usuario
 */
int menu_convocarJugadores(void)
{
    int retorno = 0;

    printf(	"\n\n\t+========================================+\n"
    			"\t|    ***    Convocar Jugadores    ***    |\n"
    			"\t+========================================+\n"
    			"\t|  1) Convocar Jugador                   |\n"
    			"\t|  2) Quitar Jugador de la Seleccion     |\n"
    			"\t|  3) Volver al menu principal           |\n"
    			"\t+----------------------------------------+\n\n");

    utn_getNumero(&retorno, "Elija una opcion: ", "Error - Elija una opcion valida", 1, 3);

    return retorno;
}

/**
 * @brief  La funcion imprime un menu y pide una opcion al jugador
 *
 * @return Retorna la opcion seleccionado por el usuario
 */
int menu_OrdenarYlistar(void)
{
    int retorno = 0;

    printf(	"\n\n\t+========================================+\n"
    			"\t|     ***    Ordenar y Listar    ***     |\n"
    			"\t+========================================+\n"
    			"\t|  1) Jugadores por nacionalidad         |\n"
    			"\t|  2) Selecciones por confederación      |\n"
    			"\t|  3) Jugadores por edad                 |\n"
				"\t|  4) Jugadores por nombre               |\n"
				"\t|  5) Volver al menu principal           |\n"
    			"\t+----------------------------------------+\n\n");

    utn_getNumero(&retorno, "Elija una opcion: ", "Error - Elija una opcion valida", 1, 5);

    return retorno;
}

/**
 * @brief  La funcion imprime un menu y pide una opcion al jugador
 *
 * @return Retorna la opcion seleccionado por el usuario
 */
int menu_GenerarArchivoBinario(void)
{
    int retorno = 0;

    printf(	"\n\n\t+========================================+\n"
    			"\t|    ***  Generar archivo binario  ***   |\n"
    			"\t+========================================+\n"
    			"\t|  1) Guardar lista convocados AFC       |\n"
    			"\t|  2) Guardar lista convocados CAF       |\n"
    			"\t|  3) Guardar lista convocados CONCACAF  |\n"
				"\t|  4) Guardar lista convocados CONMEBOL  |\n"
				"\t|  5) Guardar lista convocados UEFA      |\n"
				"\t|  6) Cancelar                           |\n"
    			"\t+----------------------------------------+\n\n");

    utn_getNumero(&retorno, "Elija una opcion: ", "Error - Elija una opcion valida", 1, 6);

    return retorno;
}



