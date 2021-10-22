#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED

int cargarDescripcionLocalidad( eLocalidad localidades[], int tam, int idLocalidad, char descripcion[] );
/** pide un id por parametro y busca ese id dentro de vec. si lo encuentra carga lo que este en
*   vec.descripcion dentro del string descripcion
*
*   return (-2) si huvo un error - (-1) no se encontro el id cargado - (0) todo ok
*/
int mostrarLocalidades( eLocalidad localidades[], int tam );
/** muestra una tabla con todos los valores en vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int validarIdLocalidad( int id, eLocalidad localidades[], int tam );
/** Pide por parametro un id y lo compara con todos los id dentro del vector
*
*   return (0) si no encuentra el valor o si fallo - (1) si encontro el id en el vector
*/
