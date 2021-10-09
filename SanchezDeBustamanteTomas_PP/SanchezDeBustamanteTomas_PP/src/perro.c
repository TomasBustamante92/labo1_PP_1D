/*
 * perro.c
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */


#include "perro.h"

void mostrarPerro(Perro perro)
{
	printf("%-15s %-15s %-15d \n",perro.nombre, perro.raza, perro.edad);
}

int mostrarPerros(Perro* perros, int len)
{
	int retorno = -1;
	int i;

	printf("%-15s %-15s %-15s \n\n","Nombre", "Raza", "Edad");
	for(i=0 ; i<len ; i++)
	{
		if(perros[i].isEmpty == OCUPADO)
		{
			mostrarPerro(perros[i]);
			retorno = 0;
		}
	}

	return retorno;
}

int compararPerroNombre(Perro* perros, int len,char* nombrePerro)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<len ; i++)
	{
		if(strcmp(nombrePerro, perros[i].nombre) == 0)
		{
			retorno = i;
		}
	}

	return retorno;
}













