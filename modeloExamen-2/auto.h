#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"
#include "auto.h"


typedef struct
{
    int id;
    int idMarca;
    int idColor;
    char caja;
    int isEmplty;

}eAuto;

int initAuto(eAuto vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/

int espacioLibreAuto(eAuto vec[], int tam);
/** busca un espacio libre en el vector preguntando si isEmply esta en 1
*   si lo encuentra devueve la posicion de este vector
*
*   return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/

int descripcionCaja(char valorCaja,char descripcion[]);
/** lee el valor en valor caja y guarda un string en descripcion dependiendo lo que sea el caracter
*   pasado como parametro
*
*   retorna (0) si huvo una falla - (1) si todo ok
*/

int validarAuto(eAuto vec[],int tam,int idBusqueda);
/** Pide por parametro un id y lo compara con todos los id dentro del vector
*
*   return (0) si no encuentra el valor o si fallo - (1) si encontro el id en el vector
*/

int buscarAutoId(eAuto vec[],int tam,int id);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int altaAuto( eAuto vec[], int tam ,eMarca mar[], int tamMar ,eColor col[], int tamCol);
/** Busca si hay lugar en el vector para cargar mas datos y si los hay pide al usuario el
*   id del auto (valida que no se repita con ningun otro)
*   marca (muestra tabla de marcas y valida que exista la marca ingresada)
*   color (muestra tabla de colores y valida que exista el color ingresado)
*   tipo de caja (pide ('m') para manual - ('a') para automatica )
*
*
*   return (-1) si fallo - (0) si todo ok - (1) si el vector eAuto esta lleno
*/

int modificarAuto( eAuto vec[], int tam ,eMarca mar[], int tamMar ,eColor col[], int tamCol);
/** Solo ingresa si hay autos cargados, pide el id de un auto y lo valida. si lo encuentra permite
*   cambiar los valores de color y marca
*
*   return (-1) si hay un error - (0) si todo ok - (1) si no hay autos cargados
*/

int modificacion();
/** Menu de opcion de la funcion modificarAuto, pregunta que opcion quiere eleguir el usuario
*   y valida entre las posibles opciones
*
*   return (int) del dato cargado del usuario
*/

int mostrarUnAuto( eAuto* vec,eMarca mar[], int tamMar ,eColor col[], int tamCol);
/** muestra en forma de filas los valores en dentro de la estructura vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int mostrarAuto(eAuto vec[], int tam ,eMarca mar[], int tamMar ,eColor col[], int tamCol);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/


#endif // AUTO_H_INCLUDED
