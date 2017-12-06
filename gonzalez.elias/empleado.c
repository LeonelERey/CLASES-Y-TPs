#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleado.h"

int LeerArchivo(FILE* archivo, ArrayList* lista)
{
    char id[500],nombre[500],apellido[500],dni[500];
    xEmpleado* empleado;
    int retorno;
    archivo=fopen("empleados.txt","r");
    if(archivo!=NULL&&lista!=NULL)
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni);

        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni);
            empleado=newEmpleadoParametros(id,nombre,apellido,dni);
            if(empleado!=NULL)
            {
                empleado->id=atoi(id);
                strcpy(empleado->nombre,nombre);
                strcpy(empleado->apellido,apellido);
                empleado->dni=atoi(dni);

                al_add(lista,empleado);
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
xEmpleado* newEmpleado()
{
    xEmpleado* aux;
    aux=(xEmpleado*)malloc(sizeof(xEmpleado));

    return aux;
}
xEmpleado* newEmpleadoParametros(int id,char nombre[],char apellido[],long long int dni)
{
    xEmpleado* persona;

    persona=newEmpleado();
    if(persona!=NULL)
    {
        persona->id=id;
        strcpy(persona->nombre,nombre);
        strcpy(persona->apellido,apellido);
        persona->dni=dni;
    }

    return (persona);
}
void altaEmpleado(ArrayList* lista)
{
    xEmpleado* empleado;
    int i;
    int idAux=100;
    char nombre[20];
    char apellido[20];
    int dni;
    int aux=lista->len(lista);
    for(i=0;i<aux;i++)
    {
        empleado=lista->get(lista,i);
        if(empleado->id!=idAux)
        {
            idAux=idAux;
        }
        else
        {
            if(empleado->id==idAux)
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
    scanf("%d",&dni);
    while(dni<10000000||dni>60000000)
    {
        printf("ingrese un numero de dni coherente:");
        scanf("%d",&dni);
    }
    empleado=newEmpleadoParametros(idAux,nombre,apellido,dni);
    al_add(lista,empleado);

}
void modificacion(ArrayList* lista)
{
    int i;
    xEmpleado* empleado;
    int dni;
    char nombre[20];
    char apellido[20];
    int id;
    int aux=lista->len(lista);

    printf("ingrese el numero de dni:");
    scanf("%d",&dni);
    while(dni<10000000||dni>60000000)
    {
        printf("ingrese un numero de dni coherente:");
        scanf("%d",&dni);
    }
    for(i=0;i<aux;i++)
    {
        empleado=(xEmpleado*)lista->get(lista,i);
        if(empleado->dni==dni)
        {
            printf("ingrese un nuevo nombre:");
            fflush(stdin);
            gets(nombre);
            printf("ingrese un nuevo apellido:");
            fflush(stdin);
            gets(apellido);
            id=empleado->id;

            empleado=newEmpleadoParametros(id,nombre,apellido,dni);

            lista->set(lista,i,empleado);
            break;


        }
    }

}
int guardarArchivo(FILE* archivo, ArrayList* lista)
{
    archivo=fopen("empleados.txt","w");
    xEmpleado* persona;
    int i;
    int retorno=-1;
    fprintf(archivo,"%s,%s,%s,%s\n","id","nombre","apellido","dni");
    for(i=0;i<lista->len(lista);i++)
    {
        persona=(xEmpleado*)lista->get(lista,i);
        fprintf(archivo,"%d,%s,%s,%lld\n",persona->id,persona->nombre,persona->apellido,persona->dni);
        if(retorno==-1)
        {
            retorno=0;
        }
    }
    fclose(archivo);
    return (retorno);
}
int comparaEmpleado(void* empleado1,void* empleado2)
{
    if(((xEmpleado*)empleado1)->dni<((xEmpleado*)empleado2)->dni)
    {
        return -1;
    }
    if(((xEmpleado*)empleado1)->dni>((xEmpleado*)empleado2)->dni)
    {
        return 1;
    }
    return 0;
}
void mostrarEmpleados(ArrayList* lista)
{
    int i;
    xEmpleado* empleado;

    printf("======================================================================\n");
    printf("|                          LISTA DE EMPLEADOS                        |\n");
    printf("|====================================================================|\n");
    printf("|    ID     |      NOMBRE      |     APELLIDO      |       DNI       |\n");
    printf("|====================================================================|\n");
    for(i=0; i<lista->len(lista); i++)
    {
        empleado=lista->get(lista,i);
        if(empleado!=NULL)
        {
            printf("|   %-5d   |   %-12s   |   %-12s    |   %-10d    |\n",empleado->id,empleado->nombre,empleado->apellido,empleado->dni);
        }
        else
        {
            printf("se a producido un error.\n");
        }
    }
}
void eliminarEmpleado(ArrayList* lista)
{
    int i;
    xEmpleado* empleado;
    int dni;
    char nombre[20];
    char apellido[20];
    int id;
    int aux=lista->len(lista);

    printf("ingrese el numero de dni:");
    scanf("%d",&dni);
    while(dni<10000000||dni>60000000)
    {
        printf("ingrese un numero de dni coherente:");
        scanf("%d",&dni);
    }
    for(i=0;i<aux;i++)
    {
        empleado=(xEmpleado*)lista->get(lista,i);
        if(empleado->dni==dni)
        {
            printf("ingrese un nuevo nombre:");
            fflush(stdin);
            gets(nombre);
            printf("ingrese un nuevo apellido:");
            fflush(stdin);
            gets(apellido);
            id=empleado->id;

            empleado=newEmpleadoParametros(id,nombre,apellido,dni);

            lista->set(lista,i,empleado);
            break;


        }
    }

}

