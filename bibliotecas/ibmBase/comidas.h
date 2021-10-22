#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[30];
}eComidas;


int cargarDescripcioncomida( eComidas comidas[], int tamCom,int idBuscador, char descripcion[] );
/** pide un id por parametro y busca ese id dentro de vec. si lo encuentra carga lo que este en
*   vec.descripcion dentro del string descripcion
*
*   return (-2) si huvo un error - (-1) no se encontro el id cargado - (0) todo ok
*/

int mostrarcomidas(eComidas comidas[], int tamCom);
/** muestra una tabla con todos los valores en vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int validarComidas(int idBuscador, eComidas comidas[], int tamCom);
/** Pide por parametro un id y lo compara con todos los id dentro del vector
*
*   return (0) si no encuentra el valor o si fallo - (1) si encontro el id en el vector
*/


#endif // COMIDAS_H_INCLUDED
