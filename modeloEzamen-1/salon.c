#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "salon.h"

int initSalon(eSalon vec[], int tam)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty=VACIO;
        }
        retorno=0;
    }

    return retorno;
}


int espacioLibreSalon(eSalon vec[], int tam)
{
    int retorno=-1;
    int flagEspacioLibre=1;
    int contadorLibres=0;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty && flagEspacioLibre)
            {
                retorno=i;
                flagEspacioLibre=0;
            }
            if(vec[i].isEmpty)
            {
                contadorLibres++;
            }
        }
        if(contadorLibres==tam)
        {
            retorno=-2;
        }
    }

    return retorno;
}

int validarTipoSalon(int entrada, char salidaTipo[])
{
    int retorno=-1;
    if(salidaTipo!=NULL)
    {
        switch(entrada)
        {
        case 1:
            strcpy(salidaTipo,"Shopping");
            break;

        case 2:
            strcpy(salidaTipo,"Local");
            break;

        default:
            strcpy(salidaTipo,"Tipo invalido");
            break;
        }
        retorno=0;
    }

    return retorno;

}

int buscarSalon(eSalon vec[],int tam,int id)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id==id && !(vec[i].isEmpty))
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
