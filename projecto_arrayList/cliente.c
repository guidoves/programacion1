#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

sCliente* cliente_new(void)
{
    sCliente* returnAux = NULL;
    returnAux = malloc(sizeof(sCliente));
    return returnAux;
}

void cliente_delete(sCliente* this)
{
    free(this);
}

int cliente_setId(sCliente* this, int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        retorno = 0;
        this->id = id;
    }
    return retorno;
}

int cliente_getId(sCliente* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->id;
    }
    return retorno;
}

int cliente_setName(sCliente* this, char* name)
{
    int retorno = -1;
    if(this != NULL && strlen(name) > 0)
    {
        retorno = 0;
        strncpy(this->name,name,50);
    }
    return retorno;
}

char* cliente_getName(sCliente* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}

int cliente_setLastName(sCliente* this, char* lastName)
{
    int retorno = -1;
    if(this != NULL && strlen(lastName) > 0)
    {
        retorno = 0;
        strncpy(this->lastName,lastName,50);
    }
    return retorno;
}

char* cliente_getLastName(sCliente* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->lastName;
    }
    return retorno;
}

int cliente_setDni(sCliente* this,int* dni)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->dni = dni;
        retorno = 0;
    }
    return retorno;
}
int cliente_getDni(sCLiente* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->dni;
    }
    return retorno;
}

