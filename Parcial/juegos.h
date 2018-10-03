#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    int idJuego;
    char descripcion[51];
    int importe;
    int isEmpty;
} eJuegos;

void inicializarJuegos(eJuegos x[], int tam);
int buscarLibre( eJuegos x[], int tam);
int buscarJuego(eJuegos x[], int tam, int id);
void agregarJuego(eJuegos Juegos[], int tam);
int generarID(eJuegos x[],int tam);
void mostrarJuego(eJuegos jgs);
void mostrarJuegos(eJuegos nomina[], int tam);
void eliminarJuego(eJuegos Juegos[], int tam);
void modificarJuego(eJuegos Juegos[], int tam);
void ordenarXImporteYDescrip(eJuegos x[],int tam);



#endif // JUEGOS_H_INCLUDED
