#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "fecha.h"

int get_fecha(eFecha* fecha, char mensaje[], char mensajeError[])
{
    int retorno=-1;
    int error;
    int dia;
    int mes;
    int anio;

    if(fecha!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            __fpurge(stdin);
            error=scanf("%2d/%2d/%4d",&dia,&mes,&anio);
            if(error==3 && (dia>=1 && dia<=31) && (mes>=1 && mes<=12) && (anio>=1700 && anio<=2021))
            {
                fecha->dia=dia;
                fecha->mes=mes;
                fecha->anio=anio;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }


        }
        while(1);

    }

    return retorno;
}
