#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED
#include "Servicio.h"

char vTipo[4][20] =
{   "Rutera",
    "Carrera",
    "Mountain",
    "BMX"
};

char vColores[5][20]  =
{   "Gris",
    "Negro",
    "Blanco",
    "Azul",
    "Rojo"
};
eServicio vServicios[] =
{
    {20000,"Limpieza",250},
    {20001,"Parche",300},
    {20002,"Centrado",400},
    {20003,"Cadena",350}
};

#endif // DATASTORE_H_INCLUDED
