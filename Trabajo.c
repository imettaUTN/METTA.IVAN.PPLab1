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
        trabajos[i].id = -1;
    }
    for(int i = 0; i< TAMTrabajos ; i++)
    {
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
    for(int i = 0; i< tamTrabajo; i++)
    {
        if(trabajos[i].id >=0)
        {
            mostrarTrabajo(trabajos,bicicletas,tipos,colores,servicios,tamTrabajo,tamBicis,tamTipo,tamColor,tamServ,i);
        }
    }
}

int mostrarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamBicis, int tamTipo, int tamColor, int tamServ, int pos)
{
    if(trabajos == NULL || tamTrabajo <0)
    {
        printf("Lista trabajo vacia\n");
        return TRUE;
    }
    printf("ID Trabajo: %d\n",trabajos[pos].id);
    printf("Fecha: \n");
    MostrarFecha(trabajos[pos].fecha);
    printf("Mascota:\n");
    MOSTRARBICI(bicicletas,tipos,colores,bicicletas[pos].id,tamBicis,tamTipo,tamColor);
    printf("Servicio realizado: \n");
    mostrarServicioById(servicios,tamServ,trabajos[pos].idServicio);
    printf("\n------------------\n");
    printf("\n\n");
    return FALSE;
}

int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].id <0)
        {
            if(ExisteIdTrabajo(trabajos,tam,i))
            {
                continue;
            }
            return i;
        }
    }
     printf("Lista llena . No hay mas lugar\n");
    return -1;
}

int BuscarProximoId(eTrabajo trabajos[], int tam)
{
    for(int i =0; i< tam ; i++)
    {
        if(trabajos[i].id <0)
        {
            if(i == 0)
            {
                return 0;
            }
            return (trabajos[i-1].id + 1);
        }
    }
    return 0;
}

int AltaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ)
{
    eTrabajo trabajo;
    int idBici = 0;
    int idServicio = 0;
    int valido = TRUE;
    do
    {
        valido = TRUE;
        printf("Seleccione el id de la bicicleta sobre la que se realizara el trabajo\n");
        ListarBicicletas(bicicletas,tipos,colores,tamBicis,tamTipos,tamColores);
        scanf("%d",&idBici);
        if(!validaciones_ValidarBicicleta(bicicletas,tamBicis,idBici))
        {
            printf("Id bicicleta invalido \n");
            valido = FALSE;
        }
        printf("Seleccione el id de servicio a realizar \n");
        listarServicios(servicios,tamServ);
        scanf("%d",&idServicio);
        if(!validaciones_ValidarServicio(servicios,tamServ,idServicio))
        {
             printf("Id servicio invalido \n");
            valido = FALSE;
        }

    }
    while(!valido);

    trabajo.fecha = getFechaActual();
    trabajo.id =BuscarProximoId(trabajos, tamTrabajos);
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


int ExisteIdTrabajo(eTrabajo trabajos[], int tam, int ID)
{
    for(int i = 0; i <tam; i++)
    {
        if(trabajos[i].id == ID)
        {
            printf("ID ya existente \n");
            return TRUE;
        }
    }
    return FALSE;
}

int BajaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int idTrabajo)
{
    int borra;
    int pos = buscarPosVecTrabajo(trabajos,tamTrabajos,idTrabajo);
    if(pos <0){return TRUE;}
    printf("Trabajo a dar de baja :\n");
    mostrarTrabajo(trabajos,bicicletas,tipos,colores,servicios,tamTrabajos,tamBicis,tamTipos,tamColores,tamServ,pos);
    printf("Esta seguro que desa darlo de baja? SI 1, NO 0\n");
    scanf("%d",&borra);
    if(borra)
    {
        trabajos[pos].id = -1;
        printf("Trabajo dada de baja\n");
    }
    return FALSE;
}

int ModificarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int idTrabajo)
{
    int modifica = 0;
    int pos = buscarPosVecTrabajo(trabajos,tamTrabajos,idTrabajo);
    if(pos <0){return TRUE;}
    printf("Trabajo a dar de modificar :\n");
    mostrarTrabajo(trabajos,bicicletas,tipos,colores,servicios,tamTrabajos,tamBicis,tamTipos,tamColores,tamServ,pos);
    printf("Esta seguro que desa modificar el trabajo? SI 1, NO 0\n");
    scanf("%d",&modifica);
    if(modifica)
    {
        printf("Ingrese la nueva fecha del trabajo \n");
        trabajos[pos].fecha = crearFecha();
        printf("Trabajo modificado correctamente \n");
        return FALSE;
    }
    return TRUE;
}

