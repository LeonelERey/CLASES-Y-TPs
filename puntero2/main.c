#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int* puntero;
    puntero=&numero;

    printf("%d\n",puntero);
    printf("%d\n",puntero+1);
    printf("%d\n",puntero+2);
    printf("%d\n",puntero+3);


    return 0;
}
