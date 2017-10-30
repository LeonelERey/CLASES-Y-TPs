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
    FILE* pFile;
    ArrayList* lista;
    Employee** empleado;
    lista=al_newArrayList();
    int parce;
    char respuesta='s';
    while(respuesta=='s')
    {
        printf("1. Parse del archivo data.csv\n");
        printf("2. Listar Empleados\n");
        printf("3. Ordenar por nombre\n");
        printf("4. Agregar un elemento\n");
        printf("5. Elimina un elemento\n");
        printf("6. Listar Empleados (Desde/Hasta)\n\n");
        printf("7. salir\n");
        printf("opcion:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            parce=parserEmployee(pFile,lista);
            break;
        case 2:
            employee_print_all(empleado,lista);
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
            respuesta='n';
            break;
        }
    }




    return 0;
}
