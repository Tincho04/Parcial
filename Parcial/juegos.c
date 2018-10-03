#include "juegos.h"

void inicializarJuegos(eJuegos x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
        x[i].idJuego= 0;
    }
}


int buscarLibre( eJuegos x[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarJuego(eJuegos x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {


        if( x[i].idJuego == id && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void agregarJuego(eJuegos Juegos[], int tam)
{
    eJuegos nuevoJuego;
    int indice;
    int esta;
    int id;

    system("cls");
    printf("  *** Alta Juego ***\n\n");

    indice = buscarLibre(Juegos, tam);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese el id del juego");
        scanf("%d", &id);

        esta = buscarJuego(Juegos, tam, id);

        if(esta != -1)
        {
            printf("Existe un Juego con el id %d\n", id);
            mostrarJuegos(Juegos, esta);
        }
        else
        {
            nuevoJuego.idJuego = generarID(Juegos,esta);

            printf("Ingrese Descripcion: ");
            fflush(stdin);
            gets(nuevoJuego.descripcion);
            printf("Ingrese Importe: ");
            scanf("%d", &nuevoJuego.importe);

            nuevoJuego.isEmpty = 1;

            Juegos[indice] = nuevoJuego;

        }
    }

}
int generarID(eJuegos x[],int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(x[i].isEmpty == 1)
            {
                    if(x[i].idJuego>retorno)
                    {
                         retorno=x[i].idJuego;
                    }

            }
        }
    }

    return retorno+1;
}


void mostrarJuego(eJuegos jgs)
{
    printf("%4d %10s %4d \n\n", jgs.idJuego, jgs.descripcion, jgs.importe);
}


void mostrarJuegos(eJuegos nomina[], int tam)
{
    int i;

    system("cls");
    printf(("id   Descripcion  Importe\n\n"));
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarJuego(nomina[i]);
        }
    }
}

void eliminarJuego(eJuegos Juegos[], int tam)
{

    int id;
    int indice;
    char borrar;

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarJuego(Juegos, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun Juego con el id %d\n", id);
    }
    else
    {
        mostrarJuego( Juegos[indice]);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            Juegos[indice].isEmpty = 0;
            printf("Se ha eliminado el Juego\n\n");
        }
        system("pause");
    }

}

void modificarJuego(eJuegos Juegos[], int tam)
{
    int id;
    int indice;
    char modificar;
    char opcion;
    char nuevaDescripcion[51];
    int nuevoImporte;

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarJuego(Juegos, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun Juego con el id %d\n", id);
    }
    else
    {
        mostrarJuego( Juegos[indice]);

        printf("Que desea modificar? \t D-Descripcion. \t I-Importe. ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'D':

            printf("\nModifica descripcion?: ");
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Ingrese la descripcion: ");
                fflush(stdin);
                gets(nuevaDescripcion);
                validarStringJ(nuevaDescripcion);
                strcpy(nuevaDescripcion,Juegos[indice].descripcion);
                system("pause");
                break;
            }
        case 'I':

            printf("\nModifica importe?: ");
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Ingrese el importe: ");
                scanf("%d",nuevoImporte);
                validarImporte(nuevoImporte);
                Juegos[indice].importe=nuevoImporte;
                system("pause");
                break;
            }
        default:
            printf("No ha ingresado una opcion valida");
            break;
        }

        system("pause");
    }
}


void ordenarXImporteYDescrip(eJuegos x[],int tam)
{
    int i, j;
    eJuegos auxJuego;

    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            if(x[i].importe==x[j].importe)
            {
                if(strcmp(x[i].descripcion, x[j].descripcion)>0)
                {
                    auxJuego=x[i];
                    x[i]=x[j];
                    x[j]=auxJuego;
                }
            }
            else if (x[i].importe>x[j].importe)
            {
                auxJuego=x[i];
                x[i]=x[j];
                x[j]=auxJuego;
            }
        }
    }
        for (i=0; i<tam; i++)
    {
        mostrarJuego(x[i]);
    }
    system("pause");
}
