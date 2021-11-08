#include <string.h>
#include "trabajo.h"
#include "dataPrueva.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"

int hardcodearAnimales(eMascota mas[],int tamMas,int cant)
{
    /*
    char nombresDuenios[20][20] =
    {
        "Mauricio",
        "Fransisco",
        "JuanI",
        "JuanII",
        "Isabela",
        "Gustavo",
        "Smirnof",
        "Ramona",
        "Jaimito",
        "Sanson",
    };
    int edadesDuenio[10] = {10,55,44,65,44,70,22,18,80,40};
    char sexos[10]={'F','M','M','M','F','F','F','M','F','M','F','F'};
    int idDuenio=400;
    */
    char nombres[20][20] =
    {
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


    int idTipo[12]= {1000,1000,1001,1000,1004,1002,1004,1001,1001,1000,1002,1000};
    int idColor[12]= {5000,5001,5002,5000,5004,5002,5004,5001,5001,5001,5002,5000};
    char vacunas[12]= {'S','N','S','S','N','S','S','N','S','S','N','S'};

    int edades[10] = {23,21,28,34,35,34,23,28,30,31};


    int idMascota=00;

    int contador = -1;
    if (mas != NULL && tamMas > 0 && cant>0 && cant<=10 )
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            mas[i].isEmpty=0;
            mas[i].id=idMascota;
            mas[i].idColor=idColor[i];
            mas[i].idTipo=idTipo[i];
            mas[i].edad=edades[i];
            mas[i].vacunas=vacunas[i];
            strcpy(mas[i].nombreMascota,nombres[i]);
            /*
            due[i].id=idDuenio;
            due[i].sexo=sexos[i];
            strcpy(due[i].nombreDuenio,nombreDuenio);
            due[i].edad=edadesDuenio[i];
            mas[i].idDuenio=idDuenio
            idDuenio++;
            */
            idMascota++;
        }
    }
    return contador;
}

int hardcodeartrabajos(eTrabajo tra[],int tamTra,int cant,int *idTrabajo)
{
    int i=0;
    int idServicio[12]= {20001,20000,20002,20000,20001,20001,20002,20001,20001,20002,20002,20001};
    int dia[12]= {10,1,10,12,11,10,20,30,25,24,8,9};
    int mes[12]= {1,12,2,11,10,2,2,3,4,5,8,8};
    int anio[12]= {2008,2001,2000,2021,2018,2015,2014,2014,2018,2015,2014,2010};
    if(tra!=NULL&&tamTra>0 && cant>0 && cant<11)
    {
        for ( i = 0; i < cant;  i++)
        {
            tra[i].id=(*idTrabajo);
            tra[i].isEmpty=0;
            tra[i].idMscota=i;
            tra[i].idServicio=idServicio[i];
            tra[i].fecha.dia=dia[i];
            tra[i].fecha.mes=mes[i];
            tra[i].fecha.anio=anio[i];
            (*idTrabajo)++;

        }
    }

    return i;
}

