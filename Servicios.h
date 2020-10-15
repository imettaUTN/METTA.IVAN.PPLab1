#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
int id;
    char descripcion[20];
    float precio;
}eServicio;

void listarServicios(eServicio servicios[], int tam);
void mostrarServicio(eServicio servicios[], int pos);
void mostrarServicioById(eServicio servicios[],int tam, int id);
int BuscarServicioPosById(eServicio servicios[], int tam , int id);

#endif // SERVICIOS_H_INCLUDED
