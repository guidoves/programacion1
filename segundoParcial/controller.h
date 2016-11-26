#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "entrega.h"
#include "utn.h"

int controller_altaEntrega(eEntrega* pEntrega, int num);
int controller_ordenarEntregas(void* entregaA,void* entregaB);
eEntrega* controller_proximaEntrega(ArrayList *pArrayEntregas);
int controller_listar(ArrayList *pArrayEntregas,char* texto);
