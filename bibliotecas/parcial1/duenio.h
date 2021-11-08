#ifndef DUENIO_H_INCLUDED
#define DUENIO_H_INCLUDED

typedef struct
{
    int id;
    char nombreDuenio[25];
    int edad;
    char sexo;
    int isEmpty;
} eDuenio;


#endif // DUENIO_H_INCLUDED

int initDuenio(eDuenio vec[], int tam);
/** @brief inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*   @param vec[] vector de tipo eDuenio
*   @param tamMas tamaño del vector eDuenio
*
*   @return (-1) si huvo un error - (0) si todo ok
*/
int descripccionDuenio(eDuenio vec[],int tam, int idBusqueda, char descipcion[]);
/** @brief pide un id por parametro y busca ese id dentro de vec[].id si lo encuentra carga lo que este en
*           vec.nombreDuenio dentro del string descripcion
*   @param vec[] vector de tipo eDuenio
*   @param tamMas tamaño del vector eDuenio
*   @param idBusqueda valor que sera buscado dentro del vector
*   @param descripcion string de estritura
*
*   @return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/
int validarDueniotaId(eDuenio vec[],int tam,int idBusqueda);
/** @brief Pide por parametro un id y lo compara con todos los id dentro del vector.
*          si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*   @param vec[] vector de tipo eDuenio
*   @param tamMas tamaño del vector eDuenio
*   @param idBusqueda valor que sera buscado dentro del vector
*
*   @return ((0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int espacioLibreDuenio(eDuenio vec[], int tam);
/** @brief busca un espacio libre en el vector preguntando si isEmply esta en 1
*          si lo encuentra devueve la posicion de este vector
*   @param vec[] vector de tipo eDuenio
*   @param tamMas tamaño del vector eDuenio
*
*   @return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/

int altaDuenio( eDuenio vec[],int tam);
/** @brief valida que haya lugares libres en el vector eDuenio y si los hay pide al usuario
*          id (valida que no este ocupado), nombre,sexo y edad.
*          luego de cargar los datos pregunta si quiere cargarse otrodato
*   @param vec[] vector de tipo eDuenio
*   @param tamMas tamaño del vector eDuenio
*
*   @return (-1) si hubo error - (0) si todo ok
*/

int mostrarDuenios( eDuenio vec[],int tam);
/** @brief muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*   @param vec[] vector de tipo eDuenio
*   @param tamMas tamaño del vector eDuenio
*
*   @return (-1) si huvo un error - (0) si todo ok
*/
