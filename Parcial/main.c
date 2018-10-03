#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "juegos.h"
#include "juegosYClientes.h"
#define J 4
#define C 10
#define A 40

int main()
{
    eJuegos juegosMain[J];
    eCliente clienteMain[C];
    eAlquiler alquileresMain[A];
    char seguir = 'S';
    char cargaC = 'N';
    char cargaJ = 'N';
    int eleccion;
    inicializarClientes(clienteMain, C);
    eleccion=menu();

    do
    {
        switch(eleccion)
        {
        case 1:
            agregarCliente(clienteMain, C);
            system("pause");
            cargaC='S';
            break;
        case 2:
            if (cargaC=='S')
            {
                system("cls");
                modificarCliente(clienteMain, C);
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }

        case 3:
            if (cargaC=='S')
            {
                system("cls");
                eliminarCliente(clienteMain, C);
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }
        case 4:
            if (cargaC=='S')
            {
                system("cls");
                ordenarXApellidoYNombre(clienteMain, C);
                system("pause");
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }
        case 5:
            agregarJuego(juegosMain, J);
            system("pause");
            cargaC='S';
            break;
        case 6:
            if (cargaJ=='S')
            {
                system("cls");
                modificarJuego(juegosMain, J);
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }

        case 7:
             if (cargaJ=='S')
            {
                system("cls");
                eliminarJuego(juegosMain, J);
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }
        case 8:
            if (cargaJ=='S')
            {
                system("cls");
                ordenarXImporteYDescrip(juegosMain, J);
                system("pause");
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }
        case 9:
             if (cargaC=='S' && cargaJ=='S')
            {
                system("cls");
                altasAlquileres(alquileresMain, A);
                system("pause");
                break;
            }
            else
            {
                printf("Debe ingresar primero los datos. \n ");
                system("pause");
                break;
            }
        case 10:
            seguir = 'N';
            break;
        }

    }
    while(seguir == 'S');

    return 0;
}
