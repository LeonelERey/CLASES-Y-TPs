#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int sumar (int num1,int num2)
{
    int resultado;

    resultado=num1+num2;

    return resultado;
}
int restar (int num1,int num2)
{
    int resultado;

    resultado=num1-num2;

    return resultado;
}
float dividir (int num1,int num2)
{
    float respuesta;

    respuesta=(float)num1/(float)num2;

    return respuesta;
}
int multiplicar(int num1,int num2)
{
    int resultado;

    resultado=num1*num2;

    return resultado;
}

