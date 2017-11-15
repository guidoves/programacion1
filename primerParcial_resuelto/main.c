#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "alquiler.h"

int main()
{
    char menu[] =
        "\n1-ALTA CLIENTE\
        \n2-VER CLIENTES\
        \n3-BAJA CLIENTE\
        \n4-VER VENDEDORES\
        \n5-SALIR\
        \nIngrese opcion: ";
    char menuError[] = "\n ERROR.\n";
    int opcion,i;
    int length;

    ArrayList *pArrayClientes;
    Cliente *pCliente;
    pArrayClientes = al_newArrayList();

    ArrayList *pArrayAlquileres;
    Alquiler *pAlquiler;
    pArrayAlquileres = al_newArrayList();

    do
    {
        //clearScreen();
        system("cls");
        opcion = 0;
        getValidInt(menu,menuError,&opcion,0,5,2);
        switch(opcion)
        {
            case 1:
                pCliente = cliente_new();
                controller_altaCliente(pCliente,pArrayClientes->size+1);
                al_add(pArrayClientes,pCliente);
                break;
            case 2:
                length = al_len(pArrayClientes);
                for(i=0;i<length;i++)
                {
                    pCliente = al_get(pArrayClientes,i);
                    if(pCliente->flagEstado == 1)
                    {
                            printf("%s\n",cliente_getNombre(pCliente));
                            printf("%d\n",cliente_getFlagEstado(pCliente));
                            printf("%d\n",cliente_getIdCliente(pCliente));
                    }
                }
                pause();
                break;
            case 3:
                controller_bajaCliente(pArrayClientes);
                pause();
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
