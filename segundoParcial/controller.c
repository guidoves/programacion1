#include "controller.h"

int controller_altaEntrega(eEntrega* pEntrega, int num)
{
    int retorno = -1;
    char direccion[51];
    int altura;
    if(pEntrega != NULL && num > 0)
    {
        retorno = getValidString("Ingrese la direccion de entrega: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.",direccion,50,3);
        if(!retorno)
        {
            retorno = getValidInt("Ingrese la altura: ","Ingreso invalido.\n",&altura,0,9999,3);
            if(!retorno)
            {
                entrega_setDireccion(pEntrega,direccion);
                entrega_setAltura(pEntrega,altura);
                entrega_setNumDespacho(pEntrega,num);
            }
        }
    }
    return retorno;
}


int controller_ordenarEntregas(void* entregaA,void* entregaB)
{
    if(strcmp(((eEntrega*)entregaA)->direccion,((eEntrega*)entregaB)->direccion)>0)
    {
        return 1;
    }
    if(strcmp(((eEntrega*)entregaA)->direccion,((eEntrega*)entregaB)->direccion)<0)
    {
        return -1;
    }
    return 0;
}

eEntrega* controller_proximaEntrega(ArrayList *pArrayEntregas)
{
    eEntrega* pEntrega = NULL;
    int i;
    if(pArrayEntregas != NULL && !(al_isEmpty(pArrayEntregas)))
    {
        for(i=0;i<(al_len(pArrayEntregas));i++)
        {
            pEntrega = al_pop(pArrayEntregas,i);
            if(pEntrega != NULL)
            {
                printf("Proxima entrega:\nNumero de despacho %d\nDireccion %s %d\n",pEntrega->numDespacho,pEntrega->direccion,pEntrega->altura);
                break;
            }
        }
    }
    return pEntrega;
}

int controller_listar(ArrayList *pArrayEntregas,char* texto)
{
    int retorno = -1,i;
    eEntrega* pEntrega;
    if(pArrayEntregas != NULL && !(al_isEmpty(pArrayEntregas)))
    {
        retorno = 0;
        printf(texto);
        for(i=0;i<(al_len(pArrayEntregas));i++)
        {
            pEntrega = al_get(pArrayEntregas,i);
            if(pEntrega != NULL)
            {
                printf("Numero de despacho: %d | Direccion: %s %d\n",pEntrega->numDespacho,pEntrega->direccion,pEntrega->altura);
            }
        }
    }
    return retorno;
}

