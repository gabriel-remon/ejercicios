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
/** @brief recorre el vector vec[] y pregunta si hay al menos un dato con vec[].id == idBusqueda
*   @param mas[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param idServicio valor que se usara para buscar
*
*   @return (0) si no se encontro - (int) valor vec.precio donde vec[].id == idBusqueda
*/

int descripccionServicio(eServicio vec[],int tam, int idBusqueda, char descipcion[]);
/** @brief pide un id por parametro y busca ese id dentro de vec[].id si lo encuentra carga lo que este en
*          vec.descripcion dentro del string descripcion
*   @param vec[] vector de tipo eServicio
*   @param tamMas tamaño del vector eServicio
*   @param idBusqueda valor que sera buscado dentro del vector
*   @param descripcion string de estritura
*
*   @return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/

int mostrarServicio( eServicio vec[], int tam );
/** @brief muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*   @param vec[] vector de tipo eServicio
*   @param tamMas tamaño del vector eSericio
*
*   @return (-1) si huvo un error - (0) si todo ok
*/
