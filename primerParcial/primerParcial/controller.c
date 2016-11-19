#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "utn.h"
#include "cliente.h"

int controller_altaCliente(Cliente* pCliente,int id)
{
    int dni;
    char nombre[51];
    char apellido[51];
    int idCliente;
    int flagEstado;
    int retorno= -1;

    retorno = getValidString("Ingrese el nombre del cliente: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.",nombre,50,3);

    if(retorno == 0)
    {
        retorno = getValidString("Ingrese el apellido del cliente: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.",apellido,50,3);
        if(retorno == 0)
        {
            retorno = getValidInt("Ingrese el dni del cliente: ","Ingreso invalido.\n",&dni,999999,99999999,3);
            if(retorno == 0)
            {
                cliente_setNombre(pCliente,nombre);
                cliente_setApellido(pCliente,apellido);
                cliente_setDni(pCliente,&dni);
                cliente_setIdCliente(pCliente,id);
                cliente_setFlagEstado(pCliente,1);
            }
        }
    }
    return retorno;
}

int controller_bajaCliente(ArrayList* pArrayCliente)
{
    int id,i;
    int retorno = -1;
    Cliente *pCliente;
    int length = al_len(pArrayCliente);

    retorno = getValidInt("Ingrese el ID a dar de baja: ","Ingreso invalido(Ingrese de 0-9999)\n",&id,0,9999,3);

    if(retorno == 0)
    {
        retorno = -1;
        for(i=0;i<length;i++)
        {
            pCliente = al_get(pArrayCliente,i);
            if(pCliente->idCliente == id && pCliente->flagEstado == 1)
            {
                cliente_setFlagEstado(pCliente,0);
                retorno = 0;
                break;
            }
        }
        if(retorno)
        {
            printf("Id invalido o ya esta eliminado.\n");
        }
    }
    return retorno;
}
/*
int controller_modificarCliente(ArrayList* pArrayCliente)
{
    int id,i;
    int retorno = -1;
    Cliente *pCliente;
    int length = al_len(pArrayCliente);

    retorno = getValidInt("Ingrese el ID a dar de baja: ","Ingreso invalido(Ingrese de 0-9999)\n",&id,0,9999,3);

    if(retorno == 0)
    {
        retorno = -1;
        for(i=0;i<length;i++)
        {
            pCliente = al_get(pArrayCliente,i);
            if(pCliente->idCliente == id && pCliente->flagEstado == 1)
            {
                cliente_setFlagEstado(pCliente,0);
                retorno = 0;
                break;
            }
        }
        if(retorno)
        {
            printf("Id invalido o ya esta eliminado.\n");
        }
    }
    return retorno;
}
*/
