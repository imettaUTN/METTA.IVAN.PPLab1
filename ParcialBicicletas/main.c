#include <stdio.h>
#include <stdlib.h>
#include "Servicio.h"
#include "Bicicleta.h"
int main()
{
    int opcion = 0;
    eBicicleta bicis[20];
    eColor colores[5];
    eTipo tipos[4];
    eServicio servicios[4];
    int diAltaPrimero = 0;
    InicializarColores(colores,5);
    InicializarTipo(tipos,4);
    InicializarBici(bicis,20);
    InicializarServicios(servicios,4);
    opcion =common_getMenu("A ALTA BICLETA\nB MODIFICAR BICICLETA:\nC BAJA BICICLETA\nD LISTAR BICICLETA\nE LISTAR TIPOS\nF LISTAR COLORES\nG LISTAR SERVICIOS\nH ALTA TRABAJO\nI LISTAR TRABAJOS","Opcion invalida. Reingrese",1,9,3);
    do
    {
        switch(opcion)
        {
            case 1:
             if(ALTA(bicis,colores,tipos,20,5,4))
             {
                 diAltaPrimero = 1;
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
                scanf(&id);
                MODIFICAR(bicis,id,colores,tipos,20,5,4);
            }
            else
            {
                printf("Primero tiene que dar el alta \n")
            }
            break;
            case 3:
            if(diAltaPrimero)
            {
                int id ;
                printf("Ingrese Id a dar de baja \n");
                scanf(&id);
                BAJA(bicis,ID,20);
            }
            else
            {
                printf("Primero tiene que dar el alta \n")
            }
            break;
            case 4:
            ListarTipos(tipos,4);
            break;
            case 5:
            ListarColores(colores,5);
            break;
            case 6:
            listarServicios(servicios,4);s
            break;
            case 7: break;
            case 8: break;
            case 9: break;
        }
        system("pause");
        system("cls");
    opcion =common_getMenu("A ALTA BICLETA\nB MODIFICAR BICICLETA:\nC BAJA BICICLETA\nD LISTAR BICICLETA\nE LISTAR TIPOS\nF LISTAR COLORES\nG LISTAR SERVICIOS\nH ALTA TRABAJO\nI LISTAR TRABAJOS","Opcion invalida. Reingrese",1,9,3);

    }
    while(!exit && opcion != 5 );
    return 0;
}
