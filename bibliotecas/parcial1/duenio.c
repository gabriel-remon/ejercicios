#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "duenio.h"

int initDuenio(eDuenio vec[], int tam)
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

int descripccionDuenio(eDuenio vec[],int tam, int idBusqueda, char descipcion[])
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
                strcpy(descipcion, vec[i].nombreDuenio);

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

int validarDueniotaId(eDuenio vec[],int tam,int idBusqueda)
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

int espacioLibreDuenio(eDuenio vec[], int tam)
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

int altaDuenio( eDuenio vec[],int tam)
{
    int retorno=-1;
    int posicion;
    int errorId;
    eDuenio aux;
    char exit;

    if (vec != NULL && tam > 0 )
    {
        do
        {
            posicion=espacioLibreDuenio(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }
            if(posicion>=0)
            {
                utn_clear();
                printf("******** alta duenio ********\n\n");

                do
                {
                    utn_getInt(&aux.id,"Ingrese el id del duenio","Error, id no valido\n");
                    errorId=validarDueniotaId(vec,tam,aux.id);
                    if(errorId!=-1)
                    {
                        printf("Id en uso, ingrese otro \n");
                    }

                }
                while( errorId !=-1);

                do
                {
                    utn_ingresoScring(aux.nombreDuenio,"Ingrese el nombre de la mascota","Error, nombre no valido\n",sizeof(aux.nombreDuenio));
                }
                while( esPalabra(aux.nombreDuenio, sizeof(aux.nombreDuenio) ) );

                utn_minMaxInt(&aux.edad,"Ingrese la edad del duenio: ","Error ingrese una edad valida\n",1,120);
                utn_confirmar(&aux.sexo,"Ingrese el sexo del dueño (M/F)","Error ingrese unicamente (M o F)",'F','M');

                aux.isEmpty=0;

                vec[posicion]=aux;
                printf("Duenio cargado con exito \n");

                utn_confirmar(&exit,"\nDesea ingresar otro duenio?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');

            }
            else
            {
                utn_clear();
                printf("No se pueden cargar mas duenios, para hacerlo realice la baja de un duenio");
                exit='N';
            }
        }
        while(exit=='S');


    }

    return retorno;
}
int mostrarDuenios( eDuenio vec[],int tam)
{
    int todoOk =-1;

    if (vec != NULL && tam > 0)
    {
        printf("      *** Lista duenios *** \n\n");
        printf("Id        nombre duenio       edad      sexo \n");
        for (int i = 0; i < tam; i++)
        {

            if(!(vec[i].isEmpty))
            {
                printf("%-6d    %-10s        %d         %c \n",
                       vec[i].id,
                       vec[i].nombreDuenio,
                       vec[i].edad,
                       vec[i].sexo
                      );
            }
        }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}
