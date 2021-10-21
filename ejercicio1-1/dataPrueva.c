#include <string.h>
#include "dataPrueva.h"
#include "salon.h"
#include "arcade.h"

char nombres[20][20] ={
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia",
};

char nacionalidades[20][20] ={
    "Argentina",
    "Peru",
    "Suecia",
    "Brasil",
    "España",
    "Francia",
    "Argentina",
    "Chile",
    "Inglaterra",
    "Italia",
};

char direcciones [20][20] ={
    "Argentina",
    "Peru",
    "Suecia",
    "Brasil",
    "España",
    "Francia",
    "Argentina",
    "Chile",
    "Inglaterra",
    "Italia",
};


char sexos[10] = {'m','m','f','m','f','f','f','m','m','f'};

int edades[10] = {23,21,28,34,35,34,23,28,30,31};

float alturas[10] = {1.65,1.74,1.68,1.80,1.64,1.69,1.75,1.74,1.73,1.82};

int idLocalidades[10] = {1004,1002,1003,1004,1003,1001,1001,1000,1000,1003};

int hardcodearPersonas(ePersona lista[], int tam, int cant, int* pId)
{
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo = sexos[i];
            lista[i].edad = edades[i];
            lista[i].altura = alturas[i];
            lista[i].idLocalidad = idLocalidades[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}

