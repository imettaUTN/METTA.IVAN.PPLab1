#include "Fecha.h"
#include <stdio.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
void MostrarFecha(eFecha fecha)
{
    printf("%d/%d/%d \n",fecha.anio,fecha.mes,fecha.dia);
}

eFecha crearFecha()
{
    int dia,mes,anio;
    printf("Ingrese anio \n");
    scanf("%d",&anio);

    while(anio < 1900)
    {
        printf("Anio invalido. reingrese \n");
        scanf("%d",&anio);
    }

    printf("Ingrese mes \n");
    scanf("%d",&mes);


    printf("Ingrese dia \n");
    scanf("%d",&dia);
    // primero valido la cantid de dias del mes
    while(mes < 1 || mes > 12)
    {
        printf("Mes invalido, reingrese\n");
        scanf("%d",&mes);

    }
    switch(mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        while(dia == 31)
        {
            printf("El mes no puede tener 31 dias. Reingrese dia\n");
            scanf("%d",&dia);
        }
    }
    // luego valido la cant de dias
    while(dia < 1 || dia > 31)
    {
        printf("Dia invalido, reingrese\n");
        scanf("%d",&dia);

    }
    eFecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;
}

