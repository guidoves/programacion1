#ifndef REGULAR_H_INCLUDED
#define REGULAR_H_INCLUDED
typedef struct
{
    int numDespacho;
    char direccion[51];
    int altura;
}eEntrega;


#endif // REGULAR_H_INCLUDED

eEntrega* entrega_new(void);
void entrega_free(eEntrega* this);
int entrega_setNumDespacho(eEntrega *this,int num);
int entrega_getNumDespacho(eEntrega *this);
int entrega_setDireccion(eEntrega *this, char *direccion);
char* entrega_getDireccion(eEntrega *this);
int entrega_setAltura(eEntrega *this,int altura);
int entrega_getAltura(eEntrega *this);

