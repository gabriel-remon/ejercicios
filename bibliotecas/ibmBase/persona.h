#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
#include "localidad.h"
#include "comidas.h"
#include "fecha.h"

#define OCUPADO 0
#define VACIO 1

typedef struct
{
    int id; 
    char nombre[20];
    char sexo;
    int edad;
    float altura;
    int idLocalidad; 
    int isEmpty; 
    eFecha fechaAlmuerzo[30];
    int idComidas[30];
} ePersona;

void mostrarPersona(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/

void mostrarUnaPersona(ePersona* vec,eLocalidad loc[], int tamLoc);
/** muestra en forma de filas los valores en dentro de la estructura vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int initPersonas(ePersona vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/

int espacioLibre(ePersona vec[], int tam);
/** busca un espacio libre en el vector preguntando si isEmply esta en 1
*   si lo encuentra devueve la posicion de este vector
*
*   return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/


int removerPersona(ePersona vec[], int tam, int posicion);

int buscarPersonaId(ePersona vec[], int tam,int id);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int ordenasPersonas(ePersona vec[], int tam, int orden);
/** se carga orden como valor y ordena al vector ePersona dependiendo el dato engresado
*
*   return (-1) si huvo un erro - (0) si todo ok
/*

int espacioLibreComida(int vec[], int tam);
/** busca un espacio con 0 en cada posicion del vector y devuelve la posicion del primer
*   espacio encontrado
*
*   return (-1) si huvo un error - (int) si encontro un espacio libre
*/



#endif // PERSONAS_H_INCLUDED
