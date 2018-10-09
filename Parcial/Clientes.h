#ifndef JUEGOSYCLIENTES_H_INCLUDED
#define JUEGOSYCLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "validaciones.h"
#include "alquiler.h"
#include "juegos.h"
#define VACIO 1
#define OCUP   0

typedef struct
{
    int idCliente;      // autoincremental
    char apellido[51];  // validar longitud de char
    char nombre[51];    // validar longitud de char
    char domicilio[51]; // validar longitud de char
    char telefono[21];  // validar longitud de char
    int isEmpty;
} eCliente;

/** \brief inicializa cada cliente desde cero a vacio
 *
 * \param x[] eCliente
 * \param tam int
 * \return void
 *
 */
void inicializarClientes(eCliente x[], int tam);
/** \brief busca el primer perfil hueco para realizar una carga de datos
 *
 * \param x[] eCliente
 * \param tam int
 * \return int
 *
 */
int buscarLibreCl(eCliente x[], int tam);

/** \brief busqueda de disponibilidad de perfil de un cliente
 *
 * \param x[] eCliente
 * \param tam int
 * \param idCliente int
 * \return int
 *
 */
int buscarClientexidCliente(eCliente x[], int tam, int id);
/** \brief carga de datos realizada en base a si hay un hueco disponible
 *
 * \param x[] eCliente
 * \param tam int
 * \return int
 *
 */

void mostrarCliente(eCliente clt);
/** \brief itera un loop que permite la muestra de datos de todos los clientes cargados
 *
 * \param nomina[] eCliente
 * \param tam int
 * \return void
 *
 */
void mostrarClientes(eCliente nomina[], int tam);
/** \brief alta de un cliente
 * \param Clientes[] eCliente
 * \param tam int
 * \return eCliente
 *
 */
int agregarCliente(eCliente Clientes[], int tam);
/** \brief Generador automatico de ID
 *
 * \return int
 *
 */
int  IDC();
/** \brief baja logica de un cliente
 *
 * \param Clientes[] eCliente
 * \param tam int
 * \return void
 *
 */
void eliminarCliente(eCliente Clientes[], int tam);
/** \brief modifica algun parametro del cliente con base en su id
 *
 * \param Clientes[] eCliente
 * \param tam int
 * \return void
 *
 */
void modificarCliente(eCliente Clientes[], int tam);
/** \brief ordena cada cliente por su apellido primordialmente y luego por su nombre
 *
 * \param x[] eCliente
 * \param tam int
 * \return void
 *
 */
void ordenarXApellidoYNombre(eCliente x[],int tam);
/** \brief menu que despliega todas las opciones a ejecutarse en este programa
 *
 * \return int
 *
 */
int menu();

/** \brief Submenu que muestra el listado de informes
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuegos
 * \param tamJ int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void subMenuInformes(eCliente clientes[], int tamC, eJuegos juegos[], int tamJ, eAlquiler alquileres[], int tamA);
#endif // JUEGOSYCLIENTES_H_INCLUDED
