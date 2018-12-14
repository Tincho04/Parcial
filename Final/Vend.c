#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vend.h"
#include "string.h"
#include "Validaciones.h"



/** \brief Solicita espacio en memoria para un nuevo vendedor.
 *
 * \return vend*
 *
 */
vend* vend_new()
{
    vend* this;
    this=malloc(sizeof(vend));
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
*\brief llama al Set de datos del vendedor.
*\param idStr char*
*\param nombreStr char*
*\param NivelStr char*
*\param prodVendidosStr char*
*\return vend*
*/

vend* vend_newParametros(char* idStr,char* nombreStr,char* NivelStr, char* prodVendidosStr, char* montoVendidoStr)
{
  vend* this;
    this = vend_new();

    int idClienteInt = atoi(idStr);
    int nivelInt = atoi(NivelStr);
    int prodVendidosInt = atoi(prodVendidosStr);
    float montoVendidoFt = atof(montoVendidoStr);

    if(
    !vend_setId(this,idClienteInt)&&
    !vend_setName(this,nombreStr)&&
    !vend_setLevel(this,nivelInt)&&
    !vend_setSold(this,prodVendidosInt)&&
    !vend_setCash(this,montoVendidoFt))
     {
         return this;
     }
    return NULL;
}

/** \brief set del nombre del vendedor.
 *
 * \param this vend*
 * \param nombre char*
 * \return int
 *
 */

int vend_setName(vend* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el nombre del vendedor.
 *
 * \param this vend*
 * \param nombre char*
 * \return int
 *
 */
int vend_getName(vend* this, char* nombre)
{
   int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief set del nivel del vendedor.
 *
 * \param this vend*
 * \param Nivel char*
 * \return int
 *
 */
int vend_setLevel(vend* this,int nivel)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->nivel=nivel;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar las horas trabajadas del vendedor.
 *
 * \param this vend*
 * \param Nivel int*
 * \return int
 *
 */
int vend_getLevel(vend* this, int* nivel)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *nivel=this->nivel;
        retorno=0;
    }
    return retorno;
}

/** \brief set del prodVendidos del vendedor.
 *
 * \param this vend*
 * \param prodVendidos int
 * \return int
 *
 */
int vend_setSold(vend* this, int prodVendidos)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->prodVendidos=prodVendidos;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el prodVendidos del vendedor.
 *
 * \param this vend*
 * \param prodVendidos int*
 * \return int
 *
 */
int vend_getSold(vend* this, int* prodVendidos)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *prodVendidos=this->prodVendidos;
        retorno=0;
    }
    return retorno;
}


/** \brief set del monto de los productos vendidos.
 *
 * \param this vend*
 * \param montoVendido float
 * \return int
 *
 */
int vend_setCash(vend* this, float montoVendido)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->montoVendido=montoVendido;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el monto de los productos vendidos.
 *
 * \param this vend*
 * \param montoVendido float*
 * \return int
 *
 */
int vend_getCash(vend* this, float* montoVendido)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *montoVendido=this->montoVendido;
        retorno=0;
    }
    return retorno;
}

/** \brief set del monto de comision por venta y nivel.
 *
 * \param this vend*
 * \param comision float
 * \return int
 *
 */
int vend_getComi(vend* this, float* comision)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *comision=this->comision;
        retorno=0;
    }
    return retorno;
}

/** \brief set del monto de comision por venta y nivel.
 *
 * \param this vend*
 * \param comision float
 * \return int
 *
 */
int vend_setComi(vend* this, float comision)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->comision=comision;
        retorno=0;
    }
    return retorno;
}

/** \brief Set del ID del vendedor.
 *
 * \param this vend*
 * \param id int
 * \return int
 *
 */
int vend_setId(vend* this,int id)
{
 int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el ID del vendedor.
 *
 * \param this vend*
 * \param id int*
 * \return int
 *
 */
int vend_getId(vend* this, int* id)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief automatizador de datos para realizar todos los gets en una sola funcion.
 *
 * \param this vend*
 * \param nombre char*
 * \param horas int*
 * \param prodVendidos int*
 * \param id int*
 * \return int
 *
 */
int vend_getAll(vend* this,char* nombre,int* nivel,int* prodVendidos,float* montoVendido,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        vend_getName(this,nombre);
        vend_getLevel(this,nivel);
        vend_getSold(this,prodVendidos);
        vend_getCash(this,montoVendido);
        vend_getId(this,id);
        retorno = 0;
    }
    return retorno;
}


/** \brief automatizador de datos para realizar todos los gets en una sola funcion.
 *
 * \param this vend*
 * \param nombre char*
 * \param horas int*
 * \param prodVendidos int*
 * \param id int*
 * \return int
 *
 */
int vend_getAllC(vend* this,char* nombre,int* nivel,int* prodVendidos,float* montoVendido,float* comision,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        vend_getName(this,nombre);
        vend_getLevel(this,nivel);
        vend_getSold(this,prodVendidos);
        vend_getCash(this,montoVendido);
        vend_getComi(this,comision);
        vend_getId(this,id);
        retorno = 0;
    }
    return retorno;
}


/** \brief Algoritmo que calcula la comision por venta en base al nivel del vendedor y/o productos vendidos.
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) Si ok
 */
int calcComision(void* vendA)
{
    int returnAux = -1;
    int nivelAux=0;
    float comiAux=0;
    float montosAux=1;
    int vendidosAux=0;
    if(vendA!=NULL){
        vend_getLevel(((vend*)vendA),&nivelAux);
        vend_getCash(((vend*)vendA),&montosAux);
        vend_getSold(((vend*)vendA),&vendidosAux);
        if(nivelAux==0){
            comiAux=2*montosAux/100;
            vend_setComi(((vend*)vendA),comiAux);
            returnAux = 1;
        }
        else if((nivelAux==1 && vendidosAux<100) || (nivelAux==2 && vendidosAux<100)){
            comiAux=3.5*montosAux/100;
            vend_setComi(((vend*)vendA),comiAux);
            returnAux = 1;
        }
        else if((nivelAux==1 && vendidosAux>=100) || (nivelAux==2 && vendidosAux>=100)) {
            comiAux=5*montosAux/100;
            vend_setComi(((vend*)vendA),comiAux);
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los vendedores en base al nivel "Junior".
 *
 * \param this vend*
 * \return int
 *
 */
int vend_filtroJr(vend* this)
{
    int returnAux = -1;
    int nivelAux;

    if (this != NULL)
    {
        vend_getLevel(this, &nivelAux);
        if(nivelAux == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los vendedores en base al nivel "Estandard".
 *
 * \param this vend*
 * \return int
 *
 */
int vend_filtroSt(vend* this)
{
    int returnAux = -1;
    int nivelAux;

    if (this != NULL)
    {
        vend_getLevel(this, &nivelAux);
        if(nivelAux == 1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Filtra los vendedores en base al nivel "Experto".
 *
 * \param this vend*
 * \return int
 *
 */

int vend_filtroEx(vend* this)
{
    int returnAux = -1;
    int nivelAux;

    if (this != NULL)
    {
        vend_getLevel(this, &nivelAux);
        if(nivelAux == 2)
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
int vend_sortByName(void* thisA,void* thisB)
{
    int retorno = 0;
    char nameA[50];
    char nameB[50];

   vend_getName(thisA,nameA);
   vend_getName(thisB,nameB);

   if(strcmp(nameA,nameB)>0)
   {
    retorno = 1;
   }
   else if(strcmp(nameA,nameB)< 0)
   {
    retorno = -1;
   }
    return retorno;
}


/** \brief Base a tomar para realizar un ordenamiento de mayor a menor en comisiones.
 *
 * \param thisA void*
 * \param thisB void*
 * \return int
 *
 */
int vend_sortByCom(void* thisA,void* thisB)
{
    int retorno = 0;
    float comA;
    float comB;

   vend_getComi(thisA,&comA);
   vend_getComi(thisB,&comB);

   if(comA>comB)
   {
    retorno = 1;
   }
   else if(comA<comB)
   {
    retorno = -1;
   }
    return retorno;
}
