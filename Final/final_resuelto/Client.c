#include "Client.h"

Client* client_new(void)
{
    Client* retorno = NULL;
    retorno = malloc(sizeof(Client));
    return retorno;
}

void client_free(Client* this)
{
    free(this);
}

int client_setName(Client *this, char *name)
{
    int retorno = -1;
    if(this != NULL && strlen(name) > 0)
    {
        strncpy(this->name,name,50);
        retorno = 0;
    }
    return retorno;
}

char* client_getName(Client *this)
{
    char *retorno = NULL;
    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}
int client_setSurname(Client *this,char *surname)
{
    int retorno = -1;
    if(this != NULL && strlen(surname) > 0)
    {
        strncpy(this->surname,surname,50);
        retorno = 0;
    }
    return retorno;
}

char* client_getSurname(Client *this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->surname;
    }
    return retorno;
}
int client_setEmail(Client *this, char *email)
{
    int retorno = -1;
    if(this != NULL && strlen(email) > 0)
    {
        strncpy(this->email,email,50);
        retorno = 0;
    }
    return retorno;
}

char* client_getEmail(Client *this)
{
    char *retorno = NULL;
    if(this != NULL)
    {
        retorno = this->email;
    }
    return retorno;
}
int client_setCard(Client *this, char *card)
{
    int retorno = -1;
    if(this != NULL && strlen(card) > 0)
    {
        strncpy(this->card,card,50);
        retorno = 0;
    }
    return retorno;
}

char* client_getCard(Client *this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->card;
    }
    return retorno;
}
int client_setId(Client *this, char* id)
{
    int retorno = -1;
    if(this != NULL && strlen(id) > 0)
    {
        strncpy(this->id,id,50);
        retorno = 0;
    }
    return retorno;
}

char* client_getId(Client *this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->id;
    }
    return retorno;
}

