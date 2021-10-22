#ifndef ARCADE_H_INCLUDED
#define ARCADE_H_INCLUDED
#define VACIO 1
#define LLENO 0


typedef struct
{
    char nacionalidad[50];
    int tipoSonido;
    int cantidadJugadores;
    int capacidadFichas;
    char nombreJuego[63];
    int idArcade;
    int idSalon;
    int isEmpty;
}eArcade;

int initArcade(eArcade vec[], int tam);
/**inicializa un vector con los valores de isEmply en 1 indicando que esta vacio
*
*retorna (-1) si falla y (0) si todo ok
*/

int espacioLibreArcade(eArcade vec[], int tam);
/** busca un espacio libre en el vector preguntando si isEmply esta en 1
*   si lo encuentra devueve la posicion de este vector
*
*   return (-1) si falla o esta lleno - (-2) si esta todo vacio - (int) si hay al menos una posicion libre
*/


int buscarArcadeIdSalon(int idSalon, eArcade arc[], int tamArc);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/

int buscarArcadeId(int id, eArcade arc[], int tamArc);
/** Pide por parametro un id y lo compara con todos los id dentro del vector.
*   si encuentra el valor devuelve la posicion del vector donde se encuentra ese id
*
*   return (0) si no encuentra el valor o si fallo - (int) si encontro el id en el vector
*/
int validarTipoArcade(int entrada, char salidaTipo[]);
/** lee el valor entrada y guarda un string en descripcion dependiendo lo que valor sea
*   pasado como parametro
*
*   retorna (0) si huvo una falla - (1) si todo ok
*/

void print_unArcade(eArcade* arc);
/** muestra en forma de filas los valores en dentro de la estructura vec
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int print_arcade(eArcade vec[],int tam);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/

int print_juegos(eArcade vec[],int tam);
/** muestra una tabla con todos los valores en vec que esten con el espacio vec.isempty en 1
*
*   return (-1) si huvo un error - (0) si todo ok
*/
#endif // ARCADE_H_INCLUDED
