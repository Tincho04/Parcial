#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Vend.h"
#include "parser.h"
#include "controller.h"
#include "Validaciones.h"


/** \brief Carga los datos de los vendedores desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pLinkedListVend)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(!parser_vendFromText(pArchivo, pLinkedListVend))
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

/** \brief Graba los datos de los empleados en el archivo un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pLinkedListVend)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pLinkedListVend))
    {
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Valida que se ejecute correctamente la funcion ll_map
 *
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_ll_map(LinkedList* pLinkedListVend)
{
    int retorno=0;
    if(pLinkedListVend == NULL){
        printf("No hay datos en la lista.\n");
    }
    else
    {
        LinkedList* newLinker=ll_clone(pLinkedListVend);
        if(newLinker!=NULL){
            ll_map(newLinker,calcComision);
                retorno=1;
            ll_deleteLinkedList(newLinker);
        }
    }
    return retorno;
}

/** \brief Listar vendedores.
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_ListVend(LinkedList* pLinkedListVend)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int nivel;
    int prodVendidos;
    float montoVendido;
    vend* auxPunteroVendedor;

    if(pLinkedListVend != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pLinkedListVend);i++)
        {
             if(i%50==0)
            {
            system("pause");
            auxPunteroVendedor = ll_get(pLinkedListVend,i);
            vend_getId(auxPunteroVendedor,&id);
            vend_getName(auxPunteroVendedor,nombre);
            vend_getLevel(auxPunteroVendedor,&nivel);
            vend_getSold(auxPunteroVendedor,&prodVendidos);
            vend_getCash(auxPunteroVendedor,&montoVendido);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nNivel: %d",nivel);
            printf("\nCantidad de productos vendidos: %d",prodVendidos);
            printf("\nMonto total de productos vendidos: %.2f",montoVendido);
            printf("\n");
            }
            else
            {
            auxPunteroVendedor = ll_get(pLinkedListVend,i);
            vend_getId(auxPunteroVendedor,&id);
            vend_getName(auxPunteroVendedor,nombre);
            vend_getLevel(auxPunteroVendedor,&nivel);
            vend_getSold(auxPunteroVendedor,&prodVendidos);
            vend_getCash(auxPunteroVendedor,&montoVendido);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nNivel: %d",nivel);
            printf("\nCantidad de productos vendidos: %d",prodVendidos);
            printf("\nMonto total de productos vendidos: %.2f",montoVendido);
            printf("\n");
            }
        }
    }
    system("pause");
    return retorno;
}

/** \brief Listar vendedores junto a sus comisiones.
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_ListVendCom(LinkedList* pLinkedListVend)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int nivel;
    int prodVendidos;
    float montoVendido;
    float comision;
    vend* auxPunteroVendedor;

    if(pLinkedListVend != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pLinkedListVend);i++)
        {
             if(i%50==0)
            {
            system("pause");
            auxPunteroVendedor = ll_get(pLinkedListVend,i);
            vend_getId(auxPunteroVendedor,&id);
            vend_getName(auxPunteroVendedor,nombre);
            vend_getLevel(auxPunteroVendedor,&nivel);
            vend_getSold(auxPunteroVendedor,&prodVendidos);
            vend_getCash(auxPunteroVendedor,&montoVendido);
            vend_getComi(auxPunteroVendedor,&comision);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nNivel: %d",nivel);
            printf("\nCantidad de productos vendidos: %d",prodVendidos);
            printf("\nMonto total de productos vendidos: %.2f",montoVendido);
            printf("\nMonto de comision: %.2f",comision);

            printf("\n");

            }
            else
            {
            auxPunteroVendedor = ll_get(pLinkedListVend,i);
            vend_getId(auxPunteroVendedor,&id);
            vend_getName(auxPunteroVendedor,nombre);
            vend_getLevel(auxPunteroVendedor,&nivel);
            vend_getSold(auxPunteroVendedor,&prodVendidos);
            vend_getCash(auxPunteroVendedor,&montoVendido);
            vend_getComi(auxPunteroVendedor,&comision);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nNivel: %d",nivel);
            printf("\nCantidad de productos vendidos: %d",prodVendidos);
            printf("\nMonto total de productos vendidos: %.2f",montoVendido);
            printf("\nMonto de comision: %.2f",comision);
            printf("\n");
            }
        retorno = 0;
        }
    }
    system("pause");
    return retorno;
}


/** \brief Controlador para el ordenamiento de vendedores.
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_sortVend(LinkedList* pLinkedListVend)
{
    int retorno = -1;

    if(pLinkedListVend != NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");
        if(!ll_sort(pLinkedListVend,vend_sortByName,1))
        {
            controller_ListVend(pLinkedListVend);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Controlador para el ordenamiento de vendedores.
 *
 * \param path char*
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int controller_sortByCom(LinkedList* pLinkedListVend)
{
    int retorno = -1;

    if(pLinkedListVend != NULL)
    {
        printf("Realizando reordenamiento por comision\n");
        if(!ll_sortCom(pLinkedListVend,vend_sortByCom,1))
        {
            controller_ListVendCom(pLinkedListVend);
            retorno = 0;
        }
    }

    return retorno;
}
