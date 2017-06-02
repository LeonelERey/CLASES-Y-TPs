#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define ARCH	"C:/Users/JOAKO/Desktop/Facultad/TP_3_Cascara/peliculas.html"


#define TAM 5




int main()
{
    char seguir='s';
    int opcion=0;
    int agreePelicula,deletePelicula,modifPelicula,X;

    FILE* HTML;
    FILE* Binario;

   Binario=fopen("bin.dat","ab+");



    EMovie peliculas[TAM];
    EMovie *movie = &peliculas[0];

    inicializarArray(movie,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("\nOPCION: ");
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                agreePelicula =  agregarPelicula(movie,TAM);
                if(agreePelicula == 1)
                {
                    printf("NO SE AGREGO LA PELICULA\n");
                }
                else
                {
                    printf("PELICULA AGREGADA CON EXITO\n");
                }
                system("pause");
                system("cls");
                break;

            case 2:
            deletePelicula = borrarPelicula(movie,TAM);
            if(deletePelicula == 1)
                {
                    printf("NO HAY PELICULAS CARGADAS\n");
                }
                else
                {
                    printf("PELICULA BORRADA CON EXITO\n");
                }
            system("pause");
            system("cls");
                break;

            case 3:
            modifPelicula = modificarPelicula(movie,TAM);
             if(modifPelicula == 1)
                {
                    printf("NO HAY PELICULAS CARGADAS\n");
                }
                else
                {
                    printf("\nPELICULA MODIFICADA CON EXITO\n");
                }

                system("pause");
                system("cls");
                    break;

            case 4:
                //FILE* HTML;

                 mostrarPelicula(movie,TAM);

                system("pause");
                system("cls");

                fclose(HTML);
                break;

            case 5:
                seguir = 'n';
                system("pause");
                system("cls");
                break;

            default:
            printf("Numero invalido...  \n\n");
            system("pause");
            system("cls");

        }
    }

     fclose(Binario);
    return 0;
}
