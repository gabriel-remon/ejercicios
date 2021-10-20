#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[30];
}eComidas;


int cargarDescripcioncomida( eComidas comidas[], int tamCom,int idBuscador, char descripcion[] );
int mostrarcomidas(eComidas comidas[], int tamCom);

// 0 si no existe el id o me devuelve 1 si existe el id
int validarComidas(int idBuscador, eComidas comidas[], int tamCom);

#endif // COMIDAS_H_INCLUDED
