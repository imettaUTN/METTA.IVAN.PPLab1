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
    float rodado;
} eBicicleta;

/** \brief
 * Buscar la posicion libre (-1) en el vector
 * \param  vector bicicletas
 * \param  tamaño vector
 * \return posicion id si encuentra id libre, -1 si lista llena
 *
 */
int BuscarIdLibre(eBicicleta bicicletas[], int tam);

/** \brief
 * Inicializa los vectores con los datos harcodeados
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tipos[] eTipo vector de tipos de bicicleta
 * \param colores[] eColor vector de colores de bicicleta
 * \param servicios[] eServicio vector de servicios
 * \param tamB int tamaño vector bicicleta
 * \param tamT int tamaño vector tipos
 * \param tamC int tamaño vector colores
 * \param tamS int tamaño vector servicios
 * \return void
 *
 */
void inicializarVectores(eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],int tamB, int tamT, int tamC, int tamS);

/** \brief
 *  inicializa vector bicicleta (pone id -1)
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tam int tamaño vector
 * \return void
 *
 */
void InicializarBicicleta(eBicicleta bicicletas[], int tam);

/** \brief
 * Busca la posicion en el vector segun el id indicado
 * \param bicicletas[] eBicicleta vector bicleta
 * \param tam int tamaño vector
 * \param id int id de la bicicleta
 * \return int posicion en el vector si se encuentra el id, -1 sino se encuentra
 *
 */
int BuscarPosById(eBicicleta bicicletas[], int tam, int id);

/** \brief
 *  Muestra la informacion de una bicicleta
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tipos[] eTipo vector tipos de bicicleta
 * \param colores[] eColor vector clores de bicicleta
i * \param tam int id de l bicicleta a mostrar
* \param id id de la bicicleta a mostrar
* \param tamB int  tamaño vector bicicleta
 * \param tamT int tamaño vector tipos de la bicicleta
 * \param tamC int tamaño vector colores de la bicicleta
 * \return void
 *
 */
void MOSTRARBICI(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int id, int tamB, int tamT, int tamC);

/** \brief
 * Modifica una bicicleta
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tipos[] eTipo vector tipos de bicicleta
 * \param colores[] eColor vector clores de bicicleta
 * \param tamBicis int tamaño vector bicicletas
 * \param tamC int tamaño vector colores
 * \param tamT int tamaño vector tipos
 * \param id int id bicicleta
 * \return int TRUE hubo error en la modificacion, False todo ok
 *
 */
int MODIFICAR(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamBicis, int tamC, int tamT,int id);


/** \brief
 * Da de alta una bicicleta
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tipos[] eTipo vector tipos de bicicleta
 * \param colores[] eColor vector clores de bicicleta
 * \param tamBicis int tamaño vector bicicletas
 * \param tamC int tamaño vector colores
 * \param tamT int tamaño vector tipos
 * \return int TRUE hubo error en la modificacion, False todo ok
 *
 */

int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamB, int tamC, int tamT);


/** \brief
 * Da de baja una bicicleta
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tipos[] eTipo vector tipos de bicicleta
 * \param colores[] eColor vector clores de bicicleta
 * \param tamBicis int tamaño vector bicicletas
 * \param tamC int tamaño vector colores
 * \param tamT int tamaño vector tipos
 * \param id int id bicicleta
 * \return int TRUE hubo error en la modificacion, False todo ok
 *
 */
int BAJA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamBicis, int tamC, int tamT,int id);

/** \brief
 * Ordena un vector por tipo y rodado
 * \param bicicletas[] eBicicleta vector bicicleta
 * \param tam int tamaño vector bicicleta
 * \return void
 *
 */
void OrdenarVectorBurbuja(eBicicleta bicicletas[], int tam);

/** \brief
 * Lista las bicibletas
 * \param bicicletas[] eBicicleta
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param tamBici int
 * \param tamTipo int
 * \param tamColor int
 * \return void
 *
 */
void ListarBicicletas(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int tamBici, int tamTipo, int tamColor);

/** \brief
 * Hace el intercambio de informacion entre dos posiciones del vector
 * \param i posicion i del vector
 * \param j posicion j del vector
 * \return void
 *
 */

void makeSwap(eBicicleta list[], int i, int j);

/** \brief
 * Lista los rodados validos
 * \return void
 *
 */
void ListarRodadosValidos();

/** \brief
 * Indica si existe el ID
 * \param bicicletas[] eBicicleta vector bicicletas
 * \param tam int tamaño vector
 * \param ID int id de la bicicleta
 * \return int TRUE / FALSE
 *
 */
int ExisteId(eBicicleta bicicletas[], int tam, int ID);

#endif // BICICLETA_H_INCLUDED
