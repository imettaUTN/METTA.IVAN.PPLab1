#include <stdio.h>
#include <string.h>
#include "Tipo.h"
#include "DataStore.h"

void InicializarTipo(eTipo tipos[],int tam)
{
    int id = 1000;
    for(int i = 0;i < tam; i++)
    {
        tipos[i].id = id;
        strcpy(tipos[i].descripcion, vTipo[i]);
        id++;
    }
}
void ListarTipos(eTipo tipos[],int tam)
{
    for(int i = 0;i < tam; i++)
    {
        printf("ID %d   Descripcion%s\n",tipos[i].id,tipos[i].descripcion);
    }
}

void MostrarTipo(eTipo tipos[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(tipos[i].id == id)
        {
            printf("Tipo %s\n",tipos[i].descripcion);
        }
    }

}
