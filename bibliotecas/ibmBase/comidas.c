#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comidas.h"

int cargarDescripcioncomida( eComidas comidas[], int tamCom,int idBuscador, char descripcion[] )
{
    int retorno = 0;
    int flagNoHay = 1;
    if (comidas != NULL && tamCom > 0 && descripcion != NULL)
    {
        retorno = 1;
        for (int i = 0; i < tamCom; i++)
        {
            if (comidas[i].id == idBuscador)
            {
                strcpy(descripcion, comidas[i].descripcion);
                flagNoHay = 0;
                break;
            }
        }
        if (flagNoHay)
        {
            retorno = -1; // no habia localidad con el id que le pasaron
        }
    }
    return retorno;
}

int mostrarcomidas(eComidas comidas[], int tamCom)
{
    int retorno = -1;
    if (comidas != NULL && tamCom > 0 )
    {
        printf("      *** Comidas *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tamCom; i++)
        {
            printf("  %d       %-10s\n",
                    comidas[i].id,
                    comidas[i].descripcion
                    );
        }
        retorno = 0;
    }

    return retorno;
}

int validarComidas(int idBuscador, eComidas comidas[], int tamCom)
{
    int retorno = 0;
    if (comidas != NULL && tamCom > 0 )
    {
        for (int i = 0; i < tamCom; i++)
        {
            if(comidas[i].id==idBuscador)
            {
                retorno=1;
                break;
            }
        }
    }

    return retorno;
}


