/*
 * perro-estadia.c
 *
 *  Created on: Oct 8, 2021
 *      Author: user
 */

#include "perro-estadia.h"

int reservarUnaEstadia(EstadiaDiaria* lista, int estadiaLen, int indiceEstadia, int id, Perro* perros, int perrosLen)
{
	int retorno = -1;
	EstadiaDiaria estadiaAux;
	char nombrePerro[NOMBRE_PERRO];
	int indicePerros;

		estadiaAux.id = id +1;

		if(input_requestStringOnlyLetters(estadiaAux.nombreDuenio, "Nombre del dueño: ", "ERROR. Nombre del dueño: ", 21) == -1)
		{
			printf("ERROR FATAL");
		}

		if(input_getNumero(&estadiaAux.telefonoContacto, "Telefono de contacto: ", "ERROR. Telefono de contacto [11********]: ", 1100000000, 1199999999))
		{
			printf("ERROR FATAL");
		}

		estadiaAux.fecha = pedirFecha();

		while(checkUnPerroPorDia(lista, estadiaLen, estadiaAux.fecha) == -1)
		{
			printf("Esta fecha ya se encuentra reservada, eliga otra: ");
			estadiaAux.fecha = pedirFecha();
		}

		if(mostrarPerros(perros, perrosLen) == -1)
		{
			printf("No hay perros en la base de datos \n");
		}

		do{
			if(input_getString(nombrePerro, "Nombre del perro: ", "Perro no encontrado, ingrese otro: ", NOMBRE_PERRO) == -1)
			{
				printf("ERROR FATAL");
			}

			indicePerros = compararPerroNombre(perros, perrosLen, nombrePerro);

		} while(indicePerros == -1);

		imprimirEstadiaMenu();
		imprimirEstadia(estadiaAux, perros, indicePerros);
		if(confirmacion("Confirmar reserva [si]: ", "Confirmar reserva [si]: ") == 0)
		{
			lista[indiceEstadia] = estadiaAux;
			retorno = 0;
		}

	return retorno;
}

void imprimirEstadia(EstadiaDiaria estadia, Perro* perros, int indicePerros)
{

	printf("%-15d %-15s %-15d %d/%d/%-15d %-15s %-15s %-15d \n",
			estadia.id, estadia.nombreDuenio, estadia.telefonoContacto, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio, perros[indicePerros].nombre, perros[indicePerros].raza, perros[indicePerros].edad);
}

void imprimirEstadiaMenu(void)
{
	printf("\n%-15s %-15s %-15s %-15s %-15s %-15s %-15s \n\n", "ID", "Dueño", "Telefono", "Fecha", "Perro", "Raza", "Edad");
}


int confirmarEstadia(EstadiaDiaria* lista, int estadiaLen, int id, Perro* perros, int perrosLen)
{
	int retorno = -1;
	int indiceEstadia;

	indiceEstadia = encontrarLugar(lista, estadiaLen);

	if(indiceEstadia != -1)
	{
		if(reservarUnaEstadia(lista, estadiaLen, indiceEstadia, id, perros, perrosLen) == 0)
		{
			printf("Se reservo la estadia \n");
			lista[indiceEstadia].isEmpty = OCUPADO;
			return 0;
		}
		else
		{
			printf("Se cancelo la reserva \n");
		}
	}
	else
	{
		printf("No hay lugar \n");
	}

	return retorno;
}



