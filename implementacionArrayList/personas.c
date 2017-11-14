#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "personas.h"

xPersona* newClub()
{
    xPersona* aux;
    aux=(xPersona*)malloc(sizeof(xPersona));

    return aux;
}
xPersona* newClubParametros( char nombre[],int id,char color[],char apellido[])
{

}
