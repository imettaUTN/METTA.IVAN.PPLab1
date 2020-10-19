#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
int id;
    char descripcion[20];
    float precio;
}eServicio;

/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \return void
 *
 */
void listarServicios(eServicio servicios[], int tam);
/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param pos int posicion en el vector servicios
 * \return void
 *
 */
void mostrarServicio(eServicio servicios[], int pos);
/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param id int id del servicio
 * \return void
 *
 */
void mostrarServicioById(eServicio servicios[],int tam, int id);
/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param id int id del servicio a buscar
 * \return int posicion en el vector, -1 si no se encuentra
 *
 */
int BuscarServicioPosById(eServicio servicios[], int tam , int id);

/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \return int TRUE erro FALSE all ok
 *
 */
int ALTASERVICOO(eServicio servicios[], int tam );

/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param idServ int id del servicio
 * \return int TRUE erro FALSE all ok
 *
 */
int BAJASERVICIO(eServicio servicios[], int tam, int idServ);
/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param idServ int id del servicio
 * \return int TRUE erro FALSE all ok
 *
 */
int MODIFICARSERVICIO(eServicio servicios[], int tam, int idServ);

/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \return int
 *
 */
int BuscarIdLibreServicio(eServicio servicios[], int tam );
/** \brief
 *
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \return void
 *
 */
void InicializarServicio(eServicio servicios[], int tam );
/** \brief
 *
 * \param servicios[] eServicio vector servicios vector servicios
 * \param tam int tamaño vector
 * \param id int posicion en el vector
 * \return int
 *
 */
int BuscarPosServicio(eServicio servicios[], int tam,int id);

/** \brief
 *  Indica si existe el id del servicio
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param ID int id color
 * \return int TRUE / FALSE
 *
 */
int ExisteIdServicio(eServicio servicios[], int tam, int ID);
#endif // SERVICIOS_H_INCLUDED
