#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "persona.h"
#include "localidad.h"
#include "utn.h"
#include "ibm.h"

int altaPersona(ePersona vec[], int tam, int* id, eLocalidad loc[],int tamLoc)
{
    int retorno=-1;
    int posicion;
    ePersona aux;
    char exit;

    if(vec!=NULL && tam>0 && id!=NULL)
    {
        do
        {
            utn_clear();

            posicion=espacioLibre(vec,tam);
            if(posicion==-2)
            {
                posicion=0;
            }
            if(posicion>=0)
            {
                do
                {
                    utn_ingresoScring(aux.nombre, "Ingrese el nombre de la persona: ", "Error (maximo 50 caracteres), ", 51);
                }
                while(esPalabra(aux.nombre,51));
                do
                {
                    utn_getFloat(&aux.altura, "Ingrese la altura: ","Error, altura no valida . ");
                }
                while(aux.altura<=0 || aux.altura>3);

                utn_getCharDos(&aux.sexo,"Ingrese el sexo de la persona", "Error, sexo no valido (f o m) \n",'f','m');
                utn_minMaxInt(&aux.edad,"ingrese la edad de la persona","Error edad no valida\n",1,130);
                mostrarLocalidades(loc, tamLoc);
                do
                {
                    utn_getInt(&aux.idLocalidad,"Ingrese la localidad donde esta la persona","Error localidad no valida");
                }
                while( !(validarIdLocalidad(aux.idLocalidad,loc,tamLoc)) );

                aux.isEmpty=0;
                aux.id=(*id);

                (*id)++;
                vec[posicion]=aux;

                printf("persona cargada con exito\n");
                utn_getCharDos(&exit,"\nDesea dar de alta otra persona?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');

                retorno=0;
            }
            else
            {
                printf("No hay espacio para cargar mas persona.\nPara hacerlo deve dar de baja a una persona actual.");
                exit='n';
                retorno=1;
            }
        }
        while(exit=='y');
    }
    return retorno;
}


int bajaPersona(ePersona vec[],int tam, eLocalidad loc[], int tamLoc)
{
    int retorno=-1;
    int posicion;
    char confirm;
    char exit='y';
    int idInput;

    if(vec!=NULL && tam>0)
    {
        if(espacioLibre(vec,tam)!=-2)
        {
            do
            {
                utn_clear();
                printf("******** BAJA DE PERSONAS ********");
                mostrarPersona(vec,tam,loc,tamLoc);

                utn_getInt(&idInput, "Ingrese el id de la persona a dar de baja: ","Error id invalido, ");
                posicion=buscarPersonaId(vec,tam,idInput);

                if(posicion>=0)
                {
                    mostrarUnaPersona(&vec[posicion],loc,tamLoc);
                    utn_getCharDos(&confirm,"\nConfirmar la baja de esta persona(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                    utn_clear();
                    if(confirm=='y')
                    {
                        removerPersona(vec, tam, posicion);
                        printf("Empleado dado de baja");
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

                if(espacioLibre(vec,tam)!=-2)
                {
                    utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
                }
                else
                {
                    break;
                }

            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
        retorno=0;
    }

    return retorno;
}



/*
void listaPersonasLocalidad(ePersona vec[], int tam, char* texto,int orden,eLocalidad loc[], int tamLoc)
{
    char localidad[30];
    if(vec!=NULL && texto!=NULL && (orden==1 || orden==0))
    {
        utn_clear();
        printf("%s\n\n",texto);
        ordenasPersonas(vec,tam,orden);
        mostrarPersona(vec,tam,loc,tamLoc);
        printf("\n\n");
    }
}
*/
int modificacionPersona(ePersona vec[],int tam, eLocalidad loc[], int tamLoc)
{
    int retorno=-1;
    int posicion;
    char exit='n';
    int id;

    if(vec!=NULL && tam>0)
    {
        if(espacioLibre(vec,tam) > -1)
        {
            do
            {
                utn_clear();
                printf("******** BAJA DE PERSONAS ********");
                mostrarPersona(vec,tam,loc,tamLoc);

                utn_getInt(&id, "Ingrese el id de la persona a modificar: ","Error id invalido, ");
                posicion=buscarPersonaId(vec,tam,id);
                if(posicion>=0)
                {
                    do
                    {
                        mostrarUnaPersona(&vec[posicion],loc,tamLoc);

                        switch(modificacion())
                        {
                        case 1:
                            do
                            {
                                utn_ingresoScring(vec[posicion].nombre, "Ingrese el nombre de la persona: ", "Error (maximo 50 caracteres), ", sizeof(vec[posicion].nombre));
                            }
                            while(esPalabra(vec[posicion].nombre, sizeof(vec[posicion].nombre)));
                            printf("\nNombre cambiado correctamente\n");
                            break;

                        case 2:
                            utn_minMaxInt(&vec[posicion].edad, "Ingrese la edad de la persona ", "Error, edad invalida\n ", 1,130);
                            printf("\nApellido cambiado correctamente\n");
                            break;

                        case 3:
                            utn_minMaxFloat(&vec[posicion].altura, "Ingrese la altura de la persona: ","Error, ", 0, 3);
                            printf("\nSueldo cambiado correctamente\n");
                            break;

                        case 4:
                            utn_getCharDos(&vec[posicion].sexo, "Ingrese el sexo de la persona ", "Error, ingrese f o m\n ",'f','m');
                            printf("\nSector cambiado correctamente\n");
                            break;

                        case 5:
                            mostrarLocalidades(loc,tamLoc);
                            do
                            {
                                utn_getInt(&vec[posicion].idLocalidad,"Ingrese el id de la localidad","Error, Ingrese un id valido");
                            }
                            while(!(validarIdLocalidad(vec[posicion].idLocalidad,loc,tamLoc)));
                            break;

                        case 6:
                            utn_getCharDos(&exit, "Esta seguro que desea salir (y/n)?", "Error ingrese 'y' o 'n'\n", 'y','n');
                            break;
                        }
                        utn_stop();
                    }
                    while(exit=='n');
                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
        retorno=0;
    }

    return retorno;
}

int modificacion()
{
    int retorno;

    printf("1-Nombre\n");
    printf("2-edad\n");
    printf("3-altura\n");
    printf("4-sexo\n");
    printf("5-localidad \n");
    printf("6-salir");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 5",1,6);

    utn_clear();
    return retorno;

}


int menu()
{
    int retorno;

    printf("-----------------Registro de personas---------------\n\n");

    printf("1- alta persona\n");
    printf("2- baja persona\n");
    printf("3- modificacion persona\n");
    printf("4- ordenar personas\n");
    printf("5- lista personas\n");
    printf("6- lista mujeres\n");
    printf("7- lista localidades\n");
    printf("8- mostrar personas una localidad\n");
    printf("9- mostrar personas por localidad\n");
    printf("10- nombre varon mas grande\n");
    printf("11- cantidad personas por localidad\n");
    printf("12- localidad menos habitada\n");
    printf("13- promedio alturas una localidad\n");
    printf("14- localidad menor promedio edad\n");
    printf("15- mostrar comidas\n");
    printf("16- alta almuerzo\n");
    printf("17- mostrar almuerzos\n");
    printf("18-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 5",1,18);
    return retorno;
}

int criterio()
{
    int retorno;

    printf("-----------------SELECCIONE CRITERIO --------------\n\n");

    printf("1- nombres asendentes\n");
    printf("2- nombres desendentes\n");
    printf("3- id asendentes\n");
    printf("4- id desendentes\n");
    printf("5- sexos asendentes\n");
    printf("6- sexos desendentes\n");
    printf("7- alturas asendentes\n");
    printf("8- alturas desendentes\n");

    printf("-SALIR\n\n");

    utn_minMaxInt(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un numero entre el 1 y el 8",1,8);
    return retorno;
}

void ordenarPersonasCriterio(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    if(vec!=NULL&& tam>0 && loc!=NULL && tamLoc>0 )
    {
        utn_clear();
        ordenasPersonas(vec,tam,criterio());
        mostrarPersona(vec,tam,loc,tamLoc);
        utn_stop();
    }
}

int print_personasUnaLocalidad(ePersona vec[],int tam,eLocalidad loc[], int tamLoc)
{
    int localidadInput;
    char localidad[30];
    int retorno=-1;

    if(vec!=NULL && tam>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) >-1)
        {
            utn_clear();
            mostrarLocalidades(loc,tamLoc);
            do
            {
                utn_getInt(&localidadInput,"Ingrese el id de una localidad","Error, ");
            }
            while(!(validarIdLocalidad(localidadInput,loc,tamLoc)));

            cargarDescripcionLocalidad(loc,tamLoc,localidadInput,localidad);

            printf("-----------------Lista de personas----------------- \n\n");
            printf("Id       Nombre         edad        altura             Sexo        localidad\n");
            for(int i=0; i<tam; i++)
            {
                if( !(vec[i].isEmpty) && vec[i].idLocalidad == localidadInput )
                {
                    printf("%d     %-10s     %d   %11.2f Mts     %7c           %s\n",
                           vec[i].id,
                           vec[i].nombre,
                           vec[i].edad,
                           vec[i].altura,
                           vec[i].sexo,
                           localidad
                          );
                }
            }
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
        retorno=0;
    }
    return retorno;
}

void mostrarListaMujeres(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    char localidad[30];
    if(vec!=NULL && tam>0)
    {
        printf("-----------------Lista de personas----------------- \n\n");
        printf("Id       Nombre         edad        altura             Sexo        localidad\n");
        for(int i=0; i<tam; i++)
        {
            if( !(vec[i].isEmpty) && vec[i].sexo=='f')
            {
                cargarDescripcionLocalidad(loc,tamLoc,vec[i].idLocalidad,localidad);
                printf("%d     %-10s     %d   %11.2f Mts     %7c           %s\n",
                       vec[i].id,
                       vec[i].nombre,
                       vec[i].edad,
                       vec[i].altura,
                       vec[i].sexo,
                       localidad
                      );
            }
        }
    }
}

void mostrarPersonasPorLocalidades(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    char localidad[30];

    if(vec!=NULL && tam>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) >-1)
        {
            utn_clear();
            printf("-----------------Lista de personas por localidad----------------- \n\n");
            for(int j=loc[0].id; j<(tamLoc+loc[0].id) ; j++)
            {
                cargarDescripcionLocalidad(loc,tamLoc,j,localidad);
                printf("Personas en la localidad %s\n\n",localidad);
                printf("Id       Nombre         edad        altura             Sexo        localidad\n");
                for(int i=0; i<tam; i++)
                {
                    if( !(vec[i].isEmpty) && vec[i].idLocalidad == j )
                    {
                        printf("%d     %-10s     %d   %11.2f Mts     %7c           %s\n",
                               vec[i].id,
                               vec[i].nombre,
                               vec[i].edad,
                               vec[i].altura,
                               vec[i].sexo,
                               localidad
                              );
                    }
                }
                printf("\n");
            }
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
    }
}

void print_nombreVaronMayor(ePersona vec[],int tam)
{
    char nombreMayor[30];
    int flagPrimerHombre=1;
    int edadMayor;
    int posicionMayor;

    if(vec!=NULL && tam>0)
    {
        utn_clear();

        if(espacioLibre(vec,tam) >-1)
        {
            for(int i=0; i<tam; i++)
            {
                if( !(vec[i].isEmpty) && vec[i].sexo=='m' &&
                        (flagPrimerHombre || vec[i].edad>edadMayor))
                {
                    flagPrimerHombre=0;
                    edadMayor=vec[i].edad;
                    posicionMayor=i;
                }
            }
            strcpy(nombreMayor,vec[posicionMayor].nombre);
            printf("El varon con mayor edad se llama %s",nombreMayor);
        }

        else
        {
            printf("Primero deve ingresar una persona");
        }
        //utn_stop();
    }
}

void cantidadPersonasPorLocalidad(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    char localidad[30];
    int contadorLocalidades;

    if(vec!=NULL && tam>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) >-1)
        {
            utn_clear();
            for(int j=loc[0].id; j<(tamLoc+loc[0].id) ; j++)
            {
                contadorLocalidades=0;
                for(int i=0; i<tam; i++)
                {
                    if( !(vec[i].isEmpty) && vec[i].idLocalidad == j )
                    {
                        contadorLocalidades++;
                    }
                }
                cargarDescripcionLocalidad(loc,tamLoc,j,localidad);
                printf("Hay %d personas en la localidad %s\n\n",contadorLocalidades,localidad);

            }
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
    }
}

void print_localidadMenosHabitada(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    char localidad[30];
    int contadorLocalidades;
    int localidadMenor;
    int contadorMenosHabitantes;
    int flagPrimeraVuelta=1;

    if(vec!=NULL && tam>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) >-1)
        {
            utn_clear();
            for(int j=loc[0].id; j<(tamLoc+loc[0].id) ; j++)
            {
                contadorLocalidades=0;
                for(int i=0; i<tam; i++)
                {
                    if( !(vec[i].isEmpty) && vec[i].idLocalidad == j )
                    {
                        contadorLocalidades++;
                    }
                }
                if(flagPrimeraVuelta || contadorLocalidades<contadorMenosHabitantes)
                {
                    flagPrimeraVuelta=0;
                    contadorMenosHabitantes=contadorLocalidades;
                    localidadMenor=j;

                }
            }
            cargarDescripcionLocalidad(loc,tamLoc,localidadMenor,localidad);
            printf("La localidad con menos habitantes es %s, con %d habitantes\n\n",localidad,contadorMenosHabitantes);

        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
    }
}

int print_localidadPromedioAltura(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    int localidadInput;
    char localidad[30];
    float alturaPromedio;
    int contadorPersonas=0;
    float totalAlturas=0;
    int retorno=-1;

    if(vec!=NULL && tam>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) >-1)
        {
            utn_clear();
            mostrarLocalidades(loc,tamLoc);
            do
            {
                utn_getInt(&localidadInput,"Ingrese el id de una localidad","Error, ");
            }
            while(!(validarIdLocalidad(localidadInput,loc,tamLoc)));

            cargarDescripcionLocalidad(loc,tamLoc,localidadInput,localidad);

            for(int i=0; i<tam; i++)
            {
                if( !(vec[i].isEmpty))
                {
                    contadorPersonas++;
                    totalAlturas=totalAlturas+vec[i].altura;
                }
            }
            if(contadorPersonas>0)
            {
                alturaPromedio=totalAlturas/contadorPersonas;
                printf("El promedio de alturas en la localidad de %s es %.2f Mts",localidad,alturaPromedio);
            }
            else
            {
                printf("No hay personas en esta localidad");
            }
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
        retorno=0;
    }
    return retorno;
}

void print_localidadMenorPromedioEdad(ePersona vec[],int tam, eLocalidad loc[],int tamLoc)
{
    char localidad[30];
    int sumaEdad;
    int localidadMenor;
    float promedioEdad;
    int contadorHabitantes;
    float promedioMenor;
    int flagPrimeraVuelta=1;

    if(vec!=NULL && tam>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) >-1)
        {
            utn_clear();
            for(int j=loc[0].id; j<(tamLoc+loc[0].id) ; j++)
            {
                contadorHabitantes=0;
                sumaEdad=0;
                promedioEdad=0;
                for(int i=0; i<tam; i++)
                {
                    if( !(vec[i].isEmpty) && vec[i].idLocalidad == j )
                    {
                        sumaEdad=sumaEdad+vec[i].edad;
                        contadorHabitantes++;
                    }
                }
                if(contadorHabitantes>0)
                {
                    promedioEdad= (float) sumaEdad/contadorHabitantes;
                }
                if(flagPrimeraVuelta || promedioEdad<promedioMenor)
                {
                    flagPrimeraVuelta=0;
                    promedioMenor=promedioEdad;
                    localidadMenor=j;

                }
            }
            cargarDescripcionLocalidad(loc,tamLoc,localidadMenor,localidad);
            printf("La localidad con menos menor promedio de edades es %s.\nCon una edad promedio de %.2f años\n\n",localidad,promedioMenor);

        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
    }
}

int altaAlmuerzo(ePersona vec[],int tam, eComidas com[],int tamCom, eLocalidad loc[],int tamLoc)
{
    int retorno=-1;
    int posicion;
    int posicionComida;
    char exit='n';
    int error;
    int id;

    if(vec!=NULL && tam>0 && com!=NULL && tamCom>0 && loc!=NULL && tamLoc>0)
    {
        if(espacioLibre(vec,tam) > -1)
        {
            do
            {
                utn_clear();
                printf("******** CARGAR ALMUERZO ********\n\n");
                mostrarPersona(vec,tam,loc,tamLoc);

                utn_getInt(&id, "Ingrese el id de la persona para cargar almuerzo: ","Error id invalido, ");
                posicion=buscarPersonaId(vec,tam,id);
                if(posicion>=0)
                {

                    posicionComida=espacioLibreComida(vec[posicion].idComidas,tamCom);
                    if(posicionComida >= 0)
                    {
                        utn_clear();
                        mostrarcomidas(com,tamCom);
                        do
                        {
                            utn_getInt(&vec[posicion].idComidas[posicionComida],"Ingrese el id de la comida deseada ", "Error, Ingrese una comida valida\n");
                        }
                        while(!(validarComidas(vec[posicion].idComidas[posicionComida], com,tamCom )));
                        do
                        {
                            printf("Ingrese la fecha de este almuerzo ");
                            __fpurge(stdin);
                            error=scanf("%2d/%2d/%4d",&vec[posicion].fechaAlmuerzo[posicionComida].dia,
                                        &vec[posicion].fechaAlmuerzo[posicionComida].mes,
                                        &vec[posicion].fechaAlmuerzo[posicionComida].anio
                                       );
                        }
                        while(!error);
                    }
                    else
                    {
                        printf("No hay mas lugar");
                        break;
                    }
                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_getCharDos(&exit,"\nDesea ingresar otro ID?(y/n) ", "Error, Ingrese 'y' o 'n'\n",'y','n');
            }
            while(exit=='y');
        }
        else
        {
            utn_clear();
            printf("Primero deve ingresar una persona");
        }
        retorno=0;
    }

    return retorno;
}

void print_almuerzos(ePersona vec[],int tam,eLocalidad loc[],int tamLoc,eComidas com[],int tamCom)
{
    char localidad[sizeof(loc[0].descripcion)];
    char comida[sizeof(com[0].descripcion)];
    if(vec!=NULL && tam>0)
    {
        utn_clear();
        printf("-----------------Lista de Almuerzos----------------- \n\n");
        printf("Id       Nombre         edad        altura             Sexo        localidad\n");
        for(int i=0; i<tam; i++)
        {
            if( !(vec[i].isEmpty) && vec[i].idComidas[0]!=0)
            {
                cargarDescripcionLocalidad(loc,tamLoc,vec[i].idLocalidad,localidad);
                printf("%d     %-10s     %d   %11.2f Mts     %7c           %s\n",
                       vec[i].id,
                       vec[i].nombre,
                       vec[i].edad,
                       vec[i].altura,
                       vec[i].sexo,
                       localidad
                      );
                for(int j=0 ; (vec[i].idComidas[j]!=0 && j< (sizeof(vec[0].idComidas)/4) ); j++)
                {
                    cargarDescripcioncomida(com,tamCom,vec[i].idComidas[j],comida);
                    printf("%dº almuerzo. fecha: %02d/%02d/%04d  comio: %s \n",j+1,
                           vec[i].fechaAlmuerzo[j].dia,
                           vec[i].fechaAlmuerzo[j].mes,
                           vec[i].fechaAlmuerzo[j].anio,
                           comida);
                }
                printf("\n");

            }
        }
    }
}
