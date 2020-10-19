#include <stdio.h>
#include <stdlib.h>
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Servicios.h"
#include "Validaciones.h"
#include "Common.h"
#define TAMBicis 20
#define TAMColores 5
#define TAMTIPOS 4
#define TAMServicio 3
#define TAMTrabajos 100
#define TRUE 1
#define FALSE 0

int main()
{
    int opcion = 0;
    eBicicleta bicicletas[TAMBicis];
    eColor colores[TAMColores];
    eTipo tipos[TAMTIPOS];
    eServicio servicios[TAMServicio];
    eTrabajo trabajos[TAMTrabajos];
    int exit= FALSE;
    int diAltaPrimero = FALSE;
    inicializarVectores(bicicletas,tipos,colores,servicios,TAMBicis,TAMTIPOS,TAMColores,TAMServicio);
    inicializarTrabajosBici(trabajos,TAMTrabajos);
    opcion =common_getMenu("1 ALTA BICICLETA\n2 MODIFICAR BICICLETA:\n3 BAJA BICICLETA\n4 LISTAR BICICLETA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 SALIR","Opcion invalida. Reingrese",1,10,3);
    int idBicicleta = 4;
    int idTrabajo = 0;
    do
    {
        int id ;
        idBicicleta++;
        idTrabajo++;
        switch(opcion)
        {
        case 1:
            if(!ALTA(bicicletas,colores,tipos,TAMBicis,TAMColores,TAMTIPOS,idBicicleta))
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
                printf("Ingrese Id a modificar \n");
                ListarBicicletas(bicicletas,tipos,colores,TAMBicis,TAMTIPOS,TAMColores);
                scanf("%d",&id);
                while(!validaciones_ValidarBicicleta(bicicletas,TAMBicis,id))
                {
                    printf("La bicicleta elegida es invalida. Reingrese Id a modificar \n");
                    ListarBicicletas(bicicletas,tipos,colores,TAMBicis,TAMTIPOS,TAMColores);
                    scanf("%d",&id);
                }
                if(MODIFICAR(bicicletas,colores,tipos,TAMBicis,TAMColores,TAMTIPOS,id))
                {
                    printf("Modificacion invalida \n");
                }
            }
            else
            {
                printf("Primero tiene que dar de alta una bicicleta \n");
            }
            break;
        case 3:
            if(diAltaPrimero)
            {
                printf("Ingrese Id a dar de baja \n");
                ListarBicicletas(bicicletas,tipos,colores,TAMBicis,TAMTIPOS,TAMColores);
                scanf("%d",&id);
                while(!validaciones_ValidarBicicleta(bicicletas,TAMBicis,id))
                {
                    printf("La bicicleta elegia no es valida. Reingrese Id a dar de baja \n");
                    ListarBicicletas(bicicletas,tipos,colores,TAMBicis,TAMTIPOS,TAMColores);
                    scanf("%d",&id);
                }
                if(BAJA(bicicletas,colores,tipos,TAMBicis,TAMColores,TAMTIPOS,id))
                {
                    printf("BAJA INVALIDA \n");
                }
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 4:
            if(diAltaPrimero)
            {
                ListarBicicletas(bicicletas,tipos,colores,TAMBicis,TAMTIPOS,TAMColores);
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
                if(AltaTrabajo(trabajos,bicicletas,tipos,colores,servicios,TAMTrabajos,TAMBicis,TAMTIPOS,TAMColores,TAMServicio,idTrabajo))
                {
                    printf("Alta de trabajo invalida \n");
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
                listarTrabajos(trabajos,bicicletas,tipos,colores,servicios,TAMTrabajos,TAMBicis,TAMTIPOS,TAMColores,TAMServicio);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 10:
            printf("El sistema se va a cerrar\n");
            exit = TRUE;
            break;
        }

        if(!exit)
        {
            printf("¿Desea continuar operador? YES 1 NOT 0\n");
            scanf("%d",&exit);
            exit = !exit;
            system("cls");
        }
        if(!exit)
        {
            opcion =common_getMenu("1 ALTA BICICLETA\n2 MODIFICAR BICICLETA:\n3 BAJA BICICLETA\n4 LISTAR BICICLETA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 SALIR","Opcion invalida. Reingrese",1,10,3);
            system("pause");
        }

    }
    while(!exit && opcion != 10 );
    return 0;
}
