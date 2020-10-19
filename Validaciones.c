#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Bicicleta.h"
#define TRUE 1
#define FALSE 0
#define TAMRODADO 4
#define MAXLENGHSTRING 20

float rodadosValidos[] = {20,26,27.5,29};
int validaciones_validarRodado(float idRodado)
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
    return (BuscarServicioPos(servicios,tam,idServicio) >=0);
}

int validaciones_ValidarBicicleta(eBicicleta bicis[], int tam, int idBicicleta)
{
    return (BuscarPosById(bicis,tam,idBicicleta) >= 0);
}


int validaciones_ValidarColorValido(eColor colores[], int tam, int id)
{
    return (BuscarPosColor(colores,tam, id) >=0);

}

int validaciones_stringValidation(char * str)
{
    if(strlen(str) <= MAXLENGHSTRING)
    {

        int i = 0;
        while (str[i] != '\0')
        {
            // Si no es del alfabeto y no es un espacio regresamos false o 0
            if (!isalpha(str[i]) )// El espacio no cuenta como válido
            {
                return FALSE ;
            }
            i++;
        }
    }
    else
    {
        return FALSE;
    }
    // Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1
    return TRUE;
}

int validaciones_ValidarTipoValido(eTipo tipos[], int tam, int id)
{
   return (BuscarPosTipo(tipos,tam,id) >= 0);
}
