#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cliente_new(void)
{
    Cliente* retorno = NULL;
    retorno = malloc(sizeof(Cliente));
    return retorno;
}

void cliente_free(Cliente this)
{
    free(this);
}

int cliente_setDni(Cliente *this, int *dni)
{
    int retorno = -1;
    if(this != NULL && dni > 0)
    {
        this->dni=dni;
        retorno = 0;
    }
    return retorno;
}

int cliente_getDni(Cliente *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->dni;
    }
    return retorno;
}

int cliente_setNombre(Cliente *this, char *nombre)
{
    int retorno = -1;
    if(this != NULL && strlen(nombre) > 0)
    {
        strncpy(this->nombre,nombre,50);
        retorno = 0;
    }
    return retorno;
}

char* cliente_getNombre(Cliente *this)
{
    char *retorno = NULL
    if(this != NULL)
    {
        retorno = this->nombre;
    }
    return retorno;
}

int cliente_setApellido(Cliente *this, char *apellido)
{
    int retorno = -1;
    if(this != NULL && strlen(apellido) > 0)
    {
        strncpy(this->apellido,apellido,50);
        retorno = 0;
    }
    return retorno;
}

char* cliente_getApellido(Cliente *this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->apellido;
    }
    return retorno;
}
int cliente_setIdCliente(Cliente *this, int *id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->idCliente = id;
        retorno = 0;
    }
    return retorno;
}

int cliente_getIdCliente(Cliente *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->idCliente;
    }
    return retorno;
}
