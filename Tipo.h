#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

/** \brief
 *  Lista los tipos de bcicleta
 * \param tipos[] eTipo vector tipos vector tipos
 * \param tam int tamaño vector tamaño vector
 * \return void
 *
 */
void ListarTipos(eTipo tipos[],int tam);

/** \brief
 *  Muesta un tipo de bicicleta
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param idTipo int id del tipo de bicicleta id del tipo de bicicleta
 * \return char*
 *
 */
char * MostrarTipo(eTipo tipos[],int tam, int idTipo);

/** \brief
 *  Da de alta un nurvo tipo de bicicleta
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \return int FALSE all ok, TRUE error
 *
 */
int ALTATIPO(eTipo tipos[], int tam );

/** \brief
 *  Da de baja un tipo de bicleta
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param idTipo int id del tipo de bicicleta
 * \return int FALSE all ok, TRUE error
 *
 */
int BAJATIPO(eTipo tipos[], int tam, int idTipo);

/** \brief
 *  Modifica tipo de bicicleta
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param idTipo int id del tipo de bicicleta
 * \return int FALSE all ok, TRUE error
 *
 */
int MODIFICARTIPO(eTipo tipos[], int tam, int idTipo);

/** \brief
  * Busca pos libre en el vector
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \return int proxima por libre
 *
 */
int BuscarIdLibreTipo(eTipo tipos[], int tam );

/** \brief
  * Inicializa el vector tipos
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \return void
 *
 */
void InicializarTip(eTipo tipos[], int tam );

/** \brief
  * Busca posicion en el vector segun el id
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param id int
 * \return int posicion en el vector -1 sino se encuentra
 *
 */
int BuscarPosTipo(eTipo tipos[], int tam,int id);

/** \brief
 *  Indica si existe el id del tipo
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param ID int id color
 * \return int TRUE / FALSE
 *
 */
int ExisteIdTipo(eTipo tipos[], int tam, int ID);
#endif // TIPO_H_INCLUDED
