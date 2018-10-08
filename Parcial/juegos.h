#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define VACIO -1
#define OCUP   0

typedef struct
{
    int idJuego;              //Autoincremental
    char descripcion[51];     //validarmaximode51char
    float importe;             //validar importe mayor a 0
    int isEmpty;
} eJuegos;

/** \brief inicializa el valor isEmpty de cada juego
 *
 * \param x[] eJuegos
 * \param tam int
 * \return void
 *
 */
void inicializarJuegos(eJuegos x[], int tam);
/** \brief busca el primer hueco libre para hacer una carga de datos
 *
 * \param x[] eJuegos
 * \param tam int
 * \return int
 *
 */
int buscarLibre( eJuegos x[], int tam);
/** \brief busca un juego en base al id ingresado
 *
 * \param x[] eJuegos
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarJuego(eJuegos x[], int tam, int id);
/** \brief permite el alta de un juego nuevo a ingresar
 *
 * \param Juegos[] eJuegos
 * \param tam int
 * \return void
 *
 */
void agregarJuego(eJuegos Juegos[], int tam);
/** \brief generador automatico de id por juego
 *
 * \param x[] eJuegos
 * \param tam int
 * \return int
 *
 */
int generarID(eJuegos x[],int tam);
/** \brief muestra uno de los juegos cargados siempre y cuando no este dado de baja
 *
 * \param jgs eJuegos
 * \return void
 *
 */
void mostrarJuego(eJuegos jgs);
/** \brief iterador que realiza una muestra de todos los juegos en posicion de alta
 *
 * \param nomina[] eJuegos
 * \param tam int
 * \return void
 *
 */
void mostrarJuegos(eJuegos nomina[], int tam);
/** \brief da de baja un juego en base a su id
 *
 * \param Juegos[] eJuegos
 * \param tam int
 * \return void
 *
 */
void eliminarJuego(eJuegos Juegos[], int tam);
/** \brief permite modificar uno de los valores del juego en base a su id
 *
 * \param Juegos[] eJuegos
 * \param tam int
 * \return void
 *
 */
void modificarJuego(eJuegos Juegos[], int tam);
/** \brief ordena primordialmente cada juego por su nombre y a posterior por su descripcion
 *
 * \param x[] eJuegos
 * \param tam int
 * \return void
 *
 */
void ordenarXImporteYDescrip(eJuegos x[],int tam);



#endif // JUEGOS_H_INCLUDED
