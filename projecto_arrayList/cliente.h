#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
   int id;
   char name[51];
   char lastName[51];
   int dni;
   int flagEstado;
}sCliente;
#endif // CLIENTE_H_INCLUDED

sCliente* cliente_new(void);
void cliente_delete(sCliente* this);
int cliente_setId(sCliente* this, int id);
int cliente_getId(sCliente* this);
int cliente_setName(sCliente* this, char* name);
char* cliente_getName(sCliente* this);
int cliente_setDni(sCliente* this,int* dni);
int cliente_getDni(sCLiente* this);


