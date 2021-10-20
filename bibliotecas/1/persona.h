#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
#include "localidad.h"
#include "comidas.h"
#include "fecha.h"

#define OCUPADO 0
#define VACIO 1

typedef struct
{
    int id; // pk
    char nombre[20];
    char sexo;
    int edad;
    float altura;
    int idLocalidad; // fk
    int isEmpty; //1 esta vacio, 0 esta lleno
    eFecha fechaAlmuerzo[30];
    int idComidas[30];
} ePersona;

void mostrarPersona(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
void mostrarUnaPersona(ePersona* vec,eLocalidad loc[], int tamLoc);

int initPersonas(ePersona vec[], int tam);

int espacioLibre(ePersona vec[], int tam);

int removerPersona(ePersona vec[], int tam, int posicion);

int buscarPersonaId(ePersona vec[], int tam,int id);

int ordenasPersonas(ePersona vec[], int tam, int orden);

int espacioLibreComida(int vec[], int tam);



#endif // PERSONAS_H_INCLUDED
