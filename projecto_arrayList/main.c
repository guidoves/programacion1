#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
int main()
{
    char nombre[]="jorge";
    ArrayList* pArrayCliente;
    sCliente* pCliente;
    sCliente* pCliente2;
    pArrayCliente = al_newArrayList();

    pCliente = cliente_new();
    cliente_setName(pCliente,"jorge");
    al_add(pArrayCliente,pCliente);
    pCliente = NULL;

    pCliente2 = al_get(pArrayCliente,0);

    printf("%s",cliente_getName(pCliente2));


    return 0;
}
