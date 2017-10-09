#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre[20];
    float altura;
    int estado;
} ePersona;

int newPersona(ePersona*, int, char[], float,int);
void cargar(ePersona*,int);
void personaToString(ePersona*,int);

int main()
{
    ePersona listaPersonas[5];
    char seguir='s';
    int opcion;
    while(seguir=='s')
    {
        printf("1- alta.\n");
        printf("2- listar.\n");
        printf("3- ordenar.\n\n");
        printf("4- salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            cargar(listaPersonas,5);
            break;
        case 2:
            personaToString(listaPersonas,5);
            break;
        case 3:
            break;
        case 4:
            seguir='n';
            break;
        default:
            printf("ingrese una opcione entre 1 y 4");
            scanf("%d",&opcion);
        }
    }
    return 0;
}

int  newPersona(ePersona* miPersona, int dni, char nombre[], float altura,int estado)
{
    int retorno=0;
    if(miPersona!=NULL)
    {
        miPersona->dni = dni;
        strcpy(miPersona->nombre, nombre);
        miPersona->altura = altura;
        miPersona->estado=1;
        retorno = 1;
    }
    return retorno;

}
void cargar(ePersona* listaPersona,int tam)
{
    int i;
    int dni;
    float altura;
    char nombre[20];
    if(listaPersona!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            if((listaPersona+i)->estado!=1)
            {
                printf("ingrese dni:");
                scanf("%d",&dni);
                printf("ingrese el nombre:");
                fflush(stdin);
                gets(nombre);
                printf("ingrese la altura:");
                scanf("%f",&altura);

                if(newPersona(listaPersona+i, dni, nombre, altura,1))
                {
                    printf("Persona generada con exito!!!\n");
                    break;
                }
                else
                {
                    printf("Carga fallida");
                    break;
                }


            }
            else
            {
                printf("ya no hay mas lugar para cargar personas.\n");
                break;
            }

        }

    }


}
void personaToString(ePersona* miPersona, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if((miPersona+i)->estado==1)
        {
            printf("%d--%s--%.2f\n",  (miPersona+i)->dni,  (miPersona+i)->nombre,  (miPersona+i)->altura);
        }

    }

}
void ordenar(ePersona* letras, int t)
{
    char auxChar;
    int i,j;
    for(i=0; i<t-1; i++)
    {
        for(j=i+1; j<t; j++)
        {
            if(*(letras+i)>*(letras+j))
            {
                swap(letras+i, letras+j);
            }
        }
    }
}
