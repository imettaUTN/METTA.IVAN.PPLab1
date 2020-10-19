#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

void MostrarFecha(eFecha fecha);
eFecha crearFecha();
eFecha getFechaActual();
#endif // FECHA_H_INCLUDED
