/*
 * informes.h
 *
 *  Created on: 8 may. 2020
 *      Author: Juan
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "publicaciones.h"


int info_imprimirClientesConCantidadDePublicaciones (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones);  //punto 7
int info_imprimePublicacionesCuit (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones);
int info_clienteConMasActivas (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones); //punto 9/1
int info_clienteConMasPausadas (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones); //punto 9/2
int info_clientePublicacionesTotal (clientes* arrayClientes,int limiteClientes,publicaciones* arrayPublicaciones,int limitePublicaciones); // punto 9/3
#endif /* INFORMES_H_ */
