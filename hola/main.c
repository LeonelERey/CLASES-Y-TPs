#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>


int main()
{
    int num1;
    int num2;
    int respuesta;
    float respuestaComa;
    int opcion;
    char pregunta;

    do
    {
        printf("ingrese un numero:");
        scanf("%d", &num1);
        printf("ingrese un segundo numero:");
        scanf("%d", &num2);

        printf("1- sumar\n");
        printf("2- restar\n");
        printf("3- dividir\n");
        printf("4- multiplicar\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            respuesta=sumar(num1,num2);
            printf("la sumatoria de los numeros es: %d\n",respuesta);

            break;
        case 2:
            respuesta=restar(num1,num2);
            printf("la resta de los numeros es: %d\n",respuesta);

            break;
        case 3:
            respuestaComa=dividir(num1,num2);
            printf("la divicion de los numeros es: %.2f\n",respuestaComa);

            break;
        case 4:
            respuesta=multiplicar(num1,num2);
            printf("la multiplicacion de los numeros es: %d\n",respuesta);

            break;
        }
        printf("desea seguir haciendo cuentas? s/n");
        pregunta=getche();
        while(pregunta!='s'||pregunta!='s')
        {
            printf("\ndesea seguir haciendo cuentas?responda con --> s/n!!!!!!!!!!!");
            pregunta=getche();
        }
        printf("\n=================================================================\n");
    }while(pregunta!='n');


    return 0;
}

