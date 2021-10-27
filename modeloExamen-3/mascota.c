#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "mascota.h"

int initMascotas(eMascota vec[], int tam)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty=1;

        }
        retorno=0;
    }

    return retorno;
}

int descripccionMascota(eMascota vec[],int tam, int idBusqueda, char descipcion[])
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
                strcpy(descipcion, vec[i].nombreMascota);

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

int validarMarcotaId(eMascota vec[],int tam,int idBusqueda)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id==idBusqueda && !(vec[i].isEmpty))
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int mostrarUnaMacota( eMascota* vec)
{
    int retorno=-1;

    if (vec != NULL )
    {
        utn_clear();
        if(!(vec->isEmpty))
        {
            printf("id: %d   \nNombre mascota: %-10s   \nedad: %d    \nraza: %s \n",
                   vec->id,
                   vec->nombreMascota,
                   vec->edad,
                   vec->raza
                  );
        }
    }
    printf("\n\n");
    retorno=0;

    return retorno;
}
