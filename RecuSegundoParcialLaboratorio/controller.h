#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief Carga archivo de texto de posteos
 *
 * \param char* path Recibe nombre de archivo para pasarle a fopen
 * \param LinkedList* pArrayListPosteos Recibe un puntero a linkedlist de posteos para cargarle los datos del archivo
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int controller_cargarPosteos(char* path, LinkedList* pArrayListPosteos);

/** \brief Despliega una lista de los posteos existentes
 *
 * \param LinkedList* pArrayListPosteos Recibe un puntero a linkedlist de posteos que se mostrara en pantalla
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int controller_listarPosteos(LinkedList* pArrayListPosteos);

/** \brief Asigna estadisticas aleatorias a los posteos
 *
 * \param LinkedList* this Recibe un puntero a linkedlist para asignarle estadisticas aleatorias a traves de la funcion map
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int controller_asignarEstadisticas(LinkedList* this);


/** \brief Genera las estadisticas random para pasarselas a la funcion de asignar estadisticas
 *
 * \param void* pElement Recibe puntero a void del elemento de la linkedlist
 * \return void* retorna el puntero a void* (parseado a ePost*) del elemento
 *
 */
void* generarEstadisticasPost(void* pElement);


/** \brief Guarda los posteos con mas de 4000 likes en un archivo de texto y muestra cuales guardo
 *
 * \param char* path Recibe el nombre del archivo de texto a crear
 * \param LinkedList* pArrayListPost Recibe un puntero a linkedlist de la lista de posteos
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int controller_guardarMejoresPosteos(char* path, LinkedList* pArrayListPost);

/** \brief Guarda los posteos que tengan mas dislikes que likes en un archivo de texto y muestra cuales guardo
 *
 * \param char* path Recibe el nombre del archivo de texto a crear
 * \param LinkedList* pArrayListPost Recibe un puntero a linkedlist de la lista de posteos
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int controller_guardarHaters(char* path, LinkedList* pArrayListPost);


/** \brief Muestra en pantalla la lista de posteos filtrada por numero followers descendente
 *
 * \param LinkedList* this Recibe un puntero a linkedlist de la lista de posteos
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */

int controller_mostrarCantidadFollowers(LinkedList* this);

/** \brief Muestra en pantalla quien es el usuario con mas likes y cuantos likes tiene
 *
 * \param LinkedList* this Recibe un puntero a linkedlist de la lista de posteos
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */

int controller_informarMasPopular(LinkedList* this);

