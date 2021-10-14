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

		limpiarPantalla();

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

		if(mostrarPerros(perros, perrosLen) == -1)
		{
			printf("No hay perros en la base de datos \n");
		}

		do{
			if(input_getString(nombrePerro, "Nombre del perro: ", "ERROR. Nombre del perro: ", NOMBRE_PERRO) == -1)
			{
				printf("ERROR FATAL");
			}

			estadiaAux.idPerro = compararPerroNombre(perros, perrosLen, nombrePerro);

			if(estadiaAux.idPerro == -1)
			{
				printf("Perro no encontrado, ingrese otro \n\n");
			}

		} while(estadiaAux.idPerro == -1);

		indicePerros = encontrarPerroId(perros, perrosLen, estadiaAux.idPerro);

		limpiarPantalla();
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

	printf("%-10d %-15s %-14d %2d/%2d/%-8d %-15s %-15s %-15d \n",
			estadia.id, estadia.nombreDuenio, estadia.telefonoContacto, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio, perros[indicePerros].nombre, perros[indicePerros].raza, perros[indicePerros].edad);
}

int imprimirEstadias(EstadiaDiaria* lista, int estadiaLen, Perro* perros,int perrosLen)
{
	int retorno = -1;
	int i;
	int indicePerros;

	limpiarPantalla();
	imprimirEstadiaMenu();

	if(lista != NULL && estadiaLen > 0)
	{
		for(i=0 ; i<estadiaLen ; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				indicePerros = encontrarPerroId(perros, perrosLen, lista[i].idPerro);

				if(indicePerros != -1)
				{
					imprimirEstadia(lista[i], perros, indicePerros);
				}
				else
				{
					printf("No se encontro ningun perro \n");
				}
				retorno = 0;

			}
		}
	}
	return retorno;
}

void imprimirEstadiaMenu(void)
{
	printf("\n%-10s %-16s %-14s %-14s %-15s %-15s %-15s \n\n", "ID", "Dueño", "Telefono", "Fecha", "Perro", "Raza", "Edad");
}


int confirmarEstadia(EstadiaDiaria* lista, int estadiaLen, int id, Perro* perros, int perrosLen)
{
	int retorno = -1;
	int indiceEstadia;

	indiceEstadia = encontrarLugarEstadia(lista, estadiaLen);

	if(indiceEstadia != -1)
	{
		if(reservarUnaEstadia(lista, estadiaLen, indiceEstadia, id, perros, perrosLen) == 0)
		{
			lista[indiceEstadia].isEmpty = OCUPADO;
			return 0;
		}
		else
		{
			printf("Se cancelo la reserva \n\n");
		}
	}
	else
	{
		printf("No hay lugar \n\n");
	}

	return retorno;
}

int encontrarPerroId(Perro* perros, int perrosLen, int reservaId)
{
	int retorno = -1;
	int i;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].id == reservaId)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int cancelarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, Perro* perros,int perrosLen)
{
	int retorno = -1;
	int id;
	int indiceEstadia;
	int indicePerros;

	if(imprimirEstadias(lista, estadiaLen, perros, perrosLen) == 0)
	{
		if(	input_getNumero(&id, "Ingrese ID del dia a cancelar: ", "ERROR. Ingrese ID del dia a cancelar: ", 100000, ultimoId) == 0)
		{
			indiceEstadia = encontrarIndiceEstadiaPorId(lista, estadiaLen, id);

			if(indiceEstadia != -1)
			{
				indicePerros = encontrarPerroId(perros, perrosLen, lista[indiceEstadia].idPerro);

				limpiarPantalla();
				imprimirEstadiaMenu();
				imprimirEstadia(lista[indiceEstadia], perros, indicePerros);

				if(confirmacion("\nConfirmar cancelacion [si]: ", "Confirmar cancelacion [si]: ") == 0)
				{
					lista[indiceEstadia].isEmpty = VACIO;
					retorno = 0;
				}
			}
		}
		else
		{
			printf("No se encuentra el ID en la base de datos \n");
		}

	}


	return retorno;
}

int modificarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, Perro* perros,int perrosLen)
{
	int retorno = -1;
	int id;
	int indiceEstadia;
	int indicePerros;
	int opciones;
	char nombrePerro[NOMBRE_PERRO];
	EstadiaDiaria estadiaAux;

	if(imprimirEstadias(lista, estadiaLen, perros, perrosLen) == 0)
	{
		if(input_getNumero(&id, "\nIngrese ID del dia a modificar: ", "ERROR. Ingrese ID del dia a modificar: ", 100000, ultimoId) == 0)
		{
			indiceEstadia = encontrarIndiceEstadiaPorId(lista, estadiaLen, id);

			if(indiceEstadia != -1)
			{
			do{
				indicePerros = encontrarPerroId(perros, perrosLen, lista[indiceEstadia].idPerro);

				limpiarPantalla();
				imprimirEstadiaMenu();
				imprimirEstadia(lista[indiceEstadia], perros, indicePerros);

				estadiaAux = lista[indiceEstadia];


				if(input_getNumero(&opciones, 	"\n1. Modificar telefono de contado \n"
												"2. Modificar perro \n"
												"3. Atras \n"
												"Opcion: ",
												"\n1. Modificar telefono de contado \n"
												"2. Modificar perro \n"
												"3. Atras \n"
												"ERROR. Opcion: ", 1, 3) == 0)
				{
					switch(opciones)
					{
						case 1:


							if(input_getNumero(&estadiaAux.telefonoContacto, "Telefono de contacto: ", "ERROR. Telefono de contacto [11********]: ", 1100000000, 1199999999) == 0)
							{
								limpiarPantalla();
								imprimirEstadiaMenu();
								imprimirEstadia(estadiaAux, perros, indicePerros);
								if(confirmacion("\nConfirmar modificacion [si]: ", "Confirmar modificacion [si]: ") == 0)
								{
									lista[indiceEstadia].telefonoContacto = estadiaAux.telefonoContacto;
									retorno = 0;
								}
							}
							break;
						case 2:
							if(mostrarPerros(perros, perrosLen) == -1)
							{
								printf("No hay perros en la base de datos \n");
							}

							do{
								if(input_getString(nombrePerro, "Nombre del perro: ", "ERROR. Nombre del perro: ", NOMBRE_PERRO) == -1)
								{
									printf("ERROR FATAL");
								}

								estadiaAux.idPerro = compararPerroNombre(perros, perrosLen, nombrePerro);

								if(estadiaAux.idPerro == -1)
								{
									printf("Perro no encontrado, ingrese otro \n\n");
								}

							} while(estadiaAux.idPerro == -1);

							indicePerros = encontrarPerroId(perros, perrosLen, estadiaAux.idPerro);

							limpiarPantalla();
							imprimirEstadiaMenu();
							imprimirEstadia(estadiaAux, perros, indicePerros);
							if(confirmacion("\nConfirmar modificacion [si]: ", "Confirmar modificacion [si]: ") == 0)
							{
								lista[indiceEstadia].idPerro = estadiaAux.idPerro;
								retorno = 0;
							}
							break;
						}
					}
					else
					{
						printf("ERROR FATAL \n");
					}
				} while(opciones != 3);
			}
			else
			{
				printf("No se encuentra el ID en la base de datos \n");
			}
		}

	}
	return retorno;
}





