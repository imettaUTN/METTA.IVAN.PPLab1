#include <stdio.h>
#include <stdlib.h>
#include "Trabajo.h"
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Validaciones.h"
#include "Servicios.h"
#include "DataStoreTrabajos.h"
#define TRUE 1
#define FALSE 0
#define TAMTrabajos 4

// tengo que usar un data store especial, porque si quiero incluir la inicializacion
//del vector trabajos en la entidad bicicleta.h
//me rompe por tener una referencia crusada con trabajo.h

void inicializarTrabajosBici(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        trabajos[i].isEmpaty = TRUE;
    }
    // datos harcodeados
    for(int i = 0; i< TAMTrabajos ; i++)
    {
        trabajos[i].isEmpaty = FALSE;
        trabajos[i].fecha = vTrabajos[i].fecha;
        trabajos[i].id = vTrabajos[i].id;
        trabajos[i].idBicicleta = vTrabajos[i].idBicicleta;
        trabajos[i].idServicio = vTrabajos[i].idServicio;
    }
}
void listarTrabajos(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eServicio servicios[], int tamTrabajo,int tamBicis, int tamTipo, int tamColor, int tamServ)
{
    if(trabajos == NULL || tamTrabajo <=0)
    {
        printf("Lista de trabajos vacia \n");
    }
    if(!ListaTrabajosVacia(trabajos,tamTrabajo))
    {
        for(int i = 0; i< tamTrabajo; i++)
        {
            if(!trabajos[i].isEmpaty)
            {
                mostrarTrabajo(trabajos,bicicletas,tipos,colores,servicios,tamTrabajo,tamBicis,tamTipo,tamColor,tamServ,i);
            }
        }
    }

}

int ListaTrabajosVacia(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        if(!trabajos[i].isEmpaty)
        {
            return FALSE;
        }
    }
    printf("Lista de trabajos vacia \n");
    return TRUE;
}

int mostrarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamBicis, int tamTipo, int tamColor, int tamServ, int pos)
{
    printf("\n");
    printf("ID Trabajo: %d\n",trabajos[pos].id);
    printf("------------------------\n");
    printf("\nFecha: \n");
    MostrarFecha(trabajos[pos].fecha);
    printf("\nBicicleta:\n");
    MOSTRARBICI(bicicletas,tipos,colores,bicicletas[pos].id,tamBicis,tamTipo,tamColor);
    printf("\nServicio realizado: \n");
    mostrarServicioById(servicios,tamServ,trabajos[pos].idServicio);
    printf("\n");
    return FALSE;
}

int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].isEmpaty)
        {
            return i;
        }
    }
     printf("Lista llena . No hay mas lugar\n");
    return -1;
}

int AltaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int id)
{
    eTrabajo trabajo;
    int idBici = 0;
    int idServicio = 0;

        printf("Ingrese el id de la bicicleta sobre la que se realizara el trabajo\n");
        ListarBicicletas(bicicletas,tipos,colores,tamBicis,tamTipos,tamColores);
        scanf("%d",&idBici);

        while(!validaciones_ValidarBicicleta(bicicletas,tamBicis,idBici))
        {
            printf("Id bicicleta invalido.Rengres el id de la bicicleta sobre la que se realizara el trabajo\n");
            ListarBicicletas(bicicletas,tipos,colores,tamBicis,tamTipos,tamColores);
            scanf("%d",&idBici);
        }
        printf("Ingrese el id de servicio a realizar \n");
        listarServicios(servicios,tamServ);
        scanf("%d",&idServicio);
        while(!validaciones_ValidarServicio(servicios,tamServ,idServicio))
        {
             printf("Id servicio invalido.Reingrese el id de servicio a realizar \n");
            listarServicios(servicios,tamServ);
            scanf("%d",&idServicio);
        }

    // encapsulo en la entidad fecha la obtencion de una fecha valida
    trabajo.fecha = crearFecha();
    trabajo.id =id;
    trabajo.idBicicleta= idBici;
    trabajo.idServicio = idServicio;
    int index =BuscarIdTrabajoLibre(trabajos,tamTrabajos);
    if(index <0){return TRUE;}
    trabajos[index] = trabajo;
    printf("Alta de trabajo correcta \n");
    return FALSE;
}

int buscarPosVecTrabajo(eTrabajo trabajos[], int tam ,int id)
{
    for(int i = 0; i< tam ; i++)
    {
        if(trabajos[i].id == id)
        {
            return i;
        }
    }
    return -1;
}


