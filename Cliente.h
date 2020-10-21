#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char sexo;
} eCliente;

/** \brief
 * Inicializa vector cliente
 * \param clientes[] eCliente vector cliente
 * \param tam int tama�o vector cliente
 * \return void
 *
 */
void inicializarCliente(eCliente clientes[], int tam);

/** \brief
 * Muestra un cliente
 * \param clientes[] eCliente vector cliente
 * \param tam int tama�o vector cliente
 * \param id int id cliente
 * \return char*
 *
 */
char * MostrarCliente(eCliente clientes[], int tam, int id);

/** \brief
 * Busca posicion en el vector del cliente
 * \param clientes[] eCliente vector cliente
 * \param tam int tama�o vector cliente
 * \param id int id cliente
 * \return int
 *
 */
int BuscarPosCliente(eCliente clientes[], int tam, int id);

/** \brief
 * Lista los clientes
 * \param clientes[] eCliente vector cliente
 * \param tam int tama�o vector cliente
 * \return void
 *
 */
void ListarClientes(eCliente clientes[],int tam);

#endif // CLIENTE_H_INCLUDED
