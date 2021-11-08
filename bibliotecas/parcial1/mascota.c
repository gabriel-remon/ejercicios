#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int mostrarUnaMacota( eMascota* vec, eColor col[], int tamCol,eTipo tip[], int tamTip)
{
    int retorno=-1;
    char tipo[20];
    char color[20];

    if (vec != NULL  && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {
        utn_clear();
        if(!(vec->isEmpty))
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripcionTipo(tip,tamTip,vec->idTipo,tipo);
            printf("id: %d   \nNombre mascota: %-10s  \ntipo de animal: %s    \nColor: %s    \nedad: %d    \nVacunado: %c \n",
                   vec->id,
                   vec->nombreMascota,
                   tipo,
                   color,
                   vec->edad,
                   vec->vacunas
                  );
        }
    }
    printf("\n\n");
    retorno=0;

    return retorno;
}

char menu()
{
    char retorno;

    printf("-----------------Registro de veterinaria---------------\n\n");

    printf("A- ALTA MASCOTA\n");
    printf("B- MODIFICAR MASCOTA\n");
    printf("C- BAJA MASCOTA\n");
    printf("D- LISTAR MASCOTAS\n");
    printf("E- LISTAR TIPOS\n");
    printf("F- LISTAR COLORES\n");
    printf("G- LISTAR SERVICIOS\n");
    printf("H- ALTA TRABAJO\n");
    printf("I- LISTAR TRABAJOS\n");
    printf("J- LISTADOS\n");

    printf("K-SALIR\n\n");

    utn_getChar(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un caracter valido\n");
    retorno= toupper(retorno);
    utn_clear();

    return retorno;
}

int altaMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{
    int retorno=-1;
    int posicion;
    int errorId;
    eMascota aux;
    char exit;

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {
        do
        {
            posicion=espacioLibreMascota(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }
            if(posicion>=0)
            {
                utn_clear();
                printf("******** alta mascota ********\n\n");

                do
                {
                    utn_getInt(&aux.id,"Ingrese el id de la mascota","Error, id no valido\n");
                    errorId=validarMarcotaId(vec,tam,aux.id);
                    if(errorId!=-1)
                    {
                        printf("Id en uso, ingrese otro \n");
                    }

                }
                while( errorId !=-1);

                do
                {
                    utn_ingresoScring(aux.nombreMascota,"Ingrese el nombre de la mascota","Error, nombre no valido\n",sizeof(aux.nombreMascota));
                }
                while( esPalabra(aux.nombreMascota, sizeof(aux.nombreMascota) ) );


                mostrarTipo(tip,tamTip);
                do
                {
                    utn_getInt(&aux.idTipo,"Ingrese el id del tipo de mascota","Error, ingrese un numero valido\n");
                }
                while(validarTipo(tip,tamTip,aux.idTipo) == 0);

                mostrarColor(col,tamCol);
                do
                {
                    utn_getInt(&aux.idColor,"Ingrese el id del color de la mascota","Error, ingrese un numero valido\n");
                }
                while(validarColor(col,tamCol,aux.idColor) == 0);


                utn_minMaxInt(&aux.edad,"Ingrese la edad de la mascota","Erro, edad no valido",1,40);
                utn_confirmar(&aux.vacunas,"La mascota esta vacunada? (S/N) ","Error, ingrese 'S' o 'N' ",'S','N');

                aux.isEmpty=0;

                vec[posicion]=aux;
                printf("Mascota cargado con exito \n");

                utn_confirmar(&exit,"\nDesea ingresar otra mascota?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');

            }
            else
            {
                utn_clear();
                printf("No se pueden cargar mas mascotas, para hacerlo realice la baja de una mascota");
                exit='N';
            }
        }
        while(exit=='S');


    }

    return retorno;
}


int espacioLibreMascota(eMascota vec[], int tam)
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


int modificarMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{
    int retorno=-1;
    int posicion;
    int id;
    //eAuto aux;
    char exit='N';

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreMascota(vec,tam)!=-2)
        {
            do
            {
                utn_clear();
                printf("******** Modoficacion mascotas ********\n");
                mostrarMascotas(vec,tam,col,tamCol,tip,tamTip);

                utn_getInt(&id, "Ingrese el id de la mascota a modificar: ","Error id invalido, ");
                posicion=validarMarcotaId(vec,tam,id);
                if(posicion>=0)
                {
                    do
                    {
                        mostrarUnaMacota(&vec[posicion],col,tamCol,tip,tamTip);
                        switch(modificacion())
                        {
                        case 'A':
                            mostrarTipo(tip,tamTip);
                            do
                            {
                                utn_getInt(&vec[posicion].idTipo,"Ingrese el id del tipo de mascota","Error, ingrese un numero valido\n");
                            }
                            while(validarTipo(tip,tamTip,vec[posicion].idTipo) == 0);

                            printf("\nTipo de mascota cambiado correctamente\n");
                            break;

                        case 'B':
                            utn_confirmar(&vec[posicion].vacunas,"La mascota esta vacunada? (S/N) ","Error, ingrese 's' o 'n' ",'S','N');
                            printf("\nServicio cambiado correctamente\n");
                            break;

                        case 'C':
                            utn_confirmar(&exit, "Esta seguro que desea salir (S/N)?", "Error ingrese 'S' o 'n'\n", 'S','N');
                            break;
                        default:
                            printf("Error, ingrese un caracter valido");

                            break;
                        }

                        retorno=0;
                        utn_stop();
                    }
                    while(exit=='N');
                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;
}



int mostrarMascotas( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{
    int todoOk =-1;
    char color[20];
    char tipo[20];

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {
        printf("      *** Lista mascotas *** \n\n");
        printf("Id        nombre mascota       tipo animal      color      edad    vacunado?\n");
        for (int i = 0; i < tam; i++)
        {

            if(!(vec[i].isEmpty))
            {
                descripccionColor(col,tamCol,vec[i].idColor,color);
                descripcionTipo(tip,tamTip,vec[i].idTipo,tipo);
                printf("%-6d    %-10s           %-15s  %-10s %d         %c \n",
                       vec[i].id,
                       vec[i].nombreMascota,
                       tipo,
                       color,
                       vec[i].edad,
                       vec[i].vacunas
                      );
            }
        }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}
char modificacion()
{
    char retorno;

    printf("-----------------modificacion de mascotas---------------\n\n");

    printf("A- TIPO DE MASCOTA\n");
    printf("B- VACUNADO\n");

    printf("C-SALIR\n\n");

    utn_getChar(&retorno,"\nIngrese la opcion a modificar: ", "Error, ingrese un caracter valido\n");
    retorno= toupper(retorno);

    return retorno;
}


int bajaMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
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
        if(espacioLibreMascota(vec,tam)>=0)
        {
                utn_clear();
                printf("******** baja mascotas ********\n");
                mostrarMascotas(vec,tam,col,tamCol,tip,tamTip);

                utn_getInt(&id, "Ingrese el id de la mascota a modificar: ","Error id invalido, ");
                posicion=validarMarcotaId(vec,tam,id);
                if(posicion>=0)
                {

                        mostrarUnaMacota(&vec[posicion],col,tamCol,tip,tamTip);

                            utn_confirmar(&confirmar, "Esta seguro que desea dar de baja a esta mascota? (S/N) ", "Error ingrese 'S' o 'N'\n", 'S','N');
                            if(confirmar=='S')
                            {
                                vec[posicion].isEmpty=1;
                                printf("mascota dada de baja");
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
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
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

int ordenarMascotas(eMascota vec[],int tam)
{
    int retorno=-1;
    int comparadorNombre;
    eMascota aux;

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
                comparadorNombre=strncasecmp(vec[i].nombreMascota, vec[j].nombreMascota, sizeof(vec[0].nombreMascota));
                if( !(vec[j].isEmpty) &&
                        (comparadorNombre>0 ||
                        (comparadorNombre==0 && vec[i].idTipo<vec[j].idTipo)
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

