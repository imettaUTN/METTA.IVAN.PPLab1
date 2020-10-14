#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"
typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int rodado;
} eBicicleta;

int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamB, int tamC, int tamT)

int BuscarIdLibre(eBicicleta bicicletas[], int tam);

void InicializarBici(eBicicleta bicicletas[], int tam);

int BAJA(eBicicleta bicicletas[], int id, int tamB);

void MostrarColor(eColor colores[],int tam, int id);

int BuscarPosById(eBicicleta bicicletas[], int tam, int id);

void MOSTRARBICI(eBicicleta bicicletas[], int id, int tam, int tamT, int tamC);

int MODIFICAR(eBicicleta bicicletas[], int id,eColor colores[], eTipo tipos[], int tamB, int tamC, int tamT);
#endif // BICICLETA_H_INCLUDED
