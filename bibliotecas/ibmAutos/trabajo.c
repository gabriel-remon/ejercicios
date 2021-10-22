#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "color.h"
#include "marca.h"
#include "auto.h"
#include "trabajo.h"
#include "servicio.h"


int initTrabajo(eTrabajo vec[], int tam)
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

int altaTrabajo( eTrabajo vec[],int tam,eAuto aut[], int tamAut,eMarca mar[], int tamMar,eColor col[], int tamCol,eServicio ser[],int tamSer,int* idIngreso)
{
    int retorno=-1;
    int posicion;
    int id;
    eTrabajo aux;
    char exit='n';

    if (vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0  && ser!=NULL &&tamSer>0 && idIngreso!=NULL)
    {

        if(espacioLibreAuto(aut,tamAut)>=0)
        {
            do
            {
                posicion=espacioLibreTrabajo(vec,tam);
                if(posicion==-2)
                {
                    posicion=0;
                }
                if(posicion>=0)
                {
                    utn_clear();
                    printf("******** alta trabajo ********\n");
                    mostrarAuto(aut,tamAut,mar,tamMar,col,tamCol);

                    utn_getInt(&id, "Ingrese el id del auto: ","Error id invalido, ");
                    if(buscarAutoId(aut,tamAut,id)>=0)
                    {

                        aux.patente=id;
                        mostrarServicio(ser,tamSer);
                        do
                        {
                            utn_getInt(&aux.idServicio,"Ingrese el id de un servicio","Error, servicio no valido");
                        }
                        while(validarServicio(ser,tamSer,aux.idServicio)==0);
                        get_fecha(&aux.fecha,"Ingrese la fecha del trabajo "," Error, Ingrese una fecha valido\n");
                        aux.isEmpty=0;
                        aux.id= (*idIngreso);
                        (*idIngreso)++;

                        vec[posicion]=aux;
                        printf("Trabajo cargado con exito \n");


                    }
                    else
                    {
                        printf("\nId no encontrado\n");
                    }
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    printf("No se pueden cargar Trabajos");
                    exit='n';
                }
            }
            while(exit=='y');
        }
        else
        {
            printf("Primero deve cargar un auto.");
            retorno=1;
        }
    }

    return retorno;
}

int espacioLibreTrabajo(eTrabajo vec[], int tam)
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
