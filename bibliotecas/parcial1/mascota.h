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
/** @brief inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*   @param vec[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*
*   @return (-1) si huvo un error - (0) si todo ok
*/

int descripccionMascota(eMascota vec[],int tam, int idBusqueda, char descipcion[]);
/** @brief pide un id por parametro y busca ese id dentro de vec[].id si lo encuentra carga lo que este en
*           vec.nombreDuenio dentro del string descripcion
*   @param vec[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param idBusqueda valor que sera buscado dentro del vector
*   @param descripcion string de estritura
*
*   @return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/

int validarMarcotaId(eMascota vec[],int tam,int idBusqueda);
/** @brief Pide por parametro un id y lo compara con todos los id dentro del vector.
*          si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*   @param vec[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMacota
*   @param idBusqueda valor que sera buscado dentro del vector
*
*   @return ((0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/


int mostrarMascotas( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*   @param vec[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector eTipo
*
*   @return (-1) si huvo un error - (0) si todo ok
*/


int mostrarUnaMacota( eMascota* vec, eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief muestra en forma de columna los valores dentro de vec
*   @param vec puntero de tipo eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector eTipo
*
*   @return (-1) si huvo un error - (0) si todo ok
*/

int espacioLibreMascota(eMascota vec[], int tam);
/** @brief busca un espacio libre en el vector preguntando si isEmply esta en 1
*          si lo encuentra devueve la posicion de este vector
*   @param vec[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*
*   @return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/

int altaMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief valida que haya lugares libres en el vector vec[] y si los hay pide al usuario
*          id (valida que no este en uso), nombre de la mascota, edad, color, tipo de animal
*          y si esta vacunado
*   @param vec[] vector de tipo eMascota
*   @param tam tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si hubo error - (0) si todo ok
*/

int modificarMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief valida que haya valores en vec[] si los hay permite modificar los campos de
           vec[].idTipo y vec[].vacunas
*   @param vec[] vector de tipo eMascota
*   @param tam tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si hay un error - (0) si todo ok - (1) si vec[] no tiene datos
*/

int bajaMascota( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief valida que haya valores en vec[] si los hay muestra lista de mascotas y pregunta que
*          id se quiere eliminar. si se desea eliminar un valor se pone la variavle vec[].isEmpty=1
*   @param vec[] vector de tipo eMascota
*   @param tam tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si hay un error - (0) si todo ok - (1) si vec[] no tiene datos
*/

int ordenarMascotas(eMascota vec[],int tam);
/** @brief ordena el vector vec tomando como referencia nombre asendente o tipos asendente
*   @param vec[] vector de tipo eMascota
*   @param tam tamaño del vector eMascota
*
*   @return return (-1) si hubo error - (0) si todo ok
*/
char modificacion();
/** @brief imprime un menu y devuelve la eleccion del usuario
*   @return caracter tipo char
*/
char menu();
/** @brief imprime un menu y devuelve la eleccion del usuario
*   @return caracter tipo char
*/
