#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "localidad.h"
#include "ArrayEmployees.h"
#include "dataPrueva.h"
#include "ibm.h"
#include "utn.h"
#define TAM 30
#define TAM_LOC 5
#define TAM_COM 6

int main()
{
    ePersona cantidadPersona[TAM];
    char salir='n';
    int nextId=2000;
    eLocalidad localidades[TAM_LOC] =
    {
        { 1000, "Avellaneda" },
        { 1001, "Bernal" },
        { 1002, "Quilmes" },
        { 1003, "Lanus" },
        { 1004, "Sarandi" },
    };
    eComidas comidas[TAM_COM] =
    {
        { 3000, "Churrasco" },
        { 3001, "Fideos" },
        { 3002, "Pizza" },
        { 3003, "Paty" },
        { 3004, "Salchichas" },
        { 3005, "Milanesa"}
    };

    initPersonas(cantidadPersona, TAM);
    hardcodearPersonas(cantidadPersona,TAM,10,&nextId);
    do
    {
        switch(menu())
        {
        case 1:
            altaPersona(cantidadPersona,TAM,&nextId,localidades,TAM_LOC);
            break;

        case 2:
            bajaPersona(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 3:
            modificacionPersona(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 4:
            ordenarPersonasCriterio(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 5:
            mostrarPersona(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 6:
            mostrarListaMujeres(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 7:
            mostrarLocalidades(localidades,TAM_LOC);
            break;

        case 8:
            print_personasUnaLocalidad(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 9:
            mostrarPersonasPorLocalidades(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 10:
            print_nombreVaronMayor(cantidadPersona,TAM);
            break;

        case 11:
            cantidadPersonasPorLocalidad(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 12:
            print_localidadMenosHabitada(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 13:
            print_localidadPromedioAltura(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 14:
            print_localidadMenorPromedioEdad(cantidadPersona,TAM,localidades,TAM_LOC);
            break;

        case 15:
            utn_clear();
            mostrarcomidas(comidas, TAM_COM);
            break;

        case 16:
            altaAlmuerzo(cantidadPersona,TAM,comidas,TAM_COM,localidades,TAM_LOC);
            break;

        case 17:
            print_almuerzos(cantidadPersona,TAM,localidades,TAM_LOC,comidas,TAM_COM);
            break;

        case 18:
            utn_getCharDos(&salir,"desea salir?(y/n) ", "Error ingrese 'n' o 'y'\n",'n','y');
            break;

        }
        utn_stop();
        utn_clear();
    }
    while(salir=='n');

    return 0;
}
