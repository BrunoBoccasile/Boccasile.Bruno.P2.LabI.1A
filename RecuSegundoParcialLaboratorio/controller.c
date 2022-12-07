#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "posteos.h"
#include "controller.h"

int controller_cargarPosteos(char* path, LinkedList* pArrayListPosteos)
{
    int todoOk = 0;
    FILE* f;
    char id[50];
    char user[50];
    char likes[50];
    char dislikes[50];
    char followers[50];


    int cant;

    if(path != NULL && pArrayListPosteos != NULL)
    {
        f = fopen(path, "r");

        if(f != NULL)
        {

            ePost* auxPost = NULL;


            fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                   id,user,likes,dislikes,followers); //lectura fantasma


            do
            {
                cant = fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                        id,user,likes,dislikes,followers);


                if(cant == 5)
                {
                    auxPost = newPostParam(id, user, likes, dislikes, followers);
                    ll_add(pArrayListPosteos, auxPost);
                }



            }
            while(!feof(f));



            fclose(f);
            todoOk = 1;
        }

    }


    return todoOk;
}

int controller_listarPosteos(LinkedList* pArrayListPosteos)
{
    int todoOk = 0;

    int id;
    char user[30];
    int likes;
    int dislikes;
    int followers;

    ePost* pPost;


    if(pArrayListPosteos != NULL)
    {

        printf("|ID   | USER                          | LIKES          | DISLIKES       | FOLLOWERS      |\n");


        for(int i=0 ; i<ll_len(pArrayListPosteos) ; i++)
        {

            pPost = (ePost*) ll_get(pArrayListPosteos, i);

            getId(pPost, &id);
            getUser(pPost, user);
            getLikes(pPost, &likes);
            getDislikes(pPost, &dislikes);
            getFollowers(pPost, &followers);

            printf("|%-3d  |%-30s | %-10d     | %-10d     | %-10d     |\n",
                   id, user, likes, dislikes, followers
                  );
        }





        todoOk = 1;
    }

    return todoOk;
}

int controller_asignarEstadisticas(LinkedList* this)
{
    int todoOk = 0;
    srand(time(NULL));

    if(this != NULL)
    {
        ll_map(this, generarEstadisticasPost);
        todoOk = 1;
    }

    return todoOk;
}

void* generarEstadisticasPost(void* pElement)
{


    int likes = (rand() % (5000 - 600 + 1)) + 600;
    int dislikes = (rand() % (3500 - 300 + 1)) + 300;
    int followers = (rand() % (20000 - 10000 + 1)) + 10000;

    ((ePost*) pElement)->likes = likes;
    ((ePost*) pElement)->dislikes = dislikes;
    ((ePost*) pElement)->followers = followers;

    return ((ePost*) pElement);
}

int controller_guardarMejoresPosteos(char* path, LinkedList* pArrayListPost)
{
    int todoOk = 0;
    FILE* f;
    ePost* pPost;
    LinkedList* listaFiltrada;
    int idObtenido;
    char userObtenido[30];
    int likesObtenidos;
    int dislikesObtenidos;
    int followersObtenidos;

    int generoIngresado;

    if(path != NULL && pArrayListPost != NULL)
    {

        f = fopen(path, "w");

        if(f != NULL)
        {
            fprintf(f,"id,user,likes,dislikes,followers\n");


            listaFiltrada = ll_filter(pArrayListPost, filtrarMejoresPosteos);


            controller_listarPosteos(listaFiltrada);

            for(int i=0 ; i<ll_len(listaFiltrada); i++)
            {
                pPost = (ePost*) ll_get(listaFiltrada, i);



                getId(pPost, &idObtenido);
                getUser(pPost, userObtenido);
                getLikes(pPost, &likesObtenidos);
                getDislikes(pPost, &dislikesObtenidos);
                getFollowers(pPost, &followersObtenidos);

                    fprintf(f, "%d,%s,%d,%d,%d\n",
                            idObtenido, userObtenido, likesObtenidos, dislikesObtenidos, followersObtenidos
                           );

            }
            fclose(f);
        }

        todoOk = 1;
    }

    return todoOk;
}

int controller_guardarHaters(char* path, LinkedList* pArrayListPost)
{
    int todoOk = 0;
    FILE* f;
    ePost* pPost;
    LinkedList* listaFiltrada;
    int idObtenido;
    char userObtenido[30];
    int likesObtenidos;
    int dislikesObtenidos;
    int followersObtenidos;

    int generoIngresado;

    if(path != NULL && pArrayListPost != NULL)
    {

        f = fopen(path, "w");

        if(f != NULL)
        {
            fprintf(f,"id,user,likes,dislikes,followers\n");


            listaFiltrada = ll_filter(pArrayListPost, filtrarHaters);


            controller_listarPosteos(listaFiltrada);

            for(int i=0 ; i<ll_len(listaFiltrada); i++)
            {
                pPost = (ePost*) ll_get(listaFiltrada, i);



                getId(pPost, &idObtenido);
                getUser(pPost, userObtenido);
                getLikes(pPost, &likesObtenidos);
                getDislikes(pPost, &dislikesObtenidos);
                getFollowers(pPost, &followersObtenidos);

                    fprintf(f, "%d,%s,%d,%d,%d\n",
                            idObtenido, userObtenido, likesObtenidos, dislikesObtenidos, followersObtenidos
                           );

            }
            fclose(f);
        }

        todoOk = 1;
    }

    return todoOk;
}

int controller_mostrarCantidadFollowers(LinkedList* this)
{
    int todoOk = 0;

    if(this != NULL)
    {
        ll_sort(this, ordenarPorFollowers, 0);

        controller_listarPosteos(this);



        todoOk = 1;
    }

    return todoOk;
}

int controller_informarMasPopular(LinkedList* this)
{
    int todoOk = 0;
    int masLikes;
    int indiceMasLikeado;
    ePost* pPost;


    if(this != NULL)
    {

        for(int i= 0; i < ll_len(this) ; i++)
        {

            pPost = ll_get(this, i);

            if(i > 0)
            {
                if(pPost->likes > masLikes)
                {

                    masLikes = pPost->likes;
                    indiceMasLikeado = i;
                }
            }
            else
            {

                masLikes = pPost->likes;
            }

        }

        pPost = ll_get(this, indiceMasLikeado);

        printf("El user con el posteo mas likeado es: %s \nEl numero de likes es: %d \n", pPost->user, pPost->likes);



        todoOk = 1;
    }

    return todoOk;
}
