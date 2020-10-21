#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "Servicios.h"
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"


/** \brief
 * valida si un rodado es valido (esta dentro del vector)
 * \param idRodado int
 * \return int TRUE valid, FALSE invalid
 *
 */
int validaciones_validarRodado(float idRodado);

/** \brief
 *  valida si un id de color es valido (esta dentro del vector)
 * \param colores[] eColor vector colores
 * \param tam int tamaño vector
 * \param id int id del color
 * \return int TRUE valid, FALSE invalid
 *
 */
int validaciones_ValidarColorValido(eColor colores[], int tam, int id);

/** \brief
 *  valida que un tipo de bicicleta sea valido (esta dentro del vector)
 * \param tipos[] eTipo vector de tipos de bicicletas
 * \param tam int tamaño vector
 * \param id int id tipo vector
 * \return int TRUE valid, FALSE invalid
 *
 */
int validaciones_ValidarTipoValido(eTipo tipos[], int tam, int id);

/** \brief
 *  valida si una bicicleta es valida (esta dentro del vector)
 * \param bicis[] eBicicleta
 * \param tam int tamaño vector
 * \param idBicicleta int
 * \return int TRUE valid, FALSE invalid
 *
 */
int validaciones_ValidarBicicleta(eBicicleta bicis[], int tam, int idBicicleta);

/** \brief
 * valida si un servicio es valido (esta dentro del vector)
 * \param servicios[] eServicio vector servicio
 * \param tam int tamaño vector
 * \param idServicio int vector servicio
 * \return int TRUE valid, FALSE invalid
 *
 */
int validaciones_ValidarServicio(eServicio servicios[], int tam, int idServicio);

/** \brief
 * valida que un cadena sea solo caracteres
 * \param str char*
 * \return int TRUE valid, FALSE invalid
 *
 */
int validaciones_stringValidation(char * str);
/** \brief
 * Valida un cliente
 * \param clientes[] eCliente vector clientes
 * \param tam int tamaño vector
 * \param idCliente int id cliente
 * \return int  TRUE / FALSE
 *
 */
int validacion_ValidarCliente(eCliente clientes[], int tam, int idCliente);

#endif // VALIDACIONES_H_INCLUDED
