/*
 * duenio.c
 *
 *  Created on: Oct 15, 2021
 *      Author: user
 */

#include "duenio.h"
#define VACIO 1
#define OCUPADO 0

void mostrarDuenio(sDuenio duenio)
{
	printf("%-15s %-15d \n",duenio.nombre, duenio.telefono);
}

int mostrarDuenios(sDuenio* lista, int len)
{
	int retorno = -1;
	int i;

	limpiarPantalla();
	printf("%-15s %-15s \n\n", "Nombre", "Telefono");

	if(lista != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				mostrarDuenio(lista[i]);
				retorno = 0;
			}
		}

		printf("\n");
	}

	return retorno;
}


int compararDuenioNombre(sDuenio* lista, int len,char* nombreDuenio)
{
	int retorno = -1;
	int i;
	char duenio1[strlen(nombreDuenio)];
	char duenio2[len];

	strcpy(duenio1,nombreDuenio);
	convertirStringMinuscula(duenio1);

	if(lista != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			strcpy(duenio2,lista[i].nombre);
			convertirStringMinuscula(duenio2);

			if(strcmp(duenio1, duenio2) == 0)
			{
				retorno = lista[i].id;
				break;
			}
		}
	}

	return retorno;
}


void inicializarDuenioIsEmpty(sDuenio* lista, int len)
{
	int i;

	if(lista != NULL && len > 0)
	{
		for(i=0; i<len ; i++)
		{
			lista[i].isEmpty = VACIO;
		}
	}
}

int encontrarDuenioId(sDuenio* lista, int len, int reservaId)
{
	int retorno = -1;
	int i;

	if(lista != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			if(lista[i].id == reservaId)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

