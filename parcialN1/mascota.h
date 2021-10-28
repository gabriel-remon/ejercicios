#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "tipo.h"
#include "color.h"


typedef struct
{
    int id;
    char nombreMascota[25];
    int idTipo;
    int idColor;
    int edad;
    char vacunas;
    int isEmpty;
} eMascota;

#endif // MASCOTA_H_INCLUDED

int initMascotas(eMascota vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/

int descripccionMascota(eMascota vec[],int tam, int idBusqueda, char descipcion[]);
/** pide un id por parametro y busca ese id dentro de vec. si lo encuentra carga lo que este en
*   vec.descripcion dentro del string descripcion
*
*   return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/

int validarMarcotaId(eMascota vec[],int tam,int idBusqueda);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int mostrarMascotas( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/


int mostrarUnaMacota( eMascota* vec, eColor col[], int tamCol,eTipo tip[], int tamTip);
/**muestra en forma de filas los valores en dentro de la estructura vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int espacioLibreMascota(eMascota vec[], int tam);
/** busca un espacio libre en el vector preguntando si isEmply esta en 1
*   si lo encuentra devueve la posicion de este vector
*
*   return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/

int altaMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** calida que haya lugares libres en el vector eTrabajo y si los hay pregunta al usuario:
*   nombre mascota
*   tipo servicio a realizar (mostrando un menu)
*   fecha de realizacion del trabajo
*
*   luego carga los datos ingresados en el vector y pregunta para cargar otro trabajo
*
*   return (-1) si hubo error - (0) si todo ok
*/

int modificarMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** Solo ingresa si hay autos cargados, pide el id de un auto y lo valida. si lo encuentra permite
*   cambiar los valores de color y marca
*
*   return (-1) si hay un error - (0) si todo ok - (1) si no hay autos cargados
*/

int bajaMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/**  Pide el id del salon a dar de baja y valida ese id ingresado. si es valido da de baja al salon con
*  todos los arcades vinculados con ese id
*/

int ordenarMascotas(eMascota vec[],int tam);
char modificacion();
char menu();
