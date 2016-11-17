#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "vendedor.h"
int main()
{
    char menu[] =
        "\n1-ALTA CLIENTE\
        \n2-VER CLIENTES\
        \n3-ALTA VENDEDOR\
        \n4-VER VENDEDORES\
        \n5-SALIR\
        \nIngrese opcion: ";
    char menuError[] = "\n ERROR.\n";
    int opcion,i;

    ArrayList *pArrayCliente;
    sCliente *pCliente;
    pArrayCliente = al_newArrayList();

    ArrayList *pArrayVendedor;
    sVendedor *pVendedor;
    pArrayVendedor = al_newArrayList();


    do
    {
        clearScreen();
        opcion = 0;
        getValidInt(menu,menuError,&opcion,0,5,2);
        switch(opcion)
        {
            case 1:
                pCliente = cliente_new();
                controller_altaCliente(pCliente);
                al_add(pArrayCliente,pCliente);
                break;
            case 2:
                for(i=0;i<pArrayCliente->size;i++)
                {
                    pCliente = al_get(pArrayCliente,i);
                    printf("%s\n",cliente_getName(pCliente));
                }
                pause();
                break;
            case 3:
                pVendedor = vendedor_new();
                controller_altaVendedor(pVendedor);
                al_add(pArrayVendedor,pVendedor);
                break;
            case 4:
                break;
            case 5:
                //SALIR
                break;
            default:
                printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
                pause();
                break;
        }
    }while(opcion != 5);
    return 0;
}
