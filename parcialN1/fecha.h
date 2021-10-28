#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

#endif // FECHA_H_INCLUDED

int get_fecha(eFecha* fecha, char mensaje[], char mensajeError[]);
/** pide al usuario una fecha donde este devera ingresar dia/mes/anio valida que sea una fecha valida
*   y lo carga dentro de la estructura eFecha. que fue pasada como puntero
*
*   return (-1) si huvo un error - (0) si todo ok
*/

