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
int espacioLibreArcade(eArcade vec[], int tam);
int buscarArcadeIdSalon(int idSalon, eArcade arc[], int tamArc);
int buscarArcadeId(int id, eArcade arc[], int tamArc);
int validarTipoArcade(int entrada, char salidaTipo[]);

void print_unArcade(eArcade* arc);
int print_arcade(eArcade vec[],int tam);
int print_juegos(eArcade vec[],int tam);
#endif // ARCADE_H_INCLUDED
