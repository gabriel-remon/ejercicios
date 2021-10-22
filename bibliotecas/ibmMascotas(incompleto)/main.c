#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "trabajo.h"
#include "servicios.h"
#define TAM_SER 3
#define TAM_TRA 1000

int main()
{
    eTrabajo trabajos[TAM_TRA];
    eServicio servicios[TAM_SER]=
    {
        {20000, "Corte",250},
        {20001, "Desparacitado",300},
        {20002, "Catrado",400},
    };
    char salir='n';
    int nextId=2000;

    initTrabajo(trabajos,TAM_TRA);
    do
    {
        switch(menu())
        {
        case 1:
            altaTrabajo(trabajos,TAM_TRA,servicios,TAM_SER,&nextId);
            break;

        case 2:
            modificarTrabajo(trabajos,TAM_TRA,servicios,TAM_SER);
            break;

        case 3:
            bajaTrabajo(trabajos,TAM_TRA,servicios,TAM_SER);
            break;

        case 4:
            ordenarTrabajos(trabajos,TAM_TRA);
            mostrarTrabajo(trabajos,TAM_TRA,servicios,TAM_SER);
            break;

        case 5:

            utn_clear();
            mostrarServicio(servicios,TAM_SER);
            break;

        case 6:
            totalPrecioServiciosTrabajos(trabajos,TAM_TRA,servicios,TAM_SER);
            break;

        case 7:
            utn_getCharDos(&salir,"desea salir?(y/n) ", "Error ingrese 'n' o 'y'\n",'n','y');
            break;

        }
        utn_stop();
        utn_clear();
    }
    while(salir=='n');

    return 0;
}
