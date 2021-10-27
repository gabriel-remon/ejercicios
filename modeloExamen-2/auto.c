#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "color.h"
#include "marca.h"
#include "auto.h"

int initAuto(eAuto vec[], int tam)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmplty=1;
        }
        retorno=0;
    }

    return retorno;
}

int descripcionCaja(char valorCaja,char descripcion[])
{
    int retorno = 0;
    if (descripcion!= NULL)
    {
        switch(valorCaja)
        {
        case 'm':
            strcpy(descripcion, "Manual");
            break;

        case 'a':
            strcpy(descripcion, "Automatica");
            break;

        default:
            strcpy(descripcion, "Dato no valido");
            break;
        }

        retorno = 1;
    }
    return retorno;
}

int validarAuto(eAuto vec[],int tam,int idBusqueda)
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

int mostrarAuto( eAuto vec[], int tam,eMarca mar[], int tamMar,eColor col[], int tamCol)
{
    int todoOk =-1;
    char color[20];
    char marca[20];
    char caja[20];

    if (vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0)
    {
        printf("      *** Lista autos *** \n\n");
        printf("Id        marca        colo          caja\n");
        for (int i = 0; i < tam; i++)
        {
            if(!(vec[i].isEmplty))
            {
                descripccionColor(col,tamCol,col[i].id,color);
                descripccionMarca(mar,tamMar,mar[i].id,marca);
                descripcionCaja(vec[i].caja,caja);
                printf("%d       %-10s   %-10s    %-10s\n",
                       vec[i].id,
                       marca,
                       color,
                       caja
                      );
            }
        }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}

int altaAuto( eAuto vec[], int tam ,eMarca mar[], int tamMar ,eColor col[], int tamCol)
{
    int retorno=-1;
    int posicion;
    eAuto aux;
    char exit;

    if(vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0)
    {
        do
        {
            utn_clear();

            posicion=espacioLibreAuto(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }
            if(posicion>=0)
            {
                utn_getInt(&aux.id,"Ingrese el id del auto","Error ingrese un numero valido");

                mostrarMarca(mar,tamMar);
                do
                {
                    utn_getInt(&aux.idMarca,"Ingrese el id de la marca","Error ingrese un id valido");
                }
                while(validarMarca(mar,tamMar,aux.idMarca)==0);

                mostrarColor(col,tamCol);
                do
                {
                    utn_getInt(&aux.idColor,"Ingrese el id del color","Error ingrese un id valido");
                }
                while(validarColor(col,tamCol,aux.idColor)==0);
                utn_getCharDos(&aux.caja,"Ingrese el tipo de caja m-manual a- automatico","Error, ingrese 'm' o 'a'\n",'m','a');

                aux.isEmplty=0;
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


int modificarAuto( eAuto vec[], int tam,eMarca mar[], int tamMar,eColor col[], int tamCol)
{
    int retorno=-1;
    int posicion;
    int id;
    //eAuto aux;
    char exit='n';

    if (vec != NULL && tam > 0  &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0 )
    {

        if(espacioLibreAuto(vec,tam)>=0)
        {
            do
            {
                utn_clear();
                printf("******** Modoficacion autos ********\n");
                mostrarAuto(vec,tam,mar,tamMar,col,tamCol);

                utn_getInt(&id, "Ingrese el id de la persona a modificar: ","Error id invalido, ");
                posicion=buscarAutoId(vec,tam,id);
                if(posicion>=0)
                {
                    do
                    {
                        mostrarUnAuto(&vec[posicion],mar,tamMar,col,tamCol);
                        switch(modificacion())
                        {
                        case 1:
                            mostrarColor(col,tamCol);
                            do
                            {
                                utn_getInt(&vec[posicion].idColor,"ingrese el id del color", "Error, ingrese un id valido\n");
                            }
                            while(!validarColor(col,tamCol,vec[posicion].idColor));
                            printf("\ncolor cambiado correctamente\n");
                            break;

                        case 2:
                            mostrarMarca(mar,tamMar);
                            do
                            {
                                utn_getInt(&vec[posicion].idMarca,"ingrese el id de la marca", "Error, ingrese un id valido\n");
                            }
                            while(!validarMarca(mar,tamMar,vec[posicion].idMarca));
                            printf("\nmarca cambiado correctamente\n");
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


int espacioLibreAuto(eAuto vec[], int tam)
{
    int retorno=-1;
    int flagEspacioLibre=1;
    int contadorLibres=0;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmplty && flagEspacioLibre)
            {
                retorno=i;
                flagEspacioLibre=0;
            }
            if(vec[i].isEmplty)
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

int buscarAutoId(eAuto vec[],int tam,int id)
{
    int retorno=-1;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id==id && !(vec[i].isEmplty))
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int mostrarUnAuto( eAuto* vec,eMarca mar[], int tamMar,eColor col[], int tamCol)
{
    int retorno=-1;
    char color[20];
    char marca[20];
    char caja[20];
    if (vec != NULL &&mar!=NULL &&tamMar> 0 &&col!=NULL && tamCol>0 )
    {
        utn_clear();
        if( !(vec->isEmplty) )
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripccionMarca(mar,tamMar,vec->idMarca,marca);
            descripcionCaja(vec->caja,caja);
            printf("Datos del auto:\n\n");
            printf("Id: %d \ncolor: %s \nmodelo: %s \ncaja:%s \n",
                   vec->id,
                   color,
                   marca,
                   caja
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
