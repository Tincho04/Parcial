#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "logistica.h"
#include "parser.h"
#include "controller.h"
#include "Validaciones.h"


/** \brief Carga los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListenvio LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pLinkedListenvio)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(!parser_envioFromText(pArchivo, pLinkedListenvio))
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

/** \brief Graba los datos de los envios en un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListenvio LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pLinkedListenvio)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pLinkedListenvio))
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
 * \param pLinkedListenvio LinkedList*
 * \return int
 *
 */
int controller_ll_map(LinkedList* pLinkedListenvio)
{
    int retorno=0;
    if(pLinkedListenvio == NULL){
        printf("No hay datos en la lista.\n");
    }
    else
    {
        LinkedList* newLinker=ll_clone(pLinkedListenvio);
        if(newLinker!=NULL){
            ll_map(newLinker,calcMonto);
                retorno=1;
            ll_deleteLinkedList(newLinker);
        }
    }
    return retorno;
}

/** \brief Listar envios.
 *
 * \param path char*
 * \param pLinkedListenvio LinkedList*
 * \return int
 *
 */
int controller_Listenvio(LinkedList* pLinkedListenvio)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    char destino[128];
    int idCam;
    int kmRec;
    int entregas;
    envio* auxPunteroenvio;

    if(pLinkedListenvio != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pLinkedListenvio);i++)
        {
             if(i%50==0)
            {
            system("pause");
            auxPunteroenvio = ll_get(pLinkedListenvio,i);
            envio_getId(auxPunteroenvio,&id);
            envio_getName(auxPunteroenvio,nombre);
            envio_getIdC(auxPunteroenvio,&idCam);
            envio_getDestino(auxPunteroenvio,destino);
            envio_getKmRec(auxPunteroenvio,&kmRec);
            envio_getEntregas(auxPunteroenvio,&entregas);

            printf("\nID de Envio: %d",id);
            printf("\nNombre del producto: %s",nombre);
            printf("\nID del camion: %d",idCam);
            printf("\nZona de destino: %s",destino);
            printf("\nKilometros Recorridos: %d",kmRec);
            printf("\nTipo de Entrega: %d",entregas);
            printf("\n");
            }
            else
            {
            auxPunteroenvio = ll_get(pLinkedListenvio,i);
            envio_getId(auxPunteroenvio,&id);
            envio_getName(auxPunteroenvio,nombre);
            envio_getIdC(auxPunteroenvio,&idCam);
            envio_getDestino(auxPunteroenvio,destino);
            envio_getKmRec(auxPunteroenvio,&kmRec);
            envio_getEntregas(auxPunteroenvio,&entregas);

            printf("\nID de Envio: %d",id);
            printf("\nNombre del producto: %s",nombre);
            printf("\nID del camion: %d",idCam);
            printf("\nZona de destino: %s",destino);
            printf("\nKilometros Recorridos: %d",kmRec);
            printf("\nTipo de Entrega: %d",entregas);
            printf("\n");
            }
        }
    }
    system("pause");
    return retorno;
}

/** \brief Listar envios junto a sus comisiones.
 *
 * \param path char*
 * \param pLinkedListenvio LinkedList*
 * \return int
 *
 */
int controller_ListenvioCost(LinkedList* pLinkedListenvio)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    char destino[128];
    int idCam;
    int kmRec;
    int entregas;
    float costos;
    envio* auxPunteroenvio;

    if(pLinkedListenvio != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pLinkedListenvio);i++)
        {
             if(i%50==0)
            {
            system("pause");
            auxPunteroenvio = ll_get(pLinkedListenvio,i);
            envio_getId(auxPunteroenvio,&id);
            envio_getName(auxPunteroenvio,nombre);
            envio_getIdC(auxPunteroenvio,&idCam);
            envio_getDestino(auxPunteroenvio,destino);
            envio_getKmRec(auxPunteroenvio,&kmRec);
            envio_getEntregas(auxPunteroenvio,&entregas);
            envio_getcosto(auxPunteroenvio,&costos);

            printf("\nID de Envio: %d",id);
            printf("\nNombre del producto: %s",nombre);
            printf("\nID del camion: %d",idCam);
            printf("\nZona de destino: %s",destino);
            printf("\nKilometros Recorridos: %d",kmRec);
            printf("\nTipo de Entrega: %d",entregas);
            printf("\nCosto del Envio: %.2f",costos);
            printf("\n");

            }
            else
            {
            auxPunteroenvio = ll_get(pLinkedListenvio,i);
            envio_getId(auxPunteroenvio,&id);
            envio_getName(auxPunteroenvio,nombre);
            envio_getIdC(auxPunteroenvio,&idCam);
            envio_getDestino(auxPunteroenvio,destino);
            envio_getKmRec(auxPunteroenvio,&kmRec);
            envio_getEntregas(auxPunteroenvio,&entregas);
            envio_getcosto(auxPunteroenvio,&costos);

            printf("\nID de Envio: %d",id);
            printf("\nNombre del producto: %s",nombre);
            printf("\nID del camion: %d",idCam);
            printf("\nZona de destino: %s",destino);
            printf("\nKilometros Recorridos: %d",kmRec);
            printf("\nTipo de Entrega: %d",entregas);
            printf("\nCosto del Envio: %.2f",costos);
            printf("\n");
            }
        retorno = 0;
        }
    }
    system("pause");
    return retorno;
}

/** \brief Ordenar envios alfabeticamente.
 *
 * \param path char*
 * \param pLinkedListEnvio LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pLinkedListEnvio)
{
    int retorno = -1;

    if(pLinkedListEnvio!= NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");
        if(!ll_sort(pLinkedListEnvio,envio_sortByZone,1))
        {
            controller_ListZone(pLinkedListEnvio);
            retorno = 0;
        }
    }

    return retorno;
}



/** \brief Listar las zonas.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListZone(LinkedList* pLinkedListEnvio)
{
    int retorno = -1;
    int i;
    char destino[128];
    int  cntLanus=0;
    int  cntAvell=0;
    int  cntQuilm=0;
    int  cntCaba=0;
    int  cntBandf=0;
    envio* auxPunteroEnvio;

    if(pLinkedListEnvio != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pLinkedListEnvio);i++)
        {
            auxPunteroEnvio = ll_get(pLinkedListEnvio,i);
            envio_getDestino(auxPunteroEnvio,destino);

            if(strcmp(destino,"lanus")==0 && cntLanus==0)
               {
                    printf("\n Zona de destino: %s \n",destino);
                    cntLanus=1;
               }
            else if(strcmp(destino,"avellaneda")==0 && cntAvell==0)
                    {
                        printf("\n Zona de destino: %s \n",destino);
                        cntAvell=1;
                    }
                 else if(strcmp(destino,"quilmes")==0 && cntQuilm==0)
                        {
                            printf("\n Zona de destino: %s \n",destino);
                            cntQuilm=1;
                        }
                        else if(strcmp(destino,"bandfield")==0 && cntBandf==0)
                                {
                                    printf("\n Zona de destino: %s \n",destino);
                                    cntBandf=1;
                                }
                                else if(strcmp(destino,"caba")==0 && cntCaba==0)
                                        {
                                            printf("\n Zona de destino: %s \n",destino);
                                            cntCaba=1;
                                        }
        }
    }
    system("pause");
    return retorno;
}
