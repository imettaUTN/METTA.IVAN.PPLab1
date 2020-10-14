#include <stdio.h>
#include <string.h>
#include "Bicicleta.h"
#include "DataStore.h"
#include "Tipo.h"
#include "Color.h"
#include "Common.h"
int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamB, int tamC, int tamT)
{
    int idTipo;
    int idColor;
    int id;
    int idRodado;
    char marca[20];
    eBicicleta bici ;
    int pos = BuscarIdLibre(bicicletas,tamB);

    printf("Ingrese ID mayor a  0\n");
    scanf(&id);

    if(id <0)
    {
        printf("Id invalido");
        return FALSE;
    }

    printf("Ingrese marca\n");
    fflush(stdin);
    gets(marca);

    printf("indique el tipo de bicicleta\n");
    ListarTipos(tipos,tamT);
    scanf(&idTipo);
    if(!common_ValidarTipoValido(tipos,tamT,idTipo))
    {
        printf("Tipo seleccionado Invalido\n")
        return TRUE;
    }
    printf("indique el color de la bicicleta\n");

    ListarColores(colores,tamC);
    scanf(&idColor);
    if(!common_ValidarTipoValido(colores,tamC,idColor))
    {
        printf("Color seleccionado Invalido\n")
        return TRUE;
    }

    printf("Ingrese rodado \n");
    scanf(&idRodado;
    if(!common_validarRodado(idRodado))
    {
       printf("Rodado invalido");
       return TRUE;
    }

    bici.id = id;
    bici.idColor = idColor;
    bici.idTipo = idTipo;
    strcpy(bici.marca, marca);
    bici.rodado = rodado;

    bicicletas[pos] = bici;

    return FALSE;
}

int BAJA(eBicicleta bicicletas[], int id, int tamB)
{
    int borra
    for(int i =0; i< tamB; i++)
    {
        if(bicicletas[i].id == id)
        {
            printf("Esta seguro que desa dar de baja la siguiente bici? SI 1, NO 0")
            MOSTRARBICI(bicicletas,i, int tam, int tamT, int tamC);
            scanf(&borra);
            if(borra)
            {
                bicicletas[i].id = -1;
                printf("Bicicleta dada de baja");
            }
        }
    }
}


void MOSTRARBICI(eBicicleta bicicletas[], int i, int tam, int tamT, int tamC)
{
    printf("ID%s  MARCA %s  TIPO%s   COLOR%s   RODADO$d\n",bicicletas[i].id,bicicletas[i].marca,MostrarTipo(bicicletas[i].idTipo, tamT),MostrarColor(bicicletas[i].idColor,tamC),bicicletas[i].rodado);

}

int MODIFICAR(eBicicleta bicicletas[], int id, eTipo tipos[], int tamB, int tamT)
{
    int pos = BuscarPosById(bicicletas,tamB,id);

    int  opcion =common_getMenu("1 Modifica Tipo\n 2 Modifica Rodado\n","Opcion invalida. Reingrese",1,2,3);

    if(opcion == 1)
    {
        int idTipo;
        printf("indique el tipo de bicicleta a modificar\n");
        ListarTipos(tipos,tamT);
        scanf(&idTipo);
        if(!common_ValidarTipoValido(tipos,tamT,idTipo))
        {
            printf("Tipo seleccionado Invalido\n")
            return TRUE;
        }
        bicicletas[pos].idTipo = idTipo;

    }
    else
    {
        int idRodado;
        printf("Ingrese rodado a modificar \n");
        scanf(&idRodado;
        if(!common_validarRodado(idRodado))
        {
           printf("Rodado invalido");
           return TRUE;
        }
        bicicletas[pos].rodado = idRodado;
    }

    return FALSE;
}


void InicializarBici(eBicicleta bicicletas[], int tam)
{
    for(int i = 0;i < tam ; i++)
    {
        bicicletas[i].id = -1;
    }
}

int BuscarPosById(eBicicleta bicicletas[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(bicicletas[i].id == id)
        {
            return i;
        }
    }

    return 0;
}


int BuscarIdLibre(eBicicleta bicicletas[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        if(bicicletas[i].id <0)
        {
            return i;
        }
    }
    return 0;
}

