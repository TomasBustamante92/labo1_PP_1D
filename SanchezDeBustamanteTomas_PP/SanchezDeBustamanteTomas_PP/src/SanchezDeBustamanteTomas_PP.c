/*
 ============================================================================

	Primer Parcial de Laboratorio I

	Alumno: Tomas Sanchez de Bustamante
	Division: D
	OS: Linux

 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "perro-estadia.h"
#include "input.h"


int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int idEstadia = 100000;
	int promedioDeEdadPerritos;

	Perro perros[PERROS_LEN] = { 	{7000, "Lobo", "Sharpei", 2, OCUPADO},
									{7001, "Sheila", "Golden", 12, OCUPADO},
									{7002, "Reina", "Galgo", 13, OCUPADO},
	};

	EstadiaDiaria estadias[100];

	inicializarEstadiaIsEmpty(estadias, 100);

	do{
		if(input_getNumero(&opcion, "\n1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Salir\n"
									"Ingrese una opcion: ",
									"\n1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Salir\n"
									"ERROR. Ingrese una opcion: ", 1, 7) == -1)
		{
			limpiarPantalla();
			printf("ERROR FATAL! \n\n");
		}

		switch(opcion)
		{
			case 1:
				if(confirmarEstadia(estadias, ESTADIA_LEN, idEstadia, perros, PERROS_LEN) == 0)
				{
					limpiarPantalla();
					printf("Reserva exitosa \n\n");
					idEstadia++;
				}
				break;
			case 2:
				if(modificarEstadia(estadias, ESTADIA_LEN, idEstadia, perros, PERROS_LEN) == 0)
				{
					limpiarPantalla();
					printf("Reserva modificada \n\n");
				}
				else
				{
					limpiarPantalla();
					printf("No hay reservas en la base de datos \n\n");
				}
				break;
			case 3:
				if(cancelarEstadia(estadias, ESTADIA_LEN, idEstadia, perros, PERROS_LEN) == 0)
				{
					limpiarPantalla();
					printf("Reserva cancelada \n\n");
				}
				else
				{
					limpiarPantalla();
					printf("No hay reservas en la base de datos \n\n");
				}
				break;
			case 4:
				ordenarEstadia(estadias, ESTADIA_LEN);

				if(imprimirEstadias(estadias, ESTADIA_LEN, perros, PERROS_LEN) == -1)
				{
					printf("No hay reservas en la base de datos \n\n");
				}
				break;
			case 5:
				if(mostrarPerros(perros, PERROS_LEN) == -1)
				{
					limpiarPantalla();
					printf("No hay perros en la base de datos \n\n");
				}
				break;
			case 6:
				promedioDeEdadPerritos = promedioDeEdadDePerros(perros, PERROS_LEN);

				if(promedioDeEdadPerritos != -1)
				{
					limpiarPantalla();
					printf("\nPromedio de edad de perros: %d \n", promedioDeEdadPerritos);
				}
				else
				{
					limpiarPantalla();
					printf("No hay perros en la base de datos \n");
				}

				break;
			case 7:
				limpiarPantalla();
				printf("Adios!\n");
				break;
		}

	} while (opcion != 7);

	return EXIT_SUCCESS;
}
