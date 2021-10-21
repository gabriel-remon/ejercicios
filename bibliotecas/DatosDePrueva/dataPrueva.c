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
    "Espaia",
    "Francia",
    "Argentina",
    "Chile",
    "Inglaterra",
    "Italia",
};

char direcciones [20][30] ={
    "jujuy 1050",
    "Peru 2030",
    "pepe 200",
    "yrigoyen 800",
    "alberdi 1000",
    "juan carlos 1025",
    "peron 5055",
    "pichincha 200",
    "arjona 100",
    "rivadabia 233",
};
char juegos [20][20] ={
    "FIFA",
    "Falout",
    "Cruz roja",
    "Juego calamar",
    "Lapicera azul",
    "god of war",
    "apaga el fuego",
    "UNO",
    "pokemon",
    "Lava auton",
};

int binario [30]= {1,2,1,1,1,2,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2};

int cantidades[30]={125,36,25,215,223,6,152,4112,366,14,236,151,26,45,6,1584};
int cantidades2[30]={321,5,1,648,264,1,54,698,3251,654,321,847,4151,321,32165,321,321};



char sexos[10] = {'m','m','f','m','f','f','f','m','m','f'};

int edades[10] = {23,21,28,34,35,34,23,28,30,31};

float alturas[10] = {1.65,1.74,1.68,1.80,1.64,1.69,1.75,1.74,1.73,1.82};

int idLocalidades[10] = {1004,1002,1003,1004,1003,1001,1001,1000,1000,1003};
/*
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
*/
int hardcodearSalonArcade(eSalon lista[], int tam,eArcade arc[],int tamArc, int cant, int* pId,int* idArc)
{
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL&& arc!=NULL && tamArc>0 && idArc!=NULL )
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            arc[i].idSalon= *pId;
            (*pId)++;
            strcpy(lista[i].nombre, nombres[i]);
            strcpy(lista[i].direccion, direcciones[i]);
            lista[i].tipo = binario[i];
            lista[i].isEmpty = 0;

            arc[i].idArcade = *idArc;
            (*idArc)++;
            strcpy(arc[i].nacionalidad, nacionalidades[i]);
            strcpy(arc[i].nombreJuego, juegos[i]);
            arc[i].tipoSonido = binario[i];
            arc[i].cantidadJugadores = cantidades[i];
            arc[i].capacidadFichas = cantidades2[i];
            arc[i].isEmpty = 0;
            contador++;

            contador++;
        }
    }
    return contador;
}



