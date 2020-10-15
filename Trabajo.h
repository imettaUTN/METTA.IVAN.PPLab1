#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Fecha.h"
#include "Color.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Servicios.h"
#include "Bicicleta.h"
typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;

} eTrabajo;


//void mostrarTrabajo(eTrabajo trabajos[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamBici, int tamTipo, int tamColor, int tamServ, int pos);

int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam);

int BuscarProximoId(eTrabajo trabajos[], int tam);

int AltaTrabajo(eTrabajo trabajos[], int idBici, int idServicio, int tam);


#endif // TRABAJO_H_INCLUDED
