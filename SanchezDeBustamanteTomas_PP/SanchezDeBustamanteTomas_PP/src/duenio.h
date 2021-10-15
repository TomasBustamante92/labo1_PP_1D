/*
 * duenio.h
 *
 *  Created on: Oct 15, 2021
 *      Author: user
 */

#ifndef DUENIO_H_
#define DUENIO_H_

#define NOMBRE_DUENIO 41
#define DUENIOS_LEN 100


#include <stdio_ext.h>
#include <stdlib.h>
#include "input.h"

typedef struct
{
	int id;
	char nombre[NOMBRE_DUENIO];
	int telefono;

	int isEmpty;
}sDuenio;

int mostrarDuenios(sDuenio* lista, int len);
void mostrarDuenio(sDuenio duenio);
int encontrarDuenioId(sDuenio* lista, int len, int reservaId);

int compararDuenioNombre(sDuenio* lista, int len,char* nombreDuenio);


//int encontrarLugarDuenio(sDuenio* lista, int duenioLen);
void inicializarDuenioIsEmpty(sDuenio* lista, int len);


#endif /* DUENIO_H_ */
