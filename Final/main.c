#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Vend.h"
#include "conio.h"
#include "string.h"
#include "Validaciones.h"
#include "parser.h"

int main()
{
    int option=0;
    int flagAr=0;
    int flagCm=0;
    int flagLv=0;
    char comision;
    char filtro[11];
    char archivo[30];
    LinkedList* listaVendedores = ll_newLinkedList();
    LinkedList* listaPorNivel;
    do
    {
        system("cls");
        option = menu();
        switch(option)
        {
        case 1:
                controller_loadFromText("data.csv",listaVendedores);
                flagAr = 1;
            break;
        case 2:
            if(flagAr!=0)
            {
                printf("A continuacion se imprimiran los datos en un salto de 50 vendedores a la vez.\n");
                controller_ListVend(listaVendedores);
            }
            else
            {
                printf("Cargue datos primero para poder realizar la lista\n\n");
                system("pause");
            }
            break;
        case 3:
                if(flagAr!=0)
            {
                if(!(controller_ll_map(listaVendedores)))
                {
                    printf("\nProblemas para calcular la comision\n\n");
                    system("pause");
                }
                else
                {
                    flagCm = 1;
                    printf("\nComision calculada exitosamente...\n\n");
                    system("pause");
                    printf("Desea ver un listado de las comisiones?  s / n \n\n");
                    fflush(stdin);
                    comision=getch();
                    if(comision=='s')
                    {
                     controller_ListVendCom(listaVendedores);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                printf("Cargue datos primero para poder guardarlos\n\n");
                system("pause");
            }
            break;
        case 4:
            if(flagCm==1)
            {
                     printf("Ingrese el nivel por el que quiere filtrar \n");
                     fflush(stdin);
                     if(getString(filtro,11) == 0)
                    {
                        if(strcmp(filtro,"Junior")==0)
                        {
                            listaPorNivel=ll_filter(listaVendedores, vend_filtroJr);
                            flagLv=1;
                        }
                        else if(strcmp(filtro,"Estandard")==0)
                        {
                            listaPorNivel=ll_filter(listaVendedores, vend_filtroSt);
                            flagLv=1;
                        }
                        else if(strcmp(filtro,"Experto")==0)
                        {
                            listaPorNivel=ll_filter(listaVendedores, vend_filtroEx);
                            flagLv=1;
                        }
                        else
                        {
                            printf("Ingrese un nivel valido");
                        }
                    }
                    if(flagLv==1)
                    {
                        strcpy(archivo,filtro);
                        strcat(archivo,".csv");
                        controller_saveAsText(archivo,listaPorNivel);
                    }
            }
            else
            {
                printf("Es necesario calcular la comision para poder hacer este grabado de archivo.\n\n");
                system("pause");
            }
            break;
               case 5:
            if(flagAr==1)
            {
                controller_sortVend(listaVendedores);
            }
            else
            {
                printf("Es necesario cargar los datos primero.\n\n");
                system("pause");
            }
            break;
               case 6:
            if(flagCm==1)
            {
                controller_sortByCom(listaVendedores);
            }
            else
            {
                printf("Es necesario calcular la comision para poder hacer este grabado de archivo.\n\n");
                system("pause");
            }
            break;
        case 7:
            break;
        default:
            printf("Ingrese una opcion valida \n\n");
            system("pause");
        }
    }
    while(option != 7);

    return 0;
}
