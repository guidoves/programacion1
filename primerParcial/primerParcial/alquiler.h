#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
typedef struct
{
    int idCliente;
    int equipo;
    int estado;
    char operador[];
    int tiempoEstimado;
    int tiempoReal;

}Alquiler;
#endif // ALQUILER_H_INCLUDED

Alquiler* cliente_new(void);
void alquiler_free(Alquiler* this);
int alquiler_setIdCliente(Alquiler *this, int *id);
int alquiler_getIdCliente(Alquiler *this);
int alquiler_setEquipo(Alquiler *this, int *equipo);
int alquiler_getEquipo(Alquiler *this);
int alquiler_setEstado(Alquiler *this, int *estado);
int alquiler_getEstado(Alquiler *this);
