#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "validaciones.h"
#include "Clientes.h"
#include "juegos.h"
#define VACIO -1
#define OCUP   0
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    int isEmpty;
    eFecha fechaAlquiler;
} eAlquiler;


/** \brief inicializa cada codigo del alquiler a huecos vacios
 *
 * \param x[] eAlquiler
 * \param tam int
 * \return void
 *
 */
void inicializarAlquiler(eAlquiler x[], int tam);
/** \brief generador autoincremental de id de alquileres
 *
 * \return int
 *
 */
int  IDA();
/** \brief busqueda de espacios libres para poder hacer una nueva carga de datos
 *
 * \param x[] eAlquiler
 * \param tam int
 * \return int
 *
 */
int buscarLibreAl( eAlquiler x[], int tam);
/** \brief busca un hueco libre para dar de alta un nuevo alquiler
 *
 * \param x[] eAlquiler
 * \param tam int
 * \return int
 *
 */
int cargarA(eAlquiler x[],int tam);
/** \brief realiza una busqueda en base al id del alquiler
 *
 * \param x[] eAlquiler
 * \param tam int
 * \param idAlquiler int
 * \return int
 *
 */
int buscarAlquiler(eAlquiler x[], int tam, int idAlquiler);
/** \brief ficha de datos a completar para dar de alta un alquiler
 *
 * \param alquiler[] eAlquiler
 * \param tam int
 * \param buscarJ[] eJuegos
 * \param tamJ int
 * \param buscarC[] eCliente
 * \param tamC int
 * \return void
 *
 */
void altaAlquiler(eAlquiler alquiler[], int tam, eJuegos buscarJ[], int tamJ, eCliente buscarC[], int tamC);


#endif // ALQUILER_H_INCLUDED
