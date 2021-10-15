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
	int idDuenio = 30004; // arranca en el 30004 por los datos hardcodeados

	float promedioDeEdadPerritos;

	Perro perros[PERROS_LEN] = { 	{7000, "Lobo", "Sharpei", 2, 0, OCUPADO},
									{7001, "Sheila", "Golden", 12, 0, OCUPADO},
									{7002, "Reina", "Galgo", 13, 0, OCUPADO},
	};

	EstadiaDiaria estadias[100];

	sDuenio duenios[DUENIOS_LEN];

	inicializarDuenioIsEmpty(duenios, DUENIOS_LEN);

	// Duenios hardcodeados
	sDuenio dueniosAux[5]  = { 	{30000, "Juan", 1152458753, OCUPADO},
								{30001, "Lucia", 1124222012, OCUPADO},
								{30002, "Hernan", 1169858740, OCUPADO},
								{30003, "Marcelo", 1124222012, OCUPADO},
								{30004, "Nicolas", 1169858740, OCUPADO},
	};

	duenios[0] = dueniosAux[0];
	duenios[1] = dueniosAux[1];
	duenios[2] = dueniosAux[2];
	duenios[3] = dueniosAux[3];
	duenios[4] = dueniosAux[4];


	inicializarEstadiaIsEmpty(estadias, 100);

	do{
		if(input_getNumero(&opcion, "\n1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Perro con mas estadias \n"
									"8. Listado de perros con sus estadias \n"
									"9. Salir\n"
									"Ingrese una opcion: ",
									"\n1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Perro con mas estadias \n"
									"8. Listado de perros con sus estadias \n"
									"9. Salir\n"
									"ERROR. Ingrese una opcion: ", 1, 9) == -1)
		{
			limpiarPantalla();
			printf("ERROR FATAL! \n\n");
		}

		switch(opcion)
		{
			case 1:
				if(confirmarEstadia(estadias, ESTADIA_LEN, idEstadia, duenios , DUENIOS_LEN,perros, PERROS_LEN) == 0)
				{
					limpiarPantalla();
					printf("Reserva exitosa \n\n");
					idDuenio++;
					idEstadia++;
				}
				break;
			case 2:
				if(modificarEstadia(estadias, ESTADIA_LEN, idEstadia, duenios,DUENIOS_LEN, perros, PERROS_LEN) == 0)
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

				if(cancelarEstadia(estadias, ESTADIA_LEN, idEstadia, duenios, DUENIOS_LEN, perros, PERROS_LEN) == 0)
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
				ordenarEstadia(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN);

				if(imprimirEstadias(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN) == -1)
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
					printf("\nPromedio de edad de perros: %.2f \n", promedioDeEdadPerritos);
				}
				else
				{
					limpiarPantalla();
					printf("No hay perros en la base de datos \n");
				}

				break;

			case 7:
				limpiarPantalla();
				if(perrosConMasEstadias(perros, PERROS_LEN) == -1)
				{
					printf("No hay reservas");
				}

				break;

			case 8:
				limpiarPantalla();
				mostrarPerrosConEstadias(perros, PERROS_LEN, estadias, ESTADIA_LEN, duenios, DUENIOS_LEN);
				break;
			case 9:
				limpiarPantalla();
				printf("Adios!\n");
				break;
		}

	} while (opcion != 9);

	return EXIT_SUCCESS;
}
