#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int legajo;
    char nombre[50];
    int nota;
}eRecursante;

 void mostarPersona (eRecursante*);
 eRecursante* newRecursante (int, char[], int);

int main()
{
   eRecursante* pRecursante;
   pRecursante=newRecursante(1000,"GER",2);
   mostarPersona(pRecursante);

    return 0;
}






eRecursante* newRecursante (int legajo, char nombre[], int nota)
{
     eRecursante* recursante;

    recursante=(eRecursante*)malloc(sizeof(eRecursante));
    if(recursante!=NULL)
    {
        recursante->legajo=legajo;
        strcpy(recursante->nombre,nombre);
        recursante->nota=nota;
    }
    else
    {
        printf("no se encontro espacion en memoria.");
        recursante->legajo=-1;
        strcpy(recursante->nombre,"");
        recursante->nota=-1;
    }

    return recursante;
}

void mostarPersona (eRecursante* recursante)
{
    printf("%d--%s--%d",recursante->legajo,recursante->nombre,recursante->nota);
}
