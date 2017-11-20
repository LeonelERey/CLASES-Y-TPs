#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "personas.h"

xPersona* newPersona()
{
    xPersona* aux;
    aux=(xPersona*)malloc(sizeof(xPersona));

    return aux;
}
xPersona* newPersonaParametros( char nombre[],int id,char color[],char apellido[])
{
    xPersona* persona;

    persona=newPersona();
    if(persona!=NULL)
    {
        persona->id=id;
        strcpy(persona->nombre,nombre);
        strcpy(persona->apellido,apellido);
        strcpy(persona->color,color);
    }

    return (persona);
}
void agregarpersona(ArrayList* lista, xPersona* persona)
{
    int id;
    char nombre[30];
    char apellido[30];
    char color[15];

    id=al_len(lista)+1;
    printf("ingrese un nombre:");
    fflush(stdin);
    gets(nombre);
    printf("ingrese un apellido:");
    fflush(stdin);
    gets(apellido);
    printf("ingrese un color:");
    fflush(stdin);
    gets(color);

    persona=newPersonaParametros(nombre,id,color,apellido);
    if(persona!=NULL)
    {
        al_add(lista,persona);
    }
}
void mostrarPersona(ArrayList* lista, xPersona* persona)
{
    int i;

    printf("==========================================================================\n");
    printf("|                           LISTA DE PERSONAS                            |\n");
    printf("|========================================================================|\n");
    printf("|   ID      |      NOMBRE      |       APELLIDO       |       COLOR      |\n");
    printf("|========================================================================|\n");
    for(i=0; i<lista->len(lista); i++)
    {
        persona=lista->get(lista,i);
        if(persona!=NULL)
        {
            printf("|   %-5d   |   %-12s   |   %-15s    |    %-10s    |\n",persona->id,persona->nombre,persona->apellido,persona->color);
        }
        else
        {
            printf("se a producido un error.\n");
        }
    }
}
void EliminarPersona(ArrayList* lista, xPersona* persona)
{
    int i;
    int aux=-1;
    int posicion;
    char respuesta;

    printf("ingrese el id de la persona que desea eliminar:");
    scanf("%d",&posicion);
    /*while(posicion>lista->len(lista))
    {
        printf("ingrese un id existente:");
        scanf("%d",&posicion);
    }*/
    persona=(xPersona*)lista->get(lista,posicion-1);
    if(lista->contains(lista,persona)==1)
    {
        aux=posicion;
    }
    if(aux!=-1)
    {
        printf("%d\t%s\t%s\t%s\n",persona->id,persona->nombre,persona->apellido,persona->color);
        printf("desea eleminar esta persona? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=tolower(respuesta);
        if(respuesta=='s')
        {
            lista->remove(lista,aux);
            printf("persona eliminada.\n");
        }
        else
        {
            printf("la operacion fue cancelada.\n");
        }
    }
    else
    {
        printf("la persona no existe.\n");
    }

}
void ModifocarPersona(ArrayList* lista, xPersona* persona)
{
    int i;
    int aux=-1;
    int posicion;
    char respuesta;

    printf("ingrese el id de la persona que desea modificas 1/%d:",al_len(lista));
    scanf("%d",&posicion);
    /*while(posicion>lista->len(lista))
    {
        printf("ingrese un id existente:");
        scanf("%d",&posicion);
    }*/
    /*for(i=0; i<lista->len(lista); i++)
    {*/
    persona=(xPersona*)lista->get(lista,posicion-1);
    if(lista->contains(lista,persona)==1)
    {
        aux=posicion;
    }
    if(aux!=-1)
    {
        printf("%d\t%s\t%s\t%s\n",persona->id,persona->nombre,persona->apellido,persona->color);
        printf("desea modificar esta persona? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=tolower(respuesta);
        if(respuesta=='s')
        {
            persona->id=persona->id;
            printf("ingrese un nombre:");
            fflush(stdin);
            gets(persona->nombre);
            printf("ingrese un apellido:");
            fflush(stdin);
            gets(persona->apellido);
            printf("ingrese un color:");
            fflush(stdin);
            gets(persona->color);
            //persona=(xPersona*)lista->set(lista,aux,persona);
        }
        else
        {
            printf("la operacion fue cancelada.\n");
        }
    }
    else
    {
        printf("la persona no existe.\n");
    }

}
void PosicionEspecificada(ArrayList* lista,xPersona* persona)
{
    int id;
    char nombre[30];
    char apellido[30];
    char color[15];
    int posicion;
    int i;

    printf("ingrese un nombre:");
    fflush(stdin);
    gets(nombre);
    printf("ingrese un apellido:");
    fflush(stdin);
    gets(apellido);
    printf("ingrese un color:");
    fflush(stdin);
    gets(color);
    printf("ingrese la posicion donde quiere ingresar la persona:");
    scanf("%d", &posicion);
    id=posicion+1;
    for(i=posicion;i<lista->len(lista);i++)
        {

            persona=(xPersona*)lista->get(lista,i);
            persona->id=i+2;

        }
    persona=newPersonaParametros(nombre,id,color,apellido);
    if(lista->push(lista,posicion,persona)==0)
    {
        lista->sort(lista,comparaPersonas,1);
        printf("la persona fue insertado correctamente.");
    }
    else
    {
        printf("No se ha podido añadir esta nueva persona.");
    }
}
int comparaPersonas(void* persona1,void* persona2)
{
    if(((xPersona*)persona1)->id<((xPersona*)persona2)->id)
    {
        return -1;
    }
    if(((xPersona*)persona1)->id>((xPersona*)persona2)->id)
    {
        return 1;
    }
    return 0;
}
int LeerArchivo(FILE* archivo, ArrayList* lista)
{
    char id[500],nombre[500],apellido[500],color[500];
    xPersona* persona;
    int retorno;
    archivo=fopen("MOCK_DATA.csv","r");
    if(archivo!=NULL&&lista!=NULL)
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,color);

        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,color);

            persona=newPersonaParametros(nombre,id,color,apellido);
            if(persona!=NULL)
            {


                persona->id=atoi(id);
                strcpy(persona->nombre,nombre);
                strcpy(persona->apellido,apellido);
                strcpy(persona->color,color);
                al_add(lista,persona);
            }
        }
        printf("Archivo cargado correctamente.\n");
        retorno=1;
    }
    else
    {
        retorno=0;
    }
    fclose(archivo);
    return (retorno);
}
int guardarArchivo(FILE* archivo, ArrayList* lista)
{
    archivo=fopen("MOCK_DATA.csv","w");
    xPersona* persona;
    int i;
    int retorno=-1;
    fprintf(archivo,"ID,NOMBRE,APELLIDO,COLOR\n");
    for(i=0;i<lista->len(lista);i++)
    {
        persona=(xPersona*)lista->get(lista,i);

        fprintf(archivo,"%d,%s,%s,%s\n",persona->id,persona->nombre,persona->apellido,persona->color);
        if(retorno==-1)
        {
            retorno=0;
        }
    }
    fclose(archivo);
    return (retorno);
}
int crearCopiaSeguridad(FILE* archivo,ArrayList* lista)
{

    archivo=fopen("CopiaSeguridad.csv","w");
    xPersona* persona;
    int i;
    int retorno=-1;
    fprintf(archivo,"ID,NOMBRE,APELLIDO,COLOR\n");
    for(i=0;i<lista->len(lista);i++)
    {
        persona=(xPersona*)lista->get(lista,i);

        fprintf(archivo,"%d,%s,%s,%s\n",persona->id,persona->nombre,persona->apellido,persona->color);
        if(retorno==-1)
        {
            retorno=0;

        }
    }
    fclose(archivo);
    return (retorno);

}
