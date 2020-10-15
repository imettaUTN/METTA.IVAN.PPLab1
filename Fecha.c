#include "Fecha.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0
void MostrarFecha(eFecha fecha)
{
    printf("Anio:%d / Mes:%d / Dia:%d",fecha.anio,fecha.mes,fecha.dia);
}

eFecha NewFecha()
{
    eFecha f;
    int anio,mes,dia;
    int valid = TRUE;

    do
    {
        valid = TRUE;
        if(!valid)
        {
            printf("Dato invalido, reingrese");
        }
        printf("Ingrese anio \n");
        scanf("%d",&f.anio);
        if(f.anio < 1900)
        {
            valid = FALSE;
        }

        printf("Ingrese mes \n");
        scanf("%d",&f.mes);
        if(f.mes < 1 || f.mes > 12)
        {
            valid = FALSE;
        }

        printf("Ingrese dia \n");
        scanf("%d",&f.dia);
        if(f.dia < 1 || f.dia > 31)
        {
            valid = FALSE;
        }
    }while(!valid);

    return f;
}
