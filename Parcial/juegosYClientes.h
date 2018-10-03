#ifndef JUEGOSYCLIENTES_H_INCLUDED
#define JUEGOSYCLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char domicilio[51];
    char telefono[21];
    int isEmpty;
} eCliente;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    int isEmpty;
} eAlquiler;

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

void inicializarClientes(eCliente x[], int tam);
int buscarLibreCl(eCliente x[], int tam);
int cargarI(eCliente x[],int tam);
int buscarCliente(eCliente x[], int tam, int idCliente);
int buscarClientexidCliente(eCliente x[], int tam, int id);
void mostrarCliente(eCliente clt);
void mostrarClientes(eCliente nomina[], int tam);
void agregarCliente(eCliente Clientes[], int tam);
void eliminarCliente(eCliente Clientes[], int tam);
void modificarCliente(eCliente Clientes[], int tam);
void ordenarXApellidoYNombre(eCliente x[],int tam);
int menu();
void correccionNombres(eCliente listado[], int tam);
void correccionApellidos(eCliente listado[], int tam);

#endif // JUEGOSYCLIENTES_H_INCLUDED
