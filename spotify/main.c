#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
#define TC 10
typedef struct
{
    int id;
    char nombre[30];
    char nacionalidad[30];
}xInterprete;
typedef struct
{
    int idCancion;
    char titulo[30];
    int idInterprete;
    char duracion[5];
}xCancion;
void inicializarInterprete (xInterprete[],int);
void inicializarCancion (xCancion[],int);
void mostrarCan(xCancion[],int);
void mostarInter(xInterprete[],int);
void mostrarCanInter(xCancion[],xInterprete[],int,int);
void cancionesPorInterprete (xCancion[],xInterprete[],int,int);
int main()
{
    xInterprete listaInterprete[TAM];
    xCancion listaCancion[TC];

    inicializarInterprete(listaInterprete,TAM);
    inicializarCancion(listaCancion,TC);

    mostarInter(listaInterprete,TAM);
    system("pause");
    mostrarCan(listaCancion,TC);
    system("pause");
    mostrarCanInter(listaCancion,listaInterprete,TC,TAM);
    system("pause");
    cancionesPorInterprete(listaCancion,listaInterprete,TC,TAM);
    system("pause");

    return 0;
}
void inicializarInterprete (xInterprete interprete[],int tamInteg)
{
    int i;
    int id[]={1,2,3,4,5};
    char nombre[][20]={"bruno mars","justin bieber","david visval","adel","el indio"};
    char nacionalidad[][20]={"EEUU","EEUU","ESPAÑA","GB","ARGENTINA"};

    for(i=0;i<tamInteg;i++)
    {
        interprete[i].id=id[i];
        strcpy(interprete[i].nombre,nombre[i]);
        strcpy(interprete[i].nacionalidad,nacionalidad[i]);
    }

}
void inicializarCancion (xCancion cancion[],int tam)
{
    int idCancion[]={1010,1011,1012,1013,1014,1014,1015,1016,1017,1018,1019};
    char titulo[][30]={"la mordidita","la bicicleta","chuncky","baby","cant feel","24k magic","vacaciones","dont wanna know","closer","duele el corazon"};
    int idInterprete[]={1,2,3,4,5,2,5,3,4,1};
    char duracion[][5]={"03:30","04:60","02:30","05:45","06:36","05:16","02:33","03:66","02:36","05:12"};
    int i;

    for(i=0;i<tam;i++)
    {
        cancion[i].idCancion=idCancion[i];
        strcpy(cancion[i].titulo,titulo[i]);
        cancion[i].idInterprete=idInterprete[i];
        strcpy(cancion[i].duracion,duracion[i]);
    }

}
void mostarInter(xInterprete interprete[],int tamInteg)
{
    int i;

    for(i=0;i<tamInteg;i++)
    {
        printf("%d==%s==%s\n",interprete[i].id,interprete[i].nombre,interprete[i].nacionalidad);
    }

}
void mostrarCan(xCancion cancion[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d==%s==%d==%.5s\n",cancion[i].idCancion,cancion[i].titulo,cancion[i].idInterprete,cancion[i].duracion);
    }

}
void mostrarCanInter(xCancion cancion[],xInterprete interprete[],int tam,int tamInteg)
{
    int i;
    int j;
    xInterprete aux;
    printf("ID\t\tNOMBRE\t\t\t      INERPRETE\t     DURACION\n");
    for(i=0;i<tam;i++)
    {
        for(j=0;j<tamInteg;j++)
        {
            if(cancion[i].idInterprete==interprete[j].id)
            {
                aux=interprete[j];
                break;
            }
        }

        printf("%.4d\t%20s\t\t%15s\t\t%.5s\n",cancion[i].idCancion,cancion[i].titulo,aux.nombre,cancion[i].duracion);
    }
}
void cancionesPorInterprete (xCancion cancion[],xInterprete interprete[],int tam,int tamInteg)
{
    int i;
    int j;
    for(i=0;i<tamInteg;i++)
    {
        printf("==================\n");
        printf("%s:\n",interprete[i].nombre);
        for(j=0;j<tam;j++)

        {
            if(cancion[j].idInterprete==interprete[i].id)
            {
                printf("%s\n",cancion[j].titulo);
            }
        }

    }
}
