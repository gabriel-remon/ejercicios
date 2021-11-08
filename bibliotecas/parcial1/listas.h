#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED



#endif // LISTAS_H_INCLUDED

void mostrarServicioPromedioMayor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer);

void prototipoTrabajo();
/** @brief texto que aparece antes de mostrar la lista de trabajos
*/
void mostrarUnTrabajo(eTrabajo *tra, eServicio ser[],int tamSer);
/** @brief muestra los datos dentro del puntero *tra en forma de fila
*   @param *tra puntero de tipo eTrabajo
*   @param ser[] vector de tipo eServicio
*   @param tamSer tamaño del vector ser[]
*/
void prototipoMascotas();
/** @brief texto que aparece antes de mostrar la lista de mascotas
*/
void mostrarUnaFilaMascota( eMascota *vec,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief muestra los datos dentro del puntero *vec en forma de fila
*   @param *vec puntero de tipo eMascota
*   @param col[] vector de tipo eColor
*   @param tamSer tamaño del vector col[]
*   @param tip[] vector de tipo eTipo
*   @param tamSer tamaño del vector tip[]
*/
void prototipoListaMascotasTrabajo();
/** @brief texto que aparece antes de mostrar la lista de mascotas con la lista de trabajos
*/
void mostrarUnaFilaMascotaTrabajo( eMascota *vec,eTrabajo *tra,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief muestra los datos dentro del puntero *vec y del puntero *tra sin contar los servicios, en forma de fila
*   @param *vec puntero de tipo eMascota
*   @param *tra puntero de tipo eTrabajo
*   @param col[] vector de tipo eColor
*   @param tamSer tamaño del vector col[]
*   @param tip[] vector de tipo eTipo
*   @param tamSer tamaño del vector tip[]
*/

char menuListas();
/** @brief imprime un menu y devuelve la eleccion del usuario
*   @return caracter tipo char
*/
int mostrarListas(  eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra);
/** @brief menu principal del area de listas donde se selecciona que funcion se usara
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*   @param vec[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param tra[] vector de tipo eTrabajo
*   @param tamTra tamaño del vector eTrabajo
*/


void mostrarAnimalesTipo( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief Muestra la lista de animales separandola por cada color de animal
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*/
void mostrarAnimalesServicio( eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip, eServicio ser[], int tamSer,eTrabajo tra[],int tamTra);
/** @brief Muestra la lista de animales separandola por cada servicio realizado a los animal
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*   @param vec[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param tra[] vector de tipo eTrabajo
*   @param tamTra tamaño del vector eTrabajo
*/
void mostrarAnimalesColor(eMascota vec[],int tam,eColor col[], int tamCol,eTipo tip[], int tamTip);
/** @brief Muestra la lista de animales separandola por cada tipo de
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*/

int informarAnimalMayor(eMascota mas[],int tamMas, eColor col[],int tamCol,eTipo tip[],int tamTip);
/** @brief comprara los valores eMascota.edad y muestra la informaion de la o las mascota con mayor edad
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int mostrarColorMasUsual(eMascota mas[],int tamMas, eColor col[],int tamCol,eTipo tip[],int tamTip);
/** @brief comprara los valores eMascota.idColor y informa el o los colores mas elegidos
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int mostrarMascotaColorSelec(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip);
/** @brief pide al usuario elegir un id del vector col[] y si es valido muestra las mascotas (mas[])
*          que tengan ese mismo id (idColor)
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int mostrarMascotaTipoSelec(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip);
/** @brief pide al usuario elegir un id del vector tip[] y si es valido muestra las mascotas (mas[])
*          que tengan ese mismo id (idTipo)
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int contarColorTipo(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip);
/** @brief pide al usuario elegir un id del vector col[] y si es valido, pide que seleccione un id
*          del vector tip[] y cuenta las cantidad de mascotas(mas[]) que coincidan con esos dos
*          id (idTipo && idColor)
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int contarMarcotasServicio(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer);
/** @brief pide al usuario elegir un id de una mascota(mas[].id) y muestra cuantos servicios se le realizaron y cuanto se gasto
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*   @param vec[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param tra[] vector de tipo eTrabajo
*   @param tamTra tamaño del vector eTrabajo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int mostrarServiciosDeMascota(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer);
/** @brief pide al usuario elegir un id de una mascota(mas[].id) y muestra los datos de esa mascota y
*          una lista de todos los trabajos que se le realizaron
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*   @param vec[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param tra[] vector de tipo eTrabajo
*   @param tamTra tamaño del vector eTrabajo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/

int mostrarMascotasDeUnServicio(eMascota mas[],int tamMas,eColor col[],int tamCol,eTipo tip[],int tamTip,eTrabajo tra[],int tamTra,eServicio ser[],int tamSer);
/** @brief pide al usuario elegir un id del vector tip[] y muestra una lista de las mascotas
*          que se realizaron ese servicio
*   @param mas[] vector de tipo eMascota
*   @param tamMas tamaño del vector eMascota
*   @param col[] vector de tipo eColor
*   @param tamCol tamaño del vector eColor
*   @param tip[] vector de tipo eTipo
*   @param tamTip tamaño del vector Etipo
*   @param vec[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param tra[] vector de tipo eTrabajo
*   @param tamTra tamaño del vector eTrabajo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/
int mostrarFechaServicios(eTrabajo tra[],int tamTra,eServicio ser[],int tamSer);
/** @brief pide al usuario que ingrese una fecha y muestra una lista de todos los servicios realizados en esa fecha cargada
*   @param vec[] vector de tipo eServicio
*   @param tamVec tamaño del vector eServicio
*   @param tra[] vector de tipo eTrabajo
*   @param tamTra tamaño del vector eTrabajo
*
*   @return (-1) si huvo un error - (0) si todo ok - (1) si no se encontraron valores en mas[]
*/


int hayColores(eMascota mas[],int tamMas,int idColor);
/** @brief recorre el vector mas[] y pregunta si hay al menos un dato con mas[].idColor == idColor
*   @param mas[] vector de tipo eMascotas
*   @param tamVec tamaño del vector eMascotas
*   @param idColor valor que se usara para buscar
*
*   @return (0) si no se encontro - (1) si se encontro
*/
int hayTipos(eMascota mas[],int tamMas,int idTipo);
/** @brief recorre el vector mas[] y pregunta si hay al menos un dato con mas[].idTipo == idTipo
*   @param mas[] vector de tipo eMascotas
*   @param tamVec tamaño del vector eMascotas
*   @param idTipo valor que se usara para buscar
*
*   @return (0) si no se encontro - (1) si se encontro
*/
int hayServicios(eTrabajo tra[],int tamTra,int idServicio);
/** @brief recorre el vector tra[] y pregunta si hay al menos un dato con tra[].idServicio == idServicio
*   @param mas[] vector de tipo eTrabajo
*   @param tamVec tamaño del vector eTrabajo
*   @param idServicio valor que se usara para buscar
*
*   @return (0) si no se encontro - (1) si se encontro
*/
int haytrabajo(eTrabajo tra[],int tamTra,int idMascota);
/** @brief recorre el vector tra[] y pregunta si hay al menos un dato con tra[].idMascota == idMascota
*   @param mas[] vector de tipo eTrabajo
*   @param tamVec tamaño del vector eTrabajo
*   @param idMascota valor que se usara para buscar
*
*   @return (0) si no se encontro - (int) posicion del vector trabajo donde esta ese id si se encontro
*/
int hayFecha(eTrabajo tra[],int tamTra, eFecha fechaIngreso);
/** @brief recorre el vector tra[] y pregunta si hay al menos un dato con tra[].fecha == fechaIngreso
*   @param mas[] vector de tipo eTrabajo
*   @param tamVec tamaño del vector eTrabajo
*   @param fechaIngreso valor que se usara para buscar
*
*   @return (0) si no se encontro - (1) si se encontro
*/
