#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
void cargarSeries(eSerie);
void cargarClientes(eCliente);
void cargarCliente_Serie(eClientes_Series);
void mostrarCliente(eCliente);
void mostrarCSerie(eCliente, eSerie, eClientes_Series);
void mostrarSCliente(eCliente, eSerie, eClientes_Series);
void buscarSerie(eCliente, eSerie, eClientes_Series);
void menosPopular(eLoser,eSerie,eClientes_Series);
void miraJuan(eCliente,eSerie,eClientes_Series);
/*
1- mostrar cada uno
2- mostrar clientes con sus series
3- por cada serie los clientes que la estan viendo
4- todos los clientes que ven una serie en particular (El usuario ingresa el titulo)
5- La serie menos popular
6- Todas las series que ven los clientes de nombre "Juan"
*/


typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
} eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;

} eCliente;

typedef struct
{
    int idCliente;
    int idSerie;
} eClientes_Series;

typedef struct//Para el punto 5
{
    int idSerie;
    int cont;
} eLoser;


int main()
{
    int opcion;
    char seguir='s';
    eSerie series[5];
    eCliente clientes[10];
    eClientes_Series idSC[20];
    eLoser personasSerie[5];

    cargarCliente_Serie(idSC);
    cargarSeries(series);
    cargarClientes(clientes);
    do
    {
        opcion=0;
        system("cls");
        printf("1-Mostrar clientes\n2-Mostrar series por cliente\n3-Mostrar clientes por serie\n4-Buscar todos los clientes que ven una serie\n5-Buscar la serie menos popular\n6-Buscar que series mira Juan\n7-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            mostrarCliente(clientes);
            break;
        case 2:
            mostrarCSerie(clientes, series, idSC);
            break;
        case 3:
            mostrarSCliente(clientes,series,idSC);
            break;
        case 4:
            buscarSerie(clientes,series,idSC);
            break;
        case 5:
            menosPopular(personasSerie,series,idSC);
            break;
        case 6:
            miraJuan(clientes,series,idSC);
            break;
        case 7:
            seguir='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        printf("Presione cualquier tecla para continuar");
        getch();
        system("cls");
    }
    while(seguir!='n');


    return 0;
}
void miraJuan(eCliente clientes[],eSerie series[],eClientes_Series quienVe[])
{
    int i,j,k;
    int flag=0;
    for(i=0; i<10; i++)
    {
        if(strcmp(clientes[i].nombre,"juan")==0)
        {
            if(flag==0)
            {
                printf("Los usuarios llamados \"Juan\" ven: ");
            }
            flag=1;
            for(j=0; j<20; j++)
            {
                if(clientes[i].idCliente==quienVe[j].idCliente)
                {
                    for(k=0; k<5; k++)
                    {
                        if(quienVe[j].idSerie==series[k].idSerie)
                        {
                            printf(" %s ",series[k].titulo);
                        }
                    }
                }
            }
        }
    }
    if(flag==0)
    {
        printf("No hay usuarios con ese nombre");
    }
    printf("\n");

}

void menosPopular(eLoser cantidades[],eSerie serie[],eClientes_Series quienVe[])
{
    int i,j,k;
    for(i=0; i<5; i++)
    {
        cantidades[i].idSerie=serie[i].idSerie;
        cantidades[i].cont=0;
        for(j=0; j<20; j++)
        {
            if(serie[i].idSerie==quienVe[j].idSerie && quienVe[j].idCliente!=0)
            {
                cantidades[i].cont++;
            }
        }
    }
    j=cantidades[0].cont;
    k=0;
    for(i=0; i<5; i++)
    {
        if(cantidades[i].cont<j)
        {
            j==cantidades[i].cont;
        }
    }
    printf("La\/s serie\/s menos popular\/es con %d personas viendo:",j);
    for(i=0; i<5; i++)
    {
        if(cantidades[i].cont==j)
        {
            printf(" %s ",serie[i].titulo);
        }
    }
    printf("\n");
}

void mostrarCliente(eCliente cliente[])
{
    int i;
    for(i=0; i<10; i++)
    {
        if(cliente[i].estado==1)
        {
            printf("ID:%d Nombre:%s\n",cliente[i].idCliente,cliente[i].nombre);
        }
    }
}
void mostrarCSerie(eCliente cliente[],eSerie serie[],eClientes_Series quienVe[])
{
    int i,a,b;
    for(i=0; i<10; i++)
    {
        if(cliente[i].estado==1)
        {
            printf("ID:%d Nombre:%s Series:",cliente[i].idCliente,cliente[i].nombre);
            for(a=0; a<20; a++)
            {
                if(quienVe[a].idCliente==cliente[i].idCliente)
                {
                    for(b=0; b<5; b++)
                    {

                        if(quienVe[a].idSerie==serie[b].idSerie)
                        {
                            printf(" %s ",serie[b].titulo);
                        }
                    }

                }

            }

            printf("\n");
        }
    }
}
void mostrarSCliente(eCliente cliente[],eSerie serie[],eClientes_Series quienVe[])
{
    int i,a,b;
    for(i=0; i<5; i++)
    {
        if(serie[i].estado==1)
        {
            printf("ID:%d\nSerie:%s\nGenero:%s\nTemporadas:%d\nClientes:",serie[i].idSerie,serie[i].titulo,serie[i].genero,serie[i].temporadas);
            for(a=0; a<20; a++)
            {
                if(serie[i].idSerie==quienVe[a].idSerie)
                {
                    for(b=0; b<10; b++)
                    {
                        if(quienVe[a].idCliente==cliente[b].idCliente)
                        {
                            printf(" %s ",cliente[b].nombre);
                        }
                    }
                }
            }
            printf("\n\n\n\n");
        }
    }
}

void buscarSerie(eCliente cliente[],eSerie serie[],eClientes_Series quienVe[])
{
    int i,a,b;
    char opcion[10];
    printf("ingrese nombre;\nTBBT\nBB\nGOT\nAHS\nSCD\n");
    fflush(stdin);
    gets(opcion);;
    for(i=0; i<5; i++)
        if(serie[i].estado==1 && strcmp(serie[i].titulo,strupr(opcion))==0)
        {
            printf("\nID:%d\nSerie:%s\nGenero:%s\nTemporadas:%d\nClientes:",serie[i].idSerie,serie[i].titulo,serie[i].genero,serie[i].temporadas);
            for(a=0; a<20; a++)
            {
                if(serie[i].idSerie==quienVe[a].idSerie)
                {
                    for(b=0; b<10; b++)
                    {
                        if(quienVe[a].idCliente==cliente[b].idCliente)
                        {
                            printf(" %s ",cliente[b].nombre);
                        }
                    }
                }
            }
            printf("\n\n\n\n");
        }
}

void cargarSeries(eSerie series[])
{
    int idSerie[5]= {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]= {9,7,7,6,1};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};

    int i;

    for(i=0; i<10; i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];

    }

}

void cargarCliente_Serie(eClientes_Series clientesSeries[])
{

    int cliente[20] = {1,1,1,2,2,3,4,4,5,5,5,7,8,8,8,9,10,10,10,10};
    int serie[20]= {101,102,103,104,103,101,101,102,104,101,101,101,101,102,103,102,101,103,102,104};
    int i;

    for(i=0; i<20; i++)
    {
        clientesSeries[i].idCliente=cliente[i];
        clientesSeries[i].idSerie = serie[i];
    }

}
