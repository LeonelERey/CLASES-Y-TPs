#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int opciones (int flag,int flag1,int num1,int num2)
{
    int opcion;
    if(flag!=1&&flag!=1)
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);
        flag=1;
    }
    else
    {
        if(flag==1&&flag1==1)
        {
            printf("1- Ingresar 1er operando (A=%d)\n",num1);
            printf("2- Ingresar 2do operando (B=%d)\n",num2);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            scanf("%d",&opcion);
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%d)\n",num1);
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            scanf("%d",&opcion);
            flag1=1;
        }
    }
    return opcion;

}
int validarnum1 (int flag)
{
    int num1;
    if(flag==0)
    {
        num1=preguntar("no se puede realicar la opercion si no a ingresado un numero antes:");
    }

}
int preguntar (char titulo[])
{
    int dato;

    printf("%s", titulo);
    scanf("%d", &dato);

    return dato;
}
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
float factorial(int num1)
{

    float resultado;
    (float)num1;
    if(num1==0)
    {
        return 1;
    }
    else
    {
        resultado=num1*factorial(num1-1);
        return (resultado);
    }
}



