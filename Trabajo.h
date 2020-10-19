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
int mostrarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamBicis, int tamTipo, int tamColor, int tamServ, int pos);

/** \brief
 * Busca la proxima posicion libre en el vector
 * \param trabajos[] eTrabajo vector trabajo
 * \param tam int tamaño vector
 * \return int posicion libre del vector, -1 si vector lleno
 *
 */
int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam);

/** \brief
 * devuelve el id siguiente al ultimo existente
 * \param trabajos[] eTrabajo vector trabajo
 * \param tam int tamaño vector
 * \return int id
 *
 */
int BuscarProximoId(eTrabajo trabajos[], int tam);

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
int AltaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ);

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
 * \param idTrabajo int id del trabajo a dar de baja
 * \return int
 *
 */
int BajaTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int idTrabajo);

/** \brief
 * Modifica un trabajo
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
 * \param idTrabajo int id del trabajo a moidifcar
 * \return int
 *
 */
int ModificarTrabajo(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[], int tamTrabajos, int tamBicis,int tamTipos,int tamColores, int tamServ, int idTrabajo);

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
void listarTrabajos(eTrabajo trabajos[],eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eServicio servicios[], int tamTrabajo,int tamMasc, int tamTipo, int tamColor, int tamServ);

/** \brief
 * Inicializa el vector trabajo
 * \param trabajos[] eTrabajo
 * \param trabajosHard[] eTrabajo harcodeados
 * \param tam int
 * \return void
 *
 */
void inicializarTrabajosBici(eTrabajo trabajos[], int tam);

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
 * Indica si existe el id
 * \param trabajos[] eTrabajo  vector trabajo
 * \param tam int tamaño
 * \param ID int id
 * \return int TRUE / FALSE
 *
 */
int ExisteIdTrabajo(eTrabajo trabajos[], int tam, int ID);

#endif // TRABAJO_H_INCLUDED
