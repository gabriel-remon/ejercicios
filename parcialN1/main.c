#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicios.h"
#include "trabajo.h"
#include "dataPrueva.h"
//#include "listas.h"

#define TAM_TIP 5
#define TAM_COL 5
#define TAM_MAS 11
#define TAM_SER 3
#define TAM_TRA 11

int main()
{
    eTipo tipoAnimal[TAM_TIP]=
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"},
    };
    eColor color[TAM_COL]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"},
    };
    eServicio servicion[TAM_SER]=
    {
        {20000, "Corte",450},
        {20001, "Desparacitado",800},
        {20002, "Catrado",600},
    };

    eMascota mascotas[TAM_MAS];
    eTrabajo trabajos[TAM_TRA];

    char salir='N';
    int nextId=2000;

    initMascotas(mascotas,TAM_MAS);
    initTrabajo(trabajos,TAM_TRA);
    hardcodearAnimales(mascotas,TAM_MAS,10); //habilitar para hardcodera para probar
    hardcodeartrabajos(trabajos,TAM_TRA,10,&nextId);//habilitar para hardcodera para probar
    do
    {
        switch(menu())
        {
        case 'A':
            altaMascota(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;

        case 'B':
            modificarMascota(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;

        case 'C':
            bajaMascota(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;

        case 'D':
            if(espacioLibreMascota(mascotas,TAM_MAS)!=-2)
            {
                ordenarMascotas(mascotas,TAM_MAS);
                mostrarMascotas(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP);
            }
            else
            {

                printf("Primero deve cargar una mascota");
            }
            break;

        case 'E':
            mostrarTipo(tipoAnimal,TAM_TIP);
            break;

        case 'F':
            mostrarColor(color,TAM_COL);
            break;

        case 'G':
            mostrarServicio(servicion,TAM_SER);
            break;
        case 'H':
            altaTrabajo(trabajos,TAM_TRA,servicion,TAM_SER,mascotas,TAM_MAS,&nextId,color,TAM_COL,tipoAnimal,TAM_TIP);
            break;
        case 'I':
            if(espacioLibreTrabajo(trabajos,TAM_TRA)!=-2)
            {
                ordenarTrabajos(trabajos,TAM_TRA,mascotas,TAM_MAS);
                mostrarTrabajo(trabajos,TAM_TRA,servicion,TAM_SER,mascotas,TAM_MAS);
            }
            else
            {
                printf("Primero deve cargar un trabajo");
            }
            break;

        case 'J':
            mostrarListas(mascotas,TAM_MAS,color,TAM_COL,tipoAnimal,TAM_TIP,servicion,TAM_SER,trabajos,TAM_TRA);
            break;

        case 'K':
            utn_confirmar(&salir,"desea salir?(S/N) ", "Error ingrese 'n' o 's'\n",'N','S');
            break;
        default:
            printf("Error, ingrese un caracter valido");

            break;

        }
        utn_stop();
        utn_clear();

    }while(salir=='N');

    return 0;
}
