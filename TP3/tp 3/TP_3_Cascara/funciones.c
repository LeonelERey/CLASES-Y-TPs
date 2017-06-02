#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(EMovie *movie, int cantidad)
{
    int espacio,flag;
   // EMovie* mov;
   // EMovie* AuxMov;

    printf("** AGREGAR PELICULA  **");

    espacio = buscarEspacio(movie,cantidad);


    if(espacio == -1)
    {

         // mov=(EMovie*)malloc(sizeof(EMovie*)*A);
         // mov=(EMovie*)malloc(sizeof(EMovie*)*A);


        printf("\n\nNO HAY ESPACIO!!!\n\n");
        flag = 1;

    }
    else
    {
        (movie + espacio)->idMovie = espacio+1;

        fflush(stdin);
        printf("\nTitulo: ");
        gets((movie+espacio)->titulo);

        fflush(stdin);
        printf("\nGenero: ");
        gets((movie+espacio)->genero);

        printf("\nDuracion [Minutos]: ");
        scanf("%d",&(movie + espacio)->duracion);

        fflush(stdin);
        printf("\nDescripcion [100 caracteres]: ");
        gets((movie+espacio)->descripcion);

        printf("\nPuntaje [1 al 10]: ");
        scanf("%d",&(movie + espacio)->puntaje);

        fflush(stdin);
        printf("\nLink De Imagen: ");
        gets((movie+espacio)->linkImagen);
    }

    system("pause");
    system("cls");
    return flag;
}
/**||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
int borrarPelicula(EMovie *movie, int cantidad)
{
    int existeID,idAux,flag,i;

    for(i=0;i<cantidad;i++)
    {
        while((movie + i)->idMovie == -1)
        {
            flag = 1;
            return flag;
            break;
        }
    }

    printf("** BORRAR PELICULA  **");
    mostrarPelicula(movie,cantidad);
    printf("\nIngrese ID de la pelicula que desea BORRAR: ");
    scanf("%d",&idAux);
    existeID = buscarPorId(movie,cantidad,idAux);
    while(existeID == -1)
    {
        printf("\nNo existe la pelicula, ingrese un ID valido, por favor: ");
        scanf("%d",&idAux);
        existeID = buscarPorId(movie,cantidad,idAux);
    }

        strcpy((movie+existeID)->titulo,"");
        strcpy((movie+existeID)->genero,"");
        (movie+existeID)->duracion = -1;
        strcpy((movie+existeID)->descripcion,"");
        (movie+existeID)->puntaje = -1;
        (movie+existeID)->idMovie = -1;
        strcpy((movie+existeID)->linkImagen,"");
        flag = 0;

    return flag;
}
/**||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
int modificarPelicula(EMovie *movie, int cantidad)
{
    int i,flag,existeID,idAux;

    for(i=0;i<cantidad;i++)
    {
        while((movie + i)->idMovie == -1)
        {
            flag = 1;
            return flag;
            break;
        }
    }

    printf("** MODIFICAR PELICULA  **");
    mostrarPelicula(movie,cantidad);
    printf("\nIngrese ID de la pelicula que desea MODIFICAR: ");
    scanf("%d",&idAux);
    existeID = buscarPorId(movie,cantidad,idAux);

    while(existeID == -1)
    {
        printf("\nNo existe la pelicula, ingrese un ID valido, por favor: ");
        scanf("%d",&idAux);
        existeID = buscarPorId(movie,cantidad,idAux);
    }
        fflush(stdin);
        printf("\nTitulo: ");
        gets((movie+existeID)->titulo);

        fflush(stdin);
        printf("\nGenero: ");
        gets((movie+existeID)->genero);

        printf("\nDuracion [Minutos]: ");
        scanf("%d",&(movie + existeID)->duracion);

        fflush(stdin);
        printf("\nDescripcion [100 caracteres]: ");
        gets((movie+existeID)->descripcion);

        printf("\nPuntaje [1 al 10]:");
        scanf("%d",&(movie + existeID)->puntaje);

        fflush(stdin);
        printf("\nLink De Imagen: ");
        gets((movie+existeID)->linkImagen);

    system("pause");
    system("cls");
    flag = 0;
    return flag;
}
/**||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
void mostrarPelicula(EMovie *movie, int cantidad)
{
    int i;
    FILE* HTML;


    char bufer[1000]={};
    HTML=fopen("C:/Users/JOAKO/Desktop/Facultad/TP_3_Cascara/peliculas.html","w");
    for(i=0;i<cantidad;i++)
    {
        while((movie+i)->idMovie != -1)
        {



            printf("\nID: %d\n",(movie + i)->idMovie);
            printf("Titulo: %s\n",(movie + i)->titulo);
            printf("Genero: %s\n",(movie + i)->genero);
            printf("Duracion: %d Minutos\n",(movie + i)->duracion);
            printf("Descripcion: %s\n",(movie + i)->descripcion);
            printf("Puntaje: %d\n",(movie + i)->puntaje);
            printf("Link De Imagen: %s\n",(movie + i)->linkImagen);
            printf("\n");
            break;
           /* fprintf(HTML,bufer);
            fclose(HTML);*/
        }
    }
}
/**||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
int buscarPorId(EMovie *movie, int cantidad,int idAux)
{
    int i,flag=-1;

    for(i=0;i<cantidad;i++)
    {
        if((movie+i)->idMovie == idAux)
        {
            flag = i;
        }
    }

    return flag;
}
/**||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
void inicializarArray(EMovie *movie,int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        strcpy((movie+i)->titulo,"");
        strcpy((movie+i)->genero,"");
        (movie+i)->duracion = -1;
        strcpy((movie+i)->descripcion,"");
        (movie+i)->puntaje = -1;
        (movie+i)->idMovie = -1;
        strcpy((movie+i)->linkImagen,"");
    }
}
/**|||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
int buscarEspacio(EMovie *movie, int cantidad)
{
    int i,flag=-1;

    for(i=0;i<cantidad;i++)
    {
        if((movie+i)->idMovie == -1)
        {
            flag = i;
            break;
        }
    }


    return flag;
}
/**|||||||||||||||||||||||||||||||||||||||||||||||||||||||**/
