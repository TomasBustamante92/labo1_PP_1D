/*
 * perro-estadia.c
 *
 *  Created on: Oct 8, 2021
 *      Author: user
 */

#include "perro-estadia.h"

int reservarUnaEstadia(EstadiaDiaria* listaEstadias, int estadiaLen, int indiceEstadia, int idEstadias, sDuenio* listaDuenios, int dueniosLen, Perro* perros, int perrosLen)
{
	int retorno = -1;
	EstadiaDiaria estadiaAux;
	//sDuenio duenioAux;
	char nombrePerro[NOMBRE_PERRO];
	char nombreDuenio[NOMBRE_DUENIO];
	int indicePerros;
	int indiceDuenios;

		limpiarPantalla();

		estadiaAux.id = idEstadias +1;
		//duenioAux.id = idDuenios +1;
		//estadiaAux.idDuenio = duenioAux.id;

		if(mostrarDuenios(listaDuenios, dueniosLen) == -1)
		{
			printf("No hay dueños en la base de datos \n");
		}

		do{
			if(input_getString(nombreDuenio, "Nombre del Dueño: ", "ERROR. Nombre del Dueño: ", NOMBRE_DUENIO) == -1)
			{
				printf("ERROR FATAL");
			}

			estadiaAux.idDuenio = compararDuenioNombre(listaDuenios, dueniosLen, nombreDuenio);

			if(estadiaAux.idDuenio == -1)
			{
				printf("Dueño no encontrado, ingrese otro \n\n");
			}

		} while(estadiaAux.idDuenio == -1);

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
		indiceDuenios = encontrarDuenioId(listaDuenios, dueniosLen, estadiaAux.idDuenio);

		limpiarPantalla();
		imprimirEstadiaMenu();

		imprimirEstadia(estadiaAux, perros, listaDuenios[indiceDuenios], indicePerros);
		if(confirmacion("Confirmar reserva [si]: ", "Confirmar reserva [si]: ") == 0)
		{

			listaEstadias[indiceEstadia] = estadiaAux;
			perros[indicePerros].contadorEstadias = perros[indicePerros].contadorEstadias +1;

			retorno = 0;
		}

	return retorno;
}

void imprimirEstadia(EstadiaDiaria estadia, Perro* perros, sDuenio duenio, int indicePerros)
{

	printf("%-10d %-15s %-14d %2d/%2d/%-8d %-15s %-15s %-15d \n",
			estadia.id, duenio.nombre, duenio.telefono, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio, perros[indicePerros].nombre, perros[indicePerros].raza, perros[indicePerros].edad);
}

int imprimirEstadias(EstadiaDiaria* lista, int estadiaLen, sDuenio* duenios, int dueniosLen, Perro* perros,int perrosLen)
{
	int retorno = -1;
	int i;
	int indicePerros;
	int indiceDuenios;

	limpiarPantalla();
	imprimirEstadiaMenu();

	if(lista != NULL && estadiaLen > 0)
	{
		for(i=0 ; i<estadiaLen ; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				indicePerros = encontrarPerroId(perros, perrosLen, lista[i].idPerro);
				indiceDuenios = encontrarDuenioId(duenios, dueniosLen, lista[i].idDuenio);

				if(indicePerros != -1 && indiceDuenios != -1)
				{
					imprimirEstadia(lista[i], perros, duenios[indiceDuenios], indicePerros);
					retorno = 0;
				}
				else
				{
					printf("No se encontro ningun perro ni dueño en la base de datos\n");
				}

			}
		}
	}
	return retorno;
}

void imprimirEstadiaMenu(void)
{
	printf("\n%-10s %-16s %-14s %-14s %-15s %-15s %-15s \n\n", "ID", "Dueño", "Telefono", "Fecha", "Perro", "Raza", "Edad");
}


int confirmarEstadia(EstadiaDiaria* lista, int estadiaLen, int idEstadia, sDuenio* listaDuenios, int dueniosLen, Perro* perros, int perrosLen)
{
	int retorno = -1;
	int indiceEstadia;

	indiceEstadia = encontrarLugarEstadia(lista, estadiaLen);

	if(indiceEstadia != -1)
	{
		if(reservarUnaEstadia(lista, estadiaLen, indiceEstadia, idEstadia, listaDuenios, dueniosLen,perros, perrosLen) == 0)
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

int cancelarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, sDuenio* duenios, int dueniosLen, Perro* perros,int perrosLen)
{
	int retorno = -1;
	int id;
	int indiceEstadia;
	int indicePerros;
	int indiceDuenios;

	if(imprimirEstadias(lista, estadiaLen, duenios, dueniosLen,  perros, perrosLen) == 0)
	{
		if(	input_getNumero(&id, "Ingrese ID del dia a cancelar: ", "ERROR. Ingrese ID del dia a cancelar: ", 100000, ultimoId) == 0)
		{
			indiceEstadia = encontrarIndiceEstadiaPorId(lista, estadiaLen, id);

			if(indiceEstadia != -1)
			{
				indicePerros = encontrarPerroId(perros, perrosLen, lista[indiceEstadia].idPerro);
				indiceDuenios = encontrarDuenioId(duenios, perrosLen, lista[indiceEstadia].idDuenio);

				limpiarPantalla();
				imprimirEstadiaMenu();

				imprimirEstadia(lista[indiceEstadia], perros, duenios[indiceDuenios], indicePerros);

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

int modificarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, sDuenio* duenios, int dueniosLen, Perro* perros,int perrosLen)
{
	int retorno = -1;
	int id;
	int indiceEstadia;
	int indiceDuenios;
	int indicePerros1;
	int indicePerros2;
	int opciones;
	char nombrePerro[NOMBRE_PERRO];
	EstadiaDiaria estadiaAux;
	sDuenio duenioAux;

	if(imprimirEstadias(lista, estadiaLen, duenios, dueniosLen, perros, perrosLen) == 0)
	{
		if(input_getNumero(&id, "\nIngrese ID del dia a modificar: ", "ERROR. Ingrese ID del dia a modificar: ", 100000, ultimoId) == 0)
		{
			indiceEstadia = encontrarIndiceEstadiaPorId(lista, estadiaLen, id);

			if(indiceEstadia != -1)
			{
			do{
				indicePerros1 = encontrarPerroId(perros, perrosLen, lista[indiceEstadia].idPerro);
				indiceDuenios = encontrarDuenioId(duenios, dueniosLen, lista[indiceEstadia].idDuenio);

				limpiarPantalla();
				imprimirEstadiaMenu();
				imprimirEstadia(lista[indiceEstadia], perros, duenios[indiceDuenios], indicePerros1);

				estadiaAux = lista[indiceEstadia];
				duenioAux = duenios[indiceDuenios];


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


							if(input_getNumero(&duenioAux.telefono, "Telefono de contacto: ", "ERROR. Telefono de contacto [11********]: ", 1100000000, 1199999999) == 0)
							{
								limpiarPantalla();
								imprimirEstadiaMenu();
								imprimirEstadia(lista[indiceEstadia], perros, duenioAux, indicePerros1);
								if(confirmacion("\nConfirmar modificacion [si]: ", "Confirmar modificacion [si]: ") == 0)
								{
									duenios[indiceDuenios].telefono = duenioAux.telefono;
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

							indicePerros2 = encontrarPerroId(perros, perrosLen, estadiaAux.idPerro);

							limpiarPantalla();
							imprimirEstadiaMenu();
							imprimirEstadia(lista[indiceEstadia], perros, duenios[indiceDuenios], indicePerros2);
							if(confirmacion("\nConfirmar modificacion [si]: ", "Confirmar modificacion [si]: ") == 0)
							{
								perros[indicePerros1].contadorEstadias = perros[indicePerros1].contadorEstadias -1;
								perros[indicePerros2].contadorEstadias = perros[indicePerros2].contadorEstadias +1;

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

void mostrarPerrosConEstadias(Perro* perros, int perrosLen, EstadiaDiaria* estadia, int estadiasLen, sDuenio* duenios, int dueniosLen)
{
	int i;
	int j;
	int duenioIndex;

	for(i=0 ; i<perrosLen ; i++)
	{
		printf("\n\n%s: \n\n", perros[i].nombre);

		printf("%-15s %-15s %-15s \n", "Nombre", "Telefono", "Fecha");

		for(j = 0 ;j<estadiasLen ; j++)
		{
			if(perros[i].id == estadia[j].idPerro)
			{
				duenioIndex = encontrarDuenioId(duenios, dueniosLen, estadia[j].idDuenio);
				printf("%-15s %-15d %-2d/%-2d/%-2d", duenios[duenioIndex].nombre, duenios[duenioIndex].telefono, estadia[j].fecha.dia, estadia[j].fecha.mes, estadia[j].fecha.anio);
			}
		}

	}
}




