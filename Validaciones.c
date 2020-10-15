#include "Validaciones.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Bicicleta.h"
#define TRUE 1
#define FALSE 0
#define TAMRODADO 4

float rodadosValidos[] = {20,26,27.5,29};
int validaciones_validarRodado(int idRodado)
{
    for(int i = 0; i< TAMRODADO; i++)
    {
        if(rodadosValidos[i] == idRodado)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int validaciones_ValidarServicio(eServicio servicios[], int tam, int idServicio)
{
    if(BuscarServicioPosById(servicios,tam,idServicio))
    {
        return TRUE;
    }
    return FALSE;
}

int validaciones_ValidarBicicleta(eBicicleta bicis[], int tam, int idBicicleta)
{
/*    if(BuscarBicicletaPosById(bicis,tam,idBicicleta))
    {
        return TRUE;
    }*/
    return FALSE;
}


int validaciones_ValidarColorValido(eColor colores[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(colores[i].id == id)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int validaciones_ValidarTipoValido(eTipo tipos[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(tipos[i].id == id)
        {
            return TRUE;
        }
    }

    return FALSE;
}
