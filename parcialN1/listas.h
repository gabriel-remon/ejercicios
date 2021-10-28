#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED



#endif // LISTAS_H_INCLUDED

void mostrarAnimalesColor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
void mostrarAnimalesTipo( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
void mostrarAnimalesServicio( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra);
void mostrarServicioPromedioMayor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer);


void mostrarUnaFilaMascota( eMascota *vec,eColor col[], int tamCol,eTipo tip[], int tamTip);
void prototipoListaMascotas();
void mostrarUnaFilaMascotaTrabajo( eMascota *vec,eTrabajo *tra,eColor col[], int tamCol,eTipo tip[], int tamTip)
void prototipoListaMascotasTrabajo();
int mostrarListas(  eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra);
char menuListas();

