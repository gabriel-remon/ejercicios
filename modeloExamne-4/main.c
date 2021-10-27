#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "color.h"
#include "tipo.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "servicio.h"
#define TAM_TIP 4
#define TAM_COL 5
#define TAM_BIC 100
#define TAM_SER 4
#define TAM_TRA 1000

int main()
{
    eTrabajo trabajos[TAM_TRA];
    eBici bicicletas[TAM_BIC];
    eColor colores[TAM_COL]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}
    };
    eTipo tipos[TAM_TIP]=
    {

        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eServicio servicios[TAM_SER]=
    {
        {20000, "Limpieza",250},
        {20001, "Parche",300},
        {20002, "Centrado",400},
        {20003, "Cadena",350},
    };
    char salir='n';
    int nextId=2000;

    initBici(bicicletas, TAM_BIC);
    initTrabajo(trabajos,TAM_TRA);
    do
    {
        switch(menu())
        {
        case 1:
            altaBici(bicicletas,TAM_BIC,tipos,TAM_TIP,colores,TAM_COL);
            break;

        case 2:
            modificarBici(bicicletas,TAM_BIC,tipos,TAM_TIP,colores,TAM_COL);
            break;

        case 3:
            bajaBici(bicicletas,TAM_BIC,colores,TAM_COL,tipos,TAM_TIP);
            break;

        case 4:
            mostrarBici(bicicletas,TAM_BIC,tipos,TAM_TIP,colores,TAM_COL);
            break;

        case 5:
            mostrarTipo(tipos,TAM_TIP);
            break;

        case 6:
            mostrarColor(colores,TAM_COL);
            break;

        case 7:
            mostrarServicio(servicios,TAM_SER);
            break;

        case 8:
            altaTrabajo(trabajos,TAM_TRA,servicios,TAM_SER,bicicletas,TAM_BIC,&nextId,colores,TAM_COL,tipos,TAM_TIP);
            break;

        case 9:
            mostrarTrabajo(trabajos,TAM_TRA,servicios,TAM_SER,bicicletas,TAM_BIC);
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
