#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "trabajo.h"
#include "servicios.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"


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

int altaTrabajo( eTrabajo vec[],int tam,eServicio ser[], int tamSer,eMascota mas[],int tamMas,int* idIngreso,eColor col[], int tamCol,eTipo tip[], int tamTip)
{
    int retorno=-1;
    int posicion;
    int idMarcotaIngreso;
    eTrabajo aux;
    char exit;

    if (vec != NULL && tam > 0 && ser!=NULL &&tamSer>0 && idIngreso!=NULL &&mas!=NULL && tamMas>0 )
    {

        if(espacioLibreMascota(mas,tamMas)>=0)
        {

            do
            {
                if(espacioLibreTrabajo(vec,tam) ==-1)
                {
                    goto salir;
                }
                utn_clear();
                printf("******** alta trabajo ********\n\n");
                mostrarMascotas(mas,tamMas,col,tamCol,tip,tamTip);
                utn_getInt(&idMarcotaIngreso,"Ingrese el id de una mascota ","error ingrese un numero valido");
                posicion=validarMarcotaId(mas,tamMas,idMarcotaIngreso);
                if(posicion>=0)
                {
                    posicion=espacioLibreTrabajo(vec,tam);
                    if(posicion==-2)
                    {
                        posicion=0;
                    }
                    if(posicion>=0)
                    {
                        utn_clear();
                        aux.idMscota=idMarcotaIngreso;
                        mostrarServicio(ser,tamSer);
                        do
                        {
                            utn_getInt(&aux.idServicio,"Ingrese el servicio deseado","Error, ingrese un numero valido\n");

                        }
                        while(validarServicio(ser,tamSer,aux.idServicio) == 0);

                        get_fecha(&aux.fecha,"Ingrese la fecha del trabajo (formato: dia/mes/anio) "," Error, Ingrese una fecha valido\n");

                        aux.isEmpty=0;
                        aux.id= (*idIngreso);
                        (*idIngreso)++;

                        vec[posicion]=aux;
                        printf("Trabajo cargado con exito \n");

                        utn_confirmar(&exit,"\nDesea ingresar otro trabajo?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');

                    }
                    else
                    {
                        salir:
                        utn_clear();
                        printf("No se pueden cargar Trabajos, para hacerlo de de baja un trabajo");
                        exit='N';
                    }
                }
                else
                {
                    utn_clear();
                    printf("No se encontro el id ingresado\n");
                    utn_confirmar(&exit,"\nDesea ingresar otro id?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
                }

            }
            while(exit=='S');
        }
        else
        {
            utn_clear();
            printf("Primero deve cargar una mascota");
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


int mostrarTrabajo(eTrabajo vec[], int tam,eServicio ser[], int tamSer,eMascota mas[],int tamMas)
{
    int todoOk =-1;
    char servicio[20];
    char nombreMascota[20];
    int posicionNombreMascota;
    int precioServicio;


    if (vec != NULL && tam > 0  && ser!=NULL && tamSer>0 && mas!=NULL && tamMas)
    {
        printf("      *** Lista trabajos *** \n\n");
        printf("Id trabajo       Nombre mascota      Servicio        Precio        Fecha\n");
        for (int i = 0; i < tam; i++)
        {
            if(!(vec[i].isEmpty))
            {
                posicionNombreMascota=validarMarcotaId(mas,tamMas,vec[i].idMscota);
                strcpy(nombreMascota,mas[posicionNombreMascota].nombreMascota);

                descripccionServicio(ser,tamSer,vec[i].idServicio,servicio);
                precioServicio= validarServicio(ser,tamSer,vec[i].idServicio);

                printf("%-8d         %-10s          %-13s   $%d        %02d/%02d/%04d\n",
                       vec[i].id,
                       nombreMascota,
                       servicio,
                       precioServicio,
                       vec[i].fecha.dia,
                       vec[i].fecha.mes,
                       vec[i].fecha.anio
                      );
            }
        }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}



int ordenarTrabajos(eTrabajo vec[], int tam, eMascota mas[], int tamMas)
{
    int retorno=-1;
    int comparadorNombre;
    int posicionMascotaI;
    int posicionMascotaJ;
    eTrabajo aux;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            if(vec[i].isEmpty)
            {
                continue;
            }
            posicionMascotaI=validarMarcotaId(mas,tamMas,vec[i].idMscota);
            for(int j=i+1; j<tam; j++)
            {
                posicionMascotaJ=validarMarcotaId(mas,tamMas,vec[j].idMscota);
                comparadorNombre=strncasecmp(mas[posicionMascotaI].nombreMascota, mas[posicionMascotaJ].nombreMascota, sizeof(mas[0].nombreMascota));
                if( !(vec[j].isEmpty) &&
                        (vec[i].fecha.anio < vec[j].fecha.anio ||
                         (comparadorNombre>0 && vec[i].fecha.anio == vec[j].fecha.anio)
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

