/*
 * estadiaDiaria.c
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */


#include "estadiaDiaria.h"

void inicializarEstadiaIsEmpty(EstadiaDiaria* lista, int len)
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


int encontrarLugarEstadia(EstadiaDiaria* lista, int estadiaLen)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<estadiaLen ; i++)
	{
		if(lista[i].isEmpty == VACIO)
		{
			retorno = i;
			break;
		}
	}


	return retorno;
}


int indiceEstadiaPorId(EstadiaDiaria* lista, int estadiaLen, int id)
{
	int retorno = -1;
	int i;

	for(i=0 ; i<estadiaLen ; i++)
	{
		if(lista[i].id == id)
		{
			retorno = i;
		}
	}

	return retorno;

}

void ordenarEstadia(EstadiaDiaria* lista, int estadiaLen)
{
	int i;
	int flagSwap;
	int nuevaEstadiaLen = estadiaLen -1;
	EstadiaDiaria estadiaAux;

	do{
		flagSwap = -1;

		for(i=0 ; i<nuevaEstadiaLen ; i++)
		{
			if(lista[i].fecha.anio < lista[i+1].fecha.anio)
			{
				estadiaAux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = estadiaAux;

				flagSwap = 0;
			}
			else if(lista[i].fecha.anio == lista[i+1].fecha.anio && lista[i].fecha.mes < lista[i+1].fecha.mes)
			{
				estadiaAux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = estadiaAux;

				flagSwap = 0;
			}
			else if(lista[i].fecha.anio == lista[i+1].fecha.anio && lista[i].fecha.mes == lista[i+1].fecha.mes && lista[i].fecha.dia < lista[i+1].fecha.dia)
			{
				estadiaAux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = estadiaAux;

				flagSwap = 0;
			}
			else if(lista[i].fecha.anio == lista[i+1].fecha.anio && lista[i].fecha.mes == lista[i+1].fecha.mes && lista[i].fecha.dia == lista[i+1].fecha.dia)
			{
				if(strcmp(lista[i].nombreDuenio, lista[i+1].nombreDuenio) < 0)
				{
					estadiaAux = lista[i];
					lista[i] = lista[i+1];
					lista[i+1] = estadiaAux;

					flagSwap = 0;
				}
			}
		}
		nuevaEstadiaLen--;

	} while(flagSwap == -1);
}











