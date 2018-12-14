#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Logistica.h"
#include "string.h"
#include "Validaciones.h"



/** \brief Solicita espacio en memoria para un nuevo envio.
 *
 * \return envio*
 *
 */
envio* envio_new()
{
    envio* this;
    this=malloc(sizeof(envio));
    if(this!=NULL)
    {
        return this;
    }
    else
    {
        return NULL;
    }
}

/**
*\brief llama al Set de datos del envio.
*\param idStr char*
*\param nombreStr char*
*\param NivelStr char*
*\param prodenvioidosStr char*
*\return envio*
*/

envio* envio_newParametros(char* idStr,char* nombreStr,char* idCamionStr, char* destinoStr, char* kmRecorridosStr, char* entregaStr)
{
  envio* this;
    this = envio_new();

    int idInt = atoi(idStr);
    int idCamionInt = atoi(idCamionStr);
    int kmRecorridosInt = atoi(kmRecorridosStr);
    int entregaInt = atoi(entregaStr);

    if(
    !envio_setId(this,idInt)&&
    !envio_setName(this,nombreStr)&&
    !envio_setIdC(this,idCamionInt)&&
    !envio_setDestino(this,destinoStr)&&
    !envio_setKmRec(this,kmRecorridosInt)&&
    !envio_setEntregas(this,entregaInt))
     {
         return this;
     }
    return NULL;
}

/** \brief set del nombre del producto.
 *
 * \param this envio*
 * \param producto char*
 * \return int
 *
 */

int envio_setName(envio* this, char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el nombre del producto.
 *
 * \param this envio*
 * \param nombre char*
 * \return int
 *
 */
int envio_getName(envio* this, char* nombre)
{
   int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->producto);
        retorno=0;
    }
    return retorno;
}

/** \brief set del ID del camion.
 *
 * \param this envio*
 * \param idCam char*
 * \return int
 *
 */
int envio_setIdC(envio* this,int idCam)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idCamion=idCam;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el ID del camion.
 *
 * \param this envio*
 * \param idCam int*
 * \return int
 *
 */
int envio_getIdC(envio* this, int* idCam)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idCam=this->idCamion;
        retorno=0;
    }
    return retorno;
}

/** \brief set de la zona de destino.
 *
 * \param this envio*
 * \param destino int
 * \return int
 *
 */
int envio_setDestino(envio* this, char* destino)
{
     int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->destino,destino);
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar la zona de destino.
 *
 * \param this envio*
 * \param destino int*
 * \return int
 *
 */
int envio_getDestino(envio* this, char* destino)
{
     int retorno=-1;
    if(this!=NULL)
    {
        strcpy(destino,this->destino);
        retorno=0;
    }
    return retorno;
}


/** \brief set de la cantidad de kilometros recorridos.
 *
 * \param this envio*
 * \param kmRec int
 * \return int
 *
 */
int envio_setKmRec(envio* this, int kmRec)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->kmRecorridos=kmRec;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar los kilometros recorridos.
 *
 * \param this envio*
 * \param kmRec int*
 * \return int
 *
 */
int envio_getKmRec(envio* this, int* kmRec)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *kmRec=this->kmRecorridos;
        retorno=0;
    }
    return retorno;
}

/** \brief set del tipo de entrega.
 *
 * \param this envio*
 * \param entregas int
 * \return int
 *
 */
int envio_setEntregas(envio* this, int entregas)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->tipoEntrega=entregas;
        retorno=0;
    }
    return retorno;
}


/** \brief funcion get para tomar el tipo de entrega.
 *
 * \param this envio*
 * \param entregas int*
 * \return int
 *
 */
int envio_getEntregas(envio* this, int* entregas)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *entregas=this->tipoEntrega;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el costo del envio.
 *
 * \param this envio*
 * \param entregas float*
 * \return int
 *
 */
int envio_getcosto(envio* this, float* costo)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *costo=this->costo;
        retorno=0;
    }
    return retorno;
}
/** \brief set del costo del envio.
 *
 * \param this envio*
 * \param comision float
 * \return int
 *
 */
int envio_setcosto(envio* this, float costo)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->costo=costo;
        retorno=0;
    }
    return retorno;
}

/** \brief Set del ID del envioedor.
 *
 * \param this envio*
 * \param id int
 * \return int
 *
 */
int envio_setId(envio* this,int id)
{
 int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->idEnvio=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->idEnvio=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el ID del envioedor.
 *
 * \param this envio*
 * \param id int*
 * \return int
 *
 */
int envio_getId(envio* this, int* id)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *id=this->idEnvio;
        retorno=0;
    }
    return retorno;
}

/** \brief automatizador de datos para realizar todos los gets en una sola funcion.
 *
 * \param this envio*
 * \param nombre char*
 * \param horas int*
 * \param prodenvioidos int*
 * \param id int*
 * \return int
 *
 */
int envio_getAll(envio* this, int* id,char* nombre,int* idCamion,char* destino,int* kmRec, int* entregas)
{
    int retorno = -1;

    if(this != NULL)
    {
        envio_getId(this,id);
        envio_getName(this,nombre);
        envio_getIdC(this,idCamion);
        envio_getDestino(this,destino);
        envio_getKmRec(this,kmRec);
        envio_getEntregas(this,entregas);
        retorno = 0;
    }
    return retorno;
}

/** \brief automatizador de datos para realizar todos los gets en una sola funcion sumado al costo de envio.
 *
 * \param this envio*
 * \param nombre char*
 * \param horas int*
 * \param prodenvioidos int*
 * \param id int*
 * \return int
 *
 */
int envio_getAllE(envio* this, int* id,char* nombre,int* idCamion,char* destino,int* kmRec, int* entregas, float* costo)
{
    int retorno = -1;

    if(this != NULL)
    {
        envio_getId(this,id);
        envio_getName(this,nombre);
        envio_getIdC(this,idCamion);
        envio_getDestino(this,destino);
        envio_getKmRec(this,kmRec);
        envio_getEntregas(this,entregas);
        envio_getcosto(this,costo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Algoritmo que calcula el costo de envio en base los kilometros recorridos.
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) Si ok
 */
int calcMonto(void* envioA)
{
    int returnAux = -1;
    int kmRecAux=0;
    int entregaAux=0;
    float costoAux=0;
    if(envioA!=NULL){
        envio_getKmRec(((envio*)envioA),&kmRecAux);
        envio_getEntregas(((envio*)envioA),&entregaAux);
        if(kmRecAux<50){
            costoAux=kmRecAux*100;
        }
        else
            {
            costoAux=kmRecAux*50;
            envio_setcosto(((envio*)envioA),costoAux);
            }
        if(entregaAux==0)
            {
                costoAux=costoAux+250;
                envio_setcosto(((envio*)envioA),costoAux);
                returnAux = 1;
            }
            else if (entregaAux==1)
                {
                    costoAux=costoAux+420;
                    envio_setcosto(((envio*)envioA),costoAux);
                    returnAux = 1;
                }
                else if (entregaAux==2)
                    {
                        costoAux=costoAux+75;
                        envio_setcosto(((envio*)envioA),costoAux);
                        returnAux = 1;
                    }
        }
    return returnAux;
}

/** \brief Filtra los envios por la zona de "Lanus".
 *
 * \param this envio*
 * \return int
 *
 */
int envio_filtroLan(envio* this)
{
    int returnAux = -1;
    char zonaAux[21];
    if (this != NULL)
    {
        envio_getDestino(this, zonaAux);
        if(strcmp(zonaAux,"lanus")==0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los envios por la zona de "Avellaneda".
 *
 * \param this envio*
 * \return int
 *
 */
int envio_filtroAve(envio* this)
{
    int returnAux = -1;
    char zonaAux[21];

    if (this != NULL)
    {
        envio_getDestino(this, zonaAux);
        if(strcmp("avellaneda",zonaAux)== 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los envios por la zona de "CABA".
 *
 * \param this envio*
 * \return int
 *
 */

int envio_filtroCaba(envio* this)
{
    int returnAux = -1;
    char zonaAux[21];

    if (this != NULL)
    {
        envio_getDestino(this, zonaAux);
        if(strcmp("caba",zonaAux)== 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los envios por la zona de "Bandfield".
 *
 * \param this envio*
 * \return int
 *
 */
int envio_filtroBand(envio* this)
{
    int returnAux = -1;
    char zonaAux[21];

    if (this != NULL)
    {
        envio_getDestino(this, zonaAux);
        if(strcmp("bandfield",zonaAux)== 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los envios por la zona de "Quilmes".
 *
 * \param this envio*
 * \return int
 *
 */

int envio_filtroQui(envio* this)
{
    int returnAux = -1;
    char zonaAux[21];

    if (this != NULL)
    {
        envio_getDestino(this, zonaAux);
        if(strcmp("quilmes",zonaAux)== 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Base a tomar para realizar un ordenamiento alfabetico de nombres.
 *
 * \param thisA void*
 * \param thisB void*
 * \return int
 *
 */
int envio_sortByZone(void* thisA,void* thisB)
{
    int retorno = 0;
    char zonaA[50];
    char zonaB[50];

   envio_getDestino(thisA,zonaA);
   envio_getDestino(thisB,zonaB);

   if(strcmp(zonaA,zonaB)>0)
   {
    retorno = 1;
   }
   else if(strcmp(zonaA,zonaB)< 0)
   {
    retorno = -1;
   }
    return retorno;
}
