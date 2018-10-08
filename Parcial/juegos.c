#include "validaciones.h"
#include "juegos.h"

void inicializarJuegos(eJuegos x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = VACIO;
        x[i].idJuego= VACIO;
    }
}


int buscarLibre( eJuegos x[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i< tam; i++)
    {

        if( x[i].isEmpty == VACIO)
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


        if( x[i].idJuego == id && x[i].isEmpty == OCUP)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int  IDJ()
{
    static int idJuego=0;
    idJuego++;
    return idJuego;
}

void agregarJuego(eJuegos Juegos[], int tam)
{
    eJuegos nuevoJuego;
    int indice;
    int esta;
    int id;
    char descrip[51];
    char importe[21];

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
            nuevoJuego.idJuego = IDJ();

            printf("Ingrese Descripcion: ");
            fflush(stdin);
            if(getStr(descrip,51)==0 && validarName(descrip,51)==1)
            {
             fflush(stdin);
             strcpy(nuevoJuego.descripcion,descrip);
            }
            printf("Ingrese Importe: ");
            if(getStr(importe,21)==0 && validarImporte(importe,21)==1)
            {
             fflush(stdin);
             nuevoJuego.importe=atof(importe);
             if(validarFloat(nuevoJuego.importe)==1)
             {
                printf("Importe almacenado exitosamente");
             }
             else {
                printf("El importe ingresado no es valido");
             }

             }
            }
            nuevoJuego.isEmpty = OCUP;

            Juegos[indice] = nuevoJuego;

        }
    }


void mostrarJuego(eJuegos jgs)
{
    printf("%4d %10s %4f \n\n", jgs.idJuego, jgs.descripcion, jgs.importe);
}


void mostrarJuegos(eJuegos nomina[], int tam)
{
    int i;

    system("cls");
    printf(("id   Descripcion  Importe\n\n"));
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == OCUP)
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
            Juegos[indice].isEmpty = VACIO;
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
    char nuevoImporte[21];

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
                if(getStr(nuevaDescripcion,51)==0 && validarName(nuevaDescripcion,51)==1)
                {
                    fflush(stdin);
                    strcpy(Juegos[indice].descripcion,nuevaDescripcion);
                }
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
                if(getStr(nuevoImporte,21)==0 && validarImporte(nuevoImporte,21)==1)
                {
                    fflush(stdin);
                    Juegos[indice].importe=atof(nuevoImporte);
                    if(Juegos[indice].importe<0)
                    {
                        printf("Reingrese un importe real: ");
                        getStr(nuevoImporte,21);
                        validarImporte(nuevoImporte,21);
                    }
                }
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
