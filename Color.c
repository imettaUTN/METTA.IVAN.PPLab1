#include "Color.h"
#include <stdio.h>
#include <string.h>
#include "Validaciones.h"
#define TRUE 1
#define FALSE 0

void ListarColores(eColor colores[],int tam)
{   printf("ID:    Nombre:\n");
    for(int i = 0;i < tam; i++)
    {
        printf("%d  %s\n",colores[i].id,colores[i].nombreColor);
    }
}


char * MostrarColor(eColor colores[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(colores[i].id == id)
        {
            return colores[i].nombreColor;
        }
    }
    return "";
}

int ALTACOLOR(eColor colores[], int tam )
{
    int id;
    char nombre[20];
    printf("Ingrese id del color \n");
    scanf("%d",&id);

    while(id < 0 || ExisteIdColor(colores,tam,id))
    {
        printf("id invalido. Reingrese id del color \n");
       scanf("%d",&id);
    }

    printf("Ingrese el nombre del color \n");
    fflush(stdin);
    gets(nombre);


    while(!validaciones_stringValidation(nombre))
    {
        printf("Nombre invalido, reingrese\n");
        fflush(stdin);
        gets(nombre);
    }
    int index = BuscarIdLibreColor(colores,tam);

    if(index <0){ return TRUE;}
    colores[index].id = id;
    strcpy(colores[index].nombreColor, nombre);
    return FALSE;

}

int BAJACOLOR(eColor colores[], int tam , int idColor)
{
    int pos = BuscarPosColor(colores,tam,idColor);
    if(pos <0)
    {
        return TRUE;
    }
    int borra = 0;
    printf("Esta seguro que quiere dar de baja el color : %", colores[pos].nombreColor);
    if(borra)
    {
        colores[pos].id = -1;
        printf("Color dado de baja \n");
        return FALSE;
    }
    return TRUE;
}


int MODIFICARCOLOR(eColor colores[], int tam , int idColor)
{
    int pos = BuscarPosColor(colores,tam,idColor);
    if(pos <0) {return TRUE;}
    int borra = 0;
    char nombre[20];
    printf("Esta seguro que quiere modificar el color : %", colores[pos].nombreColor);
    if(borra)
    {
        printf("Ingrese el nombre del color \n");
        fflush(stdin);

        gets(nombre);

        while(!validaciones_stringValidation(nombre))
        {
            printf("Nombre invalido, reingrese\n");
            fflush(stdin);
            gets(nombre);
        }
        strcpy(colores[pos].nombreColor, nombre);
        return FALSE;
    }
    return TRUE;
}


int ExisteIdColor(eColor colores[], int tam, int ID)
{
    for(int i = 0; i <tam; i++)
    {
        if(colores[i].id == ID)
        {
            printf("ID ya existente \n");
            return TRUE;
        }
    }
    return FALSE;
}

int BuscarIdLibreColor(eColor colores[], int tam )
{
     for(int i = 0; i < tam ; i++)
    {
        if(colores[i].id <0)
        {
            return i;
        }
    }
    printf("Lista llena . No hay mas lugar\n");
    return -1;
}


void InicializarColores(eColor colores[], int tam )
{
    for(int i =0; i<tam; i++ )
    {
        colores[i].id = -1;
    }
}

int BuscarPosColor(eColor colores[], int tam ,int id)
{
    for(int i =0; i<tam; i++ )
    {
        if(colores[i].id == id)
        {
            return i;
        }
    }
    printf("No se encuentra el id en la lista \n");
    return -1;
}
