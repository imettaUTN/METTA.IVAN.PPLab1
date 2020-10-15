#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

void InicializarColores(eColor colores[],int tam);

void ListarColores(eColor colores[],int tam);

char * MostrarColor(eColor colores[],int tam, int id);


#endif // COLOR_H_INCLUDED
