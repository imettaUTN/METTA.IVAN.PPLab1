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
#define TRUE 1
#define FALSE 0


void inicializarVectores(eBicicleta bicicletas[],eTipo tipos[],eColor colores[],eServicio servicios[],int tamM, int tamT, int tamC, int tamS)
{
    InicializarBicicleta(bicicletas,tamM);
    for(int i =0; i<TAMINICIALVECBICI; i++)
    {
        bicicletas[i].id = vBicicletas[i].id;
        bicicletas[i].idColor = vBicicletas[i].idColor;
        bicicletas[i].idTipo = vBicicletas[i].idTipo;
        strcpy(bicicletas[i].marca,vBicicletas[i].marca);
        bicicletas[i].rodado = vBicicletas[i].rodado;
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

    float rodados[] = {20,26,27.5,29};
    printf("Rodados disponibles :\n");
    printf("------------------------\n");

    for(int i = 0; i < TAMRODADOS ; i++)
    {
        printf("%.2f \n",rodados[i]);
    }
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

int ALTA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamBici, int tamC, int tamT, int id)
{
    char marca[20];
    int idTipo;
    int idColor;
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
    strcpy(bici.marca,marca);
    bici.rodado = rodado;
    bici.isEmpty = FALSE;

    bicicletas[pos] = bici;
    printf("Alta correcta \n");
    return FALSE;
}

int BAJA(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamBicis, int tamC, int tamT,int id)
{
    int borra;
    int pos = BuscarPosById(bicicletas,tamBicis,id);
    if(pos <0){return TRUE;}
    printf("Bicicleta a dar de baja :\n");
    MOSTRARBICI(bicicletas,tipos,colores,bicicletas[pos].id,tamBicis,tamT,tamC);
    printf("Esta seguro que desa darla de baja? SI 1, NO 0\n");
    scanf("%d",&borra);
    if(borra)
    {
        bicicletas[pos].isEmpty = TRUE;
        printf("Bicicleta dada de baja\n");
    }
    return FALSE;
}

int MODIFICAR(eBicicleta bicicletas[],eColor colores[], eTipo tipos[], int tamBicis, int tamC, int tamT,int id)
{
    int pos = BuscarPosById(bicicletas,tamBicis,id);
    if(pos <0){return TRUE;}
    int modifica = 0;
    printf("Bicicleta a Modificar :\n");
    MOSTRARBICI(bicicletas,tipos,colores,bicicletas[pos].id,tamBicis,tamT,tamC);
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

void ListarBicicletas(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int tamBicis, int tamT, int tamC)
{
    OrdenarVectorBurbuja(bicicletas,tamBicis);
    for(int i = 0; i< tamBicis; i++)
    {
        if(bicicletas[i].id > 0)
        {
          MOSTRARBICI(bicicletas,tipos,colores,bicicletas[i].id,tamBicis,tamT,tamC);
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

void MOSTRARBICI(eBicicleta bicicletas[],eTipo tipos[], eColor colores[], int id, int tam, int tamT, int tamC)
{
    int index = BuscarPosById(bicicletas,tam,id);
    printf("ID  MARCA  TIPO     COLOR    RODADO\n"),
    printf("%d    %s    %s   %s     %.2f\n",bicicletas[index].id,bicicletas[index].marca,MostrarTipo(tipos,tamT,bicicletas[index].idTipo),MostrarColor(colores,tamC,bicicletas[index].idColor),bicicletas[index].rodado);
    printf("\n");
}
