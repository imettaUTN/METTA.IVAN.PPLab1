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
#include "Cliente.h"
#define TRUE 1
#define FALSE 0
#define TAMTrabajos 4

// tengo que usar un data store especial, porque si quiero incluir la inicializacion
//del vector trabajos en la entidad bicicleta.h
//me rompe por tener una referencia crusada con trabajo.h

void inicializarTrabajos(eTrabajo trabajos[], int tam, int cargaDatos)
{
    for(int i = 0; i< tam ; i++)
    {
        trabajos[i].isEmpty = TRUE;
    }
    if(cargaDatos)
    {
    // datos harcodeados
        for(int i = 0; i< TAMTrabajos ; i++)
        {
            trabajos[i].isEmpty = FALSE;
            trabajos[i].fecha = vTrabajos[i].fecha;
            trabajos[i].id = vTrabajos[i].id;
            trabajos[i].idBicicleta = vTrabajos[i].idBicicleta;
            trabajos[i].idServicio = vTrabajos[i].idServicio;
        }
    }
}
void listarTrabajos(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo,int tamBicis, int tamTipo, int tamColor, int tamServ, int tamCliente)
{
    if(trabajos == NULL || tamTrabajo <=0)
    {
        printf("Lista de trabajos vacia \n");
    }
    if(!ListaTrabajosVacia(trabajos,tamTrabajo))
    {
        for(int i = 0; i< tamTrabajo; i++)
        {
            if(!trabajos[i].isEmpty)
            {
               mostrarTrabajo(trabajos,bicicletas,tipos,colores,servicios,clientes,tamTrabajo,tamBicis,tamTipo,tamColor,tamServ,i,tamCliente);
            }
        }
    }

}


void listarTrabajosBici(eTrabajo trabajos[],eBicicleta bicicleta,eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo, int tamTipo, int tamColor, int tamServ,int tamClientes)
{
    if(trabajos == NULL || tamTrabajo <=0)
    {
        printf("Lista de trabajos vacia \n");
    }
    if(!ListaTrabajosVacia(trabajos,tamTrabajo))
    {
        for(int i = 0; i< tamTrabajo; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajoBici(trabajos,bicicleta,tipos,colores,servicios,clientes,tamTrabajo,tamTipo,tamColor,tamServ,i,tamClientes);
            }
        }
    }

}

int ListaTrabajosVacia(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            return FALSE;
        }
    }
    printf("Lista de trabajos vacia \n");
    return TRUE;
}

int mostrarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo, int tamBicis, int tamTipo, int tamColor, int tamServ, int pos, int tamClientes)
{
    printf("\n");
    printf("ID Trabajo: %d\n",trabajos[pos].id);
    printf("------------------------\n");
    printf("\nFecha: \n");
    MostrarFecha(trabajos[pos].fecha);
    printf("\nBicicleta:\n");
    MOSTRARBICI(bicicletas,tipos,colores,clientes,bicicletas[pos].id,tamBicis,tamTipo,tamColor,tamClientes);
    printf("\nServicio realizado: \n");
    mostrarServicioById(servicios,tamServ,trabajos[pos].idServicio);
    printf("\n");
    return FALSE;
}

int mostrarTrabajoBici(eTrabajo trabajos[],eBicicleta bicicleta, eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo,int tamTipo, int tamColor, int tamServ, int pos, int tamCliente)
{
    printf("\n");
    printf("ID Trabajo: %d\n",trabajos[pos].id);
    printf("------------------------\n");
    printf("\nFecha: \n");
    MostrarFecha(trabajos[pos].fecha);
    printf("\nBicicleta:\n");
    MOSTRARUNABICI(bicicleta,tipos,colores,clientes,tamTipo,tamColor,tamCliente);
    printf("\nServicio realizado: \n");
    mostrarServicioById(servicios,tamServ,trabajos[pos].idServicio);
    printf("\n");
    return FALSE;
}

int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].isEmpty)
        {
            return i;
        }
    }
     printf("Lista llena . No hay mas lugar\n");
    return -1;
}

int AltaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],eCliente clientes[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int id, int tamClientes)
{
    eTrabajo trabajo;
    int idBici = 0;
    int idServicio = 0;

        printf("Ingrese el id de la bicicleta sobre la que se realizara el trabajo\n");
        ListarBicicletas(bicicletas,tipos,colores,clientes,tamBicis,tamTipos,tamColores,tamClientes);
        scanf("%d",&idBici);

        while(!validaciones_ValidarBicicleta(bicicletas,tamBicis,idBici))
        {
            printf("Id bicicleta invalido.Rengres el id de la bicicleta sobre la que se realizara el trabajo\n");
            ListarBicicletas(bicicletas,tipos,colores,clientes,tamBicis,tamTipos,tamColores,tamClientes);
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

void ListarTrabajosRealizadosBici(eTrabajo trabajos[], int tamTrabajos, eBicicleta bicicletas[],eCliente clientes[],int tamBicis, eTipo tipos[],int tamTipos, eServicio servicios[], int tamServ, eColor colores[], int tamColores,int tamClientes)
{
    int idBici;
    int pos;
    printf("Seleccione id de la bicicleta cuyos trabajos quiere listar \n");
    ListarBicicletas(bicicletas,tipos,colores,clientes,tamBicis,tamTipos,tamColores,tamClientes);
    scanf("%d",&idBici);
    while(!validaciones_ValidarBicicleta(bicicletas,tamBicis,idBici))
    {
        printf("Id bicicleta invalido.Reingrese el id de la bicicleta cuyos trabajos quiere listar\n");
        ListarBicicletas(bicicletas,tipos,colores,clientes,tamBicis,tamTipos,tamColores,tamClientes);
        scanf("%d",&idBici);
    }
    pos = BuscarPosById(bicicletas,tamBicis,idBici);
    if(pos >=0)
    {
        eBicicleta bici = bicicletas[pos];
        for(int i = 0; i< tamTrabajos; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajoBici(trabajos,bici,tipos,colores,servicios,clientes,tamTrabajos,tamTipos,tamColores,tamServ,i,tamClientes);
            }
        }
    }
}


/**<
Me va a cargar el vector trabajosBici con todos los trabajos de la bici.
El tamaño del vector es el mismo del vector general de trabajos xq a priori nose la cant de trabajos de una bici*/
void cargarTrabajosBicicleta(eTrabajo trabajosBici[], eTrabajo trabajosRealizados[], int tamTrabajosRealizados,int* canTrabajosRealizados, eBicicleta bici)
{
    // inicializa trabajos
    inicializarTrabajos(trabajosBici,tamTrabajosRealizados,FALSE);
    // contador de la cantidad de trabajos para la bici
    int j = 0;
    for(int i = 0; i< tamTrabajosRealizados; i++)
    {
        if(trabajosRealizados[i].idBicicleta == bici.id)
        {
            trabajosBici[j].isEmpty = FALSE;
            trabajosBici[j].fecha = trabajosRealizados[i].fecha;
            trabajosBici[j].id = trabajosRealizados[i].id;
            trabajosBici[j].idBicicleta = trabajosRealizados[i].idBicicleta;
            trabajosBici[j].idServicio = trabajosRealizados[i].idServicio;
            j++;
        }
    }
    // le sumo 1 porque arranque en 0
    (*canTrabajosRealizados) = j+1;
}

void SumarImporteTrabajosBici(eTrabajo trabajos[], int tamT,eBicicleta bicicletas[],int tamBici,eServicio servicios[], int tamServ,eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    float sumatoria = 0;
    int posServ;
    int idBici;
    printf("Seleccione id de la bicicleta\n");
    ListarBicicletas(bicicletas,tipos,colores,clientes,tamBici,tamTipos,tamColores,tamClientes);
    scanf("%d",&idBici);
    while(!validaciones_ValidarBicicleta(bicicletas,tamBici,idBici))
    {
        printf("Id bicicleta invalido.Reingrese el id de la bicicleta\n");
        ListarBicicletas(bicicletas,tipos,colores,clientes,tamBici,tamTipos,tamColores,tamClientes);
        scanf("%d",&idBici);
    }
    for(int i =0; i<tamT ;i++)
    {
        if(trabajos[i].idBicicleta == idBici)
        {
            posServ = BuscarServicioPos(servicios,tamServ,trabajos[i].idServicio);
            sumatoria += servicios[posServ].precio;
        }
    }
    printf("La sumatoria de los servicios realizados a la bicleta %s es %.2f",bicicletas[BuscarPosById(bicicletas,tamBici,idBici)].marca,sumatoria);
}

void ListaServiciosXBici(eTrabajo trabajos[],eBicicleta bicicletas[],eCliente clientes[],eServicio servicios[], eTipo tipos[], eColor colores[],int tamTrabajo,int tamBicis ,int tamClientes,int tamServ,int tamTipos ,int tamColores)
{
    int idServicio;
    printf("Seleccione el Id del servicio\n");
    listarServicios(servicios,tamServ);
    scanf("%d",&idServicio);
    while(!validaciones_ValidarServicio(servicios,tamServ,idServicio))
    {
        printf("Id invalido.ReIngrese el Id del servicio a informar\n");
        listarServicios(servicios,tamServ);
        scanf("%d",&idServicio);
    }
    int posBici;
    for(int i = 0; i<tamTrabajo; i++)
    {
        if(trabajos[i].idServicio == idServicio)
        {
            posBici = BuscarPosById(bicicletas,tamBicis,trabajos[i].idBicicleta);
            printf("Fecha:\n");
            MostrarFecha(trabajos[i].fecha);
            eBicicleta bici = bicicletas[posBici];
            MOSTRARUNABICI(bici,tipos,colores,clientes,tamTipos,tamColores,tamClientes);
        }
    }
}


void ServiciosxFecha(eTrabajo trabajos[],eServicio servicios[],int tamTrabajo,int tamServ)
{
    int pos;
    eFecha fechaABuscar;
    printf("Indique la fecha cuyos servicios quiere listar\n");
    fechaABuscar = crearFecha();
    printf("Servicios realizados :\n");
    for(int i = 0; i<tamTrabajo; i++)
    {
        if(comprarFechas(trabajos[i].fecha,fechaABuscar))
        {
           pos = BuscarServicioPos(servicios,tamServ,trabajos[i].idServicio);
           mostrarServicio(servicios,pos);
        }
    }
}

