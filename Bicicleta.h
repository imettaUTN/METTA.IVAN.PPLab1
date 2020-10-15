#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "Servicios.h"
#include "Color.h"
#include "Tipo.h"
typedef struct
{   int id;
    char marca[20];
    int idTipo;
    int idColor;
    int rodado;
} eBicicleta;


int BuscarIdLibre(eBicicleta bicicletas[], int tam);

void inicializarVectores(eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],int tamB, int tamT, int tamC, int tamS);

char * MostrarColor(eColor colores[],int tam, int id);

int BuscarBicicletaPosById(eBicicleta bicicletas[], int tam, int id);

void MOSTRARBICI(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int i, int tam, int tamT, int tamC);

int MODIFICAR(eBicicleta bicicletas[], int id, eTipo tipos[], int tamB, int tamT);

int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamB, int tamC, int tamT);

int BAJA(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int id, int tamB, int tamT, int tamC);

void OrdenarBicicletas(eBicicleta bicis[], int tam);

void ListarBicicletas(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int tamBici, int tamTipo, int tamColor);

void makeSwap(eBicicleta list[], int i, int j);
#endif // BICICLETA_H_INCLUDED
