#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tareas.h"

int main()
{
    ArrayList* lista;
    ArrayList* listaALTA;
    ArrayList* listaBAJA;
    FILE* archivo;
    FILE* archivo2;
    FILE* archivo3;
    lista=al_newArrayList();
    listaALTA=al_newArrayList();
    listaBAJA=al_newArrayList();
    int opcion;
    int flag;
    int aux;
    char respuesta;

    do
    {
        printf("1- Leer archivo.\n");
        printf("2- Ordenar.\n");
        printf("3- Particionar por prioridad.\n");
        printf("4- Resolver tarea.\n");
        printf("5- Generar.\n");
        printf("6- Salir.\n");
        printf("Opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            LeerArchivo(archivo,lista);
            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                lista->sort(lista,comparaTarea,1);
                mostrarTarea(lista);
            }
            else
            {
                printf("primero debe leer el archivo.");
            }

            break;
        case 3:
            if(flag==1)
            {
                crearLista(lista,listaALTA,listaBAJA);
                mostrarTarea(listaALTA);
                mostrarTarea(listaBAJA);
                //listaALTA->clear(listaALTA);
                //listaBAJA->clear(listaBAJA);
            }
            else
            {
                printf("primero debe leer el archivo.");
            }
            break;
        case 4:
            if(flag==1)
            {
                resolverTarea(lista);
            }
            else
            {
                printf("primero debe leer el archivo.");
            }
            break;
        case 5:
            if(flag==1)
            {
                aux=guardarArchivo(archivo2,listaALTA,"pAlta.csv");
                aux=guardarArchivo(archivo3,listaBAJA,"pBaja.csv");
                if(aux==0)
                {
                    printf("se a generado correctamente.");
                }
            }
            else
            {
                printf("primero debe leer el archivo.");
            }
            break;
        case 6:
            respuesta='s';
            break;
        default:
            printf("ingrese una opcion entre 1 y 6.\n");
        }

    }
    while(respuesta!='s');
    return 0;
}
