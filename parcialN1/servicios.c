#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "servicios.h"

int validarServicio(eServicio vec[],int tam,int idBusqueda)
{
    int esValido = 0;
    if (vec!= NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (idBusqueda == vec[i].id)
            {
                esValido = vec[i].precio;
                break;
            }
        }
    }
    return esValido;
}


int descripccionServicio(eServicio vec[],int tam, int idBusqueda, char descipcion[])
{
    int todoOk = -1;
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
            todoOk = -2; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}


int mostrarServicio( eServicio vec[], int tam )
{
    int todoOk = 0;
    if (vec != NULL && tam > 0 )
    {
        printf("      *** servicios *** \n\n");
        printf("Id         Descripcion        precio\n");
        for (int i = 0; i < tam; i++)
        {
            printf("%d      %-15s    $%d\n",
                   vec[i].id,
                   vec[i].descripcion,
                   vec[i].precio
                  );
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}
