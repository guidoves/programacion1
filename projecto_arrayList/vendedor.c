#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"

sVendedor* vendedor_new(void)
{
    sVendedor* returnAux = NULL;
    returnAux = malloc(sizeof(sVendedor));
    return returnAux;
}

void vendedor_delete(sVendedor* this)
{
    free(this);
}

int vendedor_setName(sVendedor* this, char* name)
{
    int retorno = -1;
    if(this != NULL && strlen(name) > 0)
    {
        retorno = 0;
        strncpy(this->name,name,50);
    }
    return retorno;
}

char* vendedor_getName(sVendedor* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}
int vendedor_setVentas(sVendedor* this, int* ventas)
{
    int retorno = -1;
    if(this != NULL && ventas > 0)
    {
        this->ventas=ventas;
        retorno = 0;
    }
    return retorno;
}

int* vendedor_getVentas(sVendedor* this)
{
    int* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->ventas;
    }
    return retorno;
}
