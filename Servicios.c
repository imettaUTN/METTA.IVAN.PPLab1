#include "Servicios.h"
#include <string.h>
#include <stdio.h>
#include "Validaciones.h"
#include "Common.h"
#define TRUE 1
#define FALSE 0

void listarServicios(eServicio servicios[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        mostrarServicio(servicios,i);
    }
}

void mostrarServicio(eServicio servicios[], int pos)
{
    printf("\n");
    printf("ID      DESCRIPCION     PRECIO\n");
    printf("------------------------\n");
    printf("%d   %s             %.2f\n", servicios[pos].id,servicios[pos].descripcion,servicios[pos].precio);
}

int BuscarServicioPos(eServicio servicios[], int tam, int id)
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
    int pos = BuscarServicioPos(servicios,tam,id);

    mostrarServicio(servicios,pos);
}
