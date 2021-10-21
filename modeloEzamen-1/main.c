#include <stdio.h>
#include <stdlib.h>
#include "salon.h"
#include "arcade.h"
#include "utn.h"
#include "ibm.h"
#define TAM_SAL 100
#define TAM_ARC 1000

int main()
{
    eSalon cantidadSalones[TAM_SAL];
    eArcade cantidadArcades[TAM_ARC];
    char salir='n';
    int idSalon=2000;
    int idArcade=5000;

    initSalon(cantidadSalones,TAM_SAL);
    initArcade(cantidadArcades,TAM_ARC);

    //hardcodearSalonArcade(cantidadSalones,TAM_SAL,cantidadArcades,TAM_ARC,10,&idSalon,&idArcade);
    do
    {
        switch(menu())
        {
        case 1:
            altaSalon(cantidadSalones,TAM_SAL,&idSalon);
            break;

        case 2:
            bajaSalon(cantidadSalones,TAM_SAL,cantidadArcades,TAM_ARC);
            break;

        case 3:
            utn_clear();
            print_salon(cantidadSalones,TAM_SAL,cantidadArcades,TAM_ARC);
            break;

        case 4:
            altaArcades(cantidadSalones,TAM_SAL,cantidadArcades,TAM_ARC,&idArcade);
            break;

        case 5:
            modificacionArcade(cantidadSalones,TAM_SAL,cantidadArcades,TAM_ARC);
            break;

        case 6:
            bajaArcades(cantidadSalones,TAM_SAL,cantidadArcades,TAM_ARC);
            break;

        case 7:
            print_arcade(cantidadArcades,TAM_ARC);
            break;

        case 8:
            print_juegos(cantidadArcades,TAM_ARC);
            break;

        case 9:
            utn_getCharDos(&salir,"desea salir?(y/n) ", "Error ingrese 'n' o 'y'\n",'n','y');
            break;

        }
        utn_stop();
        utn_clear();
    }
    while(salir=='n');

    return 0;
}
