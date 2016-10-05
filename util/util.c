#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "util.h"

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

x* findById(x* pArray, int length,int id)
{
    x *retorno=NULL;
    int i;

    if(pArray != NULL && length > 0)
    {

        for(i=0;i<length;i++)
        {
            if(pArray[i].id==id)
            {
                retorno=&pArray[i].id;

                break;

            }
        }
    }

    return retorno;



}

/**
* \brief Verifica que exista un lugar activo o cargado
* \param recibe la estructura completa
* \param recibe el largo de la estructura
* \return devuelve 1 si hay lugares activos o cargados y 0 si no los hay
*
*/

int chequearActivos(x array[],int largo)
{
    int i;
    int activos=0;

    for(i=0;i<largo;i++)
    {
        if(array[i].estado==1)
        {
            activos=1;

            break;
        }
    }

    return activos;
}


/**
* \brief Obtieve el primer espacio libre
* \param array Recibe el array
* \param largo Recibe el largo del array
* \return devuele el indice libre, sino encontro libres devuelve -1
*
*/

int obtenerEspacioLibre(x array[],int largo)
{
    int i;
    int indice=-1;

    for(i=0;i<largo;i++)
    {
        if(array[i].estado==0)
        {
            indice=i;

            break;
        }
    }
    return indice;
}

void setArray(x array[],int largo,int valor)
{
	int i;
	
	for(i=0;i<largo;i++)
	{
		array[i]=valor;
	}
}
/**
* \brief Funcion para validar una cadena de caracteres (No numeros) 
* \param buffer Ingreso del usuario.
* \param min valor minimo de la longitud de la cadena.
* \param max valor maximo de la longitud de la cadena.
* \param largo largo de la cadena de caracteres.
* \return Devuelve 0 si el ingreso es valido o devuelve 0 si es invalido.
*
*/


int validarString(char buffer[],int min,int max,int largo)
{
    int aux=-1;
    int i,j;
    j=strlen(buffer);

    if(j >= min && j <= max)
    {
      aux=0;

      for(i=0;i<largo;i++)
      {
        if(isdigit(buffer[i])==1)
        {
          aux=-1;

          break;
        }
        
      }


    }

    return aux;

}
/**
* \brief Funcion para validar un caracter por un determinado valor
* \param buffer Ingreso del usuario.
* \param char x caracter valido.
* \param char y caracter valido.
* \return Devuelve 0 si el ingreso es valido o devuelve -1 si es invalido.
*
*/

int validarChar(char buffer[], char x,char y)
{
    int retorno=-1;
    int j;
    char aux;

    j=strlen(buffer);

    if(j==1)
    {
      aux=buffer[0];

      if(aux == x || aux == y)
      {
        aux=-1;

      }

        
    }

    return retorno;

}
/**
* \brief Valida si el usuario ingreso un entero positivo
* \param buffer Recibe el ingreso del usuario.
* \param min Recibe el valor minimo valido
* \param max Recibe el valor maximo valido.
* \return Devuelve -1 si la cadena posee letras o signos, y devuelve 0 si la cadena posee numeros.
*
*/

int validarInt(char buffer[],int min,int max)
{
    int aux=0; // RETURN
    int j; // AUXILIAR
    int i=0; // AUXILIARCONTADOR
    int numero;

    j=strlen(buffer); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY

	while( i<j && aux == 0)
    {
	  if(isdigit(buffer[i])!=0) // isdigit devuelve 1 si es numero o 0 sino lo es.
      {
	      i++;
      }
	  else
      {
	      aux=-1;
      }
	}
	if(aux==0)
	{
        numero=cadena_entero(buffer);

        if(numero < min || numero > max)
        {
            aux=-1;
        }

	}

    return aux;
}

/**
* \brief Trasnforma una cadena de numeros a un entero(int).
* \param Recibe la cadena de numeros.
* \return Devuelve la cadena transformado a un entero.
*
*/


int cadena_entero(char numero[])
{
    int num=0; //RETURN
    int aux=strlen(numero); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY
    int i; // AUX CONTADOR
    int digito; // AUXILIAR PARA OBTENER LOS DIGITOS

    for(i=aux;i>0;i--)
    {
        digito=numero[i-1]-48; // TRANSFORMA EL ELEMENTO A UN DIGITO ENTERO
        num=num+(digito*pow(10,aux-i)); // ARMA EL NUMERO FINAL digito*10^n

    }

    return num;
}

/**
* \brief Funcion para crear un menu de opciones
* \param Son los items del menu de opciones.
* \param Define el rango minimo de opciones.
* \param Define el rango maximo de opciones.
* \return Devuelve la opcion elegida por el usuario.
*/


int menu(char texto[],int rangoOpcionMin,int rangoOpcionMax)
{
  int opcion=0;
  char buffer[4000];

  printf("%s",texto);
  printf("Opcion: ");
  gets(buffer);

  while(validarInt(buffer,rangoOpcionMin,rangoOpcionMax)!=0)
  {
    printf("Ingreso invalido. Ingrese opcion valida.\n");
    printf("Opcion: ");
    gets(buffer);

  }

  opcion=cadena_entero(buffer);

  return opcion;


}
/**
* \brief Funcion para limpiar el buffer en cualquier SO.
*/

void flush_in()
{
  int ch;

  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}



