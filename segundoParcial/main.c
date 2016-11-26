#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "entrega.h"
#include "utn.h"
#include "numeros.h"
#include "controller.h"
int main()
{
    char menu[] =
        "\n1-ENTREGA URGENTE\
        \n2-ENTREGA REGULAR\
        \n3-PROXIMA ENTREGA\
        \n4-LISTAR\
        \n5-INFORMAR\
        \n6-SALIR\
        \nIngrese opcion: ";
    char menuError[] = "\n ERROR.\n";
    int opcion = 0,flagUno,flagDos;

    ArrayList* pArrayUrgente;
    ArrayList* pArrayRegular;
    ArrayList* pArrayUEntregado;
    ArrayList* pArrayREntregado;
    ArrayList* pArrayNumeros;

    pArrayUrgente = al_newArrayList();
    pArrayRegular = al_newArrayList();
    pArrayUEntregado = al_newArrayList();
    pArrayREntregado = al_newArrayList();
    pArrayNumeros = al_newArrayList();

    eEntrega* auxEntrega;
    eNumeros* auxNumeros;


    do{
        clearScreen();
        //system("cls");
     getValidInt(menu,menuError,&opcion,1,6,3);
        switch(opcion)
        {
            case 1:
                auxNumeros = numeros_new();
                numeros_setNumero(auxNumeros,pArrayNumeros->size+1);
                al_add(pArrayNumeros,auxNumeros);

                auxEntrega = entrega_new();
                controller_altaEntrega(auxEntrega,numeros_getNumero(auxNumeros));
                al_add(pArrayUrgente,auxEntrega);
                break;
            case 2:
                auxNumeros = numeros_new();
                numeros_setNumero(auxNumeros,pArrayNumeros->size+1);
                al_add(pArrayNumeros,auxNumeros);

                auxEntrega = entrega_new();
                controller_altaEntrega(auxEntrega,numeros_getNumero(auxNumeros));
                al_add(pArrayRegular,auxEntrega);
                break;
            case 3:
                auxEntrega = controller_proximaEntrega(pArrayUrgente);
                if(auxEntrega != NULL)
                {
                    al_add(pArrayUEntregado,auxEntrega);
                }
                else
                {
                    auxEntrega = controller_proximaEntrega(pArrayRegular);
                    al_add(pArrayREntregado,auxEntrega);
                    if(auxEntrega == NULL)
                    {
                        printf("No hay entregas para realizar.\n");
                    }
                }
                pause();
                //system("pause");
                break;
            case 4:
                flagUno = controller_listar(pArrayUrgente,"Entregas pendientes:\n");
                flagDos = controller_listar(pArrayRegular,"");
                if(flagUno && flagDos)
                {
                    printf("No hay entregas pendientes.\n");
                }
                //system("pause");
                pause();
                break;
            case 5:
                al_sort(pArrayUEntregado,controller_ordenarEntregas,1);
                al_sort(pArrayREntregado,controller_ordenarEntregas,1);
                flagUno = controller_listar(pArrayUEntregado,"Entregas finalizadas:\nUrgentes:\n");
                flagDos = controller_listar(pArrayREntregado,"Regulares:\n");
                if(flagUno && flagDos)
                {
                    printf("No hay entregas finalizadas.\n");
                }
                //system("pause");
                pause();
                break;
            case 6:
                //SALIR
                break;
            default:
                printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
                pause();
                break;
        }
    }while(opcion != 6);
    return 0;
}
