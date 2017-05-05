#include <stdio.h>
#include <stdlib.h>

/*
1-relizar una funcion de carga.
2-una funcion de ordenamiento.
3-una funcion muestreo.
*/

int main()
{
    int x[5];
    int *punt;
    int i;

    punt=x;
    for(i=0;i<5;i++)
    {
        *(punt+i)=0;
    }
    for(i=0;i<5;i++)
    {
        printf("%d\n",*(punt+i));
    }


    /****************************************************************************************/
    /*
    int x[5];
    int *punt;

    x[0]=9;
    x[1]=1;
    x[2]=5;
    x[3]=6;
    x[4]=8;

    printf("%d al principio.\n",x[1]);
    // punt=&x[0];==> esta seriqa una forma de anotar la direccion de memoria del vector punt=&x[0] pero no la utilizamos.
    // punt=&x;==> esta seria otra forma de anotar la direccion punt=&x; pero no la otilizamos porque es redundante.
    punt=x;//==> esta es la forma mas optima.

    *(punt+1)=3;//==> asi accedo a una posicion el particular del vector......modifficando al balor porque usos el puntero.
    printf("%d modificado.\n",x[1]);
    */
    /*****************************************************************************************/
    /*
    int a;
    int *punt;

    punt=&a;
    printf("%p\n",punt);
    printf("%p\n",punt+1);//esto es igual a hacer punt++.
    printf("%p",punt-1);//--->cada ves que modificamos ya sea suma o resta siempre son 4 bits.
    */
    /*****************************************************************************************/
    /*
    //para tabajare con punteros debemos tener en cuenta, de debemos usar ""*(operaqdor de inacceso)"" y ""&(inacciones)""
    int a=7;
    int *punt;//---->declare el puntero.
    int *otro;

    punt=&a;
    *punt=8;//----> guarde la direccion de memoria dentro de la funcion punt.
    otro=punt;//---->le asigno
    printf("%p\n",otro);//--->me muestra la direccion de memoria de a.

    printf("%p\n",&a);//---->muestra la direccion de memoria
    printf("%p\n",punt);//---->no se utiliza "&" porque sino no mostraria la direccccion de memoria de punt y no la direccion guardada.
    printf("%d\n",a);
    printf("%d\n",*punt);//--->de esta manera nos va a mostrar el numero guardado en la rereccion de memoria y no el numero de la direccion de memoria.
    printf("%d\n",*otro);//--->de esta manera nos va a mostrar el numero guardado en la rereccion de memoria y no el numero de la direccion de memoria.
    */

    return 0;
}



