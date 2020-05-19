/*
 * informes.c
 *
 *  Created on: 8 may. 2020
 *      Author: Juan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicaciones.h"

#define CLIENTES_LEN 100
#define PUBLICACIONES_LEN 1000

static const char TXT_ESTADOS[2][8] = {"PAUSADA","ACTIVA"};


/**
 * \brief imprime la lista de cliente con la cantidad de publicaciones activas
 * \param array Array de clientes
 * \param Limite del array de clientes
 * \param array de publicaciones
 * \param Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int info_imprimirClientesConCantidadDePublicaciones (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones)  //punto 7
{
	int retorno = -1;
	int i;
	int auxiliarId;
	int contador =0;

	if(arrayClientes != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones >0)
	{
		for(i=0; i<limiteClientes; i++)
		{
			auxiliarId = arrayClientes[i].id;
			contador = pub_cantidadPublicacionesActivas (arrayPublicaciones,PUBLICACIONES_LEN, auxiliarId);
			cli_imprimirClienteActivas (&arrayClientes[i],contador);
		}
		retorno=0;
	}

		return retorno;
}


/**
 * \brief imprime un cliente con la cantidad de publicaciones activas
 * \param array Array de clientes
 * \param Limite del array de clientes
 * \param array de publicaciones
 * \param Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int info_clienteConMasActivas (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones)  //punto 9/1
{
	int retorno = -1;
	int i;
	int cantidadAvisos;

	int maximo=0;
	int IdConMasAvisos;

	if(arrayClientes != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones >0)
	{
		for(i=0; i<limiteClientes; i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0)
			{
				cantidadAvisos = pub_cantidadPublicacionesActivas (arrayPublicaciones,PUBLICACIONES_LEN, arrayPublicaciones[i].idCliente);
				if(cantidadAvisos >= maximo)
				{
					maximo=cantidadAvisos;
					IdConMasAvisos=arrayPublicaciones[i].idCliente;
				}
			}
		}

		cli_imprimir(arrayClientes,CLIENTES_LEN, IdConMasAvisos);
		printf(" cantidad de avisos activos: %d \n", maximo);
			retorno=0;
	}
		return retorno;
}


/**
 * \brief imprime un cliente con la cantidad de publicaciones pausadas
 * \param array Array de clientes
 * \param Limite del array de clientes
 * \param array de publicaciones
 * \param Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */

int info_clienteConMasPausadas (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones)  //punto 9/2
{
	int retorno = -1;
		int i;
		int cantidadAvisos;

		int maximo=0;
		int IdConMasAvisos;

		if(arrayClientes != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones >0)
		{
			for(i=0; i<limiteClientes; i++)
			{
				if(arrayPublicaciones[i].isEmpty == 0)
				{
					cantidadAvisos = pub_cantidadPublicacionesPausadas (arrayPublicaciones,PUBLICACIONES_LEN, arrayPublicaciones[i].idCliente);
					if(cantidadAvisos >= maximo)
					{
						maximo=cantidadAvisos;
						IdConMasAvisos=arrayPublicaciones[i].idCliente;
					}
				}
			}

			cli_imprimir(arrayClientes,CLIENTES_LEN, IdConMasAvisos);
			printf(" cantidad de avisos pausados: %d \n", maximo);
				retorno=0;
		}
			return retorno;


}


/**
 * \brief imprime un cliente con la cantidad de publicaciones total que tiene (activas y pausadas)
 * \param array Array de clientes
 * \param Limite del array de clientes
 * \param array de publicaciones
 * \param Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int info_clientePublicacionesTotal (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones)  //punto 9/3
{
	int retorno = -1;
	int i;
	int cantidadAvisos;

	int maximo=0;
	int IdConMasAvisos;

	if(arrayClientes != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones >0)
	{
		for(i=0; i<limiteClientes; i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0)
			{
				cantidadAvisos = pub_cantidadPublicacionesTotal (arrayPublicaciones,PUBLICACIONES_LEN, arrayPublicaciones[i].idCliente);
				if(cantidadAvisos >= maximo)
				{
					maximo=cantidadAvisos;
					IdConMasAvisos=arrayPublicaciones[i].idCliente;
				}
			}
		}

		cli_imprimir(arrayClientes,CLIENTES_LEN, IdConMasAvisos);
		printf(" cantidad de avisos total: %d \n", maximo);
		retorno=0;
	}


		return retorno;
}
int info_imprimePublicacionesCuit(clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones)
{
	int retorno= -1;
	int i;
	int j;

	if(arrayClientes != NULL && limiteClientes > 0 && arrayPublicaciones != NULL && limitePublicaciones >0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0)
			{
				for(j=0;j<limiteClientes;j++)
				{
					if(arrayClientes[j].isEmpty == 0 && arrayPublicaciones[i].idCliente == arrayClientes[j].id)
					{
						printf("ID PUBLICACION: %d - RUBRO:%d - ESTADO: %s - TEXTO: %s - ",arrayPublicaciones[i].idPublicacion,arrayPublicaciones[i].numeroDeRubro,TXT_ESTADOS[arrayPublicaciones[i].estado],arrayPublicaciones[i].texto);
						printf("CUIT: %s \n", arrayClientes[j].cuit);
					}
				}
			}
		}
		retorno=0;
	}
	return retorno;
}
