#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombreMascota[25];
    int edad;
    char raza[25];
    int isEmpty;
}eMascota;

#endif // MASCOTA_H_INCLUDED

int initMascotas(eMascota vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/

int descripccionMascota(eMascota vec[],int tam, int idBusqueda, char descipcion[]);
/** pide un id por parametro y busca ese id dentro de vec. si lo encuentra carga lo que este en
*   vec.descripcion dentro del string descripcion
*
*   return (-1) si huvo un error - (-2) no se encontro el id cargado - (0) todo ok
*/

int validarMarcotaId(eMascota vec[],int tam,int idBusqueda);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int mostrarUnaMacota( eMascota* vec);
/** muestra en forma de filas los valores en dentro de la estructura vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/
