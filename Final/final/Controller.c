#include "Controller.h"

/** \brief Carga el archivo data.csv Valida los datos y los deposita en listas
 *
 * \param ArrayList *arrayClient puntero a ArrayList (DATOS VALIDOS)
 * \param ArrayList *arrayMaster (MASTER VALIDOS)
 * \param ArrayList *arrayVisa (VISA VALIDOS)
 * \param ArrayList *arrayAmerican (AMERICAN VALIDOS)
 * \param ArrayList *arrayInvalid (DATOS INVALIDOS)
 * \return 0 OK -1 pFile = NULL
 *
 */


int controller_load(ArrayList *arrayClient, ArrayList *arrayMaster, ArrayList *arrayVisa, ArrayList *arrayAmerican, ArrayList *arrayInvalid)
{
    int retorno = -1, flag = 0,aux;
    char id[256], name[256], surname[256], email[256], card[256];
    Client *pClient;
    FILE *pFile;
    pFile = fopen("data.csv","r");
    if(pFile != NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,surname,email,card);
            if(!flag){flag=1;continue;}
            pClient = client_new();
            client_setId(pClient,id);
            client_setName(pClient,name);
            client_setSurname(pClient,surname);
            client_setEmail(pClient,email);
            client_setCard(pClient,card);
            aux = controller_validate(pClient);
            if(aux!=-1){
                al_add(arrayClient,pClient);
                if(!aux){al_add(arrayVisa,pClient);}
                else if(aux == 1){al_add(arrayMaster,pClient);}
                else if(aux == 2){al_add(arrayAmerican,pClient);}
            }
            else{al_add(arrayInvalid,pClient);}
        }
    }
    return retorno;
}

/** \brief Valida si los datos son validos o no.
 *
 * \param Client *pClient puntero a Client (Elemento a validar)
 * \return -1 si es invalido, 0 si es visa valido, 1 si es master valido, 2 si es american valido.
 *
 */


int controller_validate(Client *pClient)
{
    int retorno = -1; // 0: visa, 1: master,2: american.
    if(pClient != NULL)
    {

        if(!validarInt(client_getId(pClient),0,9999))
        {
            if(esSoloLetras(client_getName(pClient)))
            {
                if(esSoloLetras(client_getSurname(pClient)))
                {
                    if(esEmail(client_getEmail(pClient)))
                    {
                        if(pClient->card[0] == '3' && (pClient->card[1] == '4' || pClient->card[1] == '7') && strlen(pClient->card) == 15)
                        {
                            retorno = 2;
                        }
                        else if(pClient->card[0] == '4' && (strlen(pClient->card) == 13 || strlen(pClient->card) == 16))
                        {
                            retorno = 0;
                        }
                        else if(pClient->card[0] == '5' && (pClient->card[1] == '1' || pClient->card[1] == '2' || pClient->card[1] == '3' || pClient->card[1] == '4' || pClient->card[1] == '5') && strlen(pClient->card) == 16)
                        {
                            retorno = 1;
                        }
                        if((validateCard(pClient))){retorno = -1;}
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Valida la tarjeta de credito mediante el algoritmo de validacion.
 *
 * \param  Client *pclient puntero a Client
 * \return 0 si OK -1 si fallo.
 *
 */


int validateCard(Client *pclient)
{
    int retorno = -1, aux[strlen(pclient->card)],i=0,j=0,acumulador=0;
    if(pclient != NULL)
    {
      for(i=(strlen(pclient->card)-1);i>-1; i--)
      {
          aux[j] = (int)(pclient->card[i]-48);
          j++;
      }
      for(i=1;i<strlen(pclient->card);i+=2)
      {
        aux[i] = aux[i] * 2;
      }
      for(i=0;i<strlen(pclient->card);i++)
      {
          if(aux[i] > 9){aux[i] = aux[i] - 9;}
          acumulador=acumulador+aux[i];
      }
      if(acumulador%10 == 0){retorno = 0;}
    }
    return retorno;
}

/** \brief Imprime por pantalla los datos de la lista.
 * \param ArrayList *arrayClient puntero a ArrayList
 *
 */


void controller_printList(ArrayList *arrayClient)
{
    int i;
    Client *pClient;
    if(arrayClient != NULL)
    {
        for(i=0; i<al_len(arrayClient); i++)
        {
            pClient = al_get(arrayClient,i);
            printf("%s %s %s %s %s\n",client_getId(pClient),client_getName(pClient),client_getSurname(pClient),client_getEmail(pClient),client_getCard(pClient));
        }
    }
}

/** \brief Imprime por pantalla los datos de la lista y sus errores.
 *
 * \param ArrayList *arrayClient puntero a Client
 *
 */


void controller_printError(ArrayList *arrayClient)
{
    int i,flag=0;
    Client *pClient;
    if(arrayClient != NULL)
    {
        for(i=0;i<al_len(arrayClient);i++)
        {
            pClient = al_get(arrayClient,i);
            printf("%s %s %s %s %s\n",client_getId(pClient),client_getName(pClient),client_getSurname(pClient),client_getEmail(pClient),client_getCard(pClient));
            if(validarInt(client_getId(pClient),0,9999)){printf("Id invalido. [NUMERICO 0-9999]\n");}
            if(!(esSoloLetras(client_getName(pClient)))){printf("Nombre invalido. [CARACTERES A-Z y a-z]\n");}
            if(!(esSoloLetras(client_getSurname(pClient)))){printf("Apellido invalido. [CARACTERES A-Z y a-z]\n");}
            if(!(esEmail(client_getEmail(pClient)))){printf("Mail invalido. [CARACTERES A-Z y a-z,'@'.'.']\n");}
            if((pClient->card[0] == '3' && (pClient->card[1] == '4' || pClient->card[1] == '7') && strlen(pClient->card) == 15) || (pClient->card[0] == '4' && (strlen(pClient->card) == 13 || strlen(pClient->card) == 16)) || (pClient->card[0] == '5' && (pClient->card[1] == '1' || pClient->card[1] == '2' || pClient->card[1] == '3' || pClient->card[1] == '4' || pClient->card[1] == '5') && strlen(pClient->card) == 16))
            {if(!(validateCard(pClient))){flag = 1;}}
            if(!flag){printf("Tarjeta invalida. [SINTAXIS ERROR]\n");}
            printf("\n");
            flag = 0;
        }
    }
}
