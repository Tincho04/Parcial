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
#define VACIO 1
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

/** \brief Calcula el promedio de importes en base a los juegos alquilados
 *
 * \param [] eAlquiler listado
 * \param tam int
 * \param juegos eJuegos
 * \param tamJ int
 * \return float
 *
 */
float calcularPromedio(eJuegos juegos[], int tamJ, eAlquiler listado[], int tamA);

/** \brief Compara los importes con el promedio para ver cuantos de ellos no lo superan
 *
 * \param [] eJuegos listado
 * \param tam int
 * \param [] eAlquiler alquileres
 * \param tamA int
 * \return void
 *
 */
void compararImportes (eJuegos listado[], int tamJ, eAlquiler alquileres[], int tamA );
/** \brief lista los clientes que hayan alquilado un juego determinado
 *
 * \param []eCliente cliente
 * \param tamC int
 * \param []ealquiler alquileres
 * \param tamA int
 * \param []eJuegos juegos
 * \param tamJ int
 * \return void
 *
 */
void listarClientesAlquiler (eCliente cliente[], int tamC, eAlquiler alquileres[], int tamA, eJuegos juegos[],int tamJ);
/** \brief lista los juegos alquilados por un cliente ingresado
 *
 * \param []eCliente cliente
 * \param tamC int
 * \param []ealquiler alquileres
 * \param tamA int
 * \param []eJuegos juegos
 * \param tamJ int
 * \return void
 *
 */
void listarJuegosxCliente (eCliente cliente[], int tamC, eAlquiler alquileres[], int tamA, eJuegos Juegos[],int tamJ);
/** \brief ordena de forma descendente los importes por medio de burbujeo
 *
 * \param x[] eJuegos
 * \param tam int
 * \return void
 *
 */
void ordenarXImporte(eJuegos x[],int tam);
/** \brief Ordena de forma ascendente los apellidos por medio del metodo de insercion
 *
 * \param eCliente clientes
 * \param tam int
 * \return void
 *
 */
void apellidoInsercion (eCliente* clientes, int tam);
/** \brief Lista los juegos alquilados en una fecha ingresada.
 *
 * \param []eJuegos juegos
 * \param tamJ int
 * \param []eAlquiler alquileres
 * \param tamA int
 * \return void
 *
 */
void listarJPorFechaX (eJuegos juegos[], int tamJ, eAlquiler alquileres[], int tamA);

/** \brief Lista los clientes que hayan realizado al menos un alquiler en la fecha ingresada
 *
 * \param []eCliente clientes
 * \param tamC int
 * \param []eAlquiler alquileres
 * \param tamA int
 * \return
 *
 */
void listarCPorFechaX (eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA);
#endif // ALQUILER_H_INCLUDED
