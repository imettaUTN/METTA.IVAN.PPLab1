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
 * Busca el subindice del tipo en el vector, segun su id
 * \param tipos[] eTipo vector tipos de bicicleta
 * \param tam int tamaño
 * \param id int id tipo
 * \return int posicion en el vector , -1  si no se encuentra
 *
 */
int BuscarPosTipo(eTipo tipos[], int tam, int id);

#endif // TIPO_H_INCLUDED
