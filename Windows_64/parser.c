#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    char id[500], nombre[500], apellido[500],estado[500];
    Employee* empleado;

    pFile=fopen("data.csv","r");
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, estado);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, estado);
        empleado=employee_new();
        if(empleado!=NULL)
        {
            empleado->id=atoi(id);
            strcpy(empleado->name,nombre);
            strcpy(empleado->lastName,apellido);
            if(strcmp(estado,"true")==0)
            {
                empleado->isEmpty=1;
            }
            else
            {
                empleado->isEmpty=0;
            }
        }
        al_add(pArrayListEmployee,empleado);

    }
    fclose(pFile);

    return 0;
}
