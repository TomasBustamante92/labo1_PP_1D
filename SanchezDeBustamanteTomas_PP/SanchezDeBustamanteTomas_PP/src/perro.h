/*
 * perro.h
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */

#ifndef PERRO_H_
#define PERRO_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


#define PERROS_LEN 3
#define NOMBRE_PERRO 21
#define VACIO 1
#define OCUPADO 0



typedef struct{
	int id;
	char nombre[NOMBRE_PERRO];
	char raza[NOMBRE_PERRO];
	int edad;

	int isEmpty;
}Perro;

void mostrarPerro(Perro perro);
int mostrarPerros(Perro* perros, int len);
int compararPerroNombre(Perro* perros, int len,char* nombrePerro);

#endif /* PERRO_H_ */
