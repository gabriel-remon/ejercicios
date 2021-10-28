#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

int validarServicio(eServicio vec[],int tam,int idBusqueda);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encontro el id devuelca el valor en vec.precio de la posicion de ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/
//devuelte 0 falso, si es valido el valor en vec[].precio
int descripccionServicio(eServicio vec[],int tam, int idBusqueda, char descipcion[]);
/** pide un id por parametro y busca ese id dentro de vec. si lo encuentra carga lo que este en
*   vec.descripcion dentro del string descripcion
*
*   return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/

int mostrarServicio( eServicio vec[], int tam );
/** muestra una tabla con todos los valores en vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/
