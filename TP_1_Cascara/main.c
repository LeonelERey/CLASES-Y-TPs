#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    system("color c");
    char seguir='s';
    int opcion=0;
    int num1;
    int num2;
    int respuesta;
    float respuestaComa;
    int flag=0;
    int flag2=0;

    while(seguir=='s')
    {
        opcion=opciones(flag,flag2,num1,num2);

        switch(opcion)
        {
        case 1:
            num1=preguntar("ingrese el primer numero:");
            flag=1;

            break;
        case 2:
            num2=preguntar("ingrese el segundo numero:");
            flag2=1;

            break;
        case 3:
            if(flag==1&&flag2==1)
            {
                respuesta=sumar(num1,num2);
                printf("la sumatoria de los numeros es: %d\n",respuesta);
                break;

            }
            else
            {
                printf("no a ingresado los numeros!!\n");
                break;
            }
        case 4:
            if(flag==1&&flag2==1)
            {
                respuesta=restar(num1,num2);
                printf("la resta de los numeros es: %d\n",respuesta);
                break;
            }
            else
            {
                printf("no a ingresado los numeros!!\n");
                break;
            }

        case 5:
            if(flag==1&&flag2==1)
            {
                if(num2!=0)
                {
                    respuestaComa=dividir(num1,num2);
                    printf("la divicion de los numeros es: %.2f\n",respuestaComa);
                }
                else
                {
                    num2=preguntar("no se puede realizar la operacion con 0!!\ningrese otro numero:");
                }
                break;
            }
            else
            {
                printf("no a ingresado los numeros!!\n");
                break;
            }
        case 6:
            if(flag==1&&flag2==1)
            {
                respuesta=multiplicar(num1,num2);
                printf("la multiplicacion de los numeros es: %d\n",respuesta);
                break;
            }
            else
            {
                printf("no a ingresado los numeros!!\n");
                break;
            }
        case 7:
            if(flag==1)
            {
                respuesta=factorial(num1);
                printf("el factorial del numero es: %d\n",respuesta);
                break;
            }
            else
            {
                printf("no a ingresado el primer numeros!!\n");
                break;
            }
            break;
        case 8:
            if(flag==1&&flag2==1)
            {
                respuesta=sumar(num1,num2);
                printf("la sumatoria de los numeros es: %d\n",respuesta);
                respuesta=restar(num1,num2);
                printf("la resta de los numeros es: %d\n",respuesta);
                respuestaComa=dividir(num1,num2);
                printf("la divicion de los numeros es: %.2f\n",respuestaComa);
                respuesta=multiplicar(num1,num2);
                printf("la multiplicacion de los numeros es: %d\n",respuesta);
                respuesta=factorial(num1);
                printf("el factorial del numero es: %d\n",respuesta);
                break;
            }
            else
            {
                printf("no a ingresado los numeros!!\n");
                break;
            }
        case 9:
            seguir = 'n';
            break;
        }
    }


    return 0;
}
