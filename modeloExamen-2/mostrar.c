#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "auto.h"
#include "color.h"
#include "fecha.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
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
    return retorno;
}
