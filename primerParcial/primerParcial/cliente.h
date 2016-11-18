#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int dni;
    char nombre[51];
    char apellido[51];
    int idCliente;
}Cliente;
#endif // CLIENTE_H_INCLUDED

Cliente* cliente_new(void);
void cliente_free(Cliente this);
int cliente_setDni(Cliente *this, int *dni);
int cliente_getDni(Cliente *this);
int cliente_setNombre(Cliente *this, char *nombre);
char* cliente_getNombre(Cliente *this);
int cliente_setApellido(Cliente *this, char *apellido);
char* cliente_getApellido(Cliente *this);
int cliente_setIdCliente(Cliente *this, int *id);
int cliente_getIdCliente(Cliente *this);
