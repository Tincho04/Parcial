#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "Validaciones.h"
#define BUFFST 4096
#define SLEN 1000

/** \brief funcion que toma y valida una cadena string.
 *
 * \param pBuffer char*
 * \param limite int
 * \return int
 *
 */
int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFST];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferStr,limite,stdin);
        fflush(stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}

/** \brief Imprime el menu principal y toma la opcion seleccionada.
 *
 * \return int
 *
 */
int menu()
{
    int opcion;
        system ("COLOR 30");
        system("cls");
        printf("\n         ################################################################");
        printf("\n         *                                                              *");
        printf("\n         *                  - Final de Laboratorio -                    *");
        printf("\n         *                                                              *");
        printf("\n         *                  x Silva Chauvie Martin x                    *");
        printf("\n         *                                                              *");
        printf("\n         ################################################################");
        printf("\n         |                                                              |");
        printf("\n             1 - Carga de datos tipo texto");
        printf("\n         |                                                              |" );
        printf("\n             2 - Imprimir Envios");
        printf("\n         |                                                              |" );
        printf("\n             3 - Calcular costos");
        printf("\n         |                                                              |" );
        printf("\n             4 - Generar archivo de costos para zona");
        printf("\n         |                                                              |" );
        printf("\n             5 - Imprimir lista de Zonas");
        printf("\n         |                                                              |" );
        printf("\n             6 - Salir");
        printf("\n         |                                                              |" );
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" );
        printf("\n");
        printf("\n          Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    return opcion;
}
