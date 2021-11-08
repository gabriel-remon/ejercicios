#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "color.h"


int validarColor(eColor vec[],int tam,int idBusqueda)
{
    int esValido = 0;
    if (vec!= NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (idBusqueda == vec[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int descripccionColor(eColor vec[],int tam, int idBusqueda, char descipcion[])
{
    int todoOk = -2;
    int flag = 1;
    if (vec != NULL && tam> 0 && descipcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (vec[i].id == idBusqueda)
            {
                strcpy(descipcion, vec[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}

int mostrarColor( eColor vec[], int tam )
{
    int todoOk = 0;
    if (vec != NULL && tam > 0 )
    {
        printf("      *** colores *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",
                   vec[i].id,
                   vec[i].descripcion
                  );
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}
