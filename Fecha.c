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
    int valido = TRUE;
    int dia,mes,anio;

    printf("Ingrese dia \n");
    scanf("%d",&dia);
    while(dia < 1 || dia > 31)
    {
        printf("Dia invalido, reingrese\n");
        scanf("%d",&dia);

    }
    switch(mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        if(dia == 31)
        {
            while(dia == 31)
            {
                printf("El mes no puede tener 31 dias. Reingrese dia\n");

                scanf("%d",&dia);

            }
        }
    }
    printf("Ingrese mes \n");
    scanf("%d",&mes);

    while(mes < 1 || mes > 12)
    {
        printf("Mes invalido, reingrese\n");
        scanf("%d",&mes);

    }

    printf("Ingrese anio \n");
    scanf("%d",&anio);

    while(mes < 1 || mes > 12)
    {
        printf("Anio invalido. reingrese \n");
        scanf("%d",&anio);

    }
    eFecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;

}
eFecha getFechaActual()
{
    eFecha f;
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    f.dia =tm->tm_mday;
    f.mes = tm->tm_mon;
    f.anio =1900+tm->tm_year;
    return f;
}
