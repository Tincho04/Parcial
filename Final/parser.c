#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "LinkedList.h"
#include "vend.h"

/** \brief Parsea los datos los datos de los vendedores desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int parser_vendFromText(FILE* pFile, LinkedList* pLinkedListVend)
{
    vend* pAux;
    char auxId[50];
    char auxNombre[128];
    char auxNivel[50];
    char auxProdVendidos[50];
    char auxMontoVendido[50];
    int flag = 1;
    int retorno = -1;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxNivel, auxProdVendidos, auxMontoVendido);
                flag = 0;
            }
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxNivel, auxProdVendidos, auxMontoVendido);
        pAux = vend_newParametros(auxId, auxNombre, auxNivel, auxProdVendidos, auxMontoVendido);
            if(pAux !=NULL)
            {
            ll_add(pLinkedListVend,pAux);
            retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los vendedores para guardar en data.csv (modo texto)((con Comision)).
 *
 * \param FILE* pFile
 * \param pLinkedListVend LinkedList*
 * \return int
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pLinkedListVend)
{
    int retorno = -1;
    vend* auxvend;
    int len;
    int i;
    int auxId;
    char auxNombre[1000];
    int auxNivel;
    int auxProdVendidos;
    float auxMontoVendido;
    float auxComision;

    if(pFile != NULL && pLinkedListVend != NULL)
    {
        fprintf(pFile,"ID,Nombre_Vendedor,Nivel,cantidad_productos_vendidos,Monto_vendido,Comision\n");
        len = ll_len(pLinkedListVend);
        for(i=0;i<len;i++)
        {
            auxvend = ll_get(pLinkedListVend,i);
            vend_getAllC(auxvend,auxNombre,&auxNivel,&auxProdVendidos,&auxMontoVendido,&auxComision,&auxId);
            fprintf(pFile,"%d,%s,%d,%d,%.2f ,%.2f\n",auxId,auxNombre,auxNivel,auxProdVendidos, auxMontoVendido, auxComision);
            retorno = 0;
        }
    }
    return retorno;
}
