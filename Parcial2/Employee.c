#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"



/** \brief Solicita espacio en memoria para un nuevo empleado.
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
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
*\brief llama al Set de datos del empleado.
*\param idStr char*
*\param nombreStr char*
*\param horasTrabajadasStr char*
*\param sueldoStr char*
*\return Employee*
*/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
  Employee* this;
    this = employee_new();

    int idClienteInt = atoi(idStr);
    int horasTrabajadasInt = atoi(horasTrabajadasStr);

    if(
    !employee_setId(this,idClienteInt)&&
    !employee_setName(this,nombreStr)&&
    !employee_setHours(this,horasTrabajadasInt))
        return this;
    return NULL;
}

/** \brief set del nombre del empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */

int employee_setName(Employee* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el nombre del empleado.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getName(Employee* this, char* nombre)
{
   int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief set de las horas trabajadas por el empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHours(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar las horas trabajadas del empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHours(Employee* this, int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief set del sueldo del empleado.
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSalary(Employee* this, int sueldo)
{
     int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief funcion get para tomar el sueldo del empleado.
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSalary(Employee* this, int* sueldo)
{
     int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Set del ID del empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
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

/** \brief funcion get para tomar el ID del empleado.
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this, int* id)
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
 * \param this Employee*
 * \param nombre char*
 * \param horas int*
 * \param sueldo int*
 * \param id int*
 * \return int
 *
 */
int employee_getAll(Employee* this,char* nombre,int* horas,int* sueldo,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        employee_getName(this,nombre);
        employee_getHours(this,horas);
        employee_getSalary(this,sueldo);
        employee_getId(this,id);
        retorno = 0;
    }
    return retorno;
}

/** \brief Algoritmo que toma el salario en base a horas trabajadas.
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) Si ok
 */
int ll_salary(Employee* this)
{
    int returnAux = -1;
    int sueldo;
    if(this->horasTrabajadas<=176)
    {
        sueldo=this->horasTrabajadas*180;
        employee_setSalary(this,sueldo);
        returnAux = 0;
    }else if(this->horasTrabajadas>=177 && this->horasTrabajadas<=208){
        sueldo=this->horasTrabajadas*270;
        employee_setSalary(this,sueldo);
        returnAux = 0;
    }else if(this->horasTrabajadas>=209 && this->horasTrabajadas<=240){
        sueldo=this->horasTrabajadas*360;
        returnAux = 0;
        employee_setSalary(this,sueldo);
    }

    return returnAux;
}


