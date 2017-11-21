#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayList.h"
#include "personas.h"

int main()
{
    ArrayList* lista;
    ArrayList* lista2;
    xPersona* persona;
    xPersona* persona2;
    FILE* archivo;
    FILE* archivoCopia;
    lista=al_newArrayList();
    int opcion;
    int aux;
    char respuesta;
    char resp;

    do
    {
        printf("1- Leer archivo.\n");
        printf("2- Agregar persona.\n");
        printf("3- Eliminr persona.\n");
        printf("4- Modificar persona.\n");
        printf("5- Agregar persona en posicion especificada.\n");
        printf("6- Ordenar personas.\n");
        printf("7- Mostrar personas.\n");
        printf("8- Mostar desde hasta.\n");
        printf("9- Crear copia de seguridad.\n");
        printf("10- Salir.\n");
        printf("Opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            LeerArchivo(archivo,lista);
            break;
        case 2:
            agregarpersona(lista,persona);
            break;
        case 3:
            EliminarPersona(lista,persona);
            break;
        case 4:
            ModifocarPersona(lista,persona);
            break;
        case 5:
            PosicionEspecificada(lista,persona);
            break;
        case 6:
            lista->sort(lista,comparaPersonas,1);
            break;
        case 7:
            mostrarPersona(lista,persona);
            break;
        case 8:
            lista2=lista->subList(lista,89,99);
            mostrarPersona(lista2,persona);
            //lista->clear(lista);
            break;
        case 9:
            printf("desea hacer una copia de seguridad? s/n:");
            fflush(stdin);
            resp=getch();
            resp=tolower(resp);
            if(resp=='s')
            {
                ArrayList* copia;
                copia=lista->clone(lista);
                crearCopiaSeguridad(archivoCopia,copia);
                printf("\nSe creo correctamente.\n");
            }

            break;
        case 10:
            printf("desea guardar los cambios? s/n:");
            fflush(stdin);
            resp=getch();
            resp=tolower(resp);
            if(resp=='s')
            {
                guardarArchivo(archivo,lista);
                printf("\nSe guardo correctamente.");
                lista->deleteArrayList(lista);
            }
            respuesta='s';
            break;
        default:
            printf("ingrese una opcion entre 1 y 10.\n");
        }

    }while(respuesta!='s');
    return 0;
}
