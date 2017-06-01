#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int opcion;
    int i;
    char respu='s';
    FILE* archivo;
    ArrayList* lista;

    while(respu=='s')
    {
        printf("1. Parse del archivo data.csv\n");
        printf("2. Listar Empleados\n");
        printf("3. Ordenar por nombre\n");
        printf("4. Agregar un elemento\n");
        printf("5. Elimina un elemento\n");
        printf("6. Listar Empleados (Desde/Hasta)\n");
        printf("7. Salir\n\n");
        printf("elija una opcion:");
        scanf("%d",&opcion);

        while(opcion<1||opcion>7)
        {
            printf("ingrese una opcion valida:");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                lista= al_newArrayList();
                archivo=fopen("data.csv","r");
                for(i=0;i<1000;i++)
                {
                    lista->add(archivo,i);
                }
                for(i=0;i<10;i++)
                {
                    printf("%d %s %s %d",lista->len(lista));
                }



                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
    }
    }




    return 0;
}
