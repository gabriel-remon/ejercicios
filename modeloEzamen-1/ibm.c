#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include "salon.h"
#include "arcade.h"
#include "ibm.h"

int menu()
{
    int retorno;

    printf("-----------------Registro de salones---------------\n\n");

    printf("1- alta salon\n");
    printf("2- baja salon\n");
    printf("3- imprimir salon\n");

    printf("4- alta arcade\n");
    printf("5- modificar arcade\n");
    printf("6- baja arcade\n");
    printf("7- imprimir arcades\n");
    printf("8- imprimir juegos\n");
    printf("9-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 9",1,9);
    return retorno;
}

int print_salon (eSalon vec[], int tam, eArcade arc[],int tamArc)
{
    int retorno=-1;
    char tipo[30];
    int cantidadArcades;

    if(vec!=NULL && tam>0 && arc!=NULL && tamArc>0)
    {
        if(espacioLibreSalon(vec,tam) >=0)
        {
            printf("-----------------Lista de salones----------------- \n\n");
            printf("Id       Nombre         direccion            tipo             cantidad de arcades\n");
            for(int i=0; i<tam; i++)
            {

                if( !(vec[i].isEmpty) )
                {
                    validarTipoSalon(vec[i].tipo,tipo);
                    cantidadArcades= buscarArcadeIdSalon(vec[i].id,arc,tamArc) ;
                    printf("%d     %-10s     %-18s   %-18s      %d \n",
                           vec[i].id,
                           vec[i].nombre,
                           vec[i].direccion,
                           tipo,
                           cantidadArcades
                          );
                }
            }
            retorno=0;
        }
        else
        {
            utn_clear();
            printf("No hay salones cargados");
        }
    }

    return retorno;
}

int altaSalon(eSalon vec[], int tam, int* id)
{
    int retorno=-1;
    int posicion;
    char calle[43];
    char altura[7];
    eSalon aux;
    char exit;

    if(vec!=NULL && tam>0 && id!=NULL)
    {
        do
        {
            utn_clear();

            posicion=espacioLibreSalon(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }

            if(posicion>=0)
            {
                do
                {
                    utn_ingresoScring(aux.nombre, "Ingrese el nombre del salon: ", "Error (maximo 50 caracteres), ", sizeof(vec[0].nombre));
                }
                while(esPalabra(aux.nombre, sizeof(aux.nombre)) );

                printf("Ingrese la direccion del salon:\n");
                do
                {
                    utn_ingresoScring(calle, "calle: ", "Error (maximo 50 caracteres), ", sizeof(vec[0].direccion) - 7 );
                }
                while(esPalabra(aux.nombre,sizeof(vec[0].direccion)));

                do
                {
                    utn_ingresoScring(altura, "altura: ", "Error (maximo 50 caracteres), ", 6);
                }
                while(!(esNumero(altura,6)));

                sprintf(aux.direccion,"%s %s",calle,altura);
                //  strncat(aux.direccion," ");
                //  strncat(aux.direccion,altura);

                utn_minMaxInt(&aux.tipo,"ingrese el tipo de salon. 1- Shopping 2-Local", "Error, ingrese 1 o 2 (ingrese 1-Shopping 2-Local)  \n",1,2);

                aux.isEmpty=0;
                aux.id=(*id);

                (*id)++;
                vec[posicion]=aux;

                printf("salon cargado con exito\n");
                utn_getCharDos(&exit,"\nDesea dar de alta otro salon?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');

                retorno=0;
            }
            else
            {
                printf("No hay espacio para cargar mas salones.\nPara hacerlo deve dar de baja a un salon actual.");
                exit='n';
                retorno=1;
            }
        }
        while(exit=='y');
    }
    return retorno;
}

int bajaSalon(eSalon vec[], int tam,eArcade arc[], int tamArc)
{
    int retorno=-1;
    int posicion;
    char confirm;
    char exit='y';
    int idInput;

    if(vec!=NULL && tam>0 && arc!=NULL && tamArc>0)
    {
        if(espacioLibreSalon(vec,tam)!=-2)
        {
            do
            {
                utn_clear();
                printf("******** BAJA DE SALONES ********");
                print_salon(vec,tam,arc,tamArc);
                utn_getInt(&idInput, "Ingrese el id de la persona a dar de baja: ","Error id invalido, ");
                posicion=buscarSalon(vec,tam,idInput);

                if(posicion>=0)
                {
                    print_unSalon(&vec[posicion],arc,tamArc);
                    utn_getCharDos(&confirm,"\nConfirmar la baja de este salon(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                    utn_clear();
                    if(confirm=='y')
                    {
                        removerSalon(vec,tam,arc,tamArc,posicion);
                        printf("salon dado de baja");
                    }
                    else
                    {
                        printf("Se cancelo la operacion");
                    }
                }
                else
                {
                    printf("\nId no encontrado\n");
                }

                if(espacioLibreSalon(vec,tam)!=-2)
                {
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    printf("\nNo se pueden cargar mas salones\n");
                    break;
                }

            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar un salon");
        }
        retorno=0;
    }

    return retorno;
}

void print_unSalon(eSalon* vec,eArcade arc[], int tamArc)
{
    char tipo[30];
    int cantidadArcades;
    if(vec!=NULL && arc!=NULL && tamArc>0 )
    {
        utn_clear();
        if( !(vec->isEmpty) )
        {
            validarTipoSalon(vec->tipo,tipo);
            cantidadArcades=buscarArcadeIdSalon(vec->id,arc,tamArc);

            printf("Datos de la persona:\n\n");
            printf("Id: %d \nNombre: %s \ndireccion: %s \ntipo:%s \ncantidad de arcades: %d \n",
                   vec->id,
                   vec->nombre,
                   vec->direccion,
                   tipo,
                   cantidadArcades
                  );
        }

        printf("\n\n");
    }
}


int removerSalon(eSalon vec[], int tam,eArcade arc[], int tamArc,int posicion)
{
    int retorno=-1;
    int id;

    if(vec!=NULL && tam>0 && arc!=NULL && tamArc>0 && posicion>=0)
    {
        vec[posicion].isEmpty=1;
        id=vec[posicion].id;
        retorno=0;
        for(int i=0; i<tamArc; i++)
        {
            if(arc[i].idSalon == id)
            {
                arc[i].isEmpty=1;
            }
        }

    }

    return retorno;
}

int altaArcades(eSalon vec[], int tam,eArcade arc[], int tamArc,int* idArcarde)
{
    int retorno=-1;
    int posicion;
    int posicionArcade;
    eArcade aux;
    char exit='y';
    int idInput;

    if(vec!=NULL && tam>0 && arc!=NULL && tamArc>0 && idArcarde!=NULL)
    {
        if(espacioLibreSalon(vec,tam)!=-2)
        {
            do
            {
                utn_clear();
                printf("******** ALTA ARCADES ********");
                print_salon(vec,tam,arc,tamArc);
                utn_getInt(&idInput, "Ingrese el id de la persona a dar de baja: ","Error id invalido, ");
                posicion=buscarSalon(vec,tam,idInput);

                if(posicion>=0)
                {
                    posicionArcade=espacioLibreArcade(arc,tamArc);
                    if(posicionArcade==-2)
                    {
                        posicionArcade=0;
                    }
                    if(posicionArcade>=0)
                    {
                        utn_clear();
                        do
                        {
                            utn_ingresoScring(aux.nacionalidad, "Ingrese la nacionalidad: ", "Error (maximo 50 caracteres), ", sizeof(arc[0].nacionalidad));
                        }
                        while(esPalabra(aux.nacionalidad, sizeof(aux.nacionalidad)) );
                        utn_minMaxInt(&aux.tipoSonido,"ingrese el tipo de salon. 1- Mono 2-Estereo", "Error, ingrese 1 o 2 (ingrese 1- Mono 2-Estereo)  \n",1,2);
                        utn_getInt(&aux.cantidadJugadores,"Ingrese la cantidad de jugadores","Error, ingrese un numero valido\n");
                        utn_getInt(&aux.capacidadFichas,"Ingrese la capacidad de fichas","Error, ingrese un numero valido\n");


                        do
                        {
                            utn_ingresoScring(aux.nombreJuego, "Ingrese el nombre del juego ", "Error (maximo 50 caracteres), ", sizeof(arc[0].nombreJuego));
                        }
                        while(esPalabra(aux.nombreJuego,sizeof(arc[0].nombreJuego)));


                        aux.isEmpty=LLENO;
                        aux.idArcade=(*idArcarde);
                        aux.idSalon=vec[posicion].id;

                        (*idArcarde)++;
                        arc[posicionArcade]=aux;

                        printf("arcade cargado con exito\n");
                        utn_getCharDos(&exit,"\nDesea dar de alta otro salon?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');

                        retorno=0;
                    }
                    else
                    {
                        printf("\nNo se pueden cargar mas arcades\n");
                    }


                }
                else
                {
                    printf("\nId no encontrado\n");
                }

                if(espacioLibreSalon(vec,tam)!=-2)
                {
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    printf("\nNo se pueden cargar mas salones\n");
                    break;
                }

            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar un salon");
        }
        retorno=0;
    }

    return retorno;
}

int bajaArcades(eSalon vec[], int tam,eArcade arc[], int tamArc)
{
    int retorno=-1;
    int posicion;
    char confirm;
    char exit='y';
    int idInput;

    if(vec!=NULL && tam>0 && arc!=NULL && tamArc>0)
    {
        if(espacioLibreSalon(vec,tam)!=-2)
        {
            do
            {
                utn_clear();
                printf("******** BAJA DE Arcades ********");
                print_arcade(arc,tamArc);
                utn_getInt(&idInput, "Ingrese el id de la persona a dar de baja: ","Error id invalido, ");
                posicion=buscarArcadeId(idInput,arc,tamArc);

                if(posicion>=0)
                {
                    print_unSalon(&vec[buscarSalon(vec, tam,arc[posicion].idSalon)],arc,tamArc);
                    print_unArcade(&arc[posicion]);
                    utn_getCharDos(&confirm,"\nConfirmar la baja de este salon(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                    utn_clear();
                    if(confirm=='y')
                    {
                        arc[posicion].isEmpty=VACIO;
                        printf("salon dado de baja");
                    }
                    else
                    {
                        printf("Se cancelo la operacion");
                    }
                }
                else
                {
                    printf("\nId no encontrado\n");
                }

                if(espacioLibreSalon(vec,tam)!=-2)
                {
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    printf("\nNo se pueden cargar mas salones\n");
                    break;
                }

            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar un salon");
        }
        retorno=0;
    }

    return retorno;
}

int modificacionArcade(eSalon vec[], int tam,eArcade arc[], int tamArc)
{
    int retorno=-1;
    int posicion;
    char confirm='n';
    char exit='y';
    int idInput;

    if(vec!=NULL && tam>0 && arc!=NULL && tamArc>0)
    {
        if(espacioLibreSalon(vec,tam)!=-2)
        {
            do
            {
                utn_clear();
                printf("******** BAJA DE Arcades ********");
                print_arcade(arc,tamArc);
                utn_getInt(&idInput, "Ingrese el id de la persona a dar de baja: ","Error id invalido, ");
                posicion=buscarArcadeId(idInput,arc,tamArc);

                if(posicion>=0)
                {

                    do
                    {
                        utn_clear();
                        print_unSalon(&vec[buscarSalon(vec, tam,arc[posicion].idSalon)],arc,tamArc);
                        print_unArcade(&arc[posicion]);


                        switch(modificacion())
                        {
                        case 1:
                            do
                            {
                                utn_ingresoScring(arc[posicion].nacionalidad, "Ingrese el nombre de la persona: ", "Error (maximo 50 caracteres), ", sizeof(arc[0].nacionalidad));
                            }
                            while(esPalabra(arc[posicion].nacionalidad, sizeof(arc[0].nacionalidad)));
                            printf("\nnacionalidad cambiada correctamente\n");
                            break;

                        case 2:
                            utn_minMaxInt(&arc[posicion].tipoSonido, "ingrese el tipo de salon. 1- Shopping 2-Local", "Error, ingrese 1 o 2 (ingrese 1-Shopping 2-Local)  \n", 1,2);
                            printf("\ntipo cambiado correctamente\n");
                            break;

                        case 3:
                            utn_getInt(&arc[posicion].cantidadJugadores,"Ingrese la cantidad de jugadores", "Error, ingrese un numero valido");
                            printf("\njugadores cambiado correctamente\n");
                            break;

                        case 4:
                            utn_getInt(&arc[posicion].cantidadJugadores,"Ingrese la cantidad de fichas", "Error, ingrese un numero valido\n");
                            printf("\ncantidad de fichas cambiado correctamente\n");
                            break;

                        case 5:
                            do
                            {
                                utn_ingresoScring(arc[posicion].nombreJuego, "Ingrese el nombre del juego ", "Error (maximo 50 caracteres), ", sizeof(arc[0].nombreJuego));
                            }
                            while(esPalabra(arc[posicion].nombreJuego,sizeof(arc[0].nombreJuego)));
                            break;

                        case 6:
                            utn_getCharDos(&confirm, "Esta seguro que desea salir (y/n)?", "Error ingrese 'y' o 'n'\n", 'y','n');
                            break;
                        }
                        utn_stop();
                    }
                    while(confirm=='n');
                }
                else
                {
                    printf("\nId no encontrado\n");
                }

                if(espacioLibreSalon(vec,tam)!=-2)
                {
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    printf("\nNo se pueden cargar mas salones\n");
                    break;
                }

            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar un salon");
        }
        retorno=0;
    }

    return retorno;
}

int modificacion()
{
    int retorno;

    printf("-----------------modificacion de arcades ---------------\n\n");

    printf("1- nacionalidad\n");
    printf("2- tipo de sonido\n");
    printf("3- cantidad de jugadores\n");

    printf("4- capacidad de fichas\n");
    printf("5- nombre del juego\n");

    printf("6-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion a modificar: ", "Error, ingrese un numero entre el 1 y el 6",1,6);
    return retorno;
}
