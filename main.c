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
#define TAMCliente 5
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
    eCliente clientes[TAMCliente];
    int exit= FALSE;
    int diAltaPrimero = FALSE;
    inicializarVectores(bicicletas,tipos,colores,servicios,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMServicio,TAMCliente);
    inicializarTrabajos(trabajos,TAMTrabajos,TRUE);
    opcion =common_getMenu("1 ALTA BICICLETA\n2 MODIFICAR BICICLETA:\n3 BAJA BICICLETA\n4 LISTAR BICICLETA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 INFORMES\n11 SALIR","Opcion invalida. Reingrese",1,11,3);
    int idBicicleta = 4;
    int idTrabajo = 0;
    int  opcionInforme;
    //Al estar inicializado todos los vectores, no es necesario validar que los vectores y su tamaño sea <> NULL y >0
    do
    {
        int id ;
        idBicicleta++;
        idTrabajo++;
        switch(opcion)
        {
        case 1:
            if(!ALTA(bicicletas,colores,tipos,clientes,TAMBicis,TAMColores,TAMTIPOS,idBicicleta,TAMCliente))
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
                ListarBicicletas(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                scanf("%d",&id);
                while(!validaciones_ValidarBicicleta(bicicletas,TAMBicis,id))
                {
                    printf("La bicicleta elegida es invalida. Reingrese Id a modificar \n");
                    ListarBicicletas(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                    scanf("%d",&id);
                }
                if(MODIFICAR(bicicletas,colores,tipos,clientes,TAMBicis,TAMColores,TAMTIPOS,id,TAMCliente))
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
                ListarBicicletas(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                scanf("%d",&id);
                while(!validaciones_ValidarBicicleta(bicicletas,TAMBicis,id))
                {
                    printf("La bicicleta elegia no es valida. Reingrese Id a dar de baja \n");
                    ListarBicicletas(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                    scanf("%d",&id);
                }
                if(BAJA(bicicletas,colores,tipos,clientes,TAMBicis,TAMColores,TAMTIPOS,id,TAMCliente))
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
                ListarBicicletas(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
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
                if(AltaTrabajo(trabajos,bicicletas,tipos,colores,servicios,clientes,TAMTrabajos,TAMBicis,TAMTIPOS,TAMColores,TAMServicio,idTrabajo,TAMCliente))
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
                listarTrabajos(trabajos,bicicletas,tipos,colores,servicios,clientes,TAMTrabajos,TAMBicis,TAMTIPOS,TAMColores,TAMServicio,TAMCliente);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 10:
                opcionInforme = common_getMenu("1 BICICLETAS POR COLOR\n2 BICICLETAS POR TIPO\n3 BICICLETAS MENOR RODADO\n4 BICICLETAS AGRUPADAS POR TIPO\n5 CANTIDAD DE BICICLETAS POR TIPO Y COLOR\n6 COLORES MAS ELEGIDOS POR LOS CLIENTES\n7 TRABAJOS POR BICICLETA\n8 Informar sumatoria de servicios de bicicleta\n9 Mostrar bicicletas por servicio\n10 Mostrar servicios por fecha\n11 SALIR DE INFORMES","Opcion invalida. Reingrese",1,11,3);
                system("cls");
                switch(opcionInforme)
                {
                    case 1:
                        ListarBicletasPorColor(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                        break;
                    case 2:
                        ListarBicletasPorTipo(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                        break;
                    case 3:
                        MostrarBicletaMenorRodado(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                        break;
                    case 4:
                        ListarBicicletasPorTipo(bicicletas,tipos,colores,clientes,TAMBicis,TAMTIPOS,TAMColores,TAMCliente);
                        break;
                    case 5:
                        ContarBicletasPorTipoyColor(bicicletas,tipos,colores,TAMBicis,TAMTIPOS,TAMColores);
                        break;
                    case 6:
                        MostrarColoresMasElegidos(bicicletas,TAMBicis,colores,TAMColores);
                        break;
                    case 7:
                        ListarTrabajosRealizadosBici(trabajos,TAMTrabajos,bicicletas,clientes,TAMBicis,tipos,TAMTIPOS,servicios,TAMServicio,colores,TAMColores,TAMCliente);
                        break;
                    case 8:
                        SumarImporteTrabajosBici(trabajos,TAMTrabajos,bicicletas,TAMBicis,servicios,TAMServicio,tipos,TAMTIPOS,colores,TAMColores,clientes,TAMCliente);
                        break;
                    case 9:
                        ListaServiciosXBici(trabajos,bicicletas,clientes,servicios,tipos,colores,TAMTrabajos,TAMBicis,TAMCliente,TAMServicio,TAMTIPOS,TAMColores);
                        break;
                    case 10:
                        ServiciosxFecha(trabajos,servicios,TAMTrabajos,TAMServicio);
                        break;
                }

            break;
        case 11:
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
            opcion =common_getMenu("1 ALTA BICICLETA\n2 MODIFICAR BICICLETA:\n3 BAJA BICICLETA\n4 LISTAR BICICLETA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 INFORMES\n11 SALIR","Opcion invalida. Reingrese",1,11,3);
            system("pause");
        }

    }
    while(!exit && opcion != 11 );
    return 0;
}
