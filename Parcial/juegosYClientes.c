#include "juegosYClientes.h"
#include "validaciones.h"

void inicializarClientes(eCliente x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
        x[i].idCliente= 0;
    }
}


int buscarLibreCl( eCliente x[], int tam)
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

int cargarI(eCliente x[],int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(x[i].isEmpty == 1)
            {
                if(x[i].idCliente>retorno)
                {
                    retorno=x[i].idCliente;
                }
            }
        }
    }
    return retorno+1;
}

int buscarCliente(eCliente x[], int tam, int idCliente)
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



void agregarCliente(eCliente Clientes[], int tam)
{
    eCliente nuevoCliente;
    int indice;
    int esta;
    int idCliente;

    system("cls");
    printf("  *** Alta Cliente ***\n\n");

    indice = buscarLibreCl(Clientes, tam);


    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &idCliente);

        esta = buscarCliente(Clientes, tam, idCliente);

        if(esta != -1)
        {
            printf("Existe un Cliente con el id %d\n", idCliente);
            mostrarCliente(Clientes[esta]);
        }
        else
        {
            nuevoCliente.idCliente =cargarI(Clientes,esta);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoCliente.apellido);
            validarStringC(nuevoCliente.apellido, 51);
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(nuevoCliente.nombre);
            validarStringC(nuevoCliente.nombre, 51);
            printf("Ingrese Domicilio: ");
            fflush(stdin);
            gets(nuevoCliente.domicilio);
            validarStringC(nuevoCliente.domicilio, 51);
            printf("Ingrese Telefono: ");
            fflush(stdin);
            gets(nuevoCliente.telefono);
            validarStringC(nuevoCliente.telefono, 21);

            nuevoCliente.isEmpty = 1;

            Clientes[indice] = nuevoCliente;

        }
    }

}


void mostrarCliente(eCliente clt)
{
    printf("%4d %10s %10s %10s  %10s \n\n", clt.idCliente, clt.apellido, clt.nombre, clt.domicilio, clt.telefono);
}


void mostrarClientes(eCliente nomina[], int tam)
{
    int i;

    system("cls");
    printf(("idCliente   apellido  Nombre  Domicilio  Telefono\n\n"));
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarCliente(nomina[i]);
        }
    }
}

void eliminarCliente(eCliente Clientes[], int tam)
{

    int idCliente;
    int indice;
    char borrar;

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
            Clientes[indice].isEmpty = 0;
            printf("Se ha eliminado el Cliente\n\n");
        }
        system("pause");
    }

}

void modificarCliente(eCliente Clientes[], int tam)
{

    int idCliente;
    int indice;
    int validar;
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
        mostrarCliente( Clientes[indice]);

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
                gets(nuevoApellido);
                validarStringC(nuevoApellido, 51);
                strcpy(nuevoApellido,Clientes[indice].apellido);
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
                gets(nuevoNombre);
                validar=validarStringC(nuevoApellido, 51);
                if(validar!=0)
                {
                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(nuevoNombre);
                validar=validarStringC(nuevoApellido, 51);
                }
                strcpy(nuevoNombre,Clientes[indice].nombre);
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
                gets(nuevoDomicilio);
                validarStringC(nuevoApellido, 51);
                strcpy(nuevoDomicilio,Clientes[indice].domicilio);
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
                gets(nuevoTelefono);
                validarStringC(nuevoTelefono, 21);
                strcpy(nuevoTelefono,Clientes[indice].telefono);
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


void ordenarXapellidoYNombre(eCliente listado[],int tam)
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
    system("pause");
}

void validarApellido (eCliente cliente)
{
    int i;
    for (i=0; i<strlen(cliente.apellido); i++)
    {
        if (cliente.apellido[i]==' ')
        {
            break;
        }
        while (!(isalpha(cliente.apellido[i])))
        {
            printf("Reingrese un apellido valido \n");
            gets(cliente.apellido);
            fflush(stdin);
        }
    }
}

void validarNombre (eCliente cliente)
{
    int i;
    for (i=0; i<strlen(cliente.nombre); i++)
    {
        if (cliente.nombre[i]==' ')
        {
            break;
        }
        while (!(isalpha(cliente.nombre[i])))
        {
            printf("Reingrese un nombre valido \n");
            gets(cliente.nombre);
            fflush(stdin);
        }
    }
}

void correccionApellidos(eCliente listado[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        strlwr(listado[i].apellido);
    }
    for(i=0; i<tam; i++)
    {
        listado[i].apellido[0]=toupper(listado[i].apellido[0]);
        for(j=0; j<strlen(listado[i].apellido); j++)
        {
            if(listado[i].apellido[j]==' ')
            {
                listado[i].apellido[j+1]=toupper(listado[i].apellido[j+1]);
            }
        }
    }
}

void correccionNombres(eCliente listado[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        strlwr(listado[i].nombre);
    }
    for(i=0; i<tam; i++)
    {
        listado[i].nombre[0]=toupper(listado[i].nombre[0]);
        for(j=0; j<strlen(listado[i].nombre); j++)
        {
            if(listado[i].nombre[j]==' ')
            {
                listado[i].nombre[j+1]=toupper(listado[i].nombre[j+1]);
            }
        }
    }
}
