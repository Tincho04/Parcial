#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "juegos.h"
#include "Clientes.h"

/** \brief Valida que el valor flotante ingresado supere 0
 *
 * \param x float
 * \return int
 *
 */
int validarFloat(float x);
/** \brief Obtiene un array de char y valida su longitud
 *
 * \param stringb char*
 * \param limit int
 * \return int
 *
 */
int getStr(char* stringb, int limit);
/** \brief valida que el nombre o texto introducido posea solamente caracteres alfabeticos
 *
 * \param stringb char*
 * \param limite int
 * \return int
 *
 */
int validarName(char* stringb , int limite);
/** \brief valida que el array de char obtenga solamente valores numericos
 *
 * \param valuer char*
 * \param limite int
 * \return int
 *
 */
int validarImporte(char* valuer, int limite);

#endif // VALIDACIONES_H_INCLUDED
