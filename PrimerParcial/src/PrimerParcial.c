/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : JUAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "publicaciones.h"
#include "informes.h"
#include <stdlib.h>

#define CLIENTES_LEN 100
#define PUBLICACIONES_LEN 1000

int main(void)
{

	setbuf (stdout,NULL);

	clientes arrayClientes [CLIENTES_LEN];
	publicaciones arrayPublicaciones  [PUBLICACIONES_LEN];

	int opcion;
	int flagCasos=0;
	int IdClientes;
	int auxiliarIndice;
	int auxiliarId;
	int aux;
	int confirmacion;
	int auxiliarIdPublicacion;
	int confirmacionEstado; // 0 pausado , 1 activa
	int opcionInformes9; //opciones de menu 9
	int opcionInformes10; //opciones de menu 10
	int flagPublicaciones=1;
	int auxRubro;

	if (cli_inicializarArray (arrayClientes, CLIENTES_LEN) == 0)
	{
		printf("array CLIENTES inicializado con exito.\n");
	}

	if (pub_inicializarArray (arrayPublicaciones, PUBLICACIONES_LEN) == 0)
		{
			printf("array PUBLICIDADES inicializado con exito.\n \n \n \n");
		}

	cli_altaForzadaArray(arrayClientes,CLIENTES_LEN, 0, &IdClientes,"juan","cerrotti", "11111111");
	cli_altaForzadaArray(arrayClientes,CLIENTES_LEN, 1, &IdClientes,"gaby","gomez", "22222222");
	cli_altaForzadaArray(arrayClientes,CLIENTES_LEN, 2, &IdClientes,"agus","lopez", "33333333");

	do
	{
		if (utn_getNumero (&opcion, "1.ALTA DE CLIENTE\n"
									"2.MODIFICAR DATOS DEL CLIENTE\n"
									"3.DAR DE BAJA UN CLIENTE\n"
									"4.PUBLICAR \n"
									"5.PAUSAR PUBLICACION \n"
									"6.REANUDAR PUBLICACION \n"
									"7.IMPRIMIR CLIENTES \n"
									"8.IMPRIMIR PUBLICACIONES \n"
									"9.INFORMAR CLIENTES\n"
									"10.INFORMAR PUBLICACIONES \n"
									"11.SALIR. "
									,"Error no es una opcion\n",1,11,2) ==0)
		{
			switch (opcion)

			{
			case 1: //ALTA CLIENTE

				auxiliarIndice = cli_getEmptyIndex(arrayClientes, CLIENTES_LEN); //busco primer indice vacio.
				if( auxiliarIndice >= 0 &&
					cli_altaArray(arrayClientes,CLIENTES_LEN, auxiliarIndice,&IdClientes) ==0 )  //funcion que añade un empleado nuevo y le asigna un ID automaticamente.
				{
						printf("Carga OK. Con ID: %d\n",arrayClientes[auxiliarIndice].id);
						flagCasos=0;
				}
				else
					{
						printf("\nNo Hay mas lugar.\n");
					}
				break;

			case 2: //MODIFICAR CLIENTE

			if(flagCasos==0)
			{
				if(utn_getNumero(&auxiliarId,"ingrese el ID del cliente a modificar: \n", "Error de ID. \n",0,100, 2) == 0)//pido id del cliente
				{
					if(cli_buscaClientePorId (arrayClientes, CLIENTES_LEN, auxiliarId) >=0)   //verifica
					{
						auxiliarIndice=cli_buscaClientePorId (arrayClientes, CLIENTES_LEN, auxiliarId);  // me devuelve la posicion
						if(	auxiliarIndice >=0 &&
							cli_ModificarCliente(arrayClientes, CLIENTES_LEN, auxiliarIndice, auxiliarId) == 0) //llama a funcion de modificar
						{
							printf("Modificacion realizada con exito \n \n");

						}
					}
					else
					{
						printf("ID incorrecto \n");
					}

				}
			}
			else
			{
				printf("Debe dar de alta un cliente.\n\n");
			}
			if(cli_bajaTotalDeEmpleados (arrayClientes, CLIENTES_LEN) != 0) //BLOQUEA EL MENU EN CASO DE QUE NO HAYA CLIENTES CARGADOS
			{
				flagCasos=1;
			}
			break;

			case 3:  //BAJA CLIENTE (CON PUBLICACIONES)
			if(flagCasos == 0)
			{
				if(utn_getNumero(&auxiliarId,"ingrese el ID para dar de baja: \n", "Error de ID. \n",0,100, 2) == 0)
				{
					if(cli_buscaClientePorId (arrayClientes, CLIENTES_LEN, auxiliarId) >= 0)  //verifica
					{
						pub_imprimirListaPublicacionesPorId (arrayPublicaciones,PUBLICACIONES_LEN, auxiliarId); 			//imprimo lista de publicaciones con el ID ingresado.
						if(utn_getNumero(&confirmacion,"Desea confirmar la baja? [1.SI/2.NO]\n", "Error \n",1,2,2) ==0 &&
										confirmacion ==1) 																	//busco la confirmacion, si ingresa "SI=1" da la baja
						{
							cli_removerCliente(arrayClientes,CLIENTES_LEN, auxiliarId); //da de baja cliente
							pub_bajaPublicacion (arrayPublicaciones,PUBLICACIONES_LEN,auxiliarId); // da de baja publicacion.
							printf("Baja realizada ok. \n");
						}
					}
					else
					{
						printf("ID incorrecto. \n");
					}
				}
			}
			else
			{
				printf("Debe dar de alta un cliente \n \n");
			}
			if(cli_bajaTotalDeEmpleados (arrayClientes, CLIENTES_LEN) != 0) //BLOQUEA EL MENU EN CASO DE QUE NO HAYA CLIENTES CARGADOS
			{
				flagCasos=1;
			}
			break;

			case 4: // ALTA PUBLICACION
			flagPublicaciones=0;

			cli_imprimirListaClientes (arrayClientes, CLIENTES_LEN); //imprimo array de clientes
			if(utn_getNumero(&auxiliarId,"Ingrese Id del Cliente: \n", "Error \n",0,100,2) == 0)
			{
				auxiliarIndice = pub_getEmptyIndex(arrayPublicaciones, PUBLICACIONES_LEN);//busco primera posicion vacia de array de publicaciones
				if(cli_buscaClientePorId (arrayClientes, CLIENTES_LEN, auxiliarId) >= 0 &&
						 auxiliarIndice >=0
						 && auxiliarId >= 0)  //verifico que el ID ingresado pertenezca a una cliente
				{
					if(pub_altaArray(arrayPublicaciones, PUBLICACIONES_LEN, auxiliarIndice, auxiliarId, &auxiliarIdPublicacion) == 0)  //llama funcion de alta
					{
						printf("Carga Publicacion OK. ID publicacion: %d \n", arrayPublicaciones[auxiliarIndice].idPublicacion); //imprime la primer posicion vacia que encontre
						flagPublicaciones=0;
					}
				}
				else
				{
					printf("ID incorrecto. \n");
				}
			}

			if(pub_bajaTotalDePublicaciones (arrayPublicaciones, PUBLICACIONES_LEN) != 0)
			{
				flagPublicaciones = 1;
			}

			break;

			case 5: //PAUSAR PUBLICACION
			if(flagPublicaciones ==0)
			{
				if(utn_getNumero(&auxiliarId,"ingrese ID de la publicacion que desea pausar: \n", "error\n",0,1000,2) == 0 ) //me dan ID de la publicacion a pausar
				{
					if (auxiliarId>=0)
					{
						if (pub_idCliente (arrayPublicaciones,PUBLICACIONES_LEN, auxiliarId,&aux) == 0) //verifica que el ID ingresado tenga una publicacion.
						{
							auxiliarIndice=pub_DoyIdMeDaIndice(arrayPublicaciones,PUBLICACIONES_LEN, auxiliarId);  //me da indice de la publicacion
							cli_imprimiraux(&arrayClientes[aux]); 	//imprime informacion del cliente al que pertece el ID ingresado
							if(pub_estadoPausado (arrayPublicaciones, auxiliarIndice , &confirmacionEstado) == 0 && //pregunta si desea pausar y la pausa en caso de afirmacion
									confirmacionEstado == 1)
							{
								printf("publicacion pausada \n");
							}
						}
						else
						{
						printf("Accion no realizada.\n");
						}
					}
				}

			}
			else
			{
				printf("Debe dar de alta una publicacion \n \n");
			}

			break;

			case 6: // REANUDAR PUBLICACION
			if(flagPublicaciones == 0)
			{
				if(utn_getNumero(&auxiliarId,"ingrese ID de la publicacion que desea activar: \n", "error\n",0,1000,2) == 0 )
				{
					if (auxiliarId>=0)
					{
						if (pub_idCliente (arrayPublicaciones,PUBLICACIONES_LEN, auxiliarId,&aux) == 0) //verifica que el ID ingresado tenga una publicacion.
						{
							auxiliarIndice=pub_DoyIdMeDaIndice(arrayPublicaciones,PUBLICACIONES_LEN, auxiliarId);   //me da indice
							cli_imprimiraux(&arrayClientes[aux]);  //imprime informacion del cliente al que pertece el ID ingresado
							if(pub_estadoActivo (arrayPublicaciones, auxiliarIndice , &confirmacionEstado) == 0 && //pregunta si desea activar y da la activacion
								confirmacionEstado == 1)
							{
								printf("publicacion activada \n");
							}
						}
						else
						{
						printf("ID ingresado invalido.\n");
						}
					}
				}
			}
			else
			{
				printf("Debe dar de alta una publicacion \n \n");
			}
			break;

			case 7:
			info_imprimirClientesConCantidadDePublicaciones (arrayClientes,CLIENTES_LEN,arrayPublicaciones,PUBLICACIONES_LEN);  // IMRPRIME LISTA DE TODOS  LOS CLIENTES CON LA CANTIDAD DE PUBLICACIONES ACTIVAS QUE TIENE CADA UNO
			break;

			case 8:
			//info_imprimirPublicacionesCuit (arrayClientes,CLIENTES_LEN,arrayPublicaciones,PUBLICACIONES_LEN);   // IMPRIME LISTA DE PUBLICIDADES CON CUIT DEL CLIENTE
				info_imprimePublicacionesCuit (arrayClientes,CLIENTES_LEN,arrayPublicaciones,PUBLICACIONES_LEN);
			break;

			case 9:
				utn_getNumero(&opcionInformes9,"1.Cliente con mas avisos activos. \n2.Cliente con mas avisos pausados. \n3.Cliente mas avisos.\n", "No es opcion valida.",1,3,2);
				switch(opcionInformes9)
				{
					case 1: //cliente con mas avisos activos
						info_clienteConMasActivas (arrayClientes, CLIENTES_LEN ,arrayPublicaciones,PUBLICACIONES_LEN);
						break;

					case 2: //cliente con mas pausados
						info_clienteConMasPausadas (arrayClientes, CLIENTES_LEN ,arrayPublicaciones,PUBLICACIONES_LEN);
						break;
					case 3: //clientes con mas publicaciones en total
						info_clientePublicacionesTotal (arrayClientes, CLIENTES_LEN ,arrayPublicaciones,PUBLICACIONES_LEN);
						break;
				}
			break;

			case 10:
			utn_getNumero(&opcionInformes10,"1.Cantidad de publicaciones de un rubro. \n2.rubro con mas publicaciones activas. \n3.Rubro con menos publicaciones activas.\n", "No es opcion valida.",1,3,2);
			switch(opcionInformes10)
			{
				case 1:
					if(utn_getNumero(&auxRubro,"ingrese un numero de Rubro:\n", "No es opcion valida.",0,1000,2) == 0)   // ingresa un numero de RUBRO
					{
						pub_cantidadDePublicacionesDeRubro(arrayPublicaciones,PUBLICACIONES_LEN,auxRubro);  // llama a la funcion que calcula cuantas publicaciones activas hay de un rubro especifico
					}
					break;
				case 2:
					info_publicacionMasActivaFinal (arrayPublicaciones,PUBLICACIONES_LEN);   // RUBRO CON MAS PUBLICIDADES ACTIVAS
					pub_rubroMasActivo (arrayPublicaciones,PUBLICACIONES_LEN);
					break;
				case 3:
					info_publicacionMasPausadaFinal (arrayPublicaciones,PUBLICACIONES_LEN); // RUBRO CON MAS PUBLICIDADES PAUSADAS
					pub_rubroMasPausado (arrayPublicaciones,PUBLICACIONES_LEN);
					break;
			}
			break;

		}
		}

	}while(opcion != 11); //FINALIZAR


	return EXIT_SUCCESS;
}
