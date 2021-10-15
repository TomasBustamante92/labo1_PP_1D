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

/// @fn int mostrarDuenios(sDuenio*, int)
/// @brief imprime en pantalla todos los duenios
///
/// @param lista array de duenios
/// @param len longitud del array de duenios
/// @return devuelve [0] en caso de que haya duenios para imprimir, caso contrario devuelve [-1]
int mostrarDuenios(sDuenio* lista, int len);

/// @fn void mostrarDuenio(sDuenio)
/// @brief imprime un duenio en pantalla
///
/// @param duenio estructura de un duenio
void mostrarDuenio(sDuenio duenio);

/// @fn int encontrarDuenioId(sDuenio*, int, int)
/// @brief compara ids de duenio y devuelve el indice
///
/// @param lista array de duenios
/// @param len longitud del array de duenios
/// @param reservaId ID a comparar
/// @return si encuentra el ID devuelve el indice, caso contrario devuelve [-1]
int encontrarDuenioId(sDuenio* lista, int len, int reservaId);

/// @fn int compararDuenioNombre(sDuenio*, int, char*)
/// @brief busca al duenio en el array de duenios
///
/// @param lista array de duenios
/// @param len longitud del array de duenios
/// @param nombreDuenio nombre a buscar
/// @return si encuentra al duenio devuelve el ID, caso contrario devuelve [-1]
int compararDuenioNombre(sDuenio* lista, int len,char* nombreDuenio);

/// @fn void inicializarDuenioIsEmpty(sDuenio*, int)
/// @brief inicializa el array de duenios en VACIO
///
/// @param lista array de duenios
/// @param len longitud del array de duenios
void inicializarDuenioIsEmpty(sDuenio* lista, int len);


#endif /* DUENIO_H_ */
