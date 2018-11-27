#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    int flag = 1;
    int retorno = -1;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,]\n", auxId, auxNombre, auxHorasTrabajadas);
                flag = 0;
            }
        fscanf(pFile,"%[^,],%[^,],%[^,]\n", auxId, auxNombre, auxHorasTrabajadas);
        pAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas);
            if(pAux !=NULL)
            {
            ll_add(pArrayListEmployee,pAux);
            retorno = 0;
            }
        }
    }
    return retorno;
}


/** \brief Parsea los datos de los empleados para guardar en data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;
    int len;
    int i;
    int auxId;
    char auxNombre[1000];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            employee_getAll(auxEmployee,auxNombre,&auxHorasTrabajadas,&auxSueldo,&auxId);
            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados para guardar en data.bin (modo binario).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_SaveToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i = 0;
    int auxId;
    char auxNombre[51];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployee;

 if(pFile != NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&auxId);
            employee_getName(auxEmployee,auxNombre);
            employee_getHours(auxEmployee,&auxHorasTrabajadas);
            employee_getSalary(auxEmployee,&auxSueldo);
            if( auxId > 0 && strlen(auxNombre) > 0 &&
                auxHorasTrabajadas > 0 && auxSueldo > 0)
            {
                fwrite(auxEmployee,sizeof(Employee),1,pFile);
            }
        }
    }
    return retorno;
}
