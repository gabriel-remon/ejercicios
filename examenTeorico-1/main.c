#include <stdio.h>
#include <stdlib.h>
#define TAM 8

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

int ordenarEstructura(eVacuna estructura[],int tam);
float aplicarAumento(int producto);
int reemplazarCaracteres(char cadena[],char parametro1, char parametro2);

int main()
{
    int numero1=10;
    char cadena[20]="zapato";
    eVacuna vacunas[TAM]=
    {
        {10,"pepe",'a',8},
        {11,"pepa",'a',10},
        {12,"juan",'g',79},
        {13,"amelia",'f',85},
        {14,"gabreil",'g',63},
        {15,"simon",'j',52},
        {16,"amelia",'f',22},
        {17,"pepe",'a',50},
    };

    printf("producto %d. producto con aumento %.2f \n\n",numero1, aplicarAumento(numero1));
    reemplazarCaracteres(cadena,'a','x');
    printf("el nombre ahora es: %s \n\n",cadena);
    ordenarEstructura(vacunas,TAM);
    for(int i=0; i<TAM; i++)
    {
        printf("%d      %-20s   %c             %.2f \n",vacunas[i].id,vacunas[i].nombre,vacunas[i].tipo, vacunas[i].efectividad);
    }




    return 0;
}

float aplicarAumento(int producto)
{
    float retorno;

    retorno= producto*1.05;

    return retorno;
}

int reemplazarCaracteres(char cadena[],char parametro1, char parametro2)
{
    int retorno=0;
    int contador=0;


    if(cadena!=NULL)
    {
        while(cadena[contador]!= '\0')
        {
            contador++;
            if(cadena[contador] == parametro1)
            {
                cadena[contador]=parametro2;
                retorno++;
            }
        }
    }

    return retorno;
}

int ordenarEstructura(eVacuna estructura[],int tam)
{
    int retorno=-1;
    eVacuna aux;

    if(estructura!=NULL && tam>0 )
    {

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j< tam; j++ )
            {
                    if(estructura[i].tipo>estructura[j].tipo ||
                        (estructura[i].tipo == estructura[j].tipo && estructura[i].efectividad > estructura[j].efectividad )
                        )
                    {
                        aux=estructura[i];
                        estructura[i]=estructura[j];
                        estructura[j]=aux;
                    }
            }
        }
        retorno=0;
    }

    return retorno;
}
