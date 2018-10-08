#include "Clientes.h"
#include "validaciones.h"

void inicializarClientes(eCliente x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = VACIO;
    }
}


int buscarLibreCl( eCliente x[], int tam)
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

int buscarClientexidCliente(eCliente x[], int tam, int idCliente)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {

        if( x[i].idCliente == idCliente && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta de Cliente\n");
    printf("2- Modificar Cliente\n");
    printf("3- Baja de Cliente\n");
    printf("4- Listar Clientes\n");
    printf("5- Alta de Juegos\n");
    printf("6- Modificar Juegos\n");
    printf("7- Baja de Juegos\n");
    printf("8- Listar Juegos\n");
    printf("9- Alta de Alquileres\n");
    printf("10- Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int  IDC()
{
    static int idCliente=0;
    idCliente++;
    return idCliente;
}

int agregarCliente(eCliente Clientes[], int tam)
{
    int retorno = -1;
    eCliente nuevoCliente;
    int indice;
    char nuevoApellido[51];
    char nuevoNombre[51];
    char nuevoDomicilio[51];
    char nuevoTelefono[21];

    system("cls");
    printf("  *** Alta Cliente ***\n\n");
    indice = buscarLibreCl(Clientes, tam);
    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese apellido: ");
        fflush(stdin);
        if(getStr(nuevoApellido,51)==0 && validarName(nuevoApellido,51)==1)
        {
            fflush(stdin);
            strcpy(nuevoCliente.apellido,nuevoApellido);
        }
        printf("Ingrese Nombre: ");
        fflush(stdin);
        if(getStr(nuevoNombre,51)==0 && validarName(nuevoNombre,51)==1)
        {
            fflush(stdin);
            strcpy(nuevoCliente.nombre,nuevoNombre);
        }
        printf("Ingrese Domicilio: ");
        fflush(stdin);
        if(getStr(nuevoDomicilio,51)==0 && validarName(nuevoDomicilio,51)==1)
        {
            fflush(stdin);
            strcpy(nuevoCliente.domicilio,nuevoDomicilio);
        }
        printf("Ingrese Telefono: ");
        fflush(stdin);
        if(getStr(nuevoTelefono,51)==0)
        {
            fflush(stdin);
            strcpy(nuevoCliente.telefono,nuevoTelefono);
        }
        Clientes[indice].idCliente =IDC();
        nuevoCliente.isEmpty = OCUP;
        Clientes[indice] = nuevoCliente;
        retorno=0;
    }
    return retorno;
}
void mostrarCliente(eCliente clt)
{
    if(clt.isEmpty==OCUP)
    {
        printf("%4d %10s %10s %10s  %10s \n\n", clt.idCliente, clt.apellido, clt.nombre, clt.domicilio, clt.telefono);
    }
}


void mostrarClientes(eCliente nomina[], int tam)
{
    int i;

    system("cls");
    printf(("idCliente   apellido  Nombre  Domicilio  Telefono\n\n"));
    for(i=0; i< tam; i++)
    {
            mostrarCliente(nomina[i]);
    }
}

void eliminarCliente(eCliente Clientes[], int tam)
{

    int idCliente;
    int indice;
    char borrar;

    printf(("idCliente   apellido  Nombre  Domicilio  Telefono\n\n"));
    mostrarClientes(Clientes,tam);

    printf("Ingrese idCliente: ");
    scanf("%d", &idCliente);

    indice = buscarClientexidCliente(Clientes, tam, idCliente);

    if( indice == -1)
    {
        printf("No hay ningun Cliente con el idCliente %d\n", idCliente);
    }
    else
    {
        mostrarCliente(Clientes[indice]);
        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            Clientes[indice].isEmpty = VACIO;
            printf("Se ha eliminado el Cliente\n\n");
        }
        system("pause");
    }

}

void modificarCliente(eCliente Clientes[], int tam)
{

    int idCliente;
    int indice;
    char modificar;
    char opcion;
    char nuevoApellido[51];
    char nuevoNombre[51];
    char nuevoDomicilio[51];
    char nuevoTelefono[21];

    printf("Ingrese idCliente: ");
    scanf("%d", &idCliente);

    indice = buscarClientexidCliente(Clientes, tam, idCliente);

    if( indice == -1)
    {
        printf("No hay ningun Cliente con el idCliente %d\n", idCliente);
    }
    else
    {
        mostrarCliente(Clientes[indice]);

        printf("Que desea modificar? \t A-apellido. \t N-Nombre. \t D-Domicilio. \t T-Telefono. ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'A':

            printf("\nModifica apellido?: ");
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Ingrese el apellido: ");
                fflush(stdin);
                if(getStr(nuevoApellido,51)==0 && validarName(nuevoApellido,51)==1)
                {
                    fflush(stdin);
                    strcpy(Clientes[indice].apellido,nuevoApellido);
                }
                system("pause");
                break;
            }
        case 'N':

            printf("\nModifica nombre?: ");
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Ingrese el nombre: ");
                fflush(stdin);
                if(getStr(nuevoNombre,51)==0 && validarName(nuevoNombre,51)==1)
                {
                    fflush(stdin);
                    strcpy(Clientes[indice].nombre,nuevoNombre);
                }
                system("pause");
                break;
            }
        case 'D':
            printf("\nModifica domicilio?: ");
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Ingrese el domicilio: ");
                fflush(stdin);
                if(getStr(nuevoDomicilio,51)==0 && validarName(nuevoDomicilio,51)==1)
                {
                    fflush(stdin);
                    strcpy(Clientes[indice].domicilio,nuevoDomicilio);
                }
                system("pause");
                break;
            }

        case 'T':
            printf("\nModifica telefono?: ");
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Ingrese el telefono: ");
                fflush(stdin);
                if(getStr(nuevoTelefono,51)==0)
                {
                    fflush(stdin);
                    strcpy(Clientes[indice].telefono,nuevoTelefono);
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


void ordenarXApellidoYNombre(eCliente listado[],int tam)
{
    int i, j;
    eCliente auxCliente;

    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            if(strcmp(listado[i].apellido, listado[j].apellido)==0)
            {
                if(strcmp(listado[i].nombre, listado[j].nombre)>=0)
                {
                    auxCliente=listado[i];
                    listado[i]=listado[j];
                    listado[j]=auxCliente;
                }
            }
            else if (strcmp(listado[i].apellido, listado[j].apellido)>0)
            {
                auxCliente=listado[i];
                listado[i]=listado[j];
                listado[j]=auxCliente;
            }
        }
    }
    for (i=0; i<tam; i++)
    {
        mostrarCliente(listado[i]);
    }
}
