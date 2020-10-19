#include "Tipo.h"
#include <stdio.h>
#include <string.h>
#include "Validaciones.h"
#define TRUE 1
#define FALSE 0
void ListarTipos(eTipo tipos[],int tam)
{
    printf("ID:   Descripcion:\n");
    for(int i = 0;i < tam; i++)
    {
        printf("%d  %s\n",tipos[i].id,tipos[i].descripcion);
    }
}

char * MostrarTipo(eTipo tipos[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(tipos[i].id == id)
        {
            return tipos[i].descripcion;
        }
    }
    return "";
}
int ALTATIPO(eTipo tipos[], int tam )
{
    int id;
    char descripcion[20];
    printf("Ingrese id del tipo de bicicleta\n");
    scanf("%d",&id);

    while(id < 0|| ExisteIdTipo(tipos,tam,id))
    {
        printf("id invalido. Reingrese id del tipo de bicicleta \n");
       scanf("%d",&id);
    }

    printf("Ingrese la descripcion del tipo de bicicleta \n");
    fflush(stdin);
    gets(descripcion);


    while(!validaciones_stringValidation(descripcion))
    {
        printf("descripcion invalida, reingrese\n");
        fflush(stdin);
        gets(descripcion);
    }

    int index = BuscarIdLibreTipo(tipos,tam);
    if(index < 0)
    {
        return TRUE;
    }
    tipos[index].id = id;
    strcpy(tipos[index].descripcion,descripcion);
    return FALSE;
}


int ExisteIdTipo(eTipo tipos[], int tam, int ID)
{
    for(int i = 0; i <tam; i++)
    {
        if(tipos[i].id == ID)
        {
            printf("ID ya existente \n");
            return TRUE;
        }
    }
    return FALSE;
}

int BAJATIPO(eTipo tipos[], int tam, int idTipo)
{
    int pos = BuscarPosTipo(tipos,tam,idTipo);

    if(pos <0)
    {
        return TRUE;
    }
    int borra = 0;
    printf("Esta seguro que quiere dar de baja el tipo de bicicleta : %", tipos[pos].descripcion);
    if(borra)
    {
        tipos[pos].id = -1;
        printf("Tipo de bicicleta dado de baja \n");
        return FALSE;
    }
    return TRUE;
}


int MODIFICARTIPO(eTipo tipos[], int tam, int idTipo)
{
    int pos = BuscarPosTipo(tipos,tam,idTipo);
    if(pos <0) {return TRUE;}
    int borra = 0;
    char descripcion[20];
    printf("Esta seguro que quiere modificar el tipo de bicleta : %", tipos[pos].descripcion);
    if(borra)
    {
        printf("Ingrese la descripcion del tipo de bicicleta \n");
        fflush(stdin);
        gets(descripcion);

        while(!validaciones_stringValidation(descripcion))
        {
            printf("Descripcion invalida, reingrese\n");
            fflush(stdin);
            gets(descripcion);
        }
        strcpy(tipos[pos].descripcion, descripcion);
        return FALSE;
    }
    return TRUE;
}


int BuscarIdLibreTipo(eTipo tipos[], int tam )
{
     for(int i = 0; i < tam ; i++)
    {
        if(tipos[i].id <0)
        {
            return i;
        }
    }
    printf("Lista llena . No hay mas lugar\n");
    return -1;
}


void InicializarTip(eTipo tipos[], int tam )
{
    for(int i =0; i<tam; i++ )
    {
        tipos[i].id = -1;
    }
}


int BuscarPosTipo(eTipo tipos[], int tam,int id)
{
     for(int i =0; i<tam; i++ )
    {
        if(tipos[i].id == id)
        {
            return i;
        }
    }
    printf("No se encuentra el id en la lista \n");
    return -1;
}

