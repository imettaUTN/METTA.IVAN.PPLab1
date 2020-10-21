#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Fecha.h"
#include "Color.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Servicios.h"
#include "Bicicleta.h"
typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty ;
} eTrabajo;


/** \brief
 * Muestra un trabajo
 * \param trabajos[] eTrabajo vector trabajos
 * \param bicicletas[] eBicicleta vector bicicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param servicios[] eServicio vecotr servicios
 * \param tamTrabajo int tamaño vector trabajo
 * \param tamBicis int tamaño vector bicicleta
 * \param tamTipo int tamaño vector tipo
 * \param tamColor int tamaño vector colores
 * \param tamServ int tamaño vector servicios
 * \param pos int posicion del trabajo a mostrar
 * \return int TRUE : error, FALSE : ok
 *
 */
int mostrarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo, int tamBicis, int tamTipo, int tamColor, int tamServ, int pos, int tamClientes);

int mostrarTrabajoBici(eTrabajo trabajos[],eBicicleta bicicleta, eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo,int tamTipo, int tamColor, int tamServ, int pos, int tamCliente);

/** \brief
 * Muestra un trabajo
 * \param trabajos[] eTrabajo vector trabajos
 * \param bicicletas eBicicleta estructura bicicleta
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param servicios[] eServicio vecotr servicios
 * \param tamTrabajo int tamaño vector trabajo
 * \param tamTipo int tamaño vector tipo
 * \param tamColor int tamaño vector colores
 * \param tamServ int tamaño vector servicios
 * \param pos int posicion del trabajo a mostrar
 * \return int TRUE : error, FALSE : ok
 *
 */
int mostrarUnTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo, int tamBicis, int tamTipo, int tamColor, int tamServ, int pos, int tamClientes);

/** \brief
 * Busca la proxima posicion libre en el vector
 * \param trabajos[] eTrabajo vector trabajo
 * \param tam int tamaño vector
 * \return int posicion libre del vector, -1 si vector lleno
 *
 */
int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam);

/** \brief
 *
 * \param trabajos[] eTrabajo vector trabajos
 * \param bicicletas[] eBicicleta vector bicicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param servicios[] eServicio vecotr servicios
 * \param tamTrabajo int tamaño vector trabajo
 * \param tamBicis int tamaño vector bicicleta
 * \param tamTipo int tamaño vector tipo
 * \param tamColor int tamaño vector colores
 * \param tamServ int tamaño vector servicios
 * \return int
 *
 */
int AltaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],eCliente clientes[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int id, int tamClientes);

/** \brief
 * Lista todos los trabajos
 * \param trabajos[] eTrabajo
 * \param bicicletas[] eBicicleta
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param servicios[] eServicio
 * \param tamTrabajo int
 * \param tamMasc int
 * \param tamTipo int
 * \param tamColor int
 * \param tamServ int
 * \return void
 *
 */
void listarTrabajos(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eServicio servicios[],eCliente clientes[],int tamTrabajo,int tamBicis, int tamTipo, int tamColor, int tamServ, int tamCliente);


/** \brief
 * Lista todos los trabajos de una bicicleta
 * \param trabajos[] eTrabajo
 * \param bicicleta eBicicleta
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param servicios[] eServicio
 * \param tamTrabajo int
 * \param tamMasc int
 * \param tamTipo int
 * \param tamColor int
 * \param tamServ int
 * \return void
 *
 */
void ListarTrabajosRealizadosBici(eTrabajo trabajos[], int tamTrabajos, eBicicleta bicicletas[],eCliente clientes[],int tamBicis, eTipo tipos[],int tamTipos, eServicio servicios[], int tamServ, eColor colores[], int tamColores,int tamClientes);


/** \brief
 *
 * \param trabajos[] eTrabajo vector trabajos
 * \param tam int tamaño vector
 * \param cargDatosHard int bandera que indica si se carga los datos harcodeados o no
 * \return void
 *
 */
void cargarTrabajosBicicleta(eTrabajo trabajosBici[], eTrabajo trabajosRealizados[], int tamTrabajosRealizados,int* tamTrabajoBicis, eBicicleta bici);
/** \brief
 * Busca posicion en el vec trabajo en base a un id
 * \param trabajos[] eTrabajo vector trabajo
 * \param tam int tamaño vector
 * \param id int id trabajo
 * \return int
 *
 */
int buscarPosVecTrabajo(eTrabajo trabajos[], int tam ,int id);

/** \brief
 * Indica si una lista de trabajos esta vacia o no
 * \param trabajos[] eTrabajo vector trabajos
 * \param tam int tamaño vector
 * \return int TRUE / FALSE
 *
 */
int ListaTrabajosVacia(eTrabajo trabajos[], int tam);

/** \brief
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param cargaDatos int
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo trabajos[], int tam, int cargaDatos);

/** \brief
 *  Lista los trabajo realizados para una bicicleta
 * \param trabajos[] eTrabajo vector trabajos
 * \param tamTrabajos int tamaño trabajos
 * \param bicicletas[] eBicicleta vector bicletas
 * \param tamBicis int tamaño bicicletas
 * \param tipos[] eTipo vector tipos
 * \param tamTipos int tamaño tipos
 * \param servicios[] eServicio vector servicios
 * \param tamServ int tamaño servicios
 * \param colores[] eColor vector colores
 * \param tamColores int tamaño colores
 * \return void
 *
 */
void ListarTrabajosRealizadosBici(eTrabajo trabajos[], int tamTrabajos, eBicicleta bicicletas[],eCliente clientes[],int tamBicis, eTipo tipos[],int tamTipos, eServicio servicios[], int tamServ, eColor colores[], int tamColores,int tamClientes);

/** \brief
 * Muestra todos los servicios que se le realizaron a una bicicleta y su fecha
 * \param trabajos[] eTrabajo vector trabajos
 * \param tamTrabajo int tamaño vec trabajos
 * \param bicicletas[] eBicicleta vector bicicletas
 * \param clientes[] eCliente vector clientes
 * \param servicios[] eServicio vector servicios
 * \param tamBicis int tamaño vec bicicletas
 * \param tipos[] eTipo vector tipos
 * \param tamTipos int tamaño vec tipos
 * \param colores[] eColor vector colores
 * \param tamColores int tamaño vec colores
 * \param tamClientes int tamaño vec clientes
 * \param tamServ int tamaño vec servicios
 * \return void
 *
 */
void ListaServiciosXBici(eTrabajo trabajos[],eBicicleta bicicletas[],eCliente clientes[],eServicio servicios[], eTipo tipos[], eColor colores[],int tamTrabajo,int tamBicis ,int tamClientes,int tamServ,int tamTipos ,int tamColores);

/** \brief
 * Lista todos los servicios para una fecha indicada
 * \param trabajos[] eTrabajo vector trabajos
 * \param servicios[] eServicio vector servicios
 * \param tamTrabajo int tamaño vec trabajos
 * \param tamServ int tamaño vec servicios
 * \return void
 *
 */
void ServiciosxFecha(eTrabajo trabajos[],eServicio servicios[],int tamTrabajo,int tamServ);

void SumarImporteTrabajosBici(eTrabajo trabajos[], int tamT,eBicicleta bicicletas[],int tamBici,eServicio servicios[], int tamServ,eTipo tipos[], int tamTipos, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

#endif // TRABAJO_H_INCLUDED
