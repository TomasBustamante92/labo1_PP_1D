/*
 * estadiaDiaria.h
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "input.h"

#define TAM_NOMBRE_DUENIO 21
#define VACIO 1
#define OCUPADO 0
#define ESTADIA_LEN 100

typedef struct{
	int dia;
	int mes;
	int anio;

}sFecha;

typedef struct{
	int id;
	char nombreDuenio[TAM_NOMBRE_DUENIO];
	int telefonoContacto;
	int idPerro;
	sFecha fecha;
	int isEmpty;

}EstadiaDiaria;

void inicializarEstadiaIsEmpty(EstadiaDiaria* lista, int len);
sFecha pedirFecha(void);
int encontrarLugarEstadia(EstadiaDiaria* lista, int estadiaLen);
int indiceEstadiaPorId(EstadiaDiaria* lista, int estadiaLen, int id);
void ordenarEstadia(EstadiaDiaria* lista, int estadiaLen);



#endif /* ESTADIADIARIA_H_ */
