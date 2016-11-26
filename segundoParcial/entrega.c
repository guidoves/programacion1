#include "entrega.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eEntrega* entrega_new(void)
{
    eEntrega* retorno = NULL;
    retorno = malloc(sizeof(eEntrega));
    return retorno;
}

void entrega_free(eEntrega* this)
{
    free(this);
}

int entrega_setNumDespacho(eEntrega *this,int num)
{
    int retorno = -1;
    if(this != NULL && num >0)
    {
        this->numDespacho = num;
        retorno = 0;
    }
    return retorno;
}

int entrega_getNumDespacho(eEntrega *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->numDespacho;
    }
    return retorno;
}

int entrega_setDireccion(eEntrega *this, char *direccion)
{
    int retorno = -1;
    if(this != NULL && strlen(direccion) > 0)
    {
        strncpy(this->direccion,direccion,50);
        retorno = 0;
    }
    return retorno;
}

char* entrega_getDireccion(eEntrega *this)
{
    char *retorno = NULL;
    if(this != NULL)
    {
        retorno = this->direccion;
    }
    return retorno;
}

int entrega_setAltura(eEntrega *this,int altura)
{
    int retorno = -1;
    if(this != NULL && altura >0)
    {
        this->altura = altura;
        retorno = 0;
    }
    return retorno;
}

int entrega_getAltura(eEntrega *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->altura;
    }
    return retorno;
}
