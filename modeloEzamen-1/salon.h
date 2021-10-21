#ifndef SALON_H_INCLUDED
#define SALON_H_INCLUDED

#define VACIO 1
#define LLENO 0

typedef struct
{
    char nombre[50];
    char direccion[50];
    int tipo;
    int id;
    int isEmpty;
}eSalon;

int initSalon(eSalon vec[], int tam);
int espacioLibreSalon(eSalon vec[], int tam);
int buscarSalon(eSalon vec[],int tam,int id);
int validarTipoSalon(int entrada, char salidaTipo[]);

#endif // SALON_H_INCLUDED

