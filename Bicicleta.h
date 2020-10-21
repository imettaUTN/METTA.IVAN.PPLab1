#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "Servicios.h"
#include "Color.h"
#include "Tipo.h"
#include "Cliente.h"

typedef struct
{   int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    float rodado;
    int isEmpty;
} eBicicleta;

typedef struct
{
    int idColor ;
    int cantidad;
} eCantColor;

/** \brief
 * Buscar la posicion libre en el vector
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
void inicializarVectores(eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],eCliente clientes[],int tamM, int tamT, int tamC, int tamS, int tamCliente);

/** \brief
 *  inicializa vector bicicleta
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
void MOSTRARBICI(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[], int id, int tam, int tamT, int tamC, int tamClientes);


/** \brief
 *  Muestra la informacion de una bicicleta
 * \param bicicleta eBicicleta estructura bicicleta
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
void MOSTRARUNABICI(eBicicleta bicicleta,eTipo tipos[], eColor colores[],eCliente clientes[], int tamT, int tamC, int tamClientes);

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
int MODIFICAR(eBicicleta bicicletas[],eColor colores[], eTipo tipos[],eCliente clientes[], int tamBicis, int tamC, int tamT,int id, int tamClientes);

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

int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[],eCliente clientes[], int tamBici, int tamC, int tamT, int id, int tamCliente);


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
int BAJA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[],eCliente clientes[], int tamBicis, int tamC, int tamT,int id, int tamClientes);

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
void ListarBicicletas(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[], int tamBicis, int tamT, int tamC, int tamClientes);

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
 * Listar biccletas por color
 * \param bicicletas[] eBicicleta vector bicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param clientes[] eCliente vector clientes
 * \param tamBicis int tamaño vec bicleta
 * \param tamT int tamaño vec tipos
 * \param tamC int tamaño vec colores
 * \param tamCliente int tam vec clientes
 * \return void
 *
 */
void ListarBicletasPorColor(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC,int tamClientes);

/** \brief
 * Listar bicicletas por tipo
 * Listar biccletas por color
 * \param bicicletas[] eBicicleta vector bicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param clientes[] eCliente vector clientes
 * \param tamBicis int tamaño vec bicleta
 * \param tamT int tamaño vec tipos
 * \param tamC int tamaño vec colores
 * \param tamCliente int tam vec clientes
 * \return void
 *
 */
void ListarBicletasPorTipo(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC,int tamCliente);

/** \brief
 * Muestras las bicicletas de menor rodado
 * Listar biccletas por color
 * \param bicicletas[] eBicicleta vector bicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param clientes[] eCliente vector clientes
 * \param tamBicis int tamaño vec bicleta
 * \param tamT int tamaño vec tipos
 * \param tamC int tamaño vec colores
 * \param tamCliente int tam vec clientes
 * \return void
 *
 */
void MostrarBicletaMenorRodado(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC, int tamClientes);

/** \brief
 *  Lista bicicletas agrupadas por tipo
 * \param bicicletas[] eBicicleta vector bicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param clientes[] eCliente vector clientes
 * \param tamBicis int tamaño vec bicleta
 * \param tamT int tamaño vec tipos
 * \param tamC int tamaño vec colores
 * \param tamCliente int tam vec clientes
 * \return void
 *
 */
void ListarBicicletasPorTipo(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC, int tamClientes);

/** \brief
 *  Muestra la cantidad de bicicletas hay por tipo y color
 * \param bicicletas[] eBicicleta vector bicletas
 * \param tipos[] eTipo vector tipos
 * \param colores[] eColor vector colores
 * \param tamBicis int tamaño vec bicleta
 * \param tamT int tamaño vec tipos
 * \param tamC int tamaño vec colores
 * \return void
 *
 */
void ContarBicletasPorTipoyColor(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],int tamBicis, int tamT, int tamC);

/** \brief
 * Ordenar vector por cantidad de colores
 * \param cantColores[] eCantColor vector aux
 * \param tam int  tamaño vector
 * \return void
 *
 */
void OrdenarVectorCantColores(eCantColor cantColores[], int tam);

/** \brief
 * Muestra el o los colores mas elegidos por cliente
 * \param bicicletas[] eBicicleta vector bicicletas
 * \param tamBicis int  tamaño vec bicicleta
 * \param colores[] eColor vector colores
 * \param tamC int tamaño vec colores
 * \return void
 *
 */
void MostrarColoresMasElegidos(eBicicleta bicicletas[],int tamBicis,eColor colores[],int tamC);
#endif // BICICLETA_H_INCLUDED
