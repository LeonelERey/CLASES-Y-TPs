#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* lista;
    ArrayList* lista2;
    FILE* archivo;
    int opcion;
    char respuesta;
    lista=al_newArrayList();
    lista2=al_newArrayList();
    if(lista!=NULL&&lista2!=NULL)
    {
        do
        {
            printf("1- Alta de cliente.\n");
            printf("2- Modificacion de cliente.\n");
            printf("3- Baja de cliente.\n");
            printf("4- Listar clientes.\n");
            printf("5- Importar Servicios Tecnicos.\n");
            printf("6- Nuevo servicio.\n");
            printf("7- Finalizar. \n");
            printf("8- \n");
            printf("9- Imprimir servicio tecnico por producto\n");
            printf("10- \n");
            printf("11- salir.\n");
            printf("Opcion:");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                altaCliente(lista);
                system("pause");
                system("cls");
                break;
            case 2:
                modificacion(lista);
                system("pause");
                system("cls");
                break;
            case 3:
                eliminacion(lista);
                system("pause");
                system("cls");
                break;
            case 4:
                mostrarClientes(lista);
                system("pause");
                system("cls");
                break;
            case 5:
                LeerArchivos(archivo,lista,lista2);
                break;
            case 6:
                nuevoServicio(lista,lista2);
                system("pause");
                system("cls");
                break;
            case 7:
                finalizar(lista2);
                break;
            case 8:
                break;
            case 9:
                mostrarServicio(lista2);
                break;
            case 10:
                break;
            case 11:
                respuesta='s';
                break;
            default:
                printf("ingrese una opcion entre 1 y 11.\n");
            }

        }
        while(respuesta!='s');
    }
    return 0;
}
