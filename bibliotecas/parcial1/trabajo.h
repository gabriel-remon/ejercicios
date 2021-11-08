#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "servicios.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"

typedef struct
{
    int id;
    int idMscota;
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // TRABAJO_H_INCLUDED
int initTrabajo(eTrabajo vec[], int tam);
/** @brief inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*   @param vec[] vector de tipo eTrabajo
*   @param tamMas tamaño del vector eTrabajo
*
*   @return (-1) si huvo un error - (0) si todo ok
*/

int altaTrabajo( eTrabajo vec[],int tam,eServicio ser[], int tamSer,eMascota mas[],int tamMas,int* idIngreso,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief valida que haya lugares libres en el vector vec[] y si los hay pide al usuario
*          tipo de servicio a realizar y fecha.
*   @param vec[] vector de tipo eTrabajo
*   @param tam tamaño del vector eTrabajo
*   @param ser[] vector de tipo eServicio
*   @param tamSer tamaño del vector eServicio
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si hubo error - (0) si todo ok
*/

int espacioLibreTrabajo(eTrabajo vec[], int tam);
/** @brief busca un espacio libre en el vector preguntando si isEmply esta en 1
*          si lo encuentra devueve la posicion de este vector
*   @param vec[] vector de tipo eTrabajo
*   @param tamMas tamaño del vector eTrabajo
*
*   @return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/


int mostrarTrabajo(eTrabajo vec[], int tam,eServicio ser[], int tamSer,eMascota mas[],int tamMas);
/** @brief muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*   @param vec[] vector de tipo eTrabajo
*   @param tamMas tamaño del vector eTrabajo
*   @param col[] vector de tipo eServicio
*   @param tamCol tamaño del vector eServicio
*   @param tip[] vector de tipo eMascota
*   @param tamTip tamaño del vector eMascota
*
*   @return (-1) si huvo un error - (0) si todo ok
*/
int ordenarTrabajos(eTrabajo vec[], int tam, eMascota mas[], int tamMas);
/** @brief ordena el vector vec tomando como referencia fechas desendentes o nombres asendentes
*   @param vec[] vector de tipo eTrabajo
*   @param tam tamaño del vector eTrabajo
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*
*   @return return (-1) si hubo error - (0) si todo ok
*/
