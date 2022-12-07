#ifndef POSTEOS_H_INCLUDED
#define POSTEOS_H_INCLUDED

typedef struct
{
    int id;
    char user[30];
    int likes;
    int dislikes;
    int followers;

}ePost;

#endif // POSTEOS_H_INCLUDED

/** \brief Obtiene el id de un post
 *
 * \param ePost* this Recibe un puntero a ePost para extraer su id
 * \param int* id Recibe la variable para asignarle el valor del id del post
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */

int getId(ePost* this, int* id);

/** \brief Establece el id de un post
 *
 * \param ePost* this  Recibe un puntero a estructura ePost para establecer su id
 * \param int id Recibe el id para asignarselo al campo correspondiente de la estructura ePost
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int setId(ePost* this, int id);

/** \brief Obtiene el user de un post
 *
 * \param ePost* this Recibe un puntero a ePost para extraer su user
 * \param char* user Recibe la variable para asignarle el valor del user del post
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int getUser(ePost* this, char* user);

/** \brief Establece el user de un post
 *
 * \param ePost* this  Recibe un puntero a estructura ePost para establecer su user
 * \param char* user Recibe el user para asignarselo al campo correspondiente de la estructura ePost
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int setUser(ePost* this, char* user);

/** \brief Obtiene los likes de un post
 *
 * \param ePost* this Recibe un puntero a ePost para extraer sus likes
 * \param int* likes Recibe la variable para asignarle el valor de los likes del post
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int getLikes(ePost* this, int* likes);

/** \brief Establece los likes de un post
 *
 * \param ePost* this  Recibe un puntero a estructura ePost para establecer sus likes
 * \param int likes Recibe los likes para asignarselos al campo correspondiente de la estructura ePost
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int setLikes(ePost* this, int likes);

/** \brief Obtiene los dislikes de un post
 *
 * \param ePost* this Recibe un puntero a ePost para extraer sus dislikes
 * \param int* dislikes Recibe la variable para asignarle el valor de los dislikes del post
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int getDislikes(ePost* this, int* dislikes);

/** \brief Establece los dislikes de un post
 *
 * \param ePost* this  Recibe un puntero a estructura ePost para establecer sus dislikes
 * \param int dislikes Recibe los dislikes para asignarselos al campo correspondiente de la estructura ePost
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int setDislikes(ePost* this, int dislikes);

/** \brief Obtiene los followers de un post
 *
 * \param ePost* this Recibe un puntero a ePost para extraer sus followers
 * \param int* followers Recibe la variable para asignarle el valor de los followers del post
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int getFollowers(ePost* this, int* followers);

/** \brief Establece los followers de un post
 *
 * \param ePost* this  Recibe un puntero a estructura ePost para establecer sus followers
 * \param int followers Recibe los followers para asignarselos al campo correspondiente de la estructura ePost
 * \return int Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int setFollowers(ePost* this, int followers);

/** \brief Crea un nuevo post segun los parametros recibidos
 *
 * \param char* idStr Recibe un puntero a char del id del post
 * \param char* userStr Recibe un puntero a char del user del post
 * \param char* likesStr Recibe un puntero a char de la cantidad de likes del post
 * \param char* dislikesStr Recibe un puntero a char de la cantidad de dislikes del post
 * \param char* followersStr Recibe un puntero a char de la cantidad de followers del post
 * \return ePost* Retorna el puntero del nuevo post
 *
 */
ePost* newPostParam(char* idStr,char* userStr,char* likesStr, char* dislikesStr, char* followersStr);

/** \brief Reserva direccion de memoria para una nueva estructura ePost
 *
 * \return ePost* retorna el puntero del nuevo post
 *
 */
ePost* post_new();

/** \brief Filtra los posteos con cantidad mayor a 4000
 *
 * \param void* pElement Recibe un puntero a void del elemento de una estructura ePost para corroborar si tiene mas de 4000 likes
 * \return int Retorna 1 si el post tiene mas de 4000 likes, 0 en caso contrario
 *
 */

int filtrarMejoresPosteos(void* pElement);

/** \brief Filtra los posteos con mas dislikes que likes
 *
 * \param void* pElement Recibe un puntero a void del elemento de una estructura ePost para corroborar si tiene mas dislikes que likes
 * \return int Retorna 1 si el post tiene mas dislikes que likes, 0 en caso contrario
 *
 */
int filtrarHaters(void* pElement);

/** \brief Ordena los posts por cantidad de followers
 *
 * \param void* llPostA Recibe puntero a void de un post A a comparar
 * \param void* llPostB Recibe puntero a void de un post B a comparar
 * \return int Retorna 1 si el post A tiene mas followers que el post B, -1 si es al reves, 0 si tienen la misma cantidad
 *
 */
int ordenarPorFollowers(void* llPostA,void* llPostB);
