#include <stdio.h>
#include <string.h>
#include "DataStore.h"
#include "Color.h"
void InicializarColores(eColor colores[],int tam)
{
    int id = 1000;
    for(int i = 0;i < tam; i++)
    {
        colores[i].id = id;
        strcpy(colores[i].nombreColor, vTipos[i]);
        id++;
    }
}
void ListarColores(eColor colores[],int tam)
{
    for(int i = 0;i < tam; i++)
    {
        printf("ID %d   Nombre%s\n",colores[i].id,colores[i].nombreColor);
    }
}

void MostrarColor(eColor colores[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(colores[i].id == id)
        {
            printf("Color %s\n",colores[i].nombreColor);
        }
    }

}
