#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opcion;
    system("cls");
    printf("Red Social\n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir lista\n");
    printf("3- Asignar estadisticas\n");
    printf("4- Filtrar por mejores posteos\n");
    printf("5- Filtrar por haters\n");
    printf("6- Ordenar por nivel de cantidad de followers\n");
    printf("7- Mostrar mas popular\n");
    printf("8- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
