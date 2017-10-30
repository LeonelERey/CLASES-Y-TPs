#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("%d--%s--%s--%d\n",this->id,this->name,this->lastName,this->isEmpty);
}
void employee_print_all(Employee* this, ArrayList* arrayL)
{
    int i;
    for(i=0;i<al_len(arrayL);i++)
    {
        employee_print(this);
        if(i==500)
        {
            system("pause");
        }
    }
}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;
    returnAux=(Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


