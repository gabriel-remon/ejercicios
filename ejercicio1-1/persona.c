#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

void mostrarPersona(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    char localidad[30];
    if(vec!=NULL && tam>0)
    {
        printf("-----------------Lista de personas----------------- \n\n");
        printf("Id       Nombre         edad        altura             Sexo        localidad\n");
        for(int i=0; i<tam; i++)
        {
            if( !(vec[i].isEmpty) )
            {
                cargarDescripcionLocalidad(loc,tamLoc,vec[i].idLocalidad,localidad);
                printf("%d     %-10s     %d   %11.2f Mts     %7c           %s\n",
                       vec[i].id,
                       vec[i].nombre,
                       vec[i].edad,
                       vec[i].altura,
                       vec[i].sexo,
                       localidad
                      );
            }
        }
    }
}


void mostrarUnaPersona(ePersona* vec,eLocalidad loc[], int tamLoc)
{
    char localidad[30];
    if(vec!=NULL && loc!=NULL && tamLoc>0 )
    {
        utn_clear();
        if( !(vec->isEmpty) )
        {
            cargarDescripcionLocalidad(loc,tamLoc,vec->idLocalidad,localidad);

            printf("Datos de la persona:\n\n");
            printf("Id: %d \nNombre: %s \nedad: %d \nlocalidad:%s \nsexo: %c \nALtura: %.2f",
                   vec->id,
                   vec->nombre,
                   vec->edad,
                   localidad,
                   vec->sexo,
                   vec->altura
                  );
        }

        printf("\n\n");
    }
}

int removerPersona(ePersona vec[], int tam, int posicion)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        vec[posicion].isEmpty=VACIO;
        retorno=0;
    }

    return retorno;
}

int ordenasPersonas(ePersona vec[], int tam, int orden)
{
    int retorno=-1;
    int comparadorNombre;
    ePersona aux;

    if(vec!=NULL && tam>0 && (orden>=0 && orden<=7))
    {
        for(int i=0; i<tam-1; i++)
        {
            if(vec[i].isEmpty)
            {
                continue;
            }
            for(int j=i+1; j<tam; j++)
            {
                comparadorNombre=strncasecmp(vec[i].nombre, vec[j].nombre, sizeof(vec[i].nombre));
                if( !(vec[j].isEmpty) &&
                        ((comparadorNombre>0 && orden==0) ||
                         (comparadorNombre<0 && orden==1) ||
                         ((vec[i].id<vec[j].id) && orden==2) ||
                         ((vec[i].id>vec[j].id) && orden==3) ||
                         ((vec[i].sexo<vec[j].sexo) && orden==4) ||
                         ((vec[i].sexo>vec[j].sexo) && orden==5) ||
                         ((vec[i].altura<vec[j].altura) && orden==6) ||
                         ((vec[i].altura>vec[j].altura) && orden==7)

                        ))
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }

        retorno=0;
    }

    return retorno;
}



int buscarPersonaId(ePersona vec[], int tam, int id)
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

int initPersonas(ePersona vec[], int tam) //**
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty=VACIO;
            for(int j=0 ; j<(sizeof(vec[0].idComidas) / 4); j++)
            {
                vec[i].idComidas[j]=0;
            }
        }
        retorno=0;
    }

    return retorno;
}

int espacioLibre(ePersona vec[], int tam)
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

int espacioLibreComida(int vec[], int tam)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i] == 0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}
