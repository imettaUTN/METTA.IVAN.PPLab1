#include <stdio.h>
#include <stdlib.h>
#include "Trabajo.h"
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Servicios.h"
#define TRUE 1
#define FALSE 0

void listarTrabajos(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eServicio servicios[], int tamTrabajo,int tamBici, int tamTipo, int tamColor, int tamServ)
{
    for(int i = 0; i< tamTrabajo; i++)
    {
        mostrarTrabajo(trabajos,bicicletas,tipos,colores,servicios,tamTrabajo,tamBici,tamTipo,tamColor,tamServ,i);
    }
}

void mostrarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamBici, int tamTipo, int tamColor, int tamServ, int pos)
{
    printf("ID Trabajo: %d\n",trabajos[pos].id);
    printf("Fecha \n");
    MostrarFecha(trabajos[pos].fecha);
    printf("Bicicleta:\n");
    MOSTRARBICI(bicicletas,tipos,colores,trabajos[pos].idBicicleta,tamBici,tamTipo,tamColor);
    printf("Servicio realizado: \n");
    mostrarServicioById(servicios,tamServ,trabajos[pos].idServicio);
}

int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].id <0)
        {
            return i;
        }
    }
    return -1;
}

int BuscarProximoId(eTrabajo trabajos[], int tam)
{
    for(int i =0; i< tam ; i++)
    {
        if(trabajos[i].id <0)
        {
            if(i == 0)
            {
                return 0;
            }
            return (trabajos[i-1].id + 1);
        }
    }
    return 0;
}

int AltaTrabajo(eTrabajo trabajos[], int idBici, int idServicio, int tam)
{
    if(trabajos == NULL || tam <0)
    {
        printf("Lista trabajo vacia\n");
        return TRUE;
    }

    eTrabajo trabajo;
    trabajo.fecha = NewFecha();
    trabajo.id =BuscarProximoId(trabajos, tam);
    trabajo.idBicicleta = idBici;
    trabajo.idServicio = idServicio;
    trabajos[BuscarIdTrabajoLibre(trabajos,tam)] = trabajo;
    return FALSE;
}


