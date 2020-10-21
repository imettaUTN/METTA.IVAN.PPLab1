#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED
#include "Servicios.h"
#include "Trabajo.h"

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

eBicicleta vBicicletas[] =
{
    {1,"aa",1000,5000,1,20},
    {2,"bb",1001,5001,2,20},
    {3,"cc",1002,5000,3,27.5},
    {4,"dd",1003,5003,4,29}
};
#endif // DATASTORE_H_INCLUDED
