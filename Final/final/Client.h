#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _CLIENT_H
#define _CLIENT_H
typedef struct
{
    char id[51];
    char name[51];
    char surname[51];
    char email[51];
    char card[51];
}Client;
#endif // _CLIENT_H

Client* client_new(void);
void client_free(Client* this);
int client_setName(Client *this, char *name);
char* client_getName(Client *this);
int client_setSurname(Client *this,char *surname);
char* client_getSurname(Client *this);
int client_setEmail(Client *this, char *email);
char* client_getEmail(Client *this);
int client_setCard(Client *this, char *card);
char* client_getCard(Client *this);
int client_setId(Client *this, char* id);
char* client_getId(Client *this);
