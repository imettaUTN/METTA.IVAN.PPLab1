#include <stdio.h>
#include <stdlib.h>
#include "Common.h"
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Servicios.h"
#include "Validaciones.h"
#define TAMBici 20
#define TAMColores 5
#define TAMTIPOS 4
#define TAMServicio 4
#define TAMTrabajos 100
#define TRUE 1
#define FALSE 0
int main()
{
    int opcion = 0;
    int idBicicleta;
    int idServicio;
    eBicicleta bicis[TAMBici];
    eColor colores[TAMColores];
    eTipo tipos[TAMTIPOS];
    eServicio servicios[TAMServicio];
    eTrabajo trabajos[TAMTrabajos];

    int diAltaPrimero = FALSE;
    inicializarVectores(bicis,tipos,colores,servicios,TAMBici,TAMTIPOS,TAMColores,TAMServicio);
    opcion =common_getMenu("1 ALTA BICLETA\n2 MODIFICAR BICICLETA:\n3 BAJA BICICLETA\n4 LISTAR BICICLETA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS","Opcion invalida. Reingrese",1,9,3);
    do
    {
        switch(opcion)
        {
        case 1:
            if(ALTA(bicis,colores,tipos,TAMBici,TAMColores,TAMTIPOS))
            {
                diAltaPrimero = TRUE;
            }
            else
            {
                printf("Alta invalida \n");
            }
            break;
        case 2:

            if(diAltaPrimero)
            {
                int id ;
                printf("Ingrese Id a modificar \n");
                scanf("%d",&id);
                MODIFICAR(bicis,id,tipos,TAMBici,TAMTIPOS);
            }
            else
            {
                printf("Primero tiene que dar de alta una bicicleta \n");
            }
            break;
        case 3:
            if(diAltaPrimero)
            {
                int id ;
                printf("Ingrese Id a dar de baja \n");
                scanf("%d",&id);
                BAJA(bicis,tipos,colores,id,TAMBici,TAMTIPOS,TAMColores);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 4:
            if(diAltaPrimero)
            {
                ListarBicicletas(bicis,tipos,colores,TAMBici,TAMTIPOS,TAMColores);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 5:
            if(diAltaPrimero)
            {
                ListarTipos(tipos,TAMTIPOS);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 6:
            if(diAltaPrimero)
            {
                ListarColores(colores,TAMColores);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 7:
            if(diAltaPrimero)
            {
                listarServicios(servicios,TAMServicio);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 8:
            if(diAltaPrimero)
            {

                printf("Seleccione el id de la bicicleta sobre la que se realizara el trabajo\n");
                ListarBicicletas(bicis,tipos,colores,TAMBici,TAMTIPOS,TAMColores);
                scanf("%d",&idBicicleta);
                printf("Seleccione el id de servicio a realizar \n");
                listarServicios(servicios,TAMServicio);
                scanf("%d",&idServicio);

                if(validaciones_ValidarBicicleta(bicis,TAMBici,idBicicleta) && validaciones_ValidarServicio(servicios,TAMServicio,idServicio))
                {
                    AltaTrabajo(trabajos,idBicicleta,idServicio,TAMTrabajos);
                }
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 9:
            if(diAltaPrimero)
            {
                listarTrabajos(trabajos,bicis,tipos,colores,servicios,TAMTrabajos,TAMBici,TAMTIPOS,TAMColores,TAMServicio);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        }
        system("pause");
        system("cls");
        opcion =common_getMenu("1 ALTA BICLETA\n2 MODIFICAR BICICLETA:\n3 BAJA BICICLETA\n4 LISTAR BICICLETA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS","Opcion invalida. Reingrese",1,9,3);

    }
    while(opcion != 9 );
    return 0;
}
