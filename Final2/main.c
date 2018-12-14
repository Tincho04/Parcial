#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Logistica.h"
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
    LinkedList* listaEnvios = ll_newLinkedList();
    LinkedList* listaPorZona;
    do
    {
        system("cls");
        option = menu();
        switch(option)
        {
        case 1:
                printf("Ingrese el nombre del archivo que desea abrir \n");
                fflush(stdin);
                if(getString(archivo,21) == 0)
                {
                    controller_loadFromText(archivo,listaEnvios);
                    flagAr = 1;
                }
            break;
        case 2:
            if(flagAr!=0)
            {
                printf("A continuacion se imprimiran los datos en un salto de 50 envios a la vez.\n");
                controller_Listenvio(listaEnvios);
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
                if(!(controller_ll_map(listaEnvios)))
                {
                    printf("\nProblemas para calcular el costo de envio\n\n");
                    system("pause");
                }
                else
                {
                    flagCm = 1;
                    printf("\nCosto de envio calculado exitosamente...\n\n");
                    system("pause");
                    printf("Desea ver un listado de los costos?  s / n \n\n");
                    fflush(stdin);
                    comision=getch();
                    if(comision=='s')
                    {
                     controller_ListenvioCost(listaEnvios);
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
                     printf("Ingrese la zona por la que desea filtrar \n");
                     fflush(stdin);
                     if(getString(filtro,11) == 0)
                    {
                        if(strcmp(filtro,"lanus")==0)
                        {
                            listaPorZona=ll_filter(listaEnvios, envio_filtroLan);
                            flagLv=1;
                        }
                        else if(strcmp(filtro,"avellaneda")==0)
                        {
                            listaPorZona=ll_filter(listaEnvios, envio_filtroAve);
                            flagLv=1;
                        }
                        else if(strcmp(filtro,"caba")==0)
                        {
                            listaPorZona=ll_filter(listaEnvios, envio_filtroCaba);
                            flagLv=1;
                        }
                        else if(strcmp(filtro,"bandfield")==0)
                        {
                            listaPorZona=ll_filter(listaEnvios, envio_filtroBand);
                            flagLv=1;
                        }
                        else if(strcmp(filtro,"quilmes")==0)
                        {
                            listaPorZona=ll_filter(listaEnvios, envio_filtroQui);
                            flagLv=1;
                        }
                        else
                        {
                            printf("Ingrese una zona valida");
                        }
                    }
                    if(flagLv==1)
                    {
                        strcpy(archivo,filtro);
                        strcat(archivo,".csv");
                        controller_saveAsText(archivo,listaPorZona);
                    }
            }
            else
            {
                printf("Es necesario calcular el costo del envio para poder hacer este grabado de archivo.\n\n");
                system("pause");
            }
            break;
               case 5:
            if(flagAr==1)
            {
                printf("A continuacion se imprimiran las zonas disponibles: \n");
                controller_ListZone(listaEnvios);
            }
            else
            {
                printf("Es necesario cargar los datos primero.\n\n");
                system("pause");
            }
            break;
        case 6:
            break;
        default:
            printf("Ingrese una opcion valida \n\n");
            system("pause");
        }
    }
    while(option != 6);

    return 0;
}
