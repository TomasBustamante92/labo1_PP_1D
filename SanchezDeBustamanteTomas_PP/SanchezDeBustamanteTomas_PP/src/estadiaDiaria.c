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

	if(lista != NULL && len > 0)
	{
		for(i=0; i<len ; i++)
		{
			lista[i].isEmpty = VACIO;
		}
	}
}



sFecha pedirFecha(void)
{
	sFecha fecha;
	int fechaAprobada;
	do{
		fechaAprobada = 1;

		if(input_getNumero(&fecha.dia, "Ingrese dia: ", "ERROR. Ingrese dia: ", 1, 31) == -1)
		{
			printf("ERROR FATAL");
		}

		if(input_getNumero(&fecha.mes, "Ingrese mes: ", "ERROR. Ingrese mes: ", 1, 12) == -1)
		{
			printf("ERROR FATAL");
		}

		if(fecha.mes == 2 && fecha.dia > 28)	// Febrero
		{
			fechaAprobada = 0;
			printf("Febrero solo tiene 28 dias \n\n");
		}
		else if(fecha.mes == 4 && fecha.dia > 30)	// abril
		{
			fechaAprobada = 0;
			printf("Abril solo tiene 30 dias \n\n");
		}
		else if(fecha.mes == 6 && fecha.dia > 30)	// junio
		{
			fechaAprobada = 0;
			printf("Junio solo tiene 30 dias \n\n");
		}
		else if(fecha.mes == 9 && fecha.dia > 30)	// septiembre
		{
			fechaAprobada = 0;
			printf("Septiembre solo tiene 30 dias \n\n");
		}
		else if(fecha.mes == 11 && fecha.dia > 30)	// noviembre
		{
			fechaAprobada = 0;
			printf("Noviembre solo tiene 30 dias \n\n");
		}

	} while(fechaAprobada == 0);

	if(input_getNumero(&fecha.anio, "Ingrese año: ", "ERROR. Ingrese año [ej: 2021]: ", 2020, 2023) == -1)
	{
		printf("ERROR FATAL");
	}

	return fecha;
}


int encontrarLugarEstadia(EstadiaDiaria* lista, int estadiaLen)
{
	int retorno = -1;
	int i;

	if(lista != NULL && estadiaLen > 0)
	{
		for(i=0 ; i<estadiaLen ; i++)
		{
			if(lista[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int encontrarIndiceEstadiaPorId(EstadiaDiaria* lista, int estadiaLen, int id)
{
	int retorno = -1;
	int i;

	if(lista != NULL && estadiaLen > 0)
	{
		for(i=0 ; i<estadiaLen ; i++)
		{
			if(lista[i].id == id)
			{
				retorno = i;
				break;
			}
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

	if(lista != NULL && estadiaLen > 0)
	{
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
					if(strcmp(lista[i].nombreDuenio, lista[i+1].nombreDuenio) > 0)
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
}











