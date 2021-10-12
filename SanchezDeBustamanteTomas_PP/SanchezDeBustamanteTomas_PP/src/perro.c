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

	limpiarPantalla();
	printf("%-15s %-15s %-15s \n\n","Nombre", "Raza", "Edad");

	if(perros != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			if(perros[i].isEmpty == OCUPADO)
			{
				mostrarPerro(perros[i]);
				retorno = 0;
			}
		}

		printf("\n");
	}

	return retorno;
}

int compararPerroNombre(Perro* perros, int len,char* nombrePerro)
{
	int retorno = -1;
	int i;
	char perro1[strlen(nombrePerro)];
	char perro2[len];

	strcpy(perro1,nombrePerro);
	convertirStringMinuscula(perro1);

	if(perros != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			strcpy(perro2,perros[i].nombre);
			convertirStringMinuscula(perro2);

			if(strcmp(perro1, perro2) == 0)
			{
				retorno = perros[i].id;
				break;
			}
		}
	}

	return retorno;
}


float promedioDeEdadDePerros(Perro* perros,int perrosLen)
{
	float promedio = -1;
	int i;
	int contador = 0;
	int acumuladorEdades = 0;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].isEmpty == OCUPADO)
			{
				acumuladorEdades += perros[i].edad;
				contador++;
			}
		}

		if(contador > 0)
		{
			promedio = (float)acumuladorEdades / contador;
		}
	}

	return promedio;
}






