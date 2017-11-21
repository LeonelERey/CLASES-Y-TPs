#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tareas.h"
xTarea* newPersona()
{
    xTarea* aux;
    aux=(xTarea*)malloc(sizeof(xTarea));

    return aux;
}
xTarea* newPersonaParametros( char descripcion[],char prioridad[],int horas)
{
    xTarea* persona;

    persona=newPersona();
    if(persona!=NULL)
    {
        strcpy(persona->descripcion,descripcion);
         if(atoi(prioridad)==0||atoi(prioridad)==1)
                {
                    if(prioridad==1)
                    {
                        strcpy(persona->prioridad,"ALTA");
                    }
                    else
                    {
                        strcpy(persona->prioridad,"BAJA");
                    }
                }
        persona->tiempo=horas;
    }

    return (persona);
}
void mostrarTarea(ArrayList* lista)
{
    int i;
    xTarea* tarea;

    printf("=========================================\n");
    printf("|           LISTA DE TAREAS             |\n");
    printf("|=======================================|\n");
    printf("|  DESCRIPCION   | PRIORIDAD |  TIEMPO  |\n");
    printf("|=======================================|\n");
    for(i=0; i<lista->len(lista); i++)
    {
        tarea=lista->get(lista,i);
        if(tarea!=NULL)
        {
            printf("|   %-10s   |   %-5s   |   %-3d    |\n",tarea->descripcion,tarea->prioridad,tarea->tiempo);
        }
        else
        {
            printf("se a producido un error.\n");
        }
    }
}
int LeerArchivo(FILE* archivo, ArrayList* lista)
{
    char descripcion[500],prioridad[500],tiempo[500];
    xTarea* tarea;
    int retorno;
    archivo=fopen("tar.csv","r");
    if(archivo!=NULL&&lista!=NULL)
    {
        //fscanf(archivo, "%[^,],%[^,],%[^\n]\n",descripcion,prioridad,tiempo);

        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,],%[^,],%[^\n]\n",descripcion,prioridad,tiempo);
            tarea=newPersonaParametros(descripcion,prioridad,tiempo);
            if(tarea!=NULL)
            {


               tarea->tiempo=atoi(tiempo);

                    if(atoi(prioridad)==1)
                    {
                        strcpy(tarea->prioridad,"ALTA");
                    }
                    else
                    {
                        strcpy(tarea->prioridad,"BAJA");
                    }

                strcpy(tarea->descripcion,descripcion);

                al_add(lista,tarea);
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
int comparaTarea(void* persona1,void* persona2)
{
    if(((xTarea*)persona1)->tiempo<((xTarea*)persona2)->tiempo)
    {
        return -1;
    }
    if(((xTarea*)persona1)->tiempo>((xTarea*)persona2)->tiempo)
    {
        return 1;
    }
    return 0;
}
int crearLista (ArrayList* lista,ArrayList* lista2,ArrayList* lista3)
{
    xTarea* tarea;
    int i;
    lista2->clear(lista2);
    lista3->clear(lista3);

    for(i=0;i<lista->len(lista);i++)
    {
        tarea=lista->get(lista,i);
        if(strcmp(tarea->prioridad,"ALTA")==0)
        {
            al_add(lista2,tarea);
        }
        if(strcmp(tarea->prioridad,"BAJA")==0)
        {
            al_add(lista3,tarea);
        }
    }
}
int resolverTarea (ArrayList* lista)
{
    int i,j;
    int indice;
    char respuesta;
    xTarea* tarea;
    xTarea* tarea2;
    xTarea* tarea3;

    if(lista!=NULL)
    {
        //crearLista(lista,lista2,lista3);
        if(lista->len(lista)!=0)
        {
            for(i=0;i<lista->len(lista);i++)
            {
                tarea=lista->get(lista,i);
                for(j=0;j<lista->len(lista);j++)
                {
                    tarea2=lista->get(lista,j);
                    if(strcmp(tarea->prioridad,"ALTA")==0)
                        {
                            if(tarea2->tiempo>tarea->tiempo/*&&strcmp(tarea2->prioridad,"ALTA")==0*/)
                            {
                                if(strcmp(tarea2->prioridad,"ALTA")==0)
                                {
                                    tarea3=tarea;
                                    indice=i;
                                }
                            }
                        }

                }
            }
        }
        /*else
        {
            for(i=0;i<lista3->len(lista3);i++)
            {
                tarea=lista3->get(lista3,i);
                for(j=0;j<lista3->len(lista3);j++)
                {
                    tarea2=lista3->get(lista3,j);
                    if(tarea2->tiempo<tarea->tiempo)
                    {
                        tarea3=tarea2;
                        indice=j;
                    }
                }
            }
        }*/
        printf("=========================================\n");
        printf("|        PERSONA QUE SE ELIMINO         |\n");
        printf("|=======================================|\n");
        printf("|   %-10s   |   %-5s   |   %-3d    |\n",tarea3->descripcion,tarea3->prioridad,tarea3->tiempo);
        lista->remove(lista,j);
        printf("persona eliminada.\n");

    }
}
int guardarArchivo(FILE* archivo, ArrayList* lista,char nombre[])
{
    archivo=fopen(nombre,"w");
    xTarea* persona;
    int aux;
    int i;
    int retorno=-1;
    for(i=0;i<lista->len(lista);i++)
    {
        persona=(xTarea*)lista->get(lista,i);

        if(strcmp(persona->prioridad,"ALRA")==0)
           {
               aux=1;
           }
           if(strcmp(persona->prioridad,"BAJA")==0)
           {
               aux=0;
           }
        fprintf(archivo,"%s,%d,%d\n",persona->descripcion,aux,persona->tiempo);
        if(retorno==-1)
        {
            retorno=0;
        }
    }
    fclose(archivo);
    return (retorno);
}
