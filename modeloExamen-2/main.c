#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "color.h"
#include "marca.h"
#include "auto.h"
#include "trabajo.h"
#include "servicio.h"
#include "mostrar.h"
#define TAM_MAR 5
#define TAM_COL 5
#define TAM_AUT 100
#define TAM_SER 4
#define TAM_TRA 1000

int main()
{
    eTrabajo trabajos[TAM_TRA];
    eAuto autos[TAM_AUT];
    eColor colores[TAM_COL]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}

    };
    eMarca marcas[TAM_MAR]=
    {

        {1000, "Renault"},
        {1001, "Ford"},
        {1002, "Fiat"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}

    };
    eServicio servicios[TAM_SER]=
{
        {20000, "Lavado",450},
        {20001, "Pulido",500},
        {20002, "Encerado",600},
        {20003, "Completo",900},
    };
    char salir='n';
    int nextId=2000;

    initAuto(autos, TAM_AUT);
    initTrabajo(trabajos,TAM_TRA);
    do
    {
        switch(menu())
        {
        case 1:
            altaAuto(autos,TAM_AUT,marcas,TAM_MAR,colores,TAM_COL);
            break;

        case 2:
            modificarAuto(autos,TAM_AUT,marcas,TAM_MAR,colores,TAM_COL);
            break;

        case 3:

            break;

        case 4:
            mostrarAuto(autos,TAM_AUT,marcas,TAM_MAR,colores,TAM_COL);
            break;

        case 5:
            mostrarMarca(marcas,TAM_MAR);
            break;

        case 6:
            mostrarColor(colores,TAM_COL);
            break;

        case 7:
            mostrarServicio(servicios,TAM_SER);
            break;

        case 8:
            altaTrabajo(trabajos,TAM_TRA,autos,TAM_AUT,marcas,TAM_MAR,colores,TAM_COL,servicios,TAM_SER,&nextId);
            break;

        case 9:

            break;
        case 10:
            utn_getCharDos(&salir,"desea salir?(y/n) ", "Error ingrese 'n' o 'y'\n",'n','y');
            break;

        }
        utn_stop();
        utn_clear();
    }
    while(salir=='n');

    return 0;
}

