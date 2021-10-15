/*
 * perro-estadia.h
 *
 *  Created on: Oct 8, 2021
 *      Author: user
 */

#ifndef PERRO_ESTADIA_H_
#define PERRO_ESTADIA_H_

#include "perro.h"
#include "estadiaDiaria.h"
#include "duenio.h"
#include <string.h>

/// @fn int reservarUnaEstadia(EstadiaDiaria*, int, int, int, Perro*, int)
/// @brief Pide los datos al usuario de una estadia y pide confirmar, si confirma se guardan en el array de estadia
///
/// @param lista	array de estadias
/// @param estadiaLen	longitud del array de estadias
/// @param indiceEstadia	indice del array donde se guardan los datos si confirma
/// @param id	ultimo numero de ID usado anteriormente
/// @param perros	array de perros
/// @param perrosLen	longitud del array de perros
/// @return en caso de que el usuario confirme devuelve [0] caso contrario devuelve [-1]
int reservarUnaEstadia(EstadiaDiaria* listaEstadias, int estadiaLen, int indiceEstadia, int idEstadias, sDuenio* listaDuenios, int dueniosLen, Perro* perros, int perrosLen);

/// @fn int confirmarEstadia(EstadiaDiaria*, int, int, Perro*, int)
/// @brief llama a la funcion reservarUnaEstadia pidiendo confirmacion de la estadia, si esa funcioncion devuelve [0] se cambiara el parametro isEmpty a [OCUPADO]
///
/// @param lista array de estadias
/// @param estadiaLen longitud del array de estadias
/// @param id ultimo numero de ID usado anteriormente
/// @param perros array de perros
/// @param perrosLen longitud del array de perros
/// @return en caso de que el usuario confirme devuelve [0] caso contrario devuelve [-1]
int confirmarEstadia(EstadiaDiaria* lista, int estadiaLen, int idEstadia, sDuenio* listaDuenios, int dueniosLen, Perro* perros, int perrosLen);

/// @fn void imprimirEstadia(EstadiaDiaria, Perro*, int)
/// @brief imprime datos de una estadia
///
/// @param estadia una estadia
/// @param perros array de perros
/// @param indicePerros  longitud del array de perros
void imprimirEstadia(EstadiaDiaria estadia, Perro* perros, sDuenio duenio, int indicePerros);

/// @fn void imprimirEstadiaMenu(void)
/// @brief Imprime nombre de datos del menu que van arriba de los datos de las estadias y perros
///
void imprimirEstadiaMenu(void);

/// @fn int imprimirEstadias(EstadiaDiaria*, int, Perro*, int)
/// @brief imprime array de estadias
///
/// @param lista array de estadias
/// @param estadiaLen longitud del array de estadias
/// @param perros array de perros
/// @param perrosLen longitud del array de perros
/// @return devuelve [0] en caso de que se pueda imprimir, caso contrario no hay ninguna estadia y devuelve [-1]
int imprimirEstadias(EstadiaDiaria* lista, int estadiaLen, sDuenio* duenios, int dueniosLen, Perro* perros,int perrosLen);

/// @fn int encontrarPerroId(Perro*, int, int)
/// @brief se le ingresa un ID y lo busca en el array de perros, caso de que lo encuentre devuelve el indice
///
/// @param perros array de perros
/// @param perrosLen longitud de array de perros
/// @param reservaId ID que se desee buscar el indice
/// @return caso de encontrar al perro se devulve el indice, sino se encuentra devuelve [-1]
int encontrarPerroId(Perro* perros, int perrosLen, int reservaId);

/// @fn int cancelarEstadia(EstadiaDiaria*, int, int, Perro*, int)
/// @brief dar de baja logica una estadia
///
/// @param lista array de estadias
/// @param estadiaLen longitud del array de estadias
/// @param ultimoId ultimo ID ingresado anteriormente
/// @param perros array de perros
/// @param perrosLen longitud de array de perros
/// @return caso de confirmar cancelacion devuelve [0] caso contrario devuelve [-1]
int cancelarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, sDuenio* duenios, int dueniosLen, Perro* perros,int perrosLen);

/// @fn int modificarEstadia(EstadiaDiaria*, int, int, Perro*, int)
/// @brief el usuario puede modificar el telefono o el perro por medio de un sub-menu
///
/// @param lista array de estadias
/// @param estadiaLen longitud de array de estadias
/// @param ultimoId ultimo ID ingresado anteriormente
/// @param perros array de perros
/// @param perrosLen longitud de array de perros
/// @return devuelve [0] en caso de que se realice alguna modificacion, caso contrario devuelve [-1]
int modificarEstadia(EstadiaDiaria* lista, int estadiaLen, int ultimoId, sDuenio* duenios, int dueniosLen, Perro* perros,int perrosLen);

/// @fn void mostrarPerrosConEstadias(Perro*, int, EstadiaDiaria*, int, sDuenio*, int)
/// @brief Imprime listado de perros con sus estadias
///
/// @param perros	array de perros
/// @param perrosLen	longitud del array de perros
/// @param estadia array de estadias
/// @param estadiasLen longitud del array de estadias
/// @param duenios	array de duenios
/// @param dueniosLen longitud del array de duenios
void mostrarPerrosConEstadias(Perro* perros, int perrosLen, EstadiaDiaria* estadia, int estadiasLen, sDuenio* duenios, int dueniosLen);

#endif /* PERRO_ESTADIA_H_ */
