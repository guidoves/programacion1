#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Controller.h"

int main()
{
    int opcion;
    char menu[]=
    "\n1. Listar clientes con todos sus datos validos\
    \n2. Listar clientes con tarjetas MasterCard validas\
    \n3. Listar clientes con tarjetas Visa validas\
    \n4. Listar clientes con tarjetas American Express validas\
    \n5. Listas clientes con datos invalidos.\
    \n6. Salir\
    \nIngrese opcion: ";
    char menuError[] = "\n Opcion invalida.\n";

    ArrayList *arrayClient;
    ArrayList *arrayMaster;
    ArrayList *arrayVisa;
    ArrayList *arrayAmerican;
    ArrayList *arrayInvalid;

    arrayClient = al_newArrayList();
    arrayMaster = al_newArrayList();
    arrayVisa = al_newArrayList();
    arrayAmerican = al_newArrayList();
    arrayInvalid = al_newArrayList();

    controller_load(arrayClient,arrayMaster,arrayVisa,arrayAmerican,arrayInvalid);
    do
    {
        clearScreen();
        getValidInt(menu,menuError,&opcion,1,6,3);
        switch(opcion)
        {
            case 1:
                controller_printList(arrayClient);
                pause();
                break;
            case 2:
                controller_printList(arrayMaster);
                pause();
                break;
            case 3:
                controller_printList(arrayVisa);
                pause();
                break;
            case 4:
                controller_printList(arrayAmerican);
                pause();
                break;
            case 5:
                controller_printError(arrayInvalid);
                pause();
                break;
            case 6:
                //SALIR
                break;
            default:
                printf("\nOPCION INVALIDA!!\n\n");
                break;
        }
    }while(opcion!=6);
    return 0;
}
