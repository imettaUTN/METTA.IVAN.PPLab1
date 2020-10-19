#include "Tipo.h"
#include <stdio.h>
#include <string.h>
#include "Validaciones.h"
#define TRUE 1
#define FALSE 0
void ListarTipos(eTipo tipos[],int tam)
{
    printf("\n");
    printf("ID:   Descripcion:\n");
    printf("----------------------\n");
    for(int i = 0;i < tam; i++)
    {
       printf("%d  %s\n",tipos[i].id,tipos[i].descripcion);
    }
}

char * MostrarTipo(eTipo tipos[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(tipos[i].id == id)
        {
            return tipos[i].descripcion;
        }
    }
    return "";
}


int BuscarPosTipo(eTipo tipos[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(tipos[i].id == id)
        {
            return i;
        }
    }
    printf("tipo bicicleta no se encuentra \n");
    return -1;
}

