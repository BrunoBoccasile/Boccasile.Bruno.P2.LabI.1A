#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"



void validarSiNo(char* respuesta)
{
    if(*respuesta != NULL)
    {
        while(*respuesta != 's' && *respuesta != 'n')
        {
            printf("Error, ingrese 's' o 'n': ");
            fflush(stdin);
            scanf("%c", respuesta);
        }
    }
}



int confirmarSalida()
{
    char confirmacion;
    int ret;
    printf("Confirma salida?\n");
    fflush(stdin);
    scanf("%c", &confirmacion);

    validarSiNo(&confirmacion);

    if(confirmacion == 's')
    {
        ret = 1;
    }
    else if(confirmacion == 'n')
    {
        ret = 0;
    }

    return ret;
}

