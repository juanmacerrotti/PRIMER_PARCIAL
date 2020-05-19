/*
 * cliente.c
 *
 *  Created on: 8 may. 2020
 *      Author: Juan
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"

#define NOMBRE_LEN 51
#define APELLIDO_LEN 51
#define CUIT_LEN 12


/**
 * \brief Inicializa el array de clientes para que esten todos vacios (isEmpty = 1).
 * \param Array clientes para ser actualizado
 * \param Limite del array de clientes
 * \return retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray (clientes* arrayClientes, int len)
{
	int retorno=-1;
	int i;

	if(arrayClientes != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			arrayClientes[i].isEmpty = 1;
		}
		retorno=0;
	}

	return retorno;
}

/**
 * \brief Da de alta un cliente.
 * \param Array clientes
 * \param Limite del array de clientes
 * \param puntero de ID para darle el nuevo valor.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(clientes* arrayClientes,int len, int indice, int* id)
{
	int retorno = -1;
	clientes bufferClientes;

	if(arrayClientes != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(		utn_getNombre(bufferClientes.nombre,NOMBRE_LEN,"ingrese nombre:\n","\nERROR\n",2) == 0 &&
				utn_getNombre(bufferClientes.apellido,APELLIDO_LEN,"ingrese apellido:\n","\nERROR\n",2) == 0 &&
				utn_getDescripcion(bufferClientes.cuit, CUIT_LEN, "ingrese cuit:","\nERROR\n",2) ==0 )
		{
			bufferClientes.isEmpty = 0;
			bufferClientes.id = *id;
			arrayClientes[indice] = bufferClientes;
			(*id)++;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief modifica un cliente
 * \param Array de clientes para ser actualizado
 * param tamaño del array.
 * param indice
 * param id del cliente
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_ModificarCliente(clientes* arrayClientes,int len,int indice, int id)
{
	int retorno= -1;

	clientes auxClientes;

	if(arrayClientes != NULL && len>0 && indice >= 0)
	{
		{
				if(	utn_getNombre(auxClientes.nombre,NOMBRE_LEN,"ingrese nombre?\n","\nERROR\n",2) == 0 &&
					utn_getDescripcion(auxClientes.apellido,APELLIDO_LEN,"ingrese apellido?\n","\nERROR\n",2) == 0 &&
					utn_getDescripcion(auxClientes.cuit, CUIT_LEN, "ingrese cuit:","\nERROR\n",2) ==0 )
				{
					retorno = 0;
					auxClientes.id = arrayClientes[indice].id;
					auxClientes.isEmpty = 0;
					arrayClientes[indice] = auxClientes;
				}
			}
	}
	return retorno;
}

/**
 * \brief busca un cliente recibiendo como parametro su ID
 * param array de clientes
 * param tamaño del array
 * param id del cliente.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_buscaClientePorId (clientes* arrayClientes,int len, int id)
{
	int i;
	int retorno = -1;

	if(arrayClientes != NULL && len >0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(arrayClientes[i].id == id && arrayClientes[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

/**
 * \brief remueve (logicamente) un cleinte de la lista, recibiendo como parametro su ID
 * param array de clientes
 * param tamaño del array
 * param id del cliente.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_removerCliente(clientes* arrayClientes,int len, int id)
{
	int i;
	int retorno=-1;

	if(arrayClientes != NULL && len >0 && id >=0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			if(arrayClientes[i].id == id)
			{
				arrayClientes[i].isEmpty = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief imprime el array de clientes en forma encolumnada.
 * param array de clientes
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_imprimirListaClientes (clientes* arrayClientes,int len)
{
	int respuesta = -1;
	int i;
	if(arrayClientes != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayClientes[i].isEmpty != 1)
			{
				printf("\nID: %d - NOMBRE: %s - APELLIDO: %s\n",arrayClientes[i].id,arrayClientes[i].nombre,arrayClientes[i].apellido);

			}
		}
	}
	return respuesta;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimeArrayClientes (clientes* arrayClientes,int limite)
{
	int respuesta = -1;
	int i;
	if(arrayClientes != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cli_imprimiraux(&arrayClientes[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_getEmptyIndex(clientes* arrayClientes,int len)
{
	int respuesta = -1;
	int i;

	if(arrayClientes != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayClientes[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief indica si hay algun cliente cargado en el array teniendo como referencia el IsEmpty
 * param array de cliente
 * param tamaño del array
 * \return retorna 0 (MODIFICADO) y -1 (NO MODIFICADO)
 */
int cli_bajaTotalDeEmpleados (clientes* arrayClientes, int len)
{
	int retorno=-1;
	int i;

	if(arrayClientes != NULL && len > 0)
	{
		for(i=0;i<len-1;i++)
		{
			if(arrayClientes[i].isEmpty == 0)
			{
			retorno=0;
			}
	}

	}

	return retorno;
}

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimiraux(clientes* arrayClientes)
{
	int retorno=-1;
	if(arrayClientes != NULL && arrayClientes->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - NOMBRE: %s - CUIT %s \n",arrayClientes->id,arrayClientes->nombre,arrayClientes->cuit);
	}
	return retorno;
}

/**
 * \brief Imprime los datos de un cliente tendiendo en cuenta su ID
 * \param array  de clientes que deseo imprimir
 * \param id del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
*/
int cli_imprimir(clientes* arrayClientes,int limite, int id)  //punto5
{
	int retorno=-1;
	int i;

	if(arrayClientes != NULL && limite > 0 && id >=0)
	{
		for (i=0; i<limite;i++)
		{
			if(arrayClientes[i].id == id && arrayClientes[i].isEmpty == 0)
			{

				printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s - ID: %d ",arrayClientes[i].nombre,arrayClientes[i].apellido,arrayClientes[i].cuit,arrayClientes[i].id);
			}
		}
		retorno=0;
	}
	return retorno;
}

/**
 * \brief imprime lista de clientes con la cantidad de publicaciones activas
 * \param array  de clientes
 * \param tamaño del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirListaClientesPublicacionesActivas (clientes* arrayClientes,int len,int contadorDeActivas)
{
	int respuesta = -1;
	int i;
	if(arrayClientes != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayClientes[i].isEmpty != 1)
			{
				printf("\nID: %d - NOMBRE: %s - APELLIDO: %s y tiene %d publicaciones activas \n",arrayClientes[i].id,arrayClientes[i].nombre,arrayClientes[i].apellido,contadorDeActivas);

			}
		}
	}
	return respuesta;
}

/**
 * \brief imprime UN SOLO cliente con la cantidad de publicaciones activas
 * \param array  de clientes
 * \param tamaño del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirClienteActivas (clientes* arrayClientes, int contadorPublicaciones)
{
	int retorno=-1;
	if(arrayClientes != NULL && arrayClientes->isEmpty == 0)
	{
		retorno=0;
		printf("NOMBRE: %s - APELIIDO: %s - CUIT: %s - ID: %d - CANTIDAD DE PUBLICACIONES ACTIVAS: %d \n \n",arrayClientes->nombre , arrayClientes->apellido, arrayClientes->cuit, arrayClientes->id,contadorPublicaciones);
	}
	return retorno;
}

/**
 * \brief imprime UN SOLO cliente con la cantidad de publicaciones PAUSADAS
 * \param array  de clientes
 * \param tamaño del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirClientePausada (clientes* arrayClientes, int contadorPublicaciones)
{
	int retorno=-1;
	if(arrayClientes != NULL && arrayClientes->isEmpty == 0)
	{
		retorno=0;
		printf("NOMBRE: %s - APELIIDO: %s - CUIT: %s - ID: %d - CANTIDAD DE PUBLICACIONES PAUSADAS: %d \n \n",arrayClientes->nombre , arrayClientes->apellido, arrayClientes->cuit,arrayClientes->id,contadorPublicaciones);
	}
	return retorno;
}

/**
 * \brief imprime UN SOLO cliente con la cantidad de publicaciones TOTALES
 * \param array  de clientes
 * \param tamaño del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirClienteTotalPub (clientes* arrayClientes, int contadorPublicaciones)
{
	int retorno=-1;
	if(arrayClientes != NULL && arrayClientes->isEmpty == 0)
	{
		retorno=0;
		printf("NOMBRE: %s - APELIIDO: %s - CUIT: %s - CANTIDAD DE PUBLICACIONES: %d \n \n",arrayClientes->nombre , arrayClientes->apellido, arrayClientes->cuit,contadorPublicaciones);
	}
	return retorno;
}



int cli_altaForzadaArray(clientes* array,int limiteClientes, int indice, int* id,char* nombre,char* apellido, char* cuit)

{
	int respuesta = -1;
	clientes buffer;

	if(array != NULL && limiteClientes > 0 && indice < limiteClientes && indice >= 0 && id != NULL)
	{
			strncpy(buffer.nombre,nombre,NOMBRE_LEN);
			strncpy(buffer.apellido,apellido,APELLIDO_LEN);
			strncpy(buffer.cuit,cuit,CUIT_LEN);
			respuesta = 0;
			buffer.id = *id;
			buffer.isEmpty = 0;
			array[indice] = buffer;
			(*id)++;
	}
	return respuesta;
}

//prueba parael 9/1
int cli_clienteConMensajePublicaciones (clientes* arrayClientes, int indice, int contador)
{
	int retorno=-1;

	if (arrayClientes != NULL &&  indice > 0 && contador > 0)
	{
		printf("NOMBRE %s - APELLIDO %s - CUIT: %s - ID: %d PUBLICACIONES ACTIVAS: %d \n", arrayClientes[indice].nombre,arrayClientes[indice].apellido, arrayClientes[indice].cuit, arrayClientes[indice].id, contador);
	}

	return retorno;

}
