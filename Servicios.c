#include "Servicios.h"
#include <string.h>
#include <stdio.h>


void listarServicios(eServicio servicios[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        mostrarServicio(servicios,i);
    }
}

void mostrarServicio(eServicio servicios[], int pos)
{
    printf("ID%d DESCRIPCION%s PRECIO %.2f", servicios[pos].id,servicios[pos].descripcion,servicios[pos].precio);
}

int BuscarServicioPosById(eServicio servicios[], int tam , int id)
{
    for(int i = 0; i< tam; i++)
    {
        if(servicios[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarServicioById(eServicio servicios[],int tam, int id)
{
    for(int i =0; i< tam; i++)
    {
        if(servicios[i].id = id)
        {
            mostrarServicio(servicios,i);
        }
    }
}
