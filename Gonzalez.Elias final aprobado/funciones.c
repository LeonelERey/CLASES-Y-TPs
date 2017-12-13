#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

xServico* newServico()
{
    xServico* aux;
    aux=(xServico*)malloc(sizeof(xServico));

    return aux;
}
xServico* newServicoParametros(char nombre[],char apellido[],long int dni,char articulo[],float costo,int estado,int numeroServicio)
{
    xServico* servicio;

    servicio=newServico();
    if(servicio!=NULL)
    {
        strcpy(servicio->nombreCliente,nombre);
        strcpy(servicio->apellidoCliente,apellido);
        servicio->dniCliente=dni;
        strcpy(servicio->apellidoCliente,apellido);
        servicio->costo=costo;
        servicio->estado=estado;
        servicio->numeroServicio=numeroServicio;
    }

    return (servicio);
}
xCliente* newCliente()
{
    xCliente* aux;
    aux=(xCliente*)malloc(sizeof(xCliente));

    return aux;
}
xCliente* newClienteParametros(int id,char nombre[],char apellido[],long int dni)
{
    xCliente* persona;

    persona=newCliente();
    if(persona!=NULL)
    {
        persona->id=id;
        strcpy(persona->nombre,nombre);
        strcpy(persona->apellido,apellido);
        persona->dni=dni;
    }

    return (persona);
}
int LeerArchivos(FILE* archivo, ArrayList* lista,ArrayList* lista2)
{
    char codigo[500],nombre[500],apellido[500],dni[500],costo[500],estado[500],numeroServicio[500];
    xCliente* cliente;
    xServico* servicio;
    int retorno,i;
    int id=100;
    int idServicio=10;
    int aux=lista->len(lista);
    for(i=0; i<aux; i++)
    {
        cliente=lista->get(lista,i);
        if(cliente->id!=id)
        {
            id=id;
        }
        else
        {
            if(cliente->id==id)
            {
                id++;
            }
        }
    }
    archivo=fopen("servicios.csv","rw");
    if(archivo!=NULL)
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",nombre,apellido,dni,codigo,costo,estado,numeroServicio);

        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",nombre,apellido,dni,codigo,costo,estado,numeroServicio);
            cliente=newClienteParametros(id,nombre,apellido,dni);
            servicio=newServicoParametros(nombre,apellido,dni,codigo,atof(costo),estado,numeroServicio);
            if(cliente!=NULL&&servicio!=NULL)
            {
                cliente->id=id;
                strcpy(cliente->nombre,nombre);
                strcpy(cliente->apellido,apellido);
                cliente->dni=atoi(dni);

                al_add(lista,cliente);
                servicio=newServicoParametros(nombre,apellido,dni,codigo,atof(costo),estado,numeroServicio);

                strcpy(servicio->nombreCliente,nombre);
                strcpy(servicio->apellidoCliente,apellido);
                servicio->dniCliente=atoi(dni);
                strcpy(servicio->articulo,codigo);
                servicio->costo=atof(costo);
                servicio->estado=atoi(estado);
                servicio->numeroServicio=atoi(numeroServicio);
                /*for(i=0; i<lista2->len(lista2); i++)
                {
                    servicio=lista2->get(lista2,i);
                    if(servicio->numeroServicio==idServicio)
                    {
                        idServicio++;
                    }
                    else
                    {
                        if(servicio->numeroServicio!=idServicio)
                        {
                            idServicio=idServicio;
                        }
                    }
                }
                servicio->numeroServicio=idServicio;*/
                al_add(lista2,servicio);
                id++;
            }
        }
        //printf("Archivo cargado correctamente.\n");
        retorno=1;
    }
    else
    {
        retorno=0;
    }
    fclose(archivo);
    return (retorno);
}
void altaCliente(ArrayList* lista)
{
    xCliente* cliente;
    int i;
    int idAux=100;
    char nombre[20];
    char apellido[20];
    int dni;
    int aux=lista->len(lista);
    for(i=0; i<aux; i++)
    {
        cliente=lista->get(lista,i);
        if(cliente->id!=idAux)
        {
            idAux=idAux;
        }
        else
        {
            if(cliente->id==idAux)
            {
                idAux++;
            }
        }
    }

    printf("ingrese el nombre:");
    fflush(stdin);
    gets(nombre),
         printf("ingrese el apellido:");
    fflush(stdin);
    gets(apellido);
    printf("ingrese el numero de dni:");
    scanf("%ld",&dni);
    while(dni<10000000||dni>60000000)
    {
        printf("ingrese un numero de dni coherente:");
        scanf("%ld",&dni);
    }
    cliente=newClienteParametros(idAux,nombre,apellido,dni);
    al_add(lista,cliente);

}
void modificacion(ArrayList* lista)
{
    int i;
    xCliente* cliente;
    int dni;
    char nombre[20];
    char apellido[20];
    int id;
    int aux=lista->len(lista);


    printf("ingrese el numero de id:");
    scanf("%d",&id);
    while(dni<100)
    {
        printf("el id mas bajo es 100, reingrese id:");
        scanf("%d",&dni);
    }
    for(i=0; i<aux; i++)
    {
        cliente=(xCliente*)lista->get(lista,i);
        if(cliente->id==id)
        {
            printf("ingrese un nuevo nombre:");
            fflush(stdin);
            gets(nombre);
            printf("ingrese un nuevo apellido:");
            fflush(stdin);
            gets(apellido);
            printf("ingrese el numero de dni:");
            scanf("%ld",&dni);
            while(dni<10000000||dni>60000000)
            {
                printf("ingrese un numero de dni coherente:");
                scanf("%ld",&dni);
            }

            cliente=newClienteParametros(id,nombre,apellido,dni);

            lista->set(lista,i,cliente);
            break;


        }
    }

}
void eliminacion(ArrayList* lista)
{
    int i;
    xCliente* cliente;
    int dni;
    char nombre[20];
    char apellido[20];
    int id;
    int aux=lista->len(lista);

    printf("ingrese el numero de id:");
    scanf("%d",&id);
    while(dni<100)
    {
        printf("el id mas bajo es 100, reingrese id:");
        scanf("%d",&dni);
    }
    for(i=0; i<aux; i++)
    {
        cliente=(xCliente*)lista->get(lista,i);
        if(cliente->id==id)
        {
            lista->remove(lista,i);
        }
    }
}
void mostrarClientes(ArrayList* lista)
{
    int i;
    xCliente* cliente;

    printf("======================================================================\n");
    printf("|                          LISTA DE EMPLEADOS                        |\n");
    printf("|====================================================================|\n");
    printf("|    ID     |      NOMBRE      |     APELLIDO      |       DNI       |\n");
    printf("|====================================================================|\n");
    for(i=0; i<lista->len(lista); i++)
    {
        cliente=lista->get(lista,i);
        if(cliente!=NULL)
        {
            printf("|   %-5d   |   %-12s   |   %-12s    |   %-10d    |\n",cliente->id,cliente->nombre,cliente->apellido,cliente->dni);
        }
        else
        {
            printf("se a producido un error.\n");
        }
    }
}
void nuevoServicio (ArrayList* lista,ArrayList* lista2)
{
    xCliente* cliente;
    xServico* servicio;
    char codigo[5];
    float costo;
    int estado;
    int id,i;
    int idServicio=10;
    int aux;
    for(i=0; i<lista2->len(lista2); i++)
    {
        servicio=lista2->get(lista2,i);
        if(servicio->numeroServicio!=idServicio)
        {
            idServicio=idServicio;
        }
        else
        {
            if(servicio->numeroServicio==idServicio)
            {
                idServicio++;
            }
        }
    }
    printf("ingrese el id del cliente:");
    scanf("%d",&id);
    for(i=0; i<lista->len(lista); i++)
    {
        cliente=(xCliente*)lista->get(lista,i);
        if(cliente->id==id)
        {
            printf("ingrese el codigo de 5 caracteres alfanumerico:");
            fflush(stdin);
            gets(codigo);

            while(aux<5||aux>5)
            {
                printf("debe ingresar el codigo de 5 caracteres y alfanumerico:");
                fflush(stdin);
                gets(codigo);
                aux=strlen(codigo);
            }
            printf("ingrese el costo del servicio:");
            scanf("%f",&costo);
            estado=0;
            servicio=newServicoParametros(cliente->nombre,cliente->apellido,cliente->dni,codigo,costo,estado,idServicio);
            al_add(lista2,servicio);
        }
    }


}
void finalizar (ArrayList* lista2)
{
    xServico* servicio;
    int aux;
    int i;

    printf("ingrese el numero de id del sevicio:");
    scanf("%d",&aux);
    for(i=0;i<lista2->len(lista2);i++)
    {
        servicio=lista2->get(lista2,i);
        if(servicio->numeroServicio==aux&&servicio->estado!=1)
        {
            servicio->estado=1;
            break;
        }
        if(servicio->numeroServicio==aux&&servicio->estado==0)
        {
            printf("este servicio ya esta finalizado.");
            break;
        }
    }
}
void mostrarServicio(ArrayList* lista2)
{
    float resultado=0.00;
    xServico* servico;
    int i;
    printf("======================================================================\n");
    printf("|                           LISTA DE SERVICIOS                       |\n");
    printf("|====================================================================|\n");
    printf("| NOMBRE  |  APELLIDO  |    DNI    |    CODIGO     |  COSTO  |   N SERVICIO  |\n");
    printf("|====================================================================|\n");
    //printf("nombre==apellido==DNI==codigo==costo==numeroDeServicio\n");
    for(i=0;i<lista2->len(lista2);i++)
    {
        servico=lista2->get(lista2,i);
        if(servico->estado==1)
        {
            printf("|%-9s|%-10s   |%-8d  |%-15s|  %.2f   |    %d  |\n",servico->nombreCliente,servico->apellidoCliente,servico->dniCliente,servico->articulo,servico->costo,servico->numeroServicio);
            resultado=resultado+servico->costo;
        }
    }
    printf("el costo total es: %.2f\n",resultado);
}
