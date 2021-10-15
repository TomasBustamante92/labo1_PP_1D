/*
 * perro.h
 *
 *  Created on: Oct 7, 2021
 *      Author: user
 */

#ifndef PERRO_H_
#define PERRO_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


#define PERROS_LEN 3
#define NOMBRE_PERRO 21
#define VACIO 1
#define OCUPADO 0



typedef struct{
	int id;
	char nombre[NOMBRE_PERRO];
	char raza[NOMBRE_PERRO];
	int edad;

	int contadorEstadias;
	int isEmpty;
}Perro;

/// @fn void mostrarPerro(Perro)
/// @brief imprime datos de un perro
///
/// @param perro estructura de un perro
void mostrarPerro(Perro perro);

/// @fn int mostrarPerros(Perro*, int)
/// @brief muestra todos los perros en la base de datos
///
/// @param perros array de perros
/// @param len longitud del array de perros
/// @return devuelve [0] en caso de poder mostrar los perros, caso que no haya ninguno devuelve [-1]
int mostrarPerros(Perro* perros, int len);

/// @fn int compararPerroNombre(Perro*, int, char*)
/// @brief dado un nombre lo compara en la lista de perros para verificar que este
///
/// @param perros array de perros
/// @param len longitud del array de perros
/// @param nombrePerro nombre para buscar en el array de perros
/// @return devuelve el ID del perro encontrar, caso de que no se encontrara uno devuelve [-1]
int compararPerroNombre(Perro* perros, int len,char* nombrePerro);

/// @fn float promedioDeEdadDePerros(Perro*, int)
/// @brief devuelve el promedio de edad de los perros
///
/// @param perros array de perros
/// @param perrosLen longitud del array de perros
/// @return devuelve el promedio de los perros, caso de que no haya ninguno devuelve [-1]
float promedioDeEdadDePerros(Perro* perros,int perrosLen);

/// @fn int perrosConMasEstadias(Perro*, int)
/// @brief Imprime el valor de perros con mas estadias
///
/// @param perros array de perros
/// @param perrosLen longitud del array de perros
/// @return si hay perros para imprimir devuelve [0], caso contrario devuelve [-1]
int perrosConMasEstadias(Perro* perros,int perrosLen);


#endif /* PERRO_H_ */
