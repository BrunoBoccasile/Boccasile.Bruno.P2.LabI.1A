#include <stdio.h>
#include <stdlib.h>
#include "salida.h"
#include "validaciones.h"
#include "LinkedList.h"

int main()
{
    char salir = 'n';
    LinkedList* lista = ll_newLinkedList();
    int banderaCarga;
    banderaCarga = 0;
    int banderaAsignacion;
    banderaAsignacion = 0;


    do
    {
        system("cls");

        switch(menu())
        {
        case 1:
            system("cls");
            if(banderaCarga != 1)
            {
                if(controller_cargarPosteos("posts.csv", lista))
                {
                    banderaCarga = 1;
                    printf("Posteos cargados con exito\n");
                }
                else
                {
                    printf("No se pudieron cargar los posteos\n");
                }
            }
            else
            {
                printf("Los posteos ya fueron cargados\n");
            }

            break;
        case 2:
            system("cls");
            if(!ll_isEmpty(lista))
            {
                if(!controller_listarPosteos(lista))
                {
                    printf("No se pudieron listar los posteos\n");
                }
            }
            else
            {
                printf("La lista de posteos esta vacia\n");
            }

            break;
        case 3:
        system("cls");

            if(!ll_isEmpty(lista))
            {
                if(controller_asignarEstadisticas(lista))
                {
                    banderaAsignacion = 1;
                    printf("Estadisticas asignadas con exito\n");
                }
                else
                {
                    printf("No se pudieron asignar las estadisticas\n");
                }
            }
            else
            {
                printf("La lista de posteos esta vacia\n");
            }

            break;
        case 4:
            system("cls");
            if(!ll_isEmpty(lista))
            {
                if(banderaAsignacion == 1)
                {
                                    if(controller_guardarMejoresPosteos("mejoresPosteos.csv", lista))
                {
                    printf("\nMejores posteos guardados con exito\n");
                }
                else
                {
                    printf("No se pudieron guardar los mejores posteos\n");
                }
                }
                else
                {
                    printf("Primero debe asignar las estadisticas\n");
                }

            }
            else
            {
                printf("La lista de posteos esta vacia\n");
            }

            break;
        case 5:
            system("cls");
            if(!ll_isEmpty(lista))
            {
                if(banderaAsignacion == 1)
                {
                if(controller_guardarHaters("posteosHateados.csv", lista))
                {
                    printf("\nPosteos hateados guardados con exito\n");
                }
                else
                {
                    printf("No se pudieron guardar los posteos hateados\n");
                }
                }
                else
                {
                    printf("Primero debe asignar las estadisticas\n");
                }

            }
            else
            {
                printf("La lista de posteos esta vacia\n");
            }
            break;
        case 6:
            system("cls");
            if(!ll_isEmpty(lista))
            {
                if(banderaAsignacion == 1)
                {
                if(!controller_mostrarCantidadFollowers(lista))
                {
                    printf("No se pudieron mostrar los posteos ordenados por followers\n");
                }
                }
                else
                {
                    printf("Primero debe asignar las estadisticas\n");
                }

            }
            else
            {
                printf("La lista de posteos esta vacia\n");
            }
            break;
        case 7:
                        system("cls");
            if(!ll_isEmpty(lista))
            {
                if(banderaAsignacion == 1)
                {
                if(!controller_informarMasPopular(lista))
                {
                    printf("No se pudieron informar los posteos mas populares\n");
                }
                }
                else
                {
                    printf("Primero debe asignar las estadisticas\n");
                }

            }
            else
            {
                printf("La lista de posteos esta vacia\n");
            }
            break;
        case 8:
            system("cls");
            if(confirmarSalida())
            {
                salir ='s';
            }
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");

    }
    while(salir == 'n');
    return 0;
}
