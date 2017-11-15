#include "controller.h"

int controller_altaEntrega(eEntrega* pEntrega, int num)
{
    int retorno = -1;
    char direccion[51];
    int altura;
    if(pEntrega != NULL && num > 0)
    {
        retorno = getValidString("Ingrese la direccion de entrega: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.",direccion,50,3);
        if(!retorno)
        {
            retorno = getValidInt("Ingrese la altura: ","Ingreso invalido.\n",&altura,0,9999,3);
            if(!retorno)
            {
                entrega_setDireccion(pEntrega,direccion);
                entrega_setAltura(pEntrega,altura);
                entrega_setNumDespacho(pEntrega,num);
            }
        }
    }
    return retorno;
}


int controller_ordenarEntregas(void* entregaA,void* entregaB)
{
    if(strcmp(((eEntrega*)entregaA)->direccion,((eEntrega*)entregaB)->direccion)>0)
    {
        return 1;
    }
    if(strcmp(((eEntrega*)entregaA)->direccion,((eEntrega*)entregaB)->direccion)<0)
    {
        return -1;
    }
    return 0;
}

eEntrega* controller_proximaEntrega(ArrayList *pArrayEntregas)
{
    eEntrega* pEntrega = NULL;
    int i;
    if(pArrayEntregas != NULL && !(al_isEmpty(pArrayEntregas)))
    {
        for(i=0;i<(al_len(pArrayEntregas));i++)
        {
            pEntrega = al_pop(pArrayEntregas,i);
            if(pEntrega != NULL)
            {
                printf("Proxima entrega:\nNumero de despacho %d\nDireccion %s %d\n",entrega_getNumDespacho(pEntrega),entrega_getDireccion(pEntrega),entrega_getAltura(pEntrega));
                break;
            }
        }
    }
    return pEntrega;
}

int controller_listar(ArrayList *pArrayEntregas,char* texto)
{
    int retorno = -1,i;
    eEntrega* pEntrega;
    if(pArrayEntregas != NULL && !(al_isEmpty(pArrayEntregas)))
    {
        retorno = 0;
        printf(texto);
        for(i=0;i<(al_len(pArrayEntregas));i++)
        {
            pEntrega = al_get(pArrayEntregas,i);
            if(pEntrega != NULL)
            {
                printf("Numero de despacho: %d | Direccion: %s %d\n",pEntrega->numDespacho,pEntrega->direccion,pEntrega->altura);
            }
        }
    }
    return retorno;
}

int controller_otorgarNumero(ArrayList *pArrayNumeros)
{
    int retorno = -1;
    eNumeros *auxNum;
    if(pArrayNumeros != NULL)
    {
        auxNum = numeros_new();
        numeros_setNumero(auxNum,pArrayNumeros->size+1);
        al_add(pArrayNumeros,auxNum);
        retorno = numeros_getNumero(auxNum);
    }
    return retorno;
}

//int controller_cargarArchivo(ArrayList* pArrayList, char* path)
//{
//    int retorno = -1,i;
//    FILE* pFile;
//    eEntrega* aux;
//    int numDespacho;
//    char direccion[51];
//    int altura;
//
//    if(pArrayList != NULL)
//    {
//        pFile = fopen(path,"r");
//        for(i=0;i<al_len(pArrayList);i++)
//        {
//
//            aux = al_get(pArrayList,i);
//            numDespacho = entrega_getNumDespacho(aux);
//            altura = entrega_getAltura(aux);
//            strcpy(direccion,entrega_getDireccion(aux));
//
//            fprintf(pFile,"%d",numDespacho);
//            fprintf(pFile,"%d",altura);
//            fprintf(pFile,"%s",direccion);
//
//
//        }
//        fclose(pFile);
//        retorno = 0;
//    }
//    return retorno;
//
//}

int controller_guardarArchivo(ArrayList *pArrayList,char* path)
{
    int retorno = -1,i;
    FILE* pFile;
    eEntrega* aux;
    int numDespacho;
    char direccion[51];
    int altura;

    if(pArrayList != NULL)
    {
        pFile = fopen(path,"w");
        for(i=0;i<al_len(pArrayList);i++)
        {

            aux = al_get(pArrayList,i);
            numDespacho = entrega_getNumDespacho(aux);
            altura = entrega_getAltura(aux);
            strcpy(direccion,entrega_getDireccion(aux));

            fprintf(pFile,"%d",numDespacho);
            fprintf(pFile,"%s",",");
            fprintf(pFile,"%d",altura);
            fprintf(pFile,"%s",",");
            fprintf(pFile,"%s",direccion);
            fprintf(pFile,"%s","\n");
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

//int verArchivo(void)
//{
//    FILE *pfile;
//    char buffer[100];
//    pfile = fopen("texto.txt","r");
//    fread(buffer,char,100,pfile);
//    printf("%s",buffer);
//    fclose(pfile);
//}

