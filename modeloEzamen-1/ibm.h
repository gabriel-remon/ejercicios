#ifndef IBM_H_INCLUDED
#define IBM_H_INCLUDED
#include "salon.h"
#include "arcade.h"

int menu();
int modificacion();

int print_salon(eSalon vec[], int tam, eArcade arc[],int tamArc);
/**Imprime por pantalla los valores guardados en vec[] (salones) y la cantidad de valores arc[] (arcades) que les
*  corresponde a cada uno de los salones
*/
void print_unSalon(eSalon* vec,eArcade arc[], int tamArc);
/**Imprime por pantalla los datos de una sola posicion del vector vec[] (Imprime un solo salon)
*/

int altaSalon(eSalon vec[], int tam, int* id);
/**Da de alta un salon pidiendo los datos que lo componen y incrementa en una el valor en el
*  puntero *id
*/

int bajaSalon(eSalon vec[], int tam,eArcade arc[], int tamArc);
/**  Pide el id del salon a dar de baja y valida ese id ingresado. si es valido da de baja al salon con
*  todos los arcades vinculados con ese id
*/

int removerSalon(eSalon vec[], int tam,eArcade arc[], int tamArc,int posicion);
/**  se pide como parametro la posicion del vector vec que sera dada de baja y elimina de forma logica a
*    todos los valores en arc[] que esten vinculados con el id en vec[posicion]
*/

int modificacionArcade(eSalon vec[], int tam,eArcade arc[], int tamArc);
/**  Se pide al usuario que ingrese un id de un arcade y lo valida, si es valido pide el valor a modificar
*    y carga ese nuevo dato sobre el anterior
*/


int altaArcades(eSalon vec[], int tam,eArcade arc[], int tamArc,int* idArcarde);

int bajaArcades(eSalon vec[], int tam,eArcade arc[], int tamArc);

#endif // IBM_H_INCLUDED
