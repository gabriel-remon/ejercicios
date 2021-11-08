#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

#endif // COLOR_H_INCLUDED

int validarTipo(eTipo vec[],int tam,int idBusqueda);
/** @brief recorre el vector vec[] y pregunta si hay al menos un dato con vec[].id == idBusqueda
*   @param mas[] vector de tipo eTipo
*   @param tamVec tamaño del vector eTipo
*   @param idServicio valor que se usara para buscar
*
*   @return (0) si no se encontro - (1) si encontro vec[].id == idBusqueda
*/
int descripcionTipo(eTipo vec[],int tam, int idBusqueda, char descipcion[]);
/** @brief pide un id por parametro y busca ese id dentro de vec[].id si lo encuentra carga lo que este en
*          vec.descripcion dentro del string descripcion
*   @param vec[] vector de tipo eTipo
*   @param tamMas tamaño del vector eTipo
*   @param idBusqueda valor que sera buscado dentro del vector
*   @param descripcion string de estritura
*
*   @return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/

int mostrarTipo( eTipo vec[], int tam );
/** @brief muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*   @param vec[] vector de tipo eTipo
*   @param tamMas tamaño del vector eTipo
*
*   @return (-1) si huvo un error - (0) si todo ok
*/
