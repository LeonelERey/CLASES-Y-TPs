#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleado.h"

int main()
{
    ArrayList* lista;
    ArrayList* lista2;
    FILE* archivo;
    FILE* archivo2;
    int opcion;
    char respuesta;
    lista=al_newArrayList();
    if(lista!=NULL)
    {
        LeerArchivo(archivo,lista);
        do
        {
            printf("1- Alta de empleado.\n");
            printf("2- Modificacion de empleado.\n");
            printf("3- Baja de empleado.\n");
            printf("4- Listar empleados.\n");
            printf("5- Registar lista.\n");
            printf("6- Anular registro.\n");
            printf("7- Informar registros de dias.\n");
            printf("8- Informar registro de dias por tipo de parea.\n");
            printf("9- Generar informe de registro de dias.\n");
            printf("10- Informara cantidad de dias trabajados por empleado en cada tarea.\n");
            printf("11- salir.\n");
            printf("Opcion:");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                altaEmpleado(lista);
                guardarArchivo(archivo,lista);
                break;
            case 2:
                modificacion(lista);
                guardarArchivo(archivo,lista);
                break;
            case 3:
                break;
            case 4:
                lista->sort(lista,comparaEmpleado,1);
                mostrarEmpleados(lista);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
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
}
