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

/// @fn void inicializarEstadiaIsEmpty(EstadiaDiaria*, int)
/// @brief convierte todos los isEmpty del array en VACIO
///
/// @param lista array de estadias
/// @param len longitud del array de estadias
void inicializarEstadiaIsEmpty(EstadiaDiaria* lista, int len);

/// @fn sFecha pedirFecha(void)
/// @brief pedir dia mes y anio y lo devuelve en una estructura
///
/// @return devuelve estructura de la fecha
sFecha pedirFecha(void);

/// @fn int encontrarLugarEstadia(EstadiaDiaria*, int)
/// @brief busca en el array por el primer lugar con el valor VACIO en isEmpty
///
/// @param lista array de estadias
/// @param estadiaLen  longitud del array de estadias
/// @return devuelve el indice del primero lugar con el valor VACIO, caso de no encontrar devuelve [-1]
int encontrarLugarEstadia(EstadiaDiaria* lista, int estadiaLen);

/// @fn int encontrarIndiceEstadiaPorId(EstadiaDiaria*, int, int)
/// @brief busca el id en el array de estadias y si lo encuentra devuelve el indice
///
/// @param lista array de estadias
/// @param estadiaLen longitud de array de estadias
/// @param id ID que se desee buscar el indice
/// @return de encontrarlo en el array se devuelve el indice, caso contrario devuelve [-1]
int encontrarIndiceEstadiaPorId(EstadiaDiaria* lista, int estadiaLen, int id);

/// @fn void ordenarEstadia(EstadiaDiaria*, int)
/// @brief ordena el array de estadia por fecha y nombre
///
/// @param lista array de estadias
/// @param estadiaLen longitud del array de estadias
void ordenarEstadia(EstadiaDiaria* lista, int estadiaLen);



#endif /* ESTADIADIARIA_H_ */
