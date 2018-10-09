#include "alquiler.h"
#include "validaciones.h"
#include "Clientes.h"
#include "juegos.h"

void inicializarAlquiler(eAlquiler x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = VACIO;
        x[i].codAlquiler = -1;
    }
}

int  IDA()
{
    static int idAlquiler=0;
    idAlquiler++;
    return idAlquiler;
}

int buscarLibreAl( eAlquiler x[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i< tam; i++)
    {

        if( x[i].isEmpty == OCUP)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarA(eAlquiler x[],int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(x[i].isEmpty == VACIO)
            {
                if(x[i].codAlquiler>retorno)
                {
                    retorno=x[i].codAlquiler;
                }
            }
        }
    }
    return retorno+1;
}

int buscarAlquiler(eAlquiler x[], int tam, int idAlquiler)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {


        if( x[i].codAlquiler == idAlquiler && x[i].isEmpty == OCUP)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaAlquiler(eAlquiler alquiler[], int tam, eJuegos buscarJ[], int tamJ, eCliente buscarC[], int tamC)
{
    eAlquiler nuevoAlquiler;
    int indice;
    int esta;
    char codJ[11];
    char codC[11];
    char dia[3];
    char mes[3];
    char anio[5];

    system("cls");
    printf("  *** Alta Alquileres ***\n\n");

    indice = buscarLibreAl(alquiler, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese el Codigo del Juego: ");
        if(getStr(codJ,11)==0 && validarImporte(codJ,11)==1)
        {
            fflush(stdin);
            nuevoAlquiler.codJuego=atoi(codJ);
            esta = buscarJuego(buscarJ, tamJ, nuevoAlquiler.codJuego);
            if(esta != -1)
            {
                printf("Codigo ingresado correctamente\n");
                mostrarJuego(buscarJ[esta]);
            }
            else
            {
                printf("El codigo ingresado no pertenece a un juego existente. ");
            }
        }
        else
        {
            printf("Codigo no valido");
        }
        printf("Ingrese el Codigo del Cliente: ");
        if(getStr(codC,11)==0 && validarImporte(codC,11)==1)
        {
            fflush(stdin);
            nuevoAlquiler.codCliente=atoi(codC);
            esta = buscarClientexidCliente(buscarC, tamC, nuevoAlquiler.codCliente);
            if(esta != -1)
            {
                printf("Codigo ingresado correctamente\n");
                mostrarCliente(buscarC[esta]);
            }
            else
            {
                printf("El codigo ingresado no pertenece a un cliente existente. ");
            }
        }
        else
        {
            printf("Codigo no valido");
        }
        system("pause");

        printf("Ingrese el Numero de dia: ");
        if(getStr(dia,3)==0 && validarImporte(dia,3)==1)
        {
            fflush(stdin);
            nuevoAlquiler.fechaAlquiler.dia=atoi(dia);
        }
        else
        {
            printf("el dia ingresado no es valido");
        }

        printf("Ingrese el Numero de mes: ");
        if(getStr(mes,3)==0 && validarImporte(mes,3)==1)
        {
            fflush(stdin);
            nuevoAlquiler.fechaAlquiler.mes=atoi(mes);
        }
        else
        {
            printf("el mes ingresado no es valido");
        }

        printf("Ingrese el Numero del anio: ");
        if(getStr(anio,5)==0 && validarImporte(anio,5)==1)
        {
            fflush(stdin);
            nuevoAlquiler.fechaAlquiler.anio=atoi(anio);
        }
        else
        {
            printf("el anio ingresado no es valido");
        }


        nuevoAlquiler.codAlquiler = IDA();
        nuevoAlquiler.isEmpty = OCUP;

        alquiler[indice] = nuevoAlquiler;

    }
}

float calcularPromedio(eJuegos* juegos, int tamJ, eAlquiler* alquileres, int tamA)
{
    int i;
    int j;
    int contImporte=0;
    float sumaImporte=0;
    float promedioImportes;
    for (i=0; i<tamA; i++)
    {
        if(alquileres[i].isEmpty==OCUP)
        {
            for(j=0; j<tamJ; j++)
            {
                if(alquileres[i].codJuego==juegos[j].idJuego)
                {
                    sumaImporte=sumaImporte+juegos[j].importe;
                    contImporte++;
                }
            }
        }
    }
    promedioImportes=sumaImporte/contImporte;
    printf("El promedio de los importes de los juegos alquilados es de: %f \n", promedioImportes);
    printf("El total de importes de los juegos alquilados es de: %f \n", sumaImporte);

    return promedioImportes;
}

void compararImportes (eJuegos juegos[], int tamJ, eAlquiler alquileres[], int tamA )
{
    int i;
    int contJuegosSobreProme=0;
    float promedio;
    promedio=calcularPromedio(juegos, tamJ,alquileres, tamA);
    for(i=0; i<tamJ; i++)
    {
        if(juegos[i].isEmpty==OCUP && juegos[i].importe<promedio)
        {
            mostrarJuego(juegos[i]);
            contJuegosSobreProme++;
        }
    }
    printf("La cantidad de Juegos cuyo importe no supera el promedio es de: %d \n ", contJuegosSobreProme);

    system("pause");
}

void listarClientesAlquiler (eCliente cliente[], int tamC, eAlquiler alquileres[], int tamA, eJuegos juegos[],int tamJ)
{
    int i;
    int j;
    int idj;
    mostrarJuegos(juegos,tamJ);
    printf("Ingrese el codigo del juego");
    scanf("%d", &idj);
    printf("Clientes que han alquilado dicho juego: ");
    for(i=0; i<tamA; i++)
    {
        if(idj==alquileres[i].codJuego && alquileres[i].isEmpty==OCUP)
        {
            for(j=0; j<tamC; j++)
            {
                if(alquileres[i].codCliente==cliente[j].idCliente && cliente[j].isEmpty==OCUP)
                {
                    mostrarCliente(cliente[j]);
                }
            }
        }

    }
}

void listarJuegosxCliente (eCliente cliente[], int tamC, eAlquiler alquileres[], int tamA, eJuegos Juegos[],int tamJ)
{
    int i;
    int j;
    int k;
    int idc;
    mostrarClientes(cliente,tamC);
    printf("Ingrese el codigo del cliente");
    scanf("%d", &idc);
    printf("Juegos alquilados por este cliente: ");
    for(i=0; i<tamC; i++)
    {
        if(idc==cliente[i].idCliente && cliente[i].isEmpty==OCUP)
        {
            for(j=0; j<tamA; j++)
            {
                if(cliente[i].idCliente==alquileres[j].codCliente && alquileres[j].isEmpty==OCUP)
                {
                    for(k=0; k<tamJ; k++)
                    {
                        if(alquileres[j].codJuego==Juegos[k].idJuego && Juegos[k].isEmpty==OCUP)
                        {
                            mostrarJuego(Juegos[k]);
                        }
                        else
                        {
                            printf("No hay juegos alquilados por este cliente");
                        }
                    }
                }
                else
                {
                    printf("Este cliente no ha realizado alquileres.");
                }
            }
        }
        else
        {
            printf("Este cliente no se encuentra en la base de datos.");
        }
    }
    system("pause");
}
/*
void contAlquileres (eAlquiler alquileres[], int tamA,eJuegos juegos[], int tamJ)
{
    int i;
    int j;
    int alquilerMin=0;
    int alquilerMax=0;
    int contadorBeta=0;
    eAlquiler menosAlquilado;
    int i;
    for(i=0; i<tamA; i++)
    {
        if(alquileres[i].isEmpty==OCUP)
        {
            for(j=0;j<tamA;j++)
            {
                if(alquileres[j].codJuego==alquileres[i].codJuego)
                {

                }
            }
            }
    }
}
*/

void ordenarXImporte(eJuegos x[],int tam)
{
    int i, j;
    eJuegos auxJuego;
    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            if(x[i].importe<x[j].importe)
            {
                auxJuego=x[i];
                x[i]=x[j];
                x[j]=auxJuego;
            }
            else
            {
                auxJuego=x[j];
                x[j]=x[i];
                x[i]=auxJuego;
            }
        }
    }
    for (i=0; i<tam; i++)
    {
        mostrarJuego(x[i]);
    }
    system("pause");
}

void apellidoInsercion (eCliente* clientes, int tam)
{
    int i;
    int j;
    eCliente tmp;
    for (i = 1; i < tam; i++)
    {
        strcpy(tmp.apellido,clientes[i].apellido);
        j = i - 1;
        while ((j >= 0) && (strcmp(tmp.apellido, clientes[j].apellido)>1))
        {
            strcpy(clientes[j+1].apellido,clientes[j].apellido);
            j--;
        }
        strcpy(clientes[j + 1].apellido,tmp.apellido);
    }
}

void listarJPorFechaX (eJuegos juegos[], int tamJ, eAlquiler alquileres[], int tamA)
{
    eFecha aux;
    int i;
    int j;

    printf("Ingrese el dia a buscar");
    scanf("%d", &aux.dia);
    printf("Ingrese el mes a buscar");
    scanf("%d", &aux.mes);
    printf("Ingrese el anio a buscar");
    scanf("%d", &aux.anio);
    printf("Juegos que han sido alquilados en la fecha ingresada: ");
    for(i=0;i<tamA;i++){
            if(aux.dia==alquileres[i].fechaAlquiler.dia && aux.mes==alquileres[i].fechaAlquiler.mes && aux.anio==alquileres[i].fechaAlquiler.anio && alquileres[i].isEmpty==OCUP)
                {
                    for(j=0;j<tamJ;j++){
                        if(alquileres[i].codJuego==juegos[j].idJuego && juegos[j].isEmpty==OCUP)
                        {
                            mostrarJuego(juegos[j]);
                        }else{printf("No hay juegos alquilados en tal fecha");}
                    }
                }else{printf("Tal fecha no coincide con alguna registrada en los alquileres");
                }
    }
}

void listarCPorFechaX (eCliente clientes[], int tamC, eAlquiler alquileres[], int tamA)
{
    eFecha aux;
    int i;
    int j;
    printf("Ingrese el dia a buscar");
    scanf("%d", &aux.dia);
    printf("Ingrese el mes a buscar");
    scanf("%d", &aux.mes);
    printf("Ingrese el anio a buscar");
    scanf("%d", &aux.anio);

    printf("Clientes que han realizado al menos un alquiler en la fecha ingresada: ");
    for(i=0;i<tamA;i++){
            if(aux.dia==alquileres[i].fechaAlquiler.dia && aux.mes==alquileres[i].fechaAlquiler.mes && aux.anio==alquileres[i].fechaAlquiler.anio && alquileres[i].isEmpty==OCUP)
                {
                    for(j=0;j<tamC;j++){
                        if(alquileres[i].codCliente==clientes[j].idCliente && clientes[j].isEmpty==OCUP)
                        {
                            mostrarCliente(clientes[j]);
                        }else{printf("No hay clientes que hayan realizado alquileres en dicha fecha");}

                    }
                }else{printf("Tal fecha no coincide con alguna registrada en los alquileres");}

    }

}
