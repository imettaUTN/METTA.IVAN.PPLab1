#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
int id;
    char descripcion[20];
    float precio;
}eServicio;

/** \brief
 * Lista los servicios de la bicicleta
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \return void
 *
 */
void listarServicios(eServicio servicios[], int tam);
/** \brief
 * Muestra un servicio segun su posicion en el array.
 * \param servicios[] eServicio vector servicios
 * \param pos int posicion en el vector servicios
 * \return void
 *
 */
void mostrarServicio(eServicio servicios[], int pos);
/** \brief
 * Muesta un servicio segun su id
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param id int id del servicio
 * \return void
 *
 */
void mostrarServicioById(eServicio servicios[],int tam, int id);
/** \brief
 * Buscar el subindice en el vector de un id de servicio
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param id int id del servicio a buscar
 * \return int posicion en el vector, -1 si no se encuentra
 *
 */
int BuscarServicioPos(eServicio servicios[], int tam , int id);

#endif // SERVICIOS_H_INCLUDED
