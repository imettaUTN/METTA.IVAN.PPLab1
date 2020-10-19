#include "Servicios.h"
#include <string.h>
#include <stdio.h>
#include "Validaciones.h"
#include "Common.h"
#define TRUE 1
#define FALSE 0

void listarServicios(eServicio servicios[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        mostrarServicio(servicios,i);
    }
}

void mostrarServicio(eServicio servicios[], int pos)
{
    printf("ID      DESCRIPCION     PRECIO\n");
    printf("%d   %s             %.2f\n", servicios[pos].id,servicios[pos].descripcion,servicios[pos].precio);
}

int BuscarServicioPosById(eServicio servicios[], int tam, int id)
{
    for(int i = 0; i< tam; i++)
    {
        if(servicios[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarServicioById(eServicio servicios[],int tam, int id)
{
    int pos = BuscarServicioPosById(servicios,tam,id);

    mostrarServicio(servicios,pos);
}


int ALTASERVICOO(eServicio servicios[], int tam )
{
    int id;
    char nombre[20];
    float precio;
    printf("Ingrese id del servicio \n");
    scanf("%d",&id);

    while(id < 0 || ExisteIdServicio(servicios,tam,id))
    {
        printf("id invalido. Reingrese id del servicio \n");
        scanf("%d",&id);
    }

    printf("Ingrese la descripcion del servicio \n");
    fflush(stdin);
    gets(nombre);


    while(!validaciones_stringValidation(nombre))
    {
        printf("Nombre invalido, reingrese\n");
        fflush(stdin);
        gets(nombre);
    }

    printf("Ingrese  precio \n");
    scanf("%f",&precio);
    while(precio < 0)
    {
        printf("Precio invalido.Reingrese  precio \n");
        scanf("%f",&precio);
    }
    int index = BuscarIdLibreServicio(servicios,tam);
    if(index <0) {return TRUE;}
    servicios[index].id = id;
    strcpy(servicios[index].descripcion, nombre);
    servicios[index].precio = precio;
    return FALSE;

}

int BAJASERVICIO(eServicio servicios[], int tam, int idServ)
{
    int pos = BuscarPosServicio(servicios,tam,idServ);
    if(pos <0){return TRUE;}
    int borra = 0;
    printf("Esta seguro que quiere dar de baja el servcio \n");
    mostrarServicioById(servicios,tam,idServ);
    if(borra)
    {
        servicios[pos].id = -1;
        printf("Servicio dado de baja \n");
        return FALSE;
    }
    return TRUE;
}


int MODIFICARSERVICIO(eServicio servicios[], int tam, int idServ)
{
    int pos = BuscarPosServicio(servicios,tam,idServ);
    if(pos <0){return TRUE;}
    int borra = 0;
    char desc[20];
     printf("Esta seguro que quiere modificar el servcio \n");
    mostrarServicioById(servicios,tam,idServ);
    scanf("%d",&borra);
    if(borra)
    {
        int  opcion =common_getMenu("1 Modifica Descripcio \n2 Modifica Precio\n","Opcion invalida. Reingrese",1,2,3);
        if(opcion ==1 )
        {
            while(!validaciones_stringValidation(desc))
            {
                printf("Nombre invalido, reingrese\n");
                fflush(stdin);
                gets(desc);
            }
            strcpy(servicios[pos].descripcion, desc);
            return FALSE;
        }
        else
        {
            float precio;
            printf("Ingrese nuevo precio \n");
            scanf("%f",&precio);
            while(precio < 0)
            {
                printf("Precio invalido.Reingrese nuevo precio \n");
                scanf("%f",&precio);
            }
            servicios[pos].precio = precio;
            return FALSE;
        }
    }


return TRUE;
}



int BuscarIdLibreServicio(eServicio servicios[], int tam )
{
    for(int i = 0; i < tam ; i++)
    {
        if(servicios[i].id <0)
        {
            return i;
        }
    }
    printf("Lista llena . No hay mas lugar\n");
    return -1;
}


void InicializarServicio(eServicio servicios[], int tam )
{
    for(int i =0; i<tam; i++ )
    {
        servicios[i].id = -1;
    }
}



int ExisteIdServicio(eServicio servicios[], int tam, int ID)
{
    for(int i = 0; i <tam; i++)
    {
        if(servicios[i].id == ID)
        {
            printf("ID ya existente \n");
            return TRUE;
        }
    }
    return FALSE;
}

int BuscarPosServicio(eServicio servicios[], int tam,int id)
{
    for(int i =0; i<tam; i++ )
    {
        if(servicios[i].id == id)
        {
            return i;
        }
    }
    printf("No se encuentra el id en la lista \n");
    return -1;
}
