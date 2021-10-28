#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "trabajo.h"
#include "servicios.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#include "tipo.h"

void mostrarAnimalesServicio( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra)
{
    char servicio[20];
    int posicionMascota;

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0&& ser!=NULL && tamSer>0 && tra!=NULL && tamTra>0  )
    {
        for (int i = 0; i < tamSer; i++)
        {
            descripccionServicio(ser,tamSer,ser[i].id,servicio);
            printf("Servicio realizado: %s\n",servicio);
            prototipoListaMascotasTrabajo();
            for (int j=0; j<tam; j++)
            {
                if(!(tra[j].isEmpty) && tra[j].idServicio== ser[i].id )
                {
                    posicionMascota=validarMarcotaId(vec,tam,tra[j].idMscota);
                    mostrarUnaFilaMascotaTrabajo(&vec[posicionMascota],&tra[j],col,tamCol,tip,tamTip,ser,tamSer,tra,tamTra);
                }
            }
            printf("\n\n");
        }
        printf("\n\n");
    }
}


void mostrarAnimalesColor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)

{

    char color[20];

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {


        for (int i = 0; i < tamCol; i++)
        {
            descripccionColor(col,tamCol,col[i].id,color);
            printf("Mascota color %s\n",color);
            prototipoListaMascotas();
            for (int j=0; j<tam; j++)
            {
                if(!(vec[j].isEmpty) && vec[j].idColor== col[i].id)
                {
                    mostrarUnaFilaMascota(&vec[j],col,tamCol,tip,tamTip);
                }
            }
            printf("\n\n");
        }
        printf("\n\n");

    }

}


void mostrarAnimalesTipo( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char tipo[20];

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {


        for (int i = 0; i < tamTip; i++)
        {
            descripcionTipo(tip,tamTip,tip[i].id,tipo);
            printf("Mascota de tipo %s\n",tipo);
            prototipoListaMascotas();
            for (int j=0; j<tam; j++)
            {
                if(!(vec[j].isEmpty) && vec[j].idTipo== tip[j].id)
                {
                    mostrarUnaFilaMascota(&vec[j],col,tamCol,tip,tamTip);
                }
            }
            printf("\n\n");
        }
        printf("\n\n");

    }

}




void mostrarUnaFilaMascota( eMascota *vec,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char color[20];
    char tipo[20];

    if (vec != NULL  && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {
        if(!(vec->isEmpty))
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripcionTipo(tip,tamTip,vec->idTipo,tipo);
            printf("%-6d    %-10s           %-15s  %-10s %d         %c \n",
                   vec->id,
                   vec->nombreMascota,
                   tipo,
                   color,
                   vec->edad,
                   vec->vacunas
                  );
        }

    }

}

void mostrarServicioPromedioMayor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer)
{
    char servicio[20];
    int iDServicioMayor;
    int flagPrimeraVuelta =1;
    int valorServicio;
    int suma=0;
    int contador=0;
    float promedio=0;
    int promedioMayor;


    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0&& ser!=NULL && tamSer>0 && tra!=NULL && tamTra>0  )
    {

        for(int i=ser[0].id ; i<=(ser[tamSer].id) ;i++)
        {
            for(int j=0; j<tamTra;j++)
            {
                valorServicio=validarServicio(ser,tamSer,i);
                if(! tra[j].isEmpty && tra[j].idServicio== i)
                {
                    contador++;
                    suma+=valorServicio;
                }
                if(suma!=0)
                {
                    promedio=(float) suma/contador;
                }
                if(flagPrimeraVuelta || promedio>promedioMayor)
                {
                    flagPrimeraVuelta=0;
                    promedioMayor=promedio;
                    iDServicioMayor=i;
                }
            }
        }
        prototipoListaMascotasTrabajo();
        for(int i=0; i<tam;i++)
        {
            if(!tra[i].isEmpty && tra[i].idServicio==iDServicioMayor)
            {

                mostrarUnaFilaMascotaTrabajo(&vec[validarMarcotaId(vec,tam,tra[i].idMscota)],&tra[i],col,tamCol,tip,tamTip);

            }
        }
    }
}



void prototipoListaMascotas()
{
    printf("      *** Lista mascotas *** \n\n");
    printf("Id        nombre mascota       tipo animal      color      edad    vacunado?\n");

}

void mostrarUnaFilaMascotaTrabajo( eMascota *vec,eTrabajo *tra,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char color[20];
    char tipo[20];

    if (vec != NULL  && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 && tra!=NULL  )
    {
        if(!(vec->isEmpty))
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripcionTipo(tip,tamTip,vec->idTipo,tipo);
            printf("%-6d    %-10s           %-15s  %-10s %d         %c          %d        %2d/%2d/%4d \n",
                   vec->id,
                   vec->nombreMascota,
                   tipo,
                   color,
                   vec->edad,
                   vec->vacunas,
                   tra->id,
                   tra->fecha.mes,
                   tra->fecha.mes,
                   tra->fecha.anio
                  );
        }

    }

}


void prototipoListaMascotasTrabajo()
{
    printf("      *** Lista mascotas *** \n\n");
    printf("Id        nombre mascota       tipo animal      color      edad    vacunado?   id trabajo    fecha\n");

}

char menuListas()
{
    char retorno;

    printf("-----------------Elija que lista quiere ver---------------\n\n");

    printf("A- \n");
    printf("B- \n");
    printf("C- \n");
    printf("D- \n");
    printf("E- \n");
    printf("F- \n");
    printf("G- \n");
    printf("H- \n");
    printf("I- \n");


    printf("J-SALIR\n\n");

    utn_getChar(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un caracter valido\n");
    retorno= toupper(retorno);
    utn_clear();

    return retorno;
}
int mostrarListas( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra)
{

    int retorno=-1;
    char salir='N';

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0&& ser!=NULL && tamSer>0 && tra!=NULL && tamTra>0  )
    {
        do
        {
            switch(menuListas())
            {
            case 'A':
                mostrarAnimalesColor(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'B':
                mostrarAnimalesServicio(vec,tam,col,tamCol,tip,tamTip,ser,tamSer,tra,tamTra);
                break;

            case 'C':
                mostrarAnimalesTipo(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'D':

                break;

            case 'E':

                break;

            case 'F':

                break;

            case 'G':

                break;
            case 'H':

                break;
            case 'I':

                break;

            case 'J':

                break;

            case 'K':

                break;
            default:
                printf("Error, ingrese un caracter valido");

                break;

            }
            utn_stop();
            utn_clear();

        }
        while(salir=='N');
    }

    return retorno;
}

