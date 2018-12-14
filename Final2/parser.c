#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "LinkedList.h"
#include "Logistica.h"

/** \brief Parsea los datos los datos de los envios el archivo data_2F.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pLinkedListEnvio LinkedList*
 * \return int
 *
 */
int parser_envioFromText(FILE* pFile, LinkedList* pLinkedListEnvio)
{
    envio* pAux;
    char auxId[50];
    char auxNombre[128];
    char auxIdCam[50];
    char auxDestino[50];
    char auxKmRecorridos[50];
    char auxEntrega[50];
    int flag = 1;
    int retorno = -1;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxIdCam, auxDestino, auxKmRecorridos, auxEntrega);
                flag = 0;
            }
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxIdCam, auxDestino, auxKmRecorridos, auxEntrega);
        pAux = envio_newParametros(auxId, auxNombre, auxIdCam, auxDestino, auxKmRecorridos, auxEntrega);
            if(pAux !=NULL)
            {
            ll_add(pLinkedListEnvio,pAux);
            retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los envios para guardar en un archivo de modo texto.
 *
 * \param FILE* pFile
 * \param pLinkedListEnvio LinkedList*
 * \return int
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pLinkedListEnvio)
{
    int retorno = -1;
    envio* auxEnvio;
    int len;
    int i;
    int auxId;
    char auxNombre[1000];
    int auxIdCam;
    char auxDestino[1000];
    int auxKmRec;
    int auxEntregas;
    float auxCosto;

    if(pFile != NULL && pLinkedListEnvio != NULL)
    {
        fprintf(pFile,"ID_envio,Nombre_Producto,ID_Camion,Zona_Destino,KM_Recorridos,Tipo_Entrega,Costo_Envio\n");
        len = ll_len(pLinkedListEnvio);
        for(i=0;i<len;i++)
        {
            auxEnvio = ll_get(pLinkedListEnvio,i);
            envio_getAllE(auxEnvio,&auxId,auxNombre,&auxIdCam,auxDestino,&auxKmRec,&auxEntregas,&auxCosto);
            fprintf(pFile,"%d,%s,%d,%s,%d,%d,%.2f\n",auxId,auxNombre,auxIdCam,auxDestino,auxKmRec,auxEntregas,auxCosto);
            retorno = 0;
        }
    }
    return retorno;
}
