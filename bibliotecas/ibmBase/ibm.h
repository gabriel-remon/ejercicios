#ifndef IBM_H_INCLUDED
#define IBM_H_INCLUDED


//operaciones
int altaPersona(ePersona vec[], int tam, int* id, eLocalidad loc[],int tamLoc);
int bajaPersona(ePersona vec[],int tam, eLocalidad loc[], int tamLoc);
int modificacionPersona(ePersona vec[],int tam, eLocalidad loc[], int tamLoc);
void ordenarPersonasCriterio(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
int altaAlmuerzo(ePersona vec[],int tam, eComidas com[],int tamCom, eLocalidad loc[],int tamLoc);



//print
void mostrarUnaPersonaLocalidad(ePersona* vec,eLocalidad loc[], int tamLoc);
void mostrarListaMujeres(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
void mostrarPersonasPorLocalidades(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
void print_nombreVaronMayor(ePersona vec[],int tam);
void cantidadPersonasPorLocalidad(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
void print_localidadMenosHabitada(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
void print_localidadMenorPromedioEdad(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
int print_localidadPromedioAltura(ePersona vec[],int tam, eLocalidad loc[],int tamLoc);
void print_almuerzos(ePersona vec[],int tam,eLocalidad loc[],int tamLoc,eComidas com[],int tamCom);

int menu();
int modificacion();
int criterio();
int print_personasUnaLocalidad(ePersona vec[],int tam,eLocalidad loc[], int tamLoc);


#endif // IBM_H_INCLUDED
