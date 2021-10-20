#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

int cargarDescripcionLocalidad( eLocalidad localidades[], int tam,int idLocalidad, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (localidades != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (localidades[i].id == idLocalidad)
            {
                strcpy(descripcion, localidades[i].descripcion);
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

int mostrarLocalidades( eLocalidad localidades[], int tam )
{
    int todoOk = 0;
    if (localidades != NULL && tam > 0 )
    {
        printf("      *** Localidades *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",
                    localidades[i].id,
                    localidades[i].descripcion
                    );
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int validarIdLocalidad( int id, eLocalidad localidades[], int tam )
{
    int esValido = 0;
    if (localidades != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == localidades[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
