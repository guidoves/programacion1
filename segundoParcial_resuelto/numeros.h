#ifndef NUMERO_H_INCLUDED
#define NUMERO_H_INCLUDED
typedef struct
{
    int numero;

}eNumeros;

#endif // NUMERO_H_INCLUDED

eNumeros* numeros_new(void);
void numeros_free(eNumeros* this);
int numeros_setNumero(eNumeros *this,int num);
int numeros_getNumero(eNumeros *this);
