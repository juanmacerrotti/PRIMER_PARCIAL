/*
 * publicaciones.c
 *
 *  Created on: 8 may. 2020
 *      Author: Juan
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicaciones.h"
#define TEXTO_LEN 65

#define ESTADO_ACTIVA	1
#define ESTADO_PAUSADO	0

/**
 * \brief Inicializa el array de publicaciones para que esten todos con isEmpty =1.
 * \param Array publicaciones para ser actualizado
 * \param Limite del array de publicaciones
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_inicializarArray (publicaciones* arrayPublicaciones, int len)
{
	int retorno=-1;
	int i ;

	if(arrayPublicaciones != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			arrayPublicaciones[i].isEmpty = 1;
			retorno=0;
		}
	}

	return retorno;
}

/**
 * \brief Da de alta una publicacion
 * \param Array publicaciones
 * \param Limite del array de publicaciones
 * \param indice vacio
 * \param puntero para asignar ID
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_altaArray(publicaciones* arrayPublicaciones, int len, int indice, int idCliente, int* id)
{
	int retorno = -1;
	publicaciones bufferPublicaciones;

	if(arrayPublicaciones != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(		utn_getNumero(&bufferPublicaciones.numeroDeRubro,"ingrese numero rubro:\n", "Error\n",0,100,2) == 0 &&
				utn_getDescripcion(bufferPublicaciones.texto, TEXTO_LEN, "ingrese texto de la publicacion:","\nERROR\n",2) == 0 )
		{
			bufferPublicaciones.isEmpty = 0;
			bufferPublicaciones.idCliente= idCliente;
			bufferPublicaciones.idPublicacion = *id;
			bufferPublicaciones.estado = 1;
			arrayPublicaciones[indice] = bufferPublicaciones;
			(*id)++;
			retorno = 0;

		}
	}
	return retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param Array de publicaciones
 * \param limite  del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(publicaciones* arrayPublicaciones,int len)
{
	int respuesta = -1;
	int i;

	if(arrayPublicaciones != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Da de baja una publicacion
 * param array de publicaciones
 * param tamaño del array
 * param ID de la publicacion
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_bajaPublicacion (publicaciones* arrayPublicaciones,int len,int id)
{
	int respuesta = -1;
	int i;
		if(arrayPublicaciones != NULL && len > 0)
		{

			for(i=0;i<len;i++)
			{
				if(arrayPublicaciones[i].idCliente == id)
				{
					arrayPublicaciones[i].isEmpty = 1;
				}
			}
			respuesta = 0;
		}
		return respuesta;
}

/**
 * \brief confirma si se desea pausar publicacion y cambia a estado pausado
 * \param array publicaciones
 * \param limite del array
 * \param id publicacion
 * \param puntero donde se almacena la respuesta
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_estadoPausado(publicaciones* arrayPublicaciones, int indice , int* respuesta)
{

	int auxRespuesta;
	int retorno=-1;

	if (utn_getNumero(&auxRespuesta,"Desea pausar la publicacion? [1.SI/2.NO]\n", "error",1,2,2) == 0)
	{
		if(auxRespuesta == 1 && arrayPublicaciones[indice].isEmpty == 0)
		{
			retorno=0;
			*respuesta = auxRespuesta;
			arrayPublicaciones[indice].estado = 0;
		}
		else
		{
			printf("Accion cancelada. \n");
			retorno=0;
		}
	}
	return retorno;
}

/**
 * \brief confirma si se desea activar publicacion
 * \param array de publicaciones
 * \param indice del array
 * \param puntero donde se almacena la respuesta
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_estadoActivo(publicaciones* arrayPublicaciones, int indice, int* confirmacionEstado)
{

	int auxRespuesta;
	int retorno=-1;

	if (utn_getNumero(&auxRespuesta,"Desea activar la publicacion? [1.SI/2.NO] \n", "error",1,2,2) == 0)
	{
		if(auxRespuesta == 1)
		{
			retorno=0;
			*confirmacionEstado = auxRespuesta;
			arrayPublicaciones[indice].estado = 1;
		}
		else if(auxRespuesta==2)
		{
			printf("Accion cancelada. \n");
			retorno=0;
		}
	}
	return retorno;
}

/**
 * \brief imprime el ID de publicaciones en forma encolumnada.
 * param array de publicaciones
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_imprimirListaPublicaciones (publicaciones* arrayPublicaciones,int len)
{
	int respuesta = -1;
	int i;
	if(arrayPublicaciones != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].isEmpty != 1)
			{
				printf("ID: %d ",arrayPublicaciones[i].idPublicacion);
			}
		}
	}
	return respuesta;
}

/**
 * \brief imprime publicidad activa y da su ID
 * \param array de publicaciones
 * \param limite del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_imprimirActivas(publicaciones* arrayPublicaciones,int len)
{
	int retorno=-1;
	int i;

	if(arrayPublicaciones != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].estado == 1 && arrayPublicaciones[i].isEmpty == 0)
			{
				printf("publicidad activa con ID: %d \n", arrayPublicaciones[i].idPublicacion);
			}
		}
	}


	return retorno;
}

/**
 * \brief imprime publicidad pausada y da su ID
 * \param array de publicaciones
 * \param limite del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_imprimirPausadas(publicaciones* arrayPublicaciones,int len)
{
	int retorno=-1;
	int i;

	if(arrayPublicaciones != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].estado == 0 && arrayPublicaciones[i].isEmpty == 0)
			{
				printf("Publicacion pausada con ID: %d \n", arrayPublicaciones[i].idPublicacion);
			}
		}
	}


	return retorno;
}

/**
 * \brief imprime array de publicaciones con todos sus datos.
 * param array de publicaciones
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_imprimirPublicaciones (publicaciones* arrayPublicaciones,int len, char* cuit)
{
	int retorno = -1;
	int i;
	if(arrayPublicaciones != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].isEmpty != 1)
			{
				printf("\nNUMERO DE RUBRO: %d - TEXTO: %s ESTADO: %d - idPublicacion: %d idCliente: %d - CUIT: %s \n", arrayPublicaciones[i].numeroDeRubro,arrayPublicaciones[i].texto,arrayPublicaciones[i].estado,arrayPublicaciones[i].idPublicacion,arrayPublicaciones[i].idCliente,cuit);
				retorno=0;
			}
		}
	}
	return retorno;

}

/**
 * \brief imprime el array de publicaciones por un ID de cliente determinado
 * param array de publicaciones
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_imprimirListaPublicacionesPorId (publicaciones* arrayPublicaciones,int len, int id)
{
	int respuesta = -1;
	int i;
	if(arrayPublicaciones != NULL && len > 0)
	{

		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].idCliente == id && arrayPublicaciones[i].isEmpty == 0)
			{
				printf("\nNUMERO DE RUBRO: %d - ESTADO: %d - idPublicacion: %d \n",arrayPublicaciones[i].numeroDeRubro,arrayPublicaciones[i].estado,arrayPublicaciones[i].idPublicacion);
			}
		}
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Verifica que haya alguna publicacion de alta para habilitar el menu
 * param array de publicaciones
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int pub_bajaTotalDePublicaciones (publicaciones* arrayPublicaciones, int len)
{
	int retorno=-1;
	int i;

	for(i=0;i<len-1;i++)
	{
		if(arrayPublicaciones[i].isEmpty == 0)
		{
			retorno=0;
		}

	}
	return retorno;
}

/**
 * \brief se envia un id de publicacion y te devuelve el ID del cliente.
 * param array de publicaciones
 * param tamaño del array
 * param id de la publicacion
 * \return retorna el id del cliente
 */
int pub_idCliente (publicaciones* arrayPublicaciones, int limitePublicaciones, int idPublicacion ,int* aux)
{
	int retorno=-1;
	int i;
	int AuxIdCliente;
	for(i=0;i<limitePublicaciones;i++)
	{
		if(arrayPublicaciones[i].idPublicacion == idPublicacion  && arrayPublicaciones[i].isEmpty == 0)
		{
			AuxIdCliente = arrayPublicaciones[i].idCliente;
			*aux=AuxIdCliente;
			retorno=0;
		}
	}

	return retorno;
}

/**
 * \brief cuenta las publicaciones activas de un ID de cliente
 * param array de publicaciones
 * param tamaño del array
 * param ID del cliente
 * \return cantida de publicaciones activas.
 */
int pub_cantidadPublicacionesActivas (publicaciones* arrayPublicaciones, int limitePublicaciones, int idCliente)
{
	int i;
	int contadorPublicaciones=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 1 && arrayPublicaciones[i].idCliente == idCliente)
			{
				contadorPublicaciones++;
			}
		}
	}
	return contadorPublicaciones;
}

/**
 * \brief cuenta las publicaciones pausadas de un ID de cliente
 * param array de publicaciones
 * param tamaño del array
 * param ID del cliente
 * \return cantida de publicaciones activas.
 */
int pub_cantidadPublicacionesPausadas (publicaciones* arrayPublicaciones, int limitePublicaciones, int idCliente)
{
	int i;
	int contadorPublicaciones=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 0 && arrayPublicaciones[i].idCliente == idCliente)
			{
				contadorPublicaciones++;
			}
		}
	}
	return contadorPublicaciones;
}

int pub_imprimirPublicacion (publicaciones* arrayPublicaciones, char cuit)   //llama punto 8
{
	int retorno=-1;
	if(arrayPublicaciones != NULL && arrayPublicaciones->isEmpty == 0)
	{
		retorno=0;
		printf("NUMERO DE RUBRO: %d - TEXTO: %s - ESTADO: %d -ID PUBLICACION: %d - ID CLIENTE: %d - CUIT DEL CLIENTE: %d \n \n",arrayPublicaciones->numeroDeRubro , arrayPublicaciones->texto, arrayPublicaciones->estado,arrayPublicaciones->idPublicacion, arrayPublicaciones->idCliente,cuit);
	}
	return retorno;
}

/**
 * \brief cuenta las publicaciones TOTAL de un ID de cliente
 * param array de publicaciones
 * param tamaño del array
 * param ID del cliente
 * \return cantida de publicaciones activas.
 */
int pub_cantidadPublicacionesTotal (publicaciones* arrayPublicaciones, int limitePublicaciones, int idCliente)
{
	int i;
	int contadorPublicaciones=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0 && idCliente >= 0)
	{
		for(i=0;i<limitePublicaciones-1;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].idCliente == idCliente)
			{
				contadorPublicaciones++;
			}
		}
	}
	return contadorPublicaciones;
}

int pub_DoyIdMeDaIndice(publicaciones* arrayPublicaciones,int len, int id)
{
	int respuesta = -1;
	int i;

	if(arrayPublicaciones != NULL && len > 0 && id >=0)
	{
		for(i=0;i<len;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].idPublicacion == id)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

//TODAS ESTAS FUNCIONES SON PARA EL PUNTO 10
// punto 1

int pub_cantidadDePublicacionesDeRubro(publicaciones* arrayPublicaciones, int limitePublicaciones, int rubro)
{
	int retorno= -1;
	int i;
	int contadorPublicaciones=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0 && rubro > 0)
	{
		for(i=0;i<limitePublicaciones-1;i++)
				{
					if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].numeroDeRubro == rubro && arrayPublicaciones[i].estado == 1)
					{
						contadorPublicaciones++;
					}
				}
		printf("Hay %d publicaciones activas del rubro %d \n",contadorPublicaciones,rubro);
	}
return retorno;
}


//punto2
int pub_rubroMasActivo(publicaciones* arrayPublicaciones, int limitePublicaciones)
{
	int retorno= -1;
	int i;
	int j;
	int auxRubro;
	int contador=0;
	int max=0;
	int flag;
	int listaRubros [limitePublicaciones];
	int CantidadRubros=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)  // recorro array publicaciones
		{

			flag=0; // cada vez que entro a una nueva publicacion pongo el flag en 0.

			if(arrayPublicaciones[i].isEmpty == 0)  // recorro publicaciones solo activas
			{
				for(j=0;j<CantidadRubros;j++)  // recorro la cantidad de rubros (la primera vez no entra(porque j=0 y cantidadRubros=0))
				{
					if(arrayPublicaciones[i].numeroDeRubro == listaRubros[j])  // comparo el rubro con mi lista de rubros para ver si esta repetido.
					{
					flag=1; //si esta repetido cambio bandera a 1 y rompo el for.
					break;
					}
				}
				// aca termina el for y evalua como quedo la bandera para saber si esta repetido o no.
				if(flag == 0)  // si no esta repetido queda el flag en 0 y copío el rubro en la lista
				{
					listaRubros[CantidadRubros] = arrayPublicaciones[i].numeroDeRubro;
					CantidadRubros++;
				}
			}
		}


		for(i=0;i<CantidadRubros;i++) // ya fuera del for de publicaciones, recorro la lista de rubros que pude armar.
		{
			contador=pub_cantidadPublicacionesActivasPorRubro (arrayPublicaciones, limitePublicaciones,listaRubros[i]); // mando los distintos rubros y cuento cuantas publicaciones activas tienen
			if(i==0 || contador>max) // el que mas cuenta va guardando la cantidad y que rubro es.
			{
				max=contador;
				auxRubro=listaRubros[i];
			}
		}

		printf("El rubro con mas publicidades activas es el %d . \n",auxRubro); //imprimo el rubro que mas veces se repitio.

	}

return retorno;
}

int pub_rubroMasPausado(publicaciones* arrayPublicaciones, int limitePublicaciones)
{
	int retorno= -1;
	int i;
	int j;
	int auxRubro;
	int contador=0;
	int max=0;
	int flag;
	int listaRubros [limitePublicaciones];
	int CantidadRubros=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)  // recorro array publicaciones
		{

			flag=0; // cada vez que entro a una nueva publicacion pongo el flag en 0.

			if(arrayPublicaciones[i].isEmpty == 0)  // recorro publicaciones solo activas
			{
				for(j=0;j<CantidadRubros;j++)  // recorro la cantidad de rubros (la primera vez no entra(porque j=0 y cantidadRubros=0))
				{
					if(arrayPublicaciones[i].numeroDeRubro == listaRubros[j])  // comparo el rubro con mi lista de rubros para ver si esta repetido.
					{
					flag=1; //si esta repetido cambio bandera a 1 y rompo el for.
					break;
					}
				}
				// aca termina el for y evalua como quedo la bandera para saber si esta repetido o no.
				if(flag == 0)  // si no esta repetido queda el flag en 0 y copío el rubro en la lista
				{
					listaRubros[CantidadRubros] = arrayPublicaciones[i].numeroDeRubro;
					CantidadRubros++;
				}
			}
		}


		for(i=0;i<CantidadRubros;i++) // ya fuera del for de publicaciones, recorro la lista de rubros que pude armar.
		{
			contador=pub_cantidadPublicacionesPausadasPorRubro (arrayPublicaciones, limitePublicaciones,listaRubros[i]); // mando los distintos rubros y cuento cuantas publicaciones activas tienen
			if(i==0 || contador>max) // el que mas cuenta va guardando la cantidad y que rubro es.
			{
				max=contador;
				auxRubro=listaRubros[i];
			}
		}

		printf("El rubro con mas publicidades pausadas es el %d . \n",auxRubro); //imprimo el rubro que mas veces se repitio.

	}

return retorno;
}


//contador para el el 10/2
int pub_cantidadPublicacionesActivasPorRubro (publicaciones* arrayPublicaciones, int limitePublicaciones, int rubro)
{
	int i;
	int contadorPublicaciones=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 1 && arrayPublicaciones[i].numeroDeRubro == rubro)
			{
				contadorPublicaciones++;
			}
		}
	}
	return contadorPublicaciones;
}

//contador para el 10/3
int pub_cantidadPublicacionesPausadasPorRubro (publicaciones* arrayPublicaciones, int limitePublicaciones, int rubro)
{

	int i;
	int contadorPublicaciones=0;

	if (arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 0 && arrayPublicaciones[i].numeroDeRubro == rubro)
			{
				contadorPublicaciones++;
			}
		}
	}
	return contadorPublicaciones;
}

//10.2
int info_publicacionMasActivaFinal (publicaciones* arrayPublicaciones, int limitePublicaciones)
{
	int retorno = -1;
	int i;
	int maximo=0;
	int auxRubro;
	int contador;

	if(arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
	for(i=0;i<limitePublicaciones;i++)
		{
		contador = pub_cantidadPublicacionesActivasPorRubro(arrayPublicaciones, limitePublicaciones, i);
		if(i== 0 || (contador > maximo))
			{
			retorno = 0;
			maximo = contador;
			auxRubro = 	i;
			}
		}
	printf("El rubro con mas avisos activos es %d \n",auxRubro);
	}
	return retorno;
}

//10.3
int info_publicacionMasPausadaFinal (publicaciones* arrayPublicaciones, int limitePublicaciones)
{
	int retorno = -1;
	int i;
	int maximo=0;
	int auxRubro;
	int contador;

	if(arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
	for(i=0;i<limitePublicaciones;i++)
		{
		contador = pub_cantidadPublicacionesActivasPorRubro(arrayPublicaciones, limitePublicaciones, i);
		if(i== 0 || (contador > maximo))
			{
			retorno = 0;
			maximo = contador;
			auxRubro = 	i;
			}
		}
	printf("El rubro con mas avisos activos es %d \n",auxRubro);
	}
	return retorno;
}


