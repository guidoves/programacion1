#include "numeros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eNumeros* numeros_new(void)
{
    eNumeros* retorno = NULL;
    retorno = malloc(sizeof(eNumeros));
    return retorno;
}

void numeros_free(eNumeros* this)
{
    free(this);
}

int numeros_setNumero(eNumeros *this,int num)
{
    int retorno = -1;
    if(this != NULL && num >0)
    {
        this->numero = num;
        retorno = 0;
    }
    return retorno;
}

int numeros_getNumero(eNumeros *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->numero;
    }
    return retorno;
}

