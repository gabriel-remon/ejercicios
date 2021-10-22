#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "trabajo.h"
#include "servicios.h"


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

int altaTrabajo( eTrabajo vec[],int tam,eServicio ser[], int tamSer, int* idIngreso)
{
    int retorno=-1;
    int posicion;
    eTrabajo aux;
    char exit;

    if (vec != NULL && tam > 0 && ser!=NULL &&tamSer>0 && idIngreso!=NULL)
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
                printf("******** alta trabajo ********\n\n");
                mostrarServicio(ser,tamSer);
                do
                {
                    utn_getInt(&aux.idServicio,"Ingrese el servicio deseado","Error, ingrese un numero valido\n");

                }
                while(validarServicio(ser,tamSer,aux.idServicio) == 0);

                do
                {
                    utn_ingresoScring(aux.nombreMascota,"Ingrese el nombre de la mascota","Error, nombre no valido\n",sizeof(aux.nombreMascota));
                }
                while( esPalabra(aux.nombreMascota, sizeof(aux.nombreMascota) ) );

                get_fecha(&aux.fecha,"Ingrese la fecha del trabajo "," Error, Ingrese una fecha valido\n");
                aux.isEmpty=0;
                aux.id= (*idIngreso);
                (*idIngreso)++;

                vec[posicion]=aux;
                printf("Trabajo cargado con exito \n");

                utn_getCharDos(&exit,"\nDesea ingresar otro trabajo?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');

            }
            else
            {
                printf("No se pueden cargar Trabajos, para hacerlo de de baja un trabajo");
                exit='n';
            }
        }
        while(exit=='y');


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

int menu()
{
    int retorno;

    printf("-----------------Registro de veterinaria---------------\n\n");

    printf("1- alta trabajo\n");
    printf("2- modificacion trabajo\n");
    printf("3- baja trabajo\n");
    printf("4- lista Trabajos\n");
    printf("5- lista Servicios\n");
    printf("6- Total\n");

    printf("7-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 7",1,7);
    return retorno;
}

int modificacion()
{
    int retorno;

    printf("1-nombre mascota\n");
    printf("2-servicio\n");
    printf("3-salir");

    utn_minMaxInt(&retorno,"\nIngrese la opcion a modificar: ", "Error, ingrese un numero entre el 1 y el 3",1,3);

    utn_clear();
    return retorno;
}

int modificarTrabajo( eTrabajo vec[], int tam,eServicio ser[], int tamSer)
{
    int retorno=-1;
    int posicion;
    int id;
    //eAuto aux;
    char exit='n';

    if (vec != NULL && tam > 0  && ser!= NULL && tamSer>0)
    {

        if(espacioLibreTrabajo(vec,tam)>=0)
        {
            do
            {
                utn_clear();
                printf("******** Modoficacion trabajos ********\n");
                mostrarTrabajo(vec,tam,ser,tamSer);

                utn_getInt(&id, "Ingrese el id de la persona a modificar: ","Error id invalido, ");
                posicion=buscarTrabajoId(vec,tam,id);
                if(posicion>=0)
                {
                    do
                    {
                        mostrarUnTrabajo(&vec[posicion],ser,tamSer);
                        switch(modificacion())
                        {
                        case 1:
                            do
                            {
                                utn_ingresoScring(vec[posicion].nombreMascota,"Ingrese el nombre de la mascota","Error, nombre no valido\n",sizeof(vec[posicion].nombreMascota));
                            }
                            while( esPalabra(vec[posicion].nombreMascota, sizeof(vec[posicion].nombreMascota) ) );
                            printf("\nombre cambiado correctamente\n");
                            break;

                        case 2:
                            mostrarServicio(ser,tamSer);
                            do
                            {
                                utn_getInt(&vec[posicion].idServicio,"Ingrese el servicio deseado","Error, ingrese un numero valido\n");

                            }
                            while(validarServicio(ser,tamSer,vec[posicion].idServicio) == 0);
                            printf("\nservicio cambiado correctamente\n");
                            break;

                        case 3:
                            utn_getCharDos(&exit, "Esta seguro que desea salir (y/n)?", "Error ingrese 'y' o 'n'\n", 'y','n');
                            break;
                        }

                        retorno=0;
                        utn_stop();
                    }
                    while(exit=='n');
                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
            }
            while(exit=='y');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar un trabajo.");
            retorno=1;
        }
    }

    return retorno;
}

int mostrarTrabajo(eTrabajo vec[], int tam,eServicio ser[], int tamSer)
{
    int todoOk =-1;
    char servicio[20];
    int precioServicio;


    if (vec != NULL && tam > 0  && ser!=NULL && tamSer>0)
    {
        printf("      *** Lista trabajos *** \n\n");
        printf("Id        nombre mascota        servicio       precio       fecha\n");
        for (int i = 0; i < tam; i++)
        {
            if(!(vec[i].isEmpty))
            {
                descripccionServicio(ser,tamSer,vec[i].idServicio,servicio);
                precioServicio= validarServicio(ser,tamSer,vec[i].idServicio);
                printf("%d      %-10s            %-13s  $%d         %02d/%02d/%04d\n",
                       vec[i].id,
                       vec[i].nombreMascota,
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

int buscarTrabajoId(eTrabajo vec[],int tam,int id)
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

int mostrarUnTrabajo( eTrabajo* vec,eServicio ser[], int tamSer)
{
    int retorno=-1;
    char servicio[20];
    int precioServicio;

    if (vec != NULL && ser!=NULL && tamSer>0 )
    {
        utn_clear();
        if(!(vec->isEmpty))
        {
            descripccionServicio(ser,tamSer,vec->idServicio,servicio);
            precioServicio= validarServicio(ser,tamSer,vec->idServicio);
            printf("id: %d   \nNombre mascota: %-10s   \nservicio: %-10s    \ncosto: $%d  \nfecha: %02d/%02d/%04d\n",
                   vec->id,
                   vec->nombreMascota,
                   servicio,
                   precioServicio,
                   vec->fecha.dia,
                   vec->fecha.mes,
                   vec->fecha.anio
                  );
        }
    }
    printf("\n\n");
    retorno=0;

    return retorno;
}
int bajaTrabajo(eTrabajo vec[], int tam,eServicio ser[], int tamSer)
{
    int retorno=-1;
    int posicion;
    int id;
    //eAuto aux;
    char exit='n';
    char confirmar;

    if (vec != NULL && tam > 0  && ser!= NULL && tamSer>0)
    {

        do
        {
            if(espacioLibreTrabajo(vec,tam)>=0)
            {
                utn_clear();
                printf("******** baja trabajos ********\n");
                mostrarTrabajo(vec,tam,ser,tamSer);

                utn_getInt(&id, "Ingrese el id de la persona a modificar: ","Error id invalido, ");
                posicion=buscarTrabajoId(vec,tam,id);
                if(posicion>=0)
                {

                    mostrarUnTrabajo(&vec[posicion],ser,tamSer);
                    utn_getCharDos(&confirmar, "Esta seguro que desea eliminar este trabajo (y/n)?", "Error ingrese 'y' o 'n'\n", 'y','n');

                    if(confirmar=='y')
                    {
                        vec[posicion].isEmpty=1;
                        printf("Trabajo eliminado con exito");
                    }
                    else
                    {
                        printf("Operacion cancelada por el usuario");
                    }

                    retorno=0;
                    utn_stop();

                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
            }
            else
            {
                utn_clear();
                printf("Primero deve cargar un trabajo.");
                exit='n';
                retorno=1;
            }
        }while(exit=='y');

    }

    return retorno;
}

int totalPrecioServiciosTrabajos(eTrabajo vec[], int tam,eServicio ser[], int tamSer)
{
    int retorno = 0;
    int suma=0;
    if (vec != NULL && tam > 0  && ser!= NULL && tamSer>0)
    {
        if(espacioLibreTrabajo(vec,tam)>=0)
        {
        for (int i = 0; i < tam; i++)
        {
            if(!(vec[i].isEmpty))
            {
                suma=suma+  (validarServicio(ser,tamSer,vec[i].idServicio));
            }
        }
        printf("La suma de todos los servicios prestados es: $%d",suma);
        }
        else
            {
                utn_clear();
                printf("Primero deve cargar un trabajo.");

               }

        retorno = 1;
    }

    return retorno;
}

int ordenarTrabajos(eTrabajo vec[], int tam)
{
    int retorno=-1;
    int comparadorNombre;
    eTrabajo aux;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            if(vec[i].isEmpty)
            {
                continue;
            }
            for(int j=i+1; j<tam; j++)
            {
                comparadorNombre=strncasecmp(vec[i].nombreMascota, vec[j].nombreMascota, sizeof(vec[i].nombreMascota));
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
