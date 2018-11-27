#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
        printf("\n La carga de datos del Archivo tipo Texto se realizo efectivamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\n Archivo de Texto no encontrado.\n");
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo info.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee))
    {
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo info.dat (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"wb");
    int retorno = -1;
    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pArrayListEmployee))
    {
        printf("\n El grabado de datos en formato binario ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Valida que se ejecute correctamente la funcion ll_map
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ll_map(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    if(pArrayListEmployee == NULL){
        printf("No hay datos en la lista.\n");
    }
    else
    {
        LinkedList* newLinker=ll_clone(pArrayListEmployee);
        if(newLinker!=NULL){
            ll_map(newLinker,ll_salary);
                retorno=1;
            ll_deleteLinkedList(newLinker);
        }
    }
    return retorno;
}
