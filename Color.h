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
 * Da de alta un color
  * \param colores[] eColor
 * \param tam int
 * \return int
 *
 */
int ALTACOLOR(eColor colores[], int tam );

/** \brief
 * Da de baja un color
 * \param colores[] eColor
 * \param tam int
 * \param idColor int
 * \return int
 *
 */
int BAJACOLOR(eColor colores[], int tam , int idColor);


/** \brief
 * Da de baja un color
 * \param colores[] eColor
 * \param tam int
 * \param idColor int
 * \return int
 *
 */
int MODIFICARCOLOR(eColor colores[], int tam , int idColor);

/** \brief
 * Busca pos libre en el vector
 * \param colores[] eColor
 * \param tam int
 * \return int
 *
 */
int BuscarIdLibreColor(eColor colores[], int tam );

/** \brief
 * Inicializa el vector colores
 * \param colores[] eColor
 * \param tam int
 * \return void
 *
 */
void InicializarColores(eColor colores[], int tam );

/** \brief
 * Busca posicion en el vector segun el id
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \return int
 *
 */
int BuscarPosColor(eColor colores[], int tam ,int id);

/** \brief
 *  Indica si existe el id del color
 * \param colores[] eColor vector colores
 * \param tam int tamaño vector
 * \param ID int id color
 * \return int TRUE / FALSE
 *
 */
int ExisteIdColor(eColor colores[], int tam, int ID);

#endif // COLOR_H_INCLUDED
