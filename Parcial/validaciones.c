#include "validaciones.h"

void validarStringJ (char x[], int limite)
{
    char dato[limite];
    do
        {
        printf("El dato ingresado es demasiado grande. Reingrese dato");
        gets(dato);

    }
    while (strlen (x)>limite);
}

int validarStringC (char x[], int limite)
{
    int longitud;
    longitud = strlen(x);
    int retorno=0;
    if (longitud>limite)
    {
        retorno++;
    }

    return retorno;
}

int validarEntero(int x)
{
    int retorno;
    retorno=0;
    do
        {
        retorno++
    } while (x<=0);
    return retorno;
}
