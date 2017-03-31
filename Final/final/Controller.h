#include "Client.h"
#include "ArrayList.h"
#include "utn.h"

int controller_load(ArrayList *arrayClient, ArrayList *arrayMaster, ArrayList *arrayVisa, ArrayList *arrayAmerican, ArrayList *arrayInvalid);
int controller_validate(Client *pClient);
void controller_printList(ArrayList *arrayClient);
int validateCard(Client *pclient);
void controller_printError(ArrayList *arrayClient);


