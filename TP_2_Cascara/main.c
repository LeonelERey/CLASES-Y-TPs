#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define A 2

typedef struct
{
    char nombre[30];
    int edad;
    int DNI;
    int flagEstado;

} xPersona;
void inicializarPersona(xPersona[],int);
void mostarPersona(xPersona);
void mostrarPersonas(xPersona[],int);
void listaPersonas(xPersona[],int);
void preguntas(xPersona[],int);
int buscarLibre(xPersona[],int);

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    int posicion;
    int flagLugar;
    int auxDNI;
    char respuesta;
    xPersona personas[A];
    inicializarPersona(personas,A);


    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            posicion = buscarLibre(personas,A);
            if(posicion!=-1)
            {
                preguntas(personas,A);
            }
            else
            {
                printf("No hay espacio disponible!");
            }
            break;
        case 2:
            flagLugar=0;
            printf("ingresa el numero de documento de la persona que desea eliminar:");
            scanf("%d", &auxDNI);

            for(i=0; i<A; i++)
            {
                if(personas[i].flagEstado==1&&auxDNI==personas[i].DNI)
                {
                    mostarPersona(personas[i]);
                    printf("esta seguro que quiere eliminar a esta persona?\n");
                    respuesta=getche();

                    if(respuesta=='s')
                    {
                        personas[i].flagEstado=0;
                    }
                    else
                    {
                        printf("la eliminacion se a cancelado.\n");
                    }
                    flagLugar=1;

                    break;
                }
            }
            if(flagLugar==0)
            {
                printf("esa persona no a sido registrada previamente o ya fue eliminada\n.");
            }
            break;
        case 3:
            listaPersonas(personas,A);
            mostrarPersonas(personas,A);

            break;
        case 4:
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
void inicializarPersona(xPersona persona[], int tam)
{
    int i;

    for(i=0; i<A; i++)
    {
        {
            persona[i].flagEstado=0;
        }
    }
}
void mostarPersona(xPersona persona)
{
    printf("\n%s\t%d\t%d\n", persona.nombre, persona.edad, persona.DNI);
}
void mostrarPersonas(xPersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].flagEstado!=0)
        {
            mostarPersona(personas[i]);
        }
    }
}
void listaPersonas(xPersona personas[], int tam)
{
    int i;
    int j;
    xPersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(personas[i].nombre,personas[j].nombre)>0)
            {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }
        }
    }
}
void preguntas (xPersona preguntas[],int tam)
{
    int i;
    int flagLugar;

    flagLugar=0;
    for(i=0; i<tam; i++)
    {
        if(preguntas[i].flagEstado==0)
        {
            printf("ingrese el nombre de la persona que quiere ingresar: ");
            fflush(stdin);
            gets(preguntas[i].nombre);
            printf("ingrese la edad de la persona:");
            scanf("%d", &preguntas[i].edad);
            printf("ingrese el DNI de la persona:");
            scanf("%d", &preguntas[i].DNI);
            preguntas[i].flagEstado=1;
            mostrarPersonas()

            flagLugar=1;
            break;

        }
    }
}
int buscarLibre(xPersona espacio[],int tam)
{
    int lugar = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(espacio[i].flagEstado==0)
        {
            lugar = i;
            break;
        }
    }



    return lugar;
}

