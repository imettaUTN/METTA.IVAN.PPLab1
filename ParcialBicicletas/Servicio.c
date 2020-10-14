#include "Servicio.h"
#include "DataStore.h"
#include "DataStore.h"
#include <string.h>
#include <stdio.h>
void InicializarServicios(eServicio servicio[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {

        servicio[i].id = vServicios[i].id;
        strcpy(servicio[i].descripcion,vServicios[i].descripcion);
        servicio[i].precio = vServicios[i].precio;
    }
}

void listarServicios(eServicio servicios[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        mostrarServicio(servicios,i);
    }
}

void mostrarServicio(eServicio servicios[], int pos)
void mostrarServicio(eServicio servicios[], int pos)
{
    printf("ID%d DESCRIPCION%s PRECIO %.2f", servicios[pos].id,servicios[pos].descripcion,servicios[pos].precio);
}
