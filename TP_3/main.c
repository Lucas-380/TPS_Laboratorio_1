#include "Controller.h"


int main()
{
	setbuf(stdout,NULL);
    int option = 1;
    int archivosCargados = 0;
    int convocadosVacio = 0;
    int archivosGuardados = 0;

    LinkedList* listaSelecciones;
    LinkedList* listaJugadores;
    LinkedList* listaConvocados;

    listaSelecciones = ll_newLinkedList();
    listaJugadores = ll_newLinkedList();
    listaConvocados = ll_newLinkedList();

    do{
    	if(menu_principal(&option) == 0){
    		printf("Error al ingresar una opcion");
    	}

        switch(option)
        {
            case 1: // CARGA DE ARCHIVOS
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) && controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones)){
            		printf("\n\t*** CARGA DE ARCHIVOS COMPLETADA CORRECTAMENTE *** \n");
            		archivosCargados = 1;
            	}else{
            		printf("\n\tERROR\n\t*** La carga de Archivos fallo - Compruebe las rutas de los archivos o si las listas estan creadas correctemente ***\n");
            	}
                break;
            case 2: //ALTA DE JUGADOR
				if(archivosCargados && controller_agregarJugador(listaJugadores)){
					printf("\n\t*** Jugador agregado Correctamente ***\n");
				}else{
					printf("\n\t*** Para acceder a esta opcion primero debe cargar los archivos de los jugadores y selecciones ***\n");
				}
                break;
            case 3: //EDITAR JUGADOR
            	if(controller_listarJugadores(listaJugadores, listaSelecciones) && controller_editarJugador(listaJugadores)){
            		printf("\n\t*** Jugador editado Correctamente *** \n");
            	}else{
            		printf("\n\tERROR\n\t*** No se puede utilizar esta opcion - La lista de Jugadores esta vacia ***\n");
            	}
                break;
            case 4:
            	if(controller_listarJugadores(listaJugadores, listaSelecciones) && controller_removerJugador(listaJugadores, listaSelecciones)){
            		printf("\n\t*** El Jugador fue removido Correctamente *** \n");
            	}else{
            		printf("\n\tERROR\n\t*** No se puede utilizar esta opcion - La lista de Jugadores esta vacia ***\n");
            	}
                break;
            case 5:
            	switch(menu_Listados()){
            		case 1:
                    	if(!controller_listarJugadores(listaJugadores, listaSelecciones)){
                    		printf("\n *** La lista esta vacia o no existe *** \n");
                    	}
            			break;
            		case 2:
                    	if(!controller_listarSelecciones(listaSelecciones)){
                    		printf("\n *** La lista esta vacia o no existe *** \n");
                    	}
            			break;
            		case 3:
            			if(!controller_listarJugadoresConvocados(listaJugadores, listaSelecciones)){
            				printf("\n *** No hay jugadores convocados *** \n");
            			}
            			break;
            	}
                break;
			case 6:
				if(ll_isEmpty(listaJugadores) || ll_isEmpty(listaSelecciones)){
            		printf("\n\tERROR\n\t*** No se puede utilizar esta opcion - Compruebe que las listas de Jugadores y Selecciones esten cargadas correctamente ***\n");
				}else{
					switch(menu_convocarJugadores()){
						case 1: // AGREGAR CONVOCADO
							if(controller_listarJugadores(listaJugadores, listaSelecciones) && controller_agregarConvocado(listaSelecciones, listaJugadores)){
			            		printf("\n\t*** El Jugador fue convocado Correctamente *** \n");
			            	}
							break;
						case 2: // REMOVER CONVOCADO
							if(controller_listarJugadoresConvocados(listaJugadores, listaSelecciones) && controller_removerConvocado(listaSelecciones, listaJugadores)){
								printf("\n\t*** El Jugador ya no se encuentra convocado *** \n");
							}else{
			            		printf("\n\tERROR\n\t*** No se puede utilizar esta opcion - Compruebe que haya Jugadores convocados para acceder a esta opcion ***\n");
							}
							break;
						case 3:
							printf("Volviendo al menu principal...");
							break;
					}
				}
				break;
			case 7:
				switch(menu_OrdenarYlistar()){
					case 1: //JUGADORES POR NACIONALIDAD
						if(!controller_ordenarJugadores(listaJugadores, "nacionalidad") || !controller_listarJugadores(listaJugadores, listaSelecciones)){
							printf("\n\t ** Los Jugadores no se pudieron ordenar ** \n");
						}
						break;
					case 2: //SELECCION POR CONFEDERACIÓN
						if(!controller_ordenarSelecciones(listaSelecciones) || !controller_listarSelecciones(listaSelecciones)){
							printf("\n\t ** Las Selecciones no se pudieron ordenar ** \n");
						}
						break;
					case 3: //JUGADORES POR EDAD
						if(!controller_ordenarJugadores(listaJugadores, "edad") || !controller_listarJugadores(listaJugadores, listaSelecciones)){
							printf("\n\t ** Los Jugadores no se pudieron ordenar ** \n");
						}
						break;
					case 4:
						//JUGADORES POR NOMBRE
						if(!controller_ordenarJugadores(listaJugadores, "nombre") || !controller_listarJugadores(listaJugadores, listaSelecciones)){
							printf("\n\t ** Los Jugadores no se pudieron ordenar ** \n");
						}
						break;
					case 5:
						printf("Volviendo al menu principal...");
						break;
				}
				break;
			case 8:
				//GENERAR UN ARCHIVO BINARIO CON LA LISTA DE JUGADORES CONVOCADOS
				//CONTROLLER GENERAR UN ARCHIVO BINARIO DE LOS JUGADORES DE LOS CONVOCADOS SEGUN LA CONFEDERACION
				switch(menu_GenerarArchivoBinario()){
					case 1:
						if(controller_generarListaConvocados(listaJugadores, listaConvocados, listaSelecciones, "AFC") == 0){
							printf("\n\t ** No hay jugadores convocados en la confederacion seleccionada **\n");
							convocadosVacio = 1;
						}
						break;
					case 2:
						if(controller_generarListaConvocados(listaJugadores, listaConvocados, listaSelecciones, "CAF") == 0){
							printf("\n\t ** No hay jugadores convocados en la confederacion seleccionada **\n");
							convocadosVacio = 1;
						}
						break;
					case 3:
						if(controller_generarListaConvocados(listaJugadores, listaConvocados, listaSelecciones, "CONCACAF") == 0){
							printf("\n\t ** No hay jugadores convocados en la confederacion seleccionada **\n");
							convocadosVacio = 1;
						}
						break;
					case 4:
						if(controller_generarListaConvocados(listaJugadores, listaConvocados, listaSelecciones, "CONMEBOL") == 0){
							printf("\n\t ** No hay jugadores convocados en la confederacion seleccionada **\n");
							convocadosVacio = 1;
						}
						break;
					case 5:
						if(controller_generarListaConvocados(listaJugadores, listaConvocados, listaSelecciones, "UEFA") == 0){
							printf("\n\t ** No hay jugadores convocados en la confederacion seleccionada **\n");
							convocadosVacio = 1;
						}
						break;
					case 6:
						printf("Volviendo al menu principal...");
						break;
				}
				//GUARDAR EL ARCHIVO
				if(ll_isEmpty(listaConvocados) == 0 && convocadosVacio != 1 && confirmarFuncion("\n¿Seguro que quiere guardar y sobreescribir los datos? ('s' para Si 'n' para No): ")){
					controller_guardarJugadoresModoBinario("convocados.bin", listaConvocados);
				}
				break;
			case 9:
				//CARGAR ARCHIVO BINARIO
				if(archivosCargados)
				{
					if(!controller_listarJugadores(listaConvocados, listaSelecciones)){
						controller_cargarJugadoresDesdeBinario("convocados.bin", listaConvocados);
						controller_listarJugadores(listaConvocados, listaSelecciones);
					}
				}else{
					printf("\n\tERROR\n\t*** Para acceder a esta opcion Primero cargue los archivos ***\n");
				}
				break;
			case 10:
				//GUARDAR ARCHIVOS .CSV
				if(archivosCargados)
				{
					if(confirmarFuncion("\n¿Seguro que quiere guardar y sobreescribir los datos modificados? ('s' para Si 'n' para No): "))
					{
						if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) && controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones)){
							printf("\n\t*** LOS ARCHIVOS SE GUARDARON CORRECTAMENTE *** \n");
							archivosGuardados = 1;
						}else{
							printf("\n\tERROR\n\t*** Los Archivos no se pudieron guardar ***\n");
						}
					}
				}else{
					printf("\n\t*** Para guardar los cambios primero debe cargar las listas *** \n");
				}
				break;
			case 11:
				if(archivosGuardados || confirmarFuncion("\n¿Seguro que quiere Salir? NO OLVIDES GUARDAR LOS ARCHIVOS\n('s' para Si 'n' para No): ")){
					printf("Finaliza el programa");
					ll_clear(listaJugadores);
					ll_clear(listaSelecciones);
					ll_clear(listaConvocados);
					ll_deleteLinkedList(listaJugadores);
					ll_deleteLinkedList(listaSelecciones);
					ll_deleteLinkedList(listaConvocados);
					option = -1;
				}
                break;
        }
    }while(option != -1);

    return 0;
}

