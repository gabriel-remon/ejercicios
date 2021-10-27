#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "color.h"
#include "tipo.h"
#include "bicicleta.h"

int initBici(eBici vec[], int tam)
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


int validarBici(eBici vec[],int tam,int idBusqueda)
{
    int esValido = 0;
    if (vec!= NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (idBusqueda == vec[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int mostrarBici(eBici vec[], int tam ,eTipo mar[], int tamMar ,eColor col[], int tamCol)
{
    int todoOk =-1;
    char color[20];
    char tipo[20];

    if (vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0)
    {
        ordenarBici(vec,tam);
        printf("      *** Lista autos *** \n\n");
        printf("Id        marca        color          tipo        rodado \n");
        for (int i = 0; i < tam; i++)
        {
            if(!(vec[i].isEmpty))
            {
                descripccionColor(col,tamCol,col[i].id,color);
                descripccionTipo(mar,tamMar,mar[i].id,tipo);
                printf("%d       %-10s   %-10s    %-10s    %d\n",
                       vec[i].id,
                       vec[i].marca,
                       color,
                       tipo,
                       vec[i].rodado
                      );
            }
        }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}

int altaBici( eBici vec[], int tam ,eTipo mar[], int tamMar ,eColor col[], int tamCol)
{
    int retorno=-1;
    int posicion;
    eBici aux;
    char exit;

    if(vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0)
    {
        do
        {
            utn_clear();

            posicion=espacioLibreBici(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }
            if(posicion>=0)
            {
                do{
                utn_getInt(&aux.id,"Ingrese el id de la bicicleta","Error ingrese un numero valido");
                }while(buscarBiciId(vec,tam,aux.id) != -1);
                do{
                utn_ingresoScring(aux.marca,"Ingrese la marca de la bicicleta","Error ingrese un dato valido \n",sizeof(aux.marca));
                }while( esPalabra(aux.marca,sizeof(aux.marca)) != 0 );
                mostrarTipo(mar,tamMar);
                do
                {
                    utn_getInt(&aux.idTipo,"Ingrese el id del tipo","Error ingrese un id valido");
                }
                while(validarTipo(mar,tamMar,aux.idTipo)==0);

                mostrarColor(col,tamCol);
                do
                {
                    utn_getInt(&aux.idColor,"Ingrese el id del color","Error ingrese un id valido");
                }
                while(validarColor(col,tamCol,aux.idColor)==0);

                do{

                    utn_getInt(&aux.rodado,"Ingrese el rodado (20,26,27.5 o 29)", "Error ingrese un numero valido");

                }while(!(aux.rodado == 20 || aux.rodado == 26 || aux.rodado ==27.5 || aux.rodado ==29));

                aux.isEmpty=0;
                vec[posicion]=aux;

                printf("persona cargada con exito\n");
                utn_getCharDos(&exit,"\nDesea dar de alta otra persona?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');

                retorno=0;
            }
            else
            {
                printf("No hay espacio para cargar mas autos.\nPara hacerlo deve dar de baja a un auto actual.");
                exit='n';
                retorno=1;
            }
        }
        while(exit=='y');
    }
    return retorno;
}


int modificarBici( eBici vec[], int tam ,eTipo mar[], int tamMar ,eColor col[], int tamCol)
{
    int retorno=-1;
    int posicion;
    int id;
    //eAuto aux;
    char exit='n';

    if (vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0 )
    {

        if(espacioLibreBici(vec,tam)>=0)
        {
            do
            {
                utn_clear();
                printf("******** Modoficacion autos ********\n");
                mostrarBici(vec,tam,mar,tamMar,col,tamCol);

                utn_getInt(&id, "Ingrese el id de la persona a modificar: ","Error id invalido, ");
                posicion=buscarBiciId(vec,tam,id);
                if(posicion>=0)
                {
                    do
                    {
                        mostrarUnaBici(&vec[posicion],mar,tamMar,col,tamCol);
                        switch(modificacion())
                        {

                        case 1:
                            mostrarTipo(mar,tamMar);
                            do
                            {
                                utn_getInt(&vec[posicion].idTipo,"ingrese el id de la marca", "Error, ingrese un id valido\n");
                            }
                            while(!validarTipo(mar,tamMar,vec[posicion].idTipo));
                            printf("\nmarca cambiado correctamente\n");
                            break;

                        case 2:
                             do{

                                utn_getInt(&vec[posicion].rodado,"Ingrese el rodado (20,26,27.5 o 29)", "Error ingrese un numero valido");
                            }while(!(vec[posicion].rodado == 20 || vec[posicion].rodado == 26 || vec[posicion].rodado ==27.5 || vec[posicion].rodado ==29));
                            printf("\nrodado cambiado correctamente\n");
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
            printf("Primero deve cargar un auto.");
            retorno=1;
        }
    }

    return retorno;
}


int espacioLibreBici(eBici vec[], int tam)
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

int buscarBiciId(eBici vec[],int tam,int id)
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

int mostrarUnaBici( eBici* vec,eTipo mar[], int tamMar ,eColor col[], int tamCol)
{
    int retorno=-1;
    char color[20];
    char tipo[20];

    if (vec != NULL &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0 )
    {
        utn_clear();
        if( !(vec->isEmpty) )
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripccionTipo(mar,tamMar,vec->idTipo,tipo);
            printf("Datos del auto:\n\n");
            printf("Id: %d  Marca: %s \ncolor: %s \ntipo: %s \nrodado: %d \n",
                   vec->id,
                   vec->marca,
                   color,
                   tipo,
                   vec->rodado
                  );
        }

        printf("\n\n");
        retorno=0;
    }
    return retorno;
}


int modificacion()
{
    int retorno;

    printf("1-color\n");
    printf("2-modelo\n");
    printf("3-salir");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 3",1,3);

    utn_clear();
    return retorno;
}

int menu()
{
    int retorno;

    printf("-----------------Registro de personas---------------\n\n");

    printf("1- alta persona\n");
    printf("2- baja persona\n");
    printf("3- modificacion persona\n");
    printf("4- ordenar personas\n");
    printf("5- lista personas\n");
    printf("6- lista mujeres\n");
    printf("7- lista localidades\n");
    printf("8- mostrar personas una localidad\n");
    printf("9- mostrar personas por localidad\n");

    printf("10-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 10",1,10);
    utn_clear();
    return retorno;
}

int ordenarBici(eBici vec[],int tam)
{
    int retorno = -1;
    eBici aux;
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

                if( !(vec[j].isEmpty) &&
                        ((vec[i].idTipo > vec[j].idTipo ) ||
                         (vec[i].rodado> vec[j].rodado && vec[i].idTipo == vec[j].idTipo)
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

int bajaBici( eBici vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{
    int retorno=-1;
    int posicion;
    int id;
    //eAuto aux;
    char exit='N';
    char confirmar;

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

            do
            {
        if(espacioLibreBici(vec,tam)>=0)
        {
                utn_clear();
                printf("******** baja bici ********\n");
                mostrarBici(vec,tam,tip,tamTip,col,tamCol);

                utn_getInt(&id, "Ingrese el id de la bici a modificar: ","Error id invalido, ");
                posicion=buscarBiciId(vec,tam,id);
                if(posicion>=0)
                {

                        mostrarUnaBici(&vec[posicion],tip,tamTip,col,tamCol);

                            utn_getCharDos(&confirmar, "Esta seguro que desea dar de baja a esta mascota? (S/N) ", "Error ingrese 'S' o 'N'\n", 'S','N');
                            if(confirmar=='S')
                            {
                                vec[posicion].isEmpty=1;
                                printf("bici dada de baja");
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
                utn_getCharDos(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
        }
        else
        {
            utn_clear();
            exit='N';
            printf("Primero deve cargar un trabajo.");
            retorno=1;
        }
            }
            while(exit=='S');
    }

    return retorno;
}
