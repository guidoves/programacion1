#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "vendedor.h"

int controller_altaCliente(sCliente* pCliente)
{
    unsigned int dni;
    char name[51];
    char lastName[51];
    int retorno = -1;
    if(pCliente != NULL)
    {
        retorno = getValidString("Ingrese el nombre del cliente: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.\n",name,50,3);
        if(!retorno)
        {
            retorno = getValidString("Ingrese el apellido del cliente: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.\n",lastName,50,3);
            if(!retorno)
            {
                retorno = getValidInt("Ingrese el dni del cliente: ","Ingreso invalido.\n",&dni,999999,99999999,3);

                if(!retorno)
                {
                    cliente_setDni(pCliente,dni);
                    cliente_setName(pCliente,name);
                    cliente_setLastName(pCliente,lastName);
                    retorno = 0;
                    //cliente_setFlagEstado(pCliente,1);
                    //cliente_setId()
                }
            }
        }
    }
    return retorno;
}

int controller_altaVendedor(sVendedor* pVendedor)
{
    int retorno = -1;
    char name[51];
    if(pVendedor != NULL)
    {
        retorno = getValidString("Ingrese el nombre del vendedor: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.\n",name,50,3);
        if(!retorno)
        {
            vendedor_setName(pVendedor,name);
            retorno = 0;
        }
    }
    return retorno;
}
