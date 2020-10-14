#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

void InicializarTipo(eTipo tipos[],int tam);
void ListarTipos(eTipo tipos[],int tam);
void MostrarTipo(eTipo tipos[],int tam, int id);
#endif // TIPO_H_INCLUDED
