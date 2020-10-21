#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

/** \brief
 * Muestra una fecha
 * \param fecha eFecha estructura fecha
 * \return void
 *
 */
void MostrarFecha(eFecha fecha);

/** \brief
 * Crea una fecha
 * \return eFecha
 *
 */
eFecha crearFecha();

/** \brief
 * indica si dos fechas son iguales
 * \param origen eFecha fecha origen
 * \param destino eFecha fecha destino
 * \return int TRUE / FALSE
 *
 */
int comprarFechas(eFecha origen, eFecha destino);

#endif // FECHA_H_INCLUDED
