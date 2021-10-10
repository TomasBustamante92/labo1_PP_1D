/*
 * perro-estadia.h
 *
 *  Created on: Oct 8, 2021
 *      Author: user
 */

#ifndef PERRO_ESTADIA_H_
#define PERRO_ESTADIA_H_

#include "perro.h"
#include "estadiaDiaria.h"
#include <string.h>

int reservarUnaEstadia(EstadiaDiaria* lista, int estadiaLen, int indiceEstadia, int id, Perro* perros, int perrosLen);
int confirmarEstadia(EstadiaDiaria* lista, int estadiaLen, int id, Perro* perros, int perrosLen);
void imprimirEstadia(EstadiaDiaria estadia, Perro* perros, int indicePerros);
void imprimirEstadiaMenu(void);
int imprimirEstadias(EstadiaDiaria* lista, int estadiaLen, Perro* perros,int perrosLen);
int encontrarPerroId(Perro* perros, int perrosLen, int reservaId);
int cancelarEstadia (EstadiaDiaria* lista, int estadiaLen, int ultimoId, Perro* perros,int perrosLen);
int modificarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, Perro* perros,int perrosLen);
#endif /* PERRO_ESTADIA_H_ */
