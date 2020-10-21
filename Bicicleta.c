#include <stdio.h>
#include <string.h>
#include "Bicicleta.h"
#include "DataStore.h"
#define TAMINICIALVECBICI 4
#define TAMRODADOS 4
#include "Tipo.h"
#include "Color.h"
#include "Common.h"
#include "Validaciones.h"
#include "Cliente.h"
#define TRUE 1
#define FALSE 0

float rodados[] = {20,26,27.5,29};

void inicializarVectores(eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],eCliente clientes[],int tamM, int tamT, int tamC, int tamS, int tamCliente)
{

    InicializarBicicleta(bicicletas,tamM);
    inicializarCliente(clientes,tamCliente);
    for(int i =0; i<TAMINICIALVECBICI; i++)
    {
        bicicletas[i].id = vBicicletas[i].id;
        bicicletas[i].idColor = vBicicletas[i].idColor;
        bicicletas[i].idTipo = vBicicletas[i].idTipo;
        bicicletas[i].idCliente = vBicicletas[i].idCliente;
        strcpy(bicicletas[i].marca,vBicicletas[i].marca);
        bicicletas[i].rodado = vBicicletas[i].rodado;
        bicicletas[i].isEmpty = FALSE;
    }
    int id = 1000;
    for(int i =0; i<tamT; i++)
    {
        tipos[i].id = id;
        strcpy(tipos[i].descripcion,vTipo[i]);
        id ++;
    }
    id = 5000;
    for(int i =0; i<tamC; i++)
    {
        colores[i].id = id;
        strcpy(colores[i].nombreColor,vColores[i]);
        id ++;
    }
    id = 20000;
    for(int i =0; i<tamS; i++)
    {
        servicios[i].id = vServicios[i].id ;
        strcpy(servicios[i].descripcion,vServicios[i].descripcion);
        servicios[i].precio = vServicios[i].precio;
        id ++;
    }

}

void ListarRodadosValidos()
{

    printf("Rodados disponibles :\n");
    printf("------------------------\n");

    for(int i = 0; i < TAMRODADOS ; i++)
    {
        printf("%.2f \n",rodados[i]);
    }
}

int GetRodadoMenor()
{
    // uso un id que no existe, pero que es mayor a los dados
    int min = 1000;
    for(int i = 0; i < TAMRODADOS ; i++)
    {
        if(rodados[i] < min )
        {
            min = rodados[i];
        }
    }
    return min;
}

int BuscarIdLibre(eBicicleta bicicletas[], int tam)
{
     for(int i = 0; i < tam ; i++)
    {
        if(bicicletas[i].isEmpty)
        {
            return i;
        }
    }
     printf("Lista llena . No hay mas lugar\n");
    return -1;
}

int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[],eCliente clientes[], int tamBici, int tamC, int tamT, int id, int tamCliente)
{
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    float rodado;

    eBicicleta bici ;
    int pos = BuscarIdLibre(bicicletas,tamBici);
    if(pos <0) {return TRUE;}

    printf("Ingrese marca\n");
    fflush(stdin);
    gets(marca);

    while(!validaciones_stringValidation(marca))
    {
        printf("Marca invalida, reingrese\n");
        fflush(stdin);
        gets(marca);
    }
    printf("Indique el ID del tipo de bicicleta\n");
    ListarTipos(tipos,tamT);
    scanf("%d",&idTipo);
    while(!validaciones_ValidarTipoValido(tipos,tamT,idTipo))
    {
        printf("Tipo seleccionado Invalido. Reingrese\n");
        ListarTipos(tipos,tamT);
        scanf("%d",&idTipo);
    }

    printf("Indique el ID del cliente\n");
    ListarClientes(clientes,tamCliente);
    scanf("%d",&idCliente);
    while(!validacion_ValidarCliente(clientes,tamCliente,idCliente))
    {
        printf("Id cliente Invalido. Reingrese\n");
        ListarClientes(clientes,tamCliente);
        scanf("%d",&idCliente);
    }

    printf("Indique el ID del color de la bicicleta\n");
    ListarColores(colores,tamC);
    scanf("%d",&idColor);
    while(!validaciones_ValidarColorValido(colores,tamC,idColor))
    {
        printf("Color seleccionado Invalido\n");
        printf("Indique el ID del color de la bicicleta\n");
        ListarColores(colores,tamC);
        scanf("%d",&idColor);
    }

    printf("Ingrese rodado \n");
    ListarRodadosValidos();
    scanf("%f",&rodado);
    while(!validaciones_validarRodado(rodado))
    {
        printf("Rodado invalido \n");
        printf("Ingrese rodado \n");
        ListarRodadosValidos();
        scanf("%f",&rodado);
   }

    bici.id = id;
    bici.idColor = idColor;
    bici.idTipo = idTipo;
    bici.idCliente = idCliente;
    strcpy(bici.marca,marca);
    bici.rodado = rodado;
    bici.isEmpty = FALSE;

    bicicletas[pos] = bici;
    printf("Alta correcta \n");
    return FALSE;
}

int BAJA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[],eCliente clientes[], int tamBicis, int tamC, int tamT,int id, int tamClientes)
{
    int borra;
    int pos = BuscarPosById(bicicletas,tamBicis,id);
    if(pos <0){return TRUE;}
    printf("Bicicleta a dar de baja :\n");
    MOSTRARBICI(bicicletas,tipos,colores,clientes,bicicletas[pos].id,tamBicis,tamT,tamC,tamClientes);
    printf("Esta seguro que desa darla de baja? SI 1, NO 0\n");
    scanf("%d",&borra);
    if(borra)
    {
        bicicletas[pos].isEmpty = TRUE;
        printf("Bicicleta dada de baja\n");
    }
    return FALSE;
}

int MODIFICAR(eBicicleta bicicletas[],eColor colores[], eTipo tipos[],eCliente clientes[], int tamBicis, int tamC, int tamT,int id, int tamClientes)
{
    int pos = BuscarPosById(bicicletas,tamBicis,id);
    if(pos <0){return TRUE;}
    int modifica = 0;
    printf("Bicicleta a Modificar :\n");
    MOSTRARBICI(bicicletas,tipos,colores,clientes,bicicletas[pos].id,tamBicis,tamT,tamC,tamClientes);
    printf("Esta seguro que desea modificar la bicicletas? SI 1, NO 0\n");
    scanf("%d",&modifica);
    if(modifica)
    {
        int  opcion =common_getMenu("1 Modifica Tipo\n2 Modifica Rodado\n","Opcion invalida. Reingrese",1,2,3);

        if(opcion == 1)
        {
            int idTipo;
            printf("Indique el id nuevo tipo de bicicleta e\n");
            ListarTipos(tipos,tamT);
            scanf("%d",&idTipo);
            while(!validaciones_ValidarTipoValido(tipos,tamT,idTipo))
            {
                printf("Tipo seleccionado Invalido\n");
                printf("Indique el id nuevo tipo de bicicleta e\n");
                ListarTipos(tipos,tamT);
                scanf("%d",&idTipo);
            }
            bicicletas[pos].idTipo = idTipo;

        }
        else
        {
            float rodado;
            printf("Ingrese el nuevo Rodado \n");
            ListarRodadosValidos();
            scanf("%f",&rodado);
            if(!validaciones_validarRodado(rodado))
            {
                printf("Rodado invalida");
                printf("Ingrese el nuevo Rodado \n");
                scanf("%f",&rodado);
            }
            bicicletas[pos].rodado = rodado;
        }
    }
    printf("Modificacion correcta \n");
    return FALSE;
}

void ListarBicicletas(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[], int tamBicis, int tamT, int tamC, int tamClientes)
{
    OrdenarVectorBurbuja(bicicletas,tamBicis);
    for(int i = 0; i< tamBicis; i++)
    {
        if(!bicicletas[i].isEmpty)
        {
          MOSTRARBICI(bicicletas,tipos,colores,clientes,bicicletas[i].id,tamBicis,tamT,tamC,tamClientes);
        }
    }
}

void OrdenarVectorBurbuja(eBicicleta bicicletas[], int tam)
{
    for(int i =0; i < tam ; i++)
    {
        for(int j = i+1; j <tam; j++)
        {
            // Solo busco para las posiciones del vector que tiene valor
            if(bicicletas[i].isEmpty == FALSE && bicicletas[j].isEmpty == FALSE)
            {
                if(bicicletas[i].idTipo > bicicletas[j].idTipo || (bicicletas[i].idTipo == bicicletas[j].idTipo && bicicletas[i].rodado > bicicletas[j].rodado) >0)
                {
                    makeSwap(bicicletas,i,j);
                }
            }
        }
    }

}

void OrdenarVectorPorTipo(eBicicleta bicicletas[], int tam)
{
    for(int i =0; i < tam ; i++)
    {
        for(int j = i+1; j <tam; j++)
        {
             // Solo busco para las posiciones del vector que tiene valor
            if(!bicicletas[i].isEmpty && !bicicletas[j].isEmpty)
            {
                if(bicicletas[i].idTipo > bicicletas[j].idTipo)
                {
                    makeSwap(bicicletas,i,j);
                }
            }
        }
    }

}

void makeSwap(eBicicleta  bicicletas[], int i, int j)
{
    eBicicleta auxEmp;
    auxEmp = bicicletas[j];
    bicicletas[j] = bicicletas[i];
    bicicletas[i] = auxEmp;
}

void InicializarBicicleta(eBicicleta bicicletas[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        bicicletas[i].isEmpty = TRUE;
    }
}

int BuscarPosById(eBicicleta bicicletas[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(bicicletas[i].id == id)
        {
            return i;
        }
    }
    printf("No se encuentra el id en la lista \n");
    return -1;
}

void MOSTRARBICI(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[], int id, int tam, int tamT, int tamC, int tamClientes)
{
    int index = BuscarPosById(bicicletas,tam,id);
    printf("ID  MARCA  TIPO     COLOR    RODADO  CLIENTE\n"),
    printf("%d    %s    %s   %s     %.2f    %s\n",bicicletas[index].id,bicicletas[index].marca,MostrarTipo(tipos,tamT,bicicletas[index].idTipo),MostrarColor(colores,tamC,bicicletas[index].idColor),bicicletas[index].rodado,MostrarCliente(clientes,tamClientes,bicicletas[index].idCliente));
    printf("\n");
}

void MOSTRARUNABICI(eBicicleta bicicleta,eTipo tipos[], eColor colores[],eCliente clientes[], int tamT, int tamC, int tamClientes)
{
    printf("ID  MARCA  TIPO     COLOR    RODADO   CLIENTE\n"),
    printf("%d    %s    %s   %s     %.2f    %s\n",bicicleta.id,bicicleta.marca,MostrarTipo(tipos,tamT,bicicleta.idTipo),MostrarColor(colores,tamC,bicicleta.idColor),bicicleta.rodado,MostrarCliente(clientes,tamClientes,bicicleta.idCliente));
    printf("\n");
}

void ListarBicletasPorColor(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC,int tamClientes)
{
    int sIdColor;
    printf("Seleccione el color cuyas bicicletas quiere listar \n");
    ListarColores(colores,tamC);
    scanf("%d",&sIdColor);
    while(!validaciones_ValidarColorValido(colores,tamC,sIdColor))
    {
        printf("Id color invalido.Reingrese el color cuyas bicicletas quiere listar \n");
        ListarColores(colores,tamC);
        scanf("%d",&sIdColor);
    }
    for(int i=0; i<tamBicis ;i++)
    {
        if(bicicletas[i].idColor == sIdColor)
        {
            MOSTRARUNABICI(bicicletas[i],tipos,colores,clientes,tamT,tamC,tamClientes);
        }
    }
}

void ListarBicletasPorTipo(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC,int tamCliente)
{
    int sIdTipo;
    printf("Seleccione el tipo de bicicleta cuyas bicicletas quiere listar \n");
    ListarTipos(tipos,tamT);
    scanf("%d",&sIdTipo);
    while(!validaciones_ValidarTipoValido(tipos,tamT,sIdTipo))
    {
        printf("Id tipo invalido.Reingrese el tipo de bicicleta cuyas bicicletas quiere listar \n");
        ListarTipos(tipos,tamT);
        scanf("%d",&sIdTipo);
    }
    for(int i=0; i<tamBicis ;i++)
    {
        if(bicicletas[i].idTipo == sIdTipo)
        {
            MOSTRARUNABICI(bicicletas[i],tipos,colores,clientes,tamT,tamC,tamCliente);
        }
    }
}

void MostrarBicletaMenorRodado(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC, int tamClientes)
{
    int sRodado = GetRodadoMenor();
    for(int i=0; i<tamBicis ;i++)
    {
        if(bicicletas[i].rodado == sRodado)
        {
            MOSTRARUNABICI(bicicletas[i],tipos,colores,clientes,tamT,tamC,tamClientes);
        }
    }
}

void ListarBicicletasPorTipo(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamBicis, int tamT, int tamC, int tamClientes)
{
    // ordeno el vector bicicletas por tipo
    OrdenarVectorPorTipo(bicicletas,tamBicis);
    int sIdTipo =0;
    for(int i =0; i< tamBicis; i++)
    {
        if(!bicicletas[i].isEmpty)
        {
            if(sIdTipo != bicicletas[i].idTipo)
            {
                sIdTipo = bicicletas[i].idTipo;
                printf("Tipo de Bicicleta :%s \n",MostrarTipo(tipos,tamT,sIdTipo));
            }
            MOSTRARUNABICI(bicicletas[i],tipos,colores,clientes,tamT,tamC,tamClientes);
        }
    }
}

void ContarBicletasPorTipoyColor(eBicicleta bicicletas[],eTipo tipos[], eColor colores[],int tamBicis, int tamT, int tamC)
{
    int sIdTipo;
    int sIdColor;
    int cant = 0;
    printf("Seleccione el tipo de bicicleta cuyas bicicletas quiere contar \n");
    ListarTipos(tipos,tamT);
    scanf("%d",&sIdTipo);
    while(!validaciones_ValidarTipoValido(tipos,tamT,sIdTipo))
    {
        printf("Id color invalido.Reingrese el tipo de bicicleta cuyas bicicletas quiere listar \n");
        ListarTipos(tipos,tamT);
        scanf("%d",&sIdTipo);
    }

    printf("Seleccione el color cuyas bicicletas quiere listar \n");
    ListarColores(colores,tamC);
    scanf("%d",&sIdColor);
    while(!validaciones_ValidarColorValido(colores,tamC,sIdColor))
    {
        printf("Id color invalido.Reingrese el color cuyas bicicletas quiere listar \n");
        ListarColores(colores,tamC);
        scanf("%d",&sIdColor);
    }

    for(int i=0; i<tamBicis ;i++)
    {
        if((bicicletas[i].idTipo == sIdTipo) &&(bicicletas[i].idColor== sIdColor))
        {
            cant ++;
        }
    }
    printf("La cantidad de bicicletas del color: %s y el tipo: %s es : %d\n",MostrarColor(colores,tamC,sIdColor),MostrarTipo(tipos,tamT,sIdTipo),cant);
}

int contarBicletasxColor(eBicicleta bicicletas[],int tamB, int idColor)
{
    int cant = 0;
    for(int i = 0; i< tamB; i++)
    {
        if(bicicletas[i].idColor ==idColor )
        {
            cant++;
        }
    }
    return cant;
}

void OrdenarVectorCantColores(eCantColor cantColores[], int tam)
{
    // ordena de mayor a menor
    //uso una estructura auxiliar por si hay varios colores con la misma cantidad de bicis
    for(int i =0; i < tam ; i++)
    {
        for(int j = i+1; j <tam; j++)
        {
            if(cantColores[i].cantidad < cantColores[j].cantidad)
            {
                eCantColor aux;
                aux = cantColores[j];
                cantColores[j] = cantColores[i];
                cantColores[i] = aux;
            }
        }
    }
}

void MostrarColoresMasElegidos(eBicicleta bicicletas[],int tamBicis,eColor colores[],int tamC)
{
    eCantColor vecCantXColorAux[tamC];
    int maximo =0;
    for(int i =0; i < tamC ;i++)
    {
        vecCantXColorAux[i].idColor = colores[i].id;
        vecCantXColorAux[i].cantidad = contarBicletasxColor(bicicletas,tamBicis,colores[i].id);
    }
    OrdenarVectorCantColores(vecCantXColorAux,tamC);
    for(int i=0; i< tamC ; i++)
    {
        //Al estar ordenado de mayor a menor, el primero siempre va a ser el mayor
        if(vecCantXColorAux[i].cantidad >= maximo)
        {
            maximo =vecCantXColorAux[i].cantidad ;
            printf("El color mas elegido es :%s\n",MostrarColor(colores,tamC,vecCantXColorAux[i].idColor));
        }
    }
}
