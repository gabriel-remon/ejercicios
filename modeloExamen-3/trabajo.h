#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "servicios.h"

typedef struct
{
    int id;
    char nombreMascota[20]; // id auto
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
int altaTrabajo( eTrabajo vec[],int tam,eServicio ser[], int tamSer, int* idIngreso);
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

int menu();
/** Menu de opciones, pregunta que opcion quiere eleguir el usuario
*   y valida entre las posibles opciones
*
*   return (int) del dato ingresado por el usuario
*/

int mostrarTrabajo(eTrabajo vec[], int tam ,eServicio ser[], int tamSer);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int modificarTrabajo( eTrabajo vec[], int tam ,eServicio ser[], int tamSer);
/** Solo ingresa si hay autos cargados, pide el id de un auto y lo valida. si lo encuentra permite
*   cambiar los valores de color y marca
*
*   return (-1) si hay un error - (0) si todo ok - (1) si no hay autos cargados
*/

int modificacion();
/** Menu de opcion de la funcion modificarAuto, pregunta que opcion quiere eleguir el usuario
*   y valida entre las posibles opciones
*int totalPrecioServiciosTrabajos(eServicio vec[],int tam, eTrabajo tra[],int tamTra);
*   return (int) del dato cargado del usuario
*/

int buscarTrabajoId(eTrabajo vec[],int tam,int id);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int mostrarUnTrabajo( eTrabajo* vec,eServicio ser[], int tamSer);
/** muestra en forma de filas los valores en dentro de la estructura vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int bajaTrabajo(eTrabajo vec[], int tam,eServicio ser[], int tamSer);
/**  Pide el id del salon a dar de baja y valida ese id ingresado. si es valido da de baja al salon con
*  todos los arcades vinculados con ese id
*/

int totalPrecioServiciosTrabajos(eTrabajo vec[], int tam,eServicio ser[], int tamSer);

int ordenarTrabajos(eTrabajo vec[], int tam);
