/*
 * Publicaciones.h
 *
 *  Created on: 8 may. 2020
 *      Author: Juan
 */

#ifndef PUBLICACIONES_H_
#define PUBLICACIONES_H_

#define TEXTO_LEN 65

#define ESTADO_ACTIVA	1
#define ESTADO_PAUSADO	0

#include "utn.h"


typedef struct
{
	int numeroDeRubro;
	char texto [TEXTO_LEN];
	int estado;
	int idPublicacion;
	int idCliente;
	int isEmpty;
}publicaciones;

int pub_inicializarArray (publicaciones* arrayPublicaciones, int len);
int pub_altaArray(publicaciones* arrayPublicaciones, int len, int indice, int idCliente, int* id);
int pub_getEmptyIndex(publicaciones* arrayPublicaciones,int len);
int pub_bajaPublicacion (publicaciones* arrayPublicaciones,int len,int id);
int pub_estadoPausado(publicaciones* arrayPublicaciones, int indice , int* respuesta);
int pub_estadoActivo(publicaciones* arrayPublicaciones, int indice, int* confirmacionEstado);
int pub_imprimirListaPublicaciones (publicaciones* arrayPublicaciones,int len);
int pub_imprimirActivas(publicaciones* arrayPublicaciones,int len);
int pub_imprimirPausadas(publicaciones* arrayPublicaciones,int len);
int pub_imprimirPublicaciones (publicaciones* arrayPublicaciones,int len, char* cuit);
int pub_imprimirListaPublicacionesPorId (publicaciones* arrayPublicaciones,int len, int id);
int pub_bajaTotalDePublicaciones (publicaciones* arrayPublicaciones, int len);
int pub_idCliente (publicaciones* arrayPublicaciones, int limitePublicaciones, int idPublicacion, int* aux); // para punto 5
int pub_cantidadPublicacionesActivas (publicaciones* arrayPublicaciones, int limitePublicaciones, int idCliente);
int pub_cantidadPublicacionesPausadas (publicaciones* arrayPublicaciones, int limitePublicaciones, int idCliente); //punto 9/2
int pub_cantidadPublicacionesTotal (publicaciones* arrayPublicaciones, int limitePublicaciones, int idCliente); //punto 9/3
int pub_cantidadDePublicacionesDeRubro(publicaciones* arrayPublicaciones, int limitePublicaciones, int rubro); //punto 10 1
int pub_rubroMasActivo(publicaciones* arrayPublicaciones, int limitePublicaciones); //punto 10
int pub_cantidadPublicacionesActivasPorRubro (publicaciones* arrayPublicaciones, int limitePublicaciones, int rubro);
int pub_imprimirPublicacion (publicaciones* arrayPublicaciones, char cuit); //punto 8
int pub_DoyIdMeDaIndice(publicaciones* arrayPublicaciones,int len, int id);
int pub_cantidadPublicacionesPausadasPorRubro (publicaciones* arrayPublicaciones, int limitePublicaciones, int rubro);
int pub_contadorPublicacionesActivasPorRubro (publicaciones* arrayPublicaciones,int limite, int *auxRubro);

int info_publicacionMasActivaFinal (publicaciones* arrayPublicaciones, int limitePublicaciones);
int info_publicacionMasPausadaFinal (publicaciones* arrayPublicaciones, int limitePublicaciones);
#endif /* PUBLICACIONES_H_ */
