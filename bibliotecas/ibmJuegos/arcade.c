#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arcade.h"

int initArcade(eArcade vec[], int tam)
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

int espacioLibreArcade(eArcade vec[], int tam)
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

int buscarArcadeId(int id, eArcade arc[], int tamArc)
{
    int retorno=-1;
    if(arc!=NULL && tamArc>0)
    {
        for(int i=0; i<tamArc; i++)
        {
            if(!(arc[i].isEmpty) && arc[i].idArcade==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int buscarArcadeIdSalon(int idSalon, eArcade arc[], int tamArc)
{
    int retorno=-1;
    int contadorArcades=0;

    if(arc!=NULL && tamArc>0)
    {
        for(int i=0; i<tamArc; i++)
        {
            if(!(arc[i].isEmpty) && arc[i].idSalon==idSalon)
            {
                contadorArcades++;
            }
        }
        retorno=contadorArcades;
    }
    return retorno;
}

int validarTipoArcade(int entrada, char salidaTipo[])
{

    int retorno=-1;

    if(salidaTipo!=NULL)
    {
        switch(entrada)
        {
        case 1:
            strcpy(salidaTipo,"Mono");
            break;

        case 2:
            strcpy(salidaTipo,"Estereo");
            break;

        default:
            strcpy(salidaTipo,"Tipo invalido");
            break;
        }
        retorno=0;
    }

    return retorno;

}

int print_arcade(eArcade vec[],int tam)
{
    int retorno=-1;
    char tipo[30];

    if(vec!=NULL && tam>0 )
    {
        if(espacioLibreArcade(vec,tam)>=0)
        {
            utn_clear();
            printf("-----------------Lista de Arcades----------------- \n\n");
            printf("Id Arcade      nacionalidad         tipo de sonido        cantidad de jugadores    capacidad fichas    nombre juego             id de salon \n");
            for(int i=0; i<tam; i++)
            {

                if(!(vec[i].isEmpty))
                {

                    validarTipoArcade(vec[i].tipoSonido,tipo);

                    printf("%-5d            %-15s     %-15s              %-15d         %-8d      %-15s          %d \n",
                           vec[i].idArcade,
                           vec[i].nacionalidad,
                           tipo,
                           vec[i].cantidadJugadores,
                           vec[i].capacidadFichas,
                           vec[i].nombreJuego,
                           vec[i].idSalon
                          );

                }


            }
            retorno=0;
        }
        else
        {
            utn_clear();
            printf("No hay arcades cargados");
        }
    }

    return retorno;
}

void print_unArcade(eArcade* arc)
{
    char tipoSonido[30];
    if(arc!=NULL )
    {
        if( !(arc->isEmpty) )
        {
            printf("Datos del Arcade:\n");
            validarTipoArcade(arc->tipoSonido,tipoSonido);
            printf("Id arcade: %d \n nacionalidad: %s \ntipo de Sonido: %s \ncantidad de jugadores:%d \nCapacidad de fichas:%d \nNombre del juego: %s \n\n",
                   arc->idArcade,
                   arc->nacionalidad,
                   tipoSonido,
                   arc->cantidadJugadores,
                   arc->capacidadFichas,
                   arc->nombreJuego
                  );
        }

        printf("\n\n");
    }
}

int print_juegos(eArcade vec[],int tam)
{
    int retorno=-1;

    if(vec!=NULL && tam>0 )
    {
        if(espacioLibreArcade(vec,tam)>=0)
        {
            utn_clear();
            printf("-----------------Lista de juegos----------------- \n\n");
            printf("Id Arcade    nombre juego  \n");
            for(int i=0; i<tam; i++)
            {

                if(!(vec[i].isEmpty))
                {
                    printf("%d         %-10s           \n",
                           vec[i].idArcade,
                           vec[i].nombreJuego
                          );

                }
            }
            retorno=0;
        }
        else
        {
            utn_clear();
            printf("No hay arcades cargados");
        }
    }

    return retorno;
}
