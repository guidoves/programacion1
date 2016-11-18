#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"

Alquiler* cliente_new(void)
{
    Alquiler* retorno = NULL;
    retorno = malloc(sizeof(Alquiler));
    return retorno;
}

void alquiler_free(Alquiler* this)
{
    free(this);
}

int alquiler_setIdCliente(Alquiler *this, int *id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->idCliente=id;
        retorno = 0;
    }
    return retorno;
}

int alquiler_getIdCliente(Alquiler *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->idCliente;
    }
    return retorno;
}

int alquiler_setEquipo(Alquiler *this, int *equipo)
{
    int retorno = -1;
    if(this != NULL && equipo > 0)
    {
        this->equipo=equipo;
        retorno = 0;
    }
    return retorno;
}

int alquiler_getEquipo(Alquiler *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->equipo;
    }
    return retorno;
}

int alquiler_setEstado(Alquiler *this, int *estado)
{
    int retorno = -1;
    if(this != NULL && estado > 0)
    {
        this->estado=estado;
        retorno = 0;
    }
    return retorno;
}

int alquiler_getEstado(Alquiler *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->estado;
    }
    return retorno;
}
