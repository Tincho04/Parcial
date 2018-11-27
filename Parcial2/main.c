#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"
#include "parser.h"

int main()
{
    int option=0;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char archivo[21];
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
                controller_loadFromText(archivo,listaEmpleados);
                flag = 1;
            }
            break;
        case 2:
            if(flag!=0)
            {
                if(!(controller_ll_map(listaEmpleados)))
                {
                    printf("\nProblemas para calcular el sueldo\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nSueldo calculado exitosamente...\n\n");
                    system("pause");
                }
            }
            else
            {
                printf("Cargue datos primero para poder guardarlos");
            }
            break;
        case 3:
            system("cls");
            if(flag!=0)
            {
                controller_saveAsText("info.csv",listaEmpleados);
            }
            else
            {
                printf("Cargue datos primero para poder guardarlos");
            }
            break;
        case 4:
            system("cls");
            if(flag!=0)
            {
                controller_saveAsBinary("info.dat",listaEmpleados);
            }
            else
            {
                printf("Cargue datos primero para poder guardarlos");
            }
            break;
        case 5:
            break;
        default:
            printf("Ingrese una opcion valida \n");
            system("pause");
        }
    }
    while(option != 5);

    return 0;
}
