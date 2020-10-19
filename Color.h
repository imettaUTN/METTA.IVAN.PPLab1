#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

/** \brief
 * Inicializa vector colores
 * \param colores[] eColor vector colores
 * \param tam int tamaño vector
 * \return void
 *
 */
void InicializarColores(eColor colores[],int tam);

/** \brief
 *
 * \param colores[] eColor
 * \param tam int
 * \return void
 *
 */
void ListarColores(eColor colores[],int tam);

/** \brief
 *  Muestra un color del vector
* \param colores[] eColor vector colores
 * \param tam int tamaño vector
 * \param id int id del color
 * \return char*
 *
 */
char * MostrarColor(eColor colores[],int tam, int id);

/** \brief
 * Busca el subindice del color en el vector, segun su id
 * \param colores[] eColor vector colores
 * \param tam int tamaño
 * \param id int id color
 * \return int posicion en el vector , -1  si no se encuentra
 *
 */
int BuscarPosColor(eColor colores[], int tam, int id);

#endif // COLOR_H_INCLUDED
