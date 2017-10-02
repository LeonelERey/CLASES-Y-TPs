#include <stdio.h>
#include <stdlib.h>
void modificar(int*);
int main()
{
    int* puntero;
    int variable;
    variable=15;
    puntero=&variable;

    printf("valor:%d\n", *puntero);
    printf("direccion:%p\n", puntero);
    *puntero=20;
    printf("valor modificado:%d\n", *puntero);
    printf("direccion:%p\n", puntero);
    printf("direccion del puntero:%p\n",&puntero);
    *puntero=50;
    printf("valor modificado otra vez:%d\n", *puntero);
    modificar(puntero);
    printf("valor modificado por funciion:%d\n", *puntero);
    printf("valor modificado por funciion:%d\n", variable);
    return 0;
}
void modificar(int* valor)
{
    *valor=98;
}
