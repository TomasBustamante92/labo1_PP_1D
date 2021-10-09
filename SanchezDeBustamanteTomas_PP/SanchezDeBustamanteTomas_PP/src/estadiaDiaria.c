/*
 * estadiaDiaria.c
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */


#include "estadiaDiaria.h"

void inicializarIsEmpty(EstadiaDiaria* lista, int len)
{
	int i;

	for(i=0; i<len ; i++)
	{
		lista[i].isEmpty = VACIO;
	}
}



sFecha pedirFecha(void)
{
	sFecha fecha;

	if(input_getNumero(&fecha.dia, "Ingrese dia: ", "ERROR. Ingrese dia: ", 1, 31) == -1)
	{
		printf("ERROR FATAL");
	}

	if(input_getNumero(&fecha.mes, "Ingrese mes: ", "ERROR. Ingrese mes: ", 1, 12) == -1)
	{
		printf("ERROR FATAL");
	}

	if(input_getNumero(&fecha.anio, "Ingrese año: ", "ERROR. Ingrese año [ej: 2021]: ", 2000, 2021) == -1)
	{
		printf("ERROR FATAL");
	}

	return fecha;
}

int checkUnPerroPorDia(EstadiaDiaria* lista, int estadiaLen, sFecha fecha)
{
	int retorno = 0;
	int i;

	for(i=0 ; i<estadiaLen ; i++)
	{
		if(lista[i].fecha.dia == fecha.dia && lista[i].fecha.mes == fecha.mes && lista[i].fecha.anio == fecha.anio)
		{
			retorno = -1;
			break;
		}
	}

	return retorno;
}

int encontrarLugar(EstadiaDiaria* lista, int estadiaLen)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<estadiaLen ; i++)
	{
		if(lista[i].isEmpty == VACIO)
		{
			retorno = i;
		}
	}


	return retorno;
}







