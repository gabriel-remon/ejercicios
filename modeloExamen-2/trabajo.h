#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "servicio.h"

typedef struct
{
    int id;
    int patente; // id auto
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int initTrabajo(eTrabajo vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/
int altaTrabajo( eTrabajo vec[],int tam,eAuto aut[], int tamAut ,eMarca mar[], int tamMar ,eColor col[], int tamCol ,eServicio ser[],int tamSer,int* idIngreso);

int espacioLibreTrabajo(eTrabajo vec[], int tam);
/** busca un espacio libre en el vector preguntando si isEmply esta en 1
*   si lo encuentra devueve la posicion de este vector
*
*   return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/
