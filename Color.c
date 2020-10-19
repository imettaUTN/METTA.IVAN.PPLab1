#include "Color.h"
#include <stdio.h>
#include <string.h>
#include "Validaciones.h"
#define TRUE 1
#define FALSE 0

void ListarColores(eColor colores[],int tam)
{
    printf("\n");
    printf("ID:    Nombre:\n");
    printf("-------------------------\n");
    for(int i = 0;i < tam; i++)
    {
         printf("%d  %s\n",colores[i].id,colores[i].nombreColor);
    }
}

char * MostrarColor(eColor colores[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(colores[i].id == id)
        {
            return colores[i].nombreColor;
        }
    }
    return "";
}


int BuscarPosColor(eColor colores[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(colores[i].id == id)
        {
            return i;
        }
    }
    printf("color bicicleta no se encuentra\n");
    return -1;
}
