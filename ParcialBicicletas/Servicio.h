#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eServicio;

void listarServicios(eServicio servicios, int tam);
void mostrarServicio(eServicio servicios, int pos);

#endif // SERVICIO_H_INCLUDED
