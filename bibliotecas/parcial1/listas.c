#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "trabajo.h"
#include "servicios.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#include "tipo.h"
#include "listas.h"

void mostrarAnimalesServicio( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra)
{
    char servicio[20];
    char color[20];
    char tipo[20];
    int posicionMascota;

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0&& ser!=NULL && tamSer>0 && tra!=NULL && tamTra>0  )
    {
        for (int i = 0; i < tamSer; i++)
        {
            descripccionServicio(ser,tamSer,ser[i].id,servicio);

            if(!hayServicios(tra,tamTra,ser[i].id))
            {
                printf("No hay servicios de tipo %s\n\n",servicio);
                continue;
            }

            printf("Servicio realizado: %s\n",servicio);
            prototipoListaMascotasTrabajo();
            for (int j=0; j<tam; j++)
            {
                if(!(tra[j].isEmpty) && tra[j].idServicio== ser[i].id )
                {
                    posicionMascota=validarMarcotaId(vec,tam,tra[j].idMscota);
                    descripccionColor(col,tamCol,vec->idColor,color);
                    descripcionTipo(tip,tamTip,vec->idTipo,tipo);
                    printf("%-6d    %-10s           %-15s  %-10s %d         %c          %d        %2d/%2d/%4d \n",
                           vec[posicionMascota].id,
                           vec[posicionMascota].nombreMascota,
                           tipo,
                           color,
                           vec[posicionMascota].edad,
                           vec[posicionMascota].vacunas,
                           tra[j].id,
                           tra[j].fecha.mes,
                           tra[j].fecha.mes,
                           tra[j].fecha.anio
                          );
                }
            }
            printf("\n\n");
        }
        printf("\n\n");
    }
}


void mostrarAnimalesColor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char color[20];

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        for (int i = 0; i < tamCol; i++)
        {
            descripccionColor(col,tamCol,col[i].id,color);
            if(!hayColores(vec,tam,col[i].id))
            {
                printf("No hay mascotas de color %s\n\n",color);
                continue;
            }

            printf("Mascota color %s\n",color);
            printf("      *** Lista mascotas *** \n\n");
            printf("Id        nombre mascota       tipo animal      color      edad    vacunado?\n");

            for (int j=0; j<tam; j++)
            {
                if(!(vec[j].isEmpty) && vec[j].idColor== col[i].id)
                {
                    mostrarUnaFilaMascota(&vec[j],col,tamCol,tip,tamTip);
                }
            }
            printf("\n\n");
        }
        printf("\n\n");

    }

}


void mostrarAnimalesTipo( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char tipo[20];

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {


        for (int i = 0; i < tamTip; i++)
        {
            descripcionTipo(tip,tamTip,tip[i].id,tipo);
            if(!hayTipos(vec,tam,tip[i].id))
            {
                printf("No hay mascotas de tipo %s\n\n",tipo);
                continue;
            }
            printf("Mascota de tipo %s\n",tipo);
            printf("      *** Lista mascotas *** \n\n");
            printf("Id        nombre mascota       tipo animal      color      edad    vacunado?\n");

            for (int j=0; j<tam; j++)
            {
                if(!(vec[j].isEmpty) && vec[j].idTipo== tip[i].id)
                {
                    mostrarUnaFilaMascota(&vec[j],col,tamCol,tip,tamTip);
                }
            }
            printf("\n\n");
        }
        printf("\n\n");

    }

}

void prototipoMascotas()
{
    printf("      *** Lista mascotas *** \n\n");
    printf("Id        nombre mascota       tipo animal      color      edad    vacunado?\n");

}




void mostrarUnaFilaMascota( eMascota *vec,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char color[20];
    char tipo[20];

    if (vec != NULL  && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {
        if(!(vec->isEmpty))
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripcionTipo(tip,tamTip,vec->idTipo,tipo);
            printf("%-6d    %-10s           %-15s  %-10s %d         %c \n",
                   vec->id,
                   vec->nombreMascota,
                   tipo,
                   color,
                   vec->edad,
                   vec->vacunas
                  );
        }

    }

}

void mostrarServicioPromedioMayor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer)
{
    //  char servicio[20];
    int iDServicioMayor;
    int flagPrimeraVuelta =1;
    int valorServicio;
    int suma=0;
    int contador=0;
    float promedio=0;
    int promedioMayor;
    int posicionMascota;


    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0&& ser!=NULL && tamSer>0 && tra!=NULL && tamTra>0  )
    {

        for(int i=ser[0].id ; i<=(ser[2].id) ; i++)
        {
            suma=0;
            contador=0;
            promedio=0;
            for(int j=0; j<tamTra; j++)
            {
                valorServicio=validarServicio(ser,tamSer,i);
                if(! tra[j].isEmpty && tra[j].idServicio== i)
                {
                    contador++;
                    suma+=valorServicio;
                }
            }
            if(suma!=0)
            {
                promedio=(float) suma/contador;
            }
            if(flagPrimeraVuelta || promedio>promedioMayor)
            {
                flagPrimeraVuelta=0;
                promedioMayor=promedio;
                iDServicioMayor=i;
            }
        }

        prototipoListaMascotasTrabajo();
        for(int i=0; i<tam; i++)
        {
            if(!(tra[i].isEmpty) && tra[i].idServicio==iDServicioMayor)
            {

                posicionMascota=validarMarcotaId(vec,tam,(tra[i].idMscota));

                mostrarUnaFilaMascotaTrabajo(&vec[posicionMascota],&tra[i],col,tamCol,tip,tamTip);


            }
        }
    }
}





void mostrarUnaFilaMascotaTrabajo( eMascota *vec,eTrabajo *tra,eColor col[], int tamCol,eTipo tip[], int tamTip)
{

    char color[20];
    char tipo[20];

    if (vec != NULL  && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 && tra!=NULL  )
    {
        if(!(vec->isEmpty))
        {
            descripccionColor(col,tamCol,vec->idColor,color);
            descripcionTipo(tip,tamTip,vec->idTipo,tipo);
            printf("%-6d    %-10s           %-15s  %-10s %d         %c          %d        %2d/%2d/%4d \n",
                   vec->id,
                   vec->nombreMascota,
                   tipo,
                   color,
                   vec->edad,
                   vec->vacunas,
                   tra->id,
                   tra->fecha.mes,
                   tra->fecha.mes,
                   tra->fecha.anio
                  );
        }

    }

}


void prototipoListaMascotasTrabajo()
{
    printf("      *** Lista mascotas *** \n\n");
    printf("Id        nombre mascota       tipo animal      color      edad    vacunado?   id trabajo    fecha\n");

}


char menuListas()
{
    char retorno;

    printf("-----------------Elija que lista quiere ver---------------\n\n");

    printf("A- ANIMALES SEPARADOS POR COLOR\n");
    printf("B- ANIMALES SEPARADOS POR SERVICIO\n");
    printf("C- ANIMALES SEPARADOS POR TIPO\n");
    printf("D- MASCOTAS DE UN COLOR\n");
    printf("E- MASCOTAS DE UN TIPO\n");
    printf("F- CANTIDAD MASCOTAS POR TIPO Y COLOR\n");
    printf("G- SERVICIOS DE UNA MASCOTA\n");
    printf("H- MASCOTAS POR EL SERVICIO PROMEDIO EN COSTO\n");
    printf("I- MASCOTAS CON UN MISMO SERVICIO\n");
    printf("J- CANTIDAD DE MASCOTAS POR UN SERVICIO\n");
    printf("K- SERVICIOS DE UNA FECHA\n");
    printf("L- INFORME ANIMALES MAS EDAD\n");
    printf("M- COLOR MAS USUAL\n");


    printf("N-SALIR\n\n");

    utn_getChar(&retorno,"\nIngrese la opcion deseada: ", "Error, ingrese un caracter valido\n");
    retorno= toupper(retorno);
    utn_clear();

    return retorno;
}
int mostrarListas( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra)
{

    int retorno=-1;
    char salir='N';

    if (vec != NULL && tam > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0&& ser!=NULL && tamSer>0 && tra!=NULL && tamTra>0  )
    {
        do
        {
            switch(menuListas())
            {
            case 'A':
                mostrarAnimalesColor(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'B':
                mostrarAnimalesServicio(vec,tam,col,tamCol,tip,tamTip,ser,tamSer,tra,tamTra);
                break;

            case 'C':
                mostrarAnimalesTipo(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'D':
                mostrarMascotaColorSelec(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'E':
                mostrarMascotaTipoSelec(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'F':
                contarColorTipo(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'G':
                mostrarServiciosDeMascota(vec,tam,col,tamCol,tip,tamTip,tra,tamTra,ser,tamSer);
                break;
            case 'H':
                mostrarServicioPromedioMayor(vec,tam,col,tamCol,tip,tamTip,tra,tamTra,ser,tamSer);
                break;
            case 'I':
                mostrarMascotasDeUnServicio(vec,tam,col,tamCol,tip,tamTip,tra,tamTra,ser,tamSer);
                break;

            case 'J':
                contarMarcotasServicio(vec,tam,col,tamCol,tip,tamTip,tra,tamTra,ser,tamSer);
                break;

            case 'K':
                mostrarFechaServicios(tra,tamTra,ser,tamSer);
                break;

            case 'L':
                informarAnimalMayor(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'M':
                mostrarColorMasUsual(vec,tam,col,tamCol,tip,tamTip);
                break;

            case 'N':
                utn_confirmar(&salir,"desea salir?(S/N) ", "Error ingrese 'n' o 's'\n",'N','S');
                break;

            default:
                printf("Error, ingrese un caracter valido");

                break;

            }
            utn_stop();
            utn_clear();

        }
        while(salir=='N');
    }

    return retorno;
}


int hayColores(eMascota mas[],int tamMas,int idColor)
{
    int retorno=0;

    if(mas!=NULL && tamMas>0)
    {
        for(int i=0; i<tamMas; i++)
        {
            if(mas[i].idColor==idColor && !(mas[i].isEmpty))
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int hayTipos(eMascota mas[],int tamMas,int idTipo)
{
    int retorno=0;

    if(mas!=NULL && tamMas>0)
    {
        for(int i=0; i<tamMas; i++)
        {
            if(mas[i].idTipo==idTipo && !(mas[i].isEmpty))
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int hayServicios(eTrabajo tra[],int tamTra,int idServicio)
{
    int retorno=0;

    if(tra!=NULL && tamTra>0)
    {
        for(int i=0; i<tamTra; i++)
        {
            if(tra[i].idServicio==idServicio && !(tra[i].isEmpty))
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}




int mostrarMascotaColorSelec(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip)
{
    int retorno=-1;

    int id;
    char exit='N';

    if (mas != NULL && tamMas > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreMascota(mas,tamMas)!=-2)
        {
            do
            {
                utn_clear();
                mostrarColor(col,tamCol);

                utn_getInt(&id, "Ingrese el id del color : ","Error id invalido, ");
                //posicion=validarColor(col,tamCol,id);
                if(validarColor(col,tamCol,id))
                {
                    if(hayColores(mas,tamMas,id))
                    {
                        utn_clear();
                        prototipoMascotas();
                        for(int i=0; i<tamMas; i++)
                        {
                            if(mas[i].idColor==id)
                            {
                                mostrarUnaFilaMascota(&mas[i],col,tamCol,tip,tamTip);
                            }
                        }
                        retorno=0;
                    }
                    else
                    {
                        printf("No hay mascotas con este color");
                    }

                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;
}

int mostrarMascotaTipoSelec(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip)
{
    int retorno=-1;
    int id;
    char exit='N';

    if (mas != NULL && tamMas > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreMascota(mas,tamMas)!=-2)
        {
            do
            {
                utn_clear();
                mostrarTipo(tip,tamTip);

                utn_getInt(&id, "Ingrese el id del color : ","Error id invalido, ");
                //posicion=validarTipo(tip,tamTip,id);
                if(validarTipo(tip,tamTip,id))
                {
                    if(hayTipos(mas,tamMas,id))
                    {
                        utn_clear();
                        prototipoMascotas();
                        for(int i=0; i<tamMas; i++)
                        {
                            if(mas[i].idTipo==id)
                            {
                                mostrarUnaFilaMascota(&mas[i],col,tamCol,tip,tamTip);
                            }
                        }
                        retorno=0;
                    }
                    else
                    {
                        printf("No hay mascotas de este tipo");
                    }
                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;
}

int contarColorTipo(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip)
{
    int retorno=-1;
    int contador;
    int idTipo;
    int idColor;
    char tipo[20];
    char color[20];
    char exit='N';

    if (mas != NULL && tamMas > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreMascota(mas,tamMas)!=-2)
        {
            do
            {
                utn_clear();
                mostrarTipo(tip,tamTip);

                utn_getInt(&idTipo, "Ingrese el id del tipo : ","Error id invalido, ");
                //posicion=validarTipo(tip,tamTip,id);
                if(validarTipo(tip,tamTip,idTipo))
                {

                    do
                    {
                        exit='N';
                        contador=0;
                        utn_clear();
                        mostrarColor(col,tamCol);
                        utn_getInt(&idColor, "Ingrese el id del color : ","Error id invalido, ");
                        if(validarColor(col,tamCol,idColor))
                        {
                            descripccionColor(col,tamCol,idColor,color);
                            descripcionTipo(tip,tamTip,idTipo,tipo);
                            for(int i=0; i<tamMas; i++)
                            {
                                if(!(mas[i].isEmpty)&& mas[i].idColor==idColor&& mas[i].idTipo==idTipo)
                                {
                                    contador++;
                                }
                            }
                            utn_clear();
                            if(contador)
                            {
                                printf("Hay un total de %d mascotas del tipo %s y color %s \n",contador,tipo,color);
                            }
                            else
                            {
                                printf("No hay mascotas del tipo %s  y color %s\n",tipo,color);
                            }
                        }
                        else
                        {
                            printf("\nId no encontrado\n");
                            utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
                        }
                    }
                    while(exit=='S');


                    retorno=0;

                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;
}

int mostrarServiciosDeMascota(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer)
{

    int retorno=-1;
    int posicion;
    int idMascota;

    char exit='N';

    if (mas != NULL && tamMas > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreTrabajo(tra,tamTra)!=-2)
        {
            do
            {
                utn_clear();
                mostrarMascotas(mas,tamMas,col,tamCol,tip,tamTip);

                utn_getInt(&idMascota, "Ingrese el id del tipo : ","Error id invalido, ");
                posicion=validarMarcotaId(mas,tamMas,idMascota);
                if(posicion!=-1)
                {
                    if(haytrabajo(tra,tamTra,idMascota)>=0)
                    {
                        mostrarUnaMacota(&mas[posicion],col,tamCol,tip,tamTip);
                        prototipoTrabajo();
                        for(int i=0; i<tamTra; i++)
                        {
                            if(!(tra[i].isEmpty) && tra[i].idMscota== idMascota)
                            {
                                mostrarUnTrabajo(&tra[i],ser,tamSer);
                            }
                        }
                    }
                    else
                    {
                        printf("No se le realizo ningun servicio a esta mascota");
                    }

                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;

}

void prototipoTrabajo()
{
    printf("      *** Lista trabajos *** \n\n");
    printf("Id trabajo       Servicio              Precio        Fecha\n");
}
void mostrarUnTrabajo(eTrabajo *tra, eServicio ser[],int tamSer)
{
    int precioServicio;
    char servicio[20];
    if(tra!=NULL && ser!=NULL &&tamSer>0)
    {
        if(!(tra->isEmpty))
        {

            descripccionServicio(ser,tamSer,tra->idServicio,servicio);
            precioServicio= validarServicio(ser,tamSer,tra->idServicio);

            printf("%-8d         %-10s         $%d        %02d/%02d/%04d\n",
                   tra->id,

                   servicio,
                   precioServicio,
                   tra->fecha.dia,
                   tra->fecha.mes,
                   tra->fecha.anio
                  );
        }
    }

}

int haytrabajo(eTrabajo tra[],int tamTra,int idMascota)
{
    int retorno=-1;

    if(tra!=NULL && tamTra>0)
    {
        for(int i=0; i<tamTra; i++)
        {
            if(tra[i].idMscota==idMascota && !(tra[i].isEmpty))
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int mostrarMascotasDeUnServicio(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer)
{

    int retorno=-1;
    int idServicio;

    char exit='N';

    if (mas != NULL && tamMas > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreTrabajo(tra,tamTra)!=-2)
        {
            do
            {
                utn_clear();
                mostrarServicio(ser,tamSer);

                utn_getInt(&idServicio, "Ingrese el id del tipo : ","Error id invalido, ");
                //posicion=validarMarcotaId(mas,tamMas,idMascota);
                if(validarServicio(ser,tamSer,idServicio))
                {
                    if(hayServicios(tra,tamTra,idServicio))
                    {
                        utn_clear();
                        prototipoMascotas();
                        for(int i=0; i<tamTra; i++)
                        {
                            if(!(tra[i].isEmpty) && tra[i].idServicio== idServicio)
                            {
                                //validarMarcotaId(mas,tamMas,tra[i].idMscota);
                                mostrarUnaFilaMascota(&mas[validarMarcotaId(mas,tamMas,tra[i].idMscota)],col,tamCol,tip,tamTip);
                            }
                        }
                    }
                    else
                    {
                        printf("No se encontro ninguna mascota con este servicio");
                    }

                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;

}


int contarMarcotasServicio(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer)
{

    int retorno=-1;
    int posicion;
    int idMascota;
    int totalGasto;
    int contadorServicios;

    char exit='N';

    if (mas != NULL && tamMas > 0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0 )
    {

        if(espacioLibreTrabajo(tra,tamTra)!=-2)
        {
            do
            {
                totalGasto=0;
                contadorServicios=0;
                utn_clear();
                mostrarMascotas(mas,tamMas,col,tamCol,tip,tamTip);

                utn_getInt(&idMascota, "Ingrese el id del tipo : ","Error id invalido, ");
                posicion=validarMarcotaId(mas,tamMas,idMascota);
                utn_clear();
                if(posicion!=-1)
                {
                    for(int i=0; i<tamTra; i++)
                    {
                        if(!(tra[i].isEmpty) && tra[i].idMscota== idMascota)
                        {
                            totalGasto+=validarServicio(ser,tamSer,tra[i].idServicio);
                            contadorServicios++;
                        }
                    }

                    printf("A esta mascota se le realizaron %d servicios y se gasto $%.2d\n",contadorServicios,totalGasto);

                }
                else
                {
                    printf("\nId no encontrado\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otro ID?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;
}

int mostrarFechaServicios(eTrabajo tra[],int tamTra,eServicio ser[],int tamSer)
{

    eFecha fechaIngreso;
    int retorno=-1;
    char exit='N';

    if (tra != NULL && tamTra > 0 && ser!=NULL && tamSer>0 )
    {

        if(espacioLibreTrabajo(tra,tamTra)!=-2)
        {
            do
            {
                utn_clear();
                get_fecha(&fechaIngreso,"Ingrese la fecha a buscar","Error ingrese una fecha valida");
                // mostrarServicio(ser,tamSer);

                //utn_getInt(&idServicio, "Ingrese el id del tipo : ","Error id invalido, ");
                //posicion=validarMarcotaId(mas,tamMas,idMascota);
                if(hayFecha(tra,tamTra,fechaIngreso))
                {

                    utn_clear();
                    prototipoTrabajo();
                    for(int i=0; i<tamTra; i++)
                    {
                        if(!(tra[i].isEmpty) &&
                                tra[i].fecha.dia== fechaIngreso.dia &&
                                tra[i].fecha.mes== fechaIngreso.mes &&
                                tra[i].fecha.anio== fechaIngreso.anio)
                        {
                            //validarMarcotaId(mas,tamMas,tra[i].idMscota);
                            mostrarUnTrabajo(&tra[i],ser,tamSer);
                        }
                    }



                }
                else
                {
                    printf("\nNo hay registros de esta fecha\n");
                }
                utn_confirmar(&exit,"\nDesea ingresar otra fecha?(S/N) ", "Error, Ingrese 'S' o 'N'\n",'S','N');
            }
            while(exit=='S');
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            retorno=1;
        }
    }

    return retorno;

}

int hayFecha(eTrabajo tra[],int tamTra, eFecha fechaIngreso)
{
    int retorno=0;
    if(tra!=NULL && tamTra >0)
    {
        for(int i=0; i<tamTra; i++)
        {
            if(!(tra[i].isEmpty) &&
                    tra[i].fecha.dia== fechaIngreso.dia &&
                    tra[i].fecha.mes== fechaIngreso.mes &&
                    tra[i].fecha.anio== fechaIngreso.anio)
            {
                retorno=1;
                break;
            }
        }
    }

    return retorno;
}

int informarAnimalMayor(eMascota mas[],int tamMas, eColor col[],int tamCol,eTipo tip[],int tamTip)
{
    int returno=-1;
    int mayor;
    int flagPrimeraVuelta=1;

    if(mas!=NULL && tamMas>0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0)
    {
        if(espacioLibreMascota(mas,tamMas)!=-2)
        {
            for(int i=0; i<tamMas; i++)
            {
                if(!(mas[i].isEmpty) && ( flagPrimeraVuelta || mas[i].edad>mayor))
                {
                    flagPrimeraVuelta=0;
                    mayor=mas[i].edad;
                }
            }
            utn_clear();
            prototipoMascotas();
            for(int i=0; i<tamMas; i++)
            {
                if(!(mas[i].isEmpty) && mas[i].edad==mayor)
                {
                    mostrarUnaFilaMascota(&mas[i],col,tamCol,tip,tamTip);
                }
            }
            returno=0;
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            returno=1;
        }
    }

    return returno;
}

int mostrarColorMasUsual(eMascota mas[],int tamMas, eColor col[],int tamCol,eTipo tip[],int tamTip)
{
    int returno=-1;
    int flagPrimeraVuelta=1;
    int contador;
    int contadorMayor;
    char color[20];


    if(mas!=NULL && tamMas>0 && col!=NULL && tamCol>0 && tip!=NULL && tamTip>0)
    {
        if(espacioLibreMascota(mas,tamMas)!=-2)
        {
            for(int i=col[0].id ; i<=(col[4].id) ; i++)
            {
                contador=0;
                for(int j=0; j<tamMas; j++)
                {
                    if(!( mas[j].isEmpty) && mas[j].idColor== i)
                    {
                        contador++;
                    }

                }
                if(flagPrimeraVuelta || contador>contadorMayor)
                {
                    flagPrimeraVuelta=0;
                    contadorMayor=contador;
                }
            }
            for(int i=col[0].id ; i<=(col[4].id) ; i++)
            {
                contador=0;
                for(int j=0; j<tamMas; j++)
                {
                    if(! mas[j].isEmpty && mas[j].idColor== i)
                    {
                        contador++;
                    }

                }
                if(contador>=contadorMayor)
                {
                    descripccionColor(col,tamCol,i,color);
                    printf("El color %s es el que aparece mas veces", color);
                }
            }
            returno=0;
        }
        else
        {
            utn_clear();

            printf("Primero deve cargar una mascota.");
            returno=1;
        }
    }

    return returno;
}
