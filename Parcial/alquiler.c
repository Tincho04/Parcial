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

