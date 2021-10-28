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

}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int initTrabajo(eTrabajo vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/

int altaTrabajo( eTrabajo vec[],int tam,eServicio ser[], int tamSer,eMascota mas[],int tamMas ,int* idIngreso,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** calida que haya lugares libres en el vector eTrabajo y si los hay pregunta al usuario:
*   nombre mascota
*   tipo servicio a realizar (mostrando un menu)
*   fecha de realizacion del trabajo
*
*   luego carga los datos ingresados en el vector y pregunta para cargar otro trabajo
*
*   return (-1) si hubo error - (0) si todo ok
*/

int espacioLibreTrabajo(eTrabajo vec[], int tam);
/** busca un espacio libre en el vector preguntando si isEmply esta en 1
*   si lo encuentra devueve la posicion de este vector
*
*   return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/


int mostrarTrabajo(eTrabajo vec[], int tam,eServicio ser[], int tamSer,eMascota mas[],int tamMas);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/








int ordenarTrabajos(eTrabajo vec[], int tam, eMascota mas[], int tamMas);
