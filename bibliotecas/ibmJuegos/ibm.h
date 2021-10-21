#ifndef IBM_H_INCLUDED
#define IBM_H_INCLUDED
#include "salon.h"
#include "arcade.h"

int menu();
int modificacion();
int print_salon(eSalon vec[], int tam, eArcade arc[] ,int tamArc);
void print_unSalon(eSalon* vec,eArcade arc[], int tamArc);

int altaSalon(eSalon vec[], int tam, int* id);
int bajaSalon(eSalon vec[], int tam,eArcade arc[], int tamArc);
int removerSalon(eSalon vec[], int tam,eArcade arc[], int tamArc,int posicion);

int modificacionArcade(eSalon vec[], int tam,eArcade arc[], int tamArc);

int altaArcades(eSalon vec[], int tam,eArcade arc[], int tamArc,int* idArcarde);

int bajaArcades(eSalon vec[], int tam,eArcade arc[], int tamArc);

#endif // IBM_H_INCLUDED
