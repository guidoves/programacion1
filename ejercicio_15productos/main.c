#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PRODUCTOS 15


int menu();
void flush_in();


int main()
{

int codigo[PRODUCTOS]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},auxCodigo;
float precio[PRODUCTOS],auxPrecio;
char descripcion [PRODUCTOS][50],auxDescripcion[50],respuesta;

int i;


    switch(menu())
    {
        case 1:

            system("clear");

            for(i=0;i<PRODUCTOS;i++)
            {
                if(codigo[i]==-1)
                {

                    printf("Ingrese CODIGO ENTRADA: ");
                    scanf("%d",&auxCodigo);

                    printf("Ingrese DESCRIPCION: ");
                    flush_in();
                    gets(auxDescripcion);

                    printf("Ingrese PRECIO: ");
                    fflush(stdin);
                    scanf("%f",&auxPrecio);

                    printf("Usted esta por ingresar:\nENTRADA: %d\nDESCRIPCION: %s\nPRECIO: %.2f\n",auxCodigo,auxDescripcion,auxPrecio);
                    printf("Desea confirmar la operacion: ");
                    scanf("%c",&respuesta);
                    if(respuesta=='s')
                    {
                        codigo[i]=auxCodigo;
                        strcpy(descripcion[i],auxDescripcion);
                        precio[i]=auxPrecio;

                        break;
                    }


                    break;
                }
            }


    }

    return 0;
}

int menu()
{
    int opcion;

    printf("MENU\n");
    printf("INGRESE (1,2,3)\n");
    printf("1)ALTAS\n");
    printf("2)BAJAS\n");
    printf("3)LISTAR\n");
    printf("Opcion: ");
    scanf("%d",&opcion);

    while(opcion < 1 || opcion > 3)
    {
        printf("Opcion incorrecta\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

    }

    return opcion;
}

void flush_in()
{
int ch;

while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
