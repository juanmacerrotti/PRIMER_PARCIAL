/*
 * cliente.h
 *
 *  Created on: 8 may. 2020
 *      Author: Juan
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "utn.h"
#define NAME_LEN 51
#define APELLIDO_LEN 51
#define CUIT_LEN 12

typedef struct
{
	char nombre [NAME_LEN];
	char apellido [APELLIDO_LEN];
	char cuit [CUIT_LEN];
	int id;
	int isEmpty;
}clientes;

int cli_inicializarArray (clientes* arrayClientes,int len);   //punto 0
int cli_altaArray(clientes* arrayClientes,int len, int indice, int* id); // punto 1
int cli_ModificarCliente(clientes* arrayClientes,int len,int indice, int id); //punto 2
int cli_buscaClientePorId (clientes* arrayClientes,int len, int id); //punto2
int cli_removerCliente(clientes* arrayClientes,int len, int id); //punto 3
int cli_imprimirListaClientes (clientes* arrayClientes,int len); // punto 4 y 6
int cli_imprimeArrayClientes (clientes* arrayClientes,int limite);  //punto5
int cli_getEmptyIndex(clientes* arrayClientes,int len);   //busca indice libre (GENERAL)
int cli_bajaTotalDeEmpleados (clientes* arrayClientes, int len);  //bloquea menu  (GENERAL)
int cli_imprimiraux(clientes* arrayClientes);
int cli_imprimir(clientes* arrayClientes,int limite, int id);
int cli_imprimirListaClientesPublicacionesActivas (clientes* arrayClientes,int len,int contadorDeActivas);
int cli_imprimirClienteActivas (clientes* arrayClientes, int contadorPublicaciones);  	// PUNTO 9/1
int cli_imprimirClientePausada (clientes* arrayClientes, int contadorPublicaciones); 	// PUNTO 9/2
int cli_imprimirClienteTotalPub (clientes* arrayClientes, int contadorPublicaciones);	// PUNTO 9/3

int cli_clienteConMensajePublicaciones (clientes* arrayClientes, int indice, int contador);

int cli_altaForzadaArray(clientes* array,int limiteClientes, int indice, int* id,char* nombre,char* apellido, char* cuit);

#endif /* CLIENTE_H_ */


