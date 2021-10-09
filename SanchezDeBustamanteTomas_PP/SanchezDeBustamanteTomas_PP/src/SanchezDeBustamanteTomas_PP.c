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
	Perro perros[PERROS_LEN] = { 	{7000, "Lobo", "Sharpei", 2, OCUPADO},
									{7001, "Sheila", "Golden", 12, OCUPADO},
									{7002, "Reina", "Galgo", 13, OCUPADO},
	};

	EstadiaDiaria estadias[100];

	inicializarIsEmpty(estadias, 100);


	do{
		if(input_getNumero(&opcion, "1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Salir\n"
									"Ingrese una opcion: ",
									"1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Salir\n"
									"ERROR. Ingrese una opcion: ", 1, 7) == -1)
		{
			printf("ERROR FATAL!");
		}

		switch(opcion)
		{
			case 1:
				if(confirmarEstadia(estadias, ESTADIA_LEN, idEstadia, perros, PERROS_LEN) ==0)
				{
					idEstadia++;
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				printf("Adios!\n");
				break;
		}

	} while (opcion != 7);

	return EXIT_SUCCESS;
}
