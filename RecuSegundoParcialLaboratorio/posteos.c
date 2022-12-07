#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posteos.h"


int getId(ePost* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;

        todoOk = 1;
    }

    return todoOk;
}

int setId(ePost* this, int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;


        todoOk = 1;
    }

    return todoOk;
}

int getUser(ePost* this, char* user)
{
    int todoOk = 0;
    if(this != NULL && user != NULL)
    {
        strcpy(user, this->user);
        todoOk = 1;
    }

    return todoOk;
}

int setUser(ePost* this, char* user)
{
    int todoOk = 0;
    if(this != NULL && strlen(user) > 0 && strlen(user) < 30)
    {
        strcpy(this->user, user);
        todoOk = 1;
    }

    return todoOk;
}

int getLikes(ePost* this, int* likes)
{
    int todoOk = 0;
    if(this != NULL && likes != NULL)
    {
        *likes = this->likes;

        todoOk = 1;
    }

    return todoOk;
}

int setLikes(ePost* this, int likes)
{
    int todoOk = 0;
    if(this != NULL && likes >= 0)
    {
        this->likes = likes;


        todoOk = 1;
    }

    return todoOk;
}

int getDislikes(ePost* this, int* dislikes)
{
    int todoOk = 0;
    if(this != NULL && dislikes != NULL)
    {
        *dislikes = this->dislikes;

        todoOk = 1;
    }

    return todoOk;
}

int setDislikes(ePost* this, int dislikes)
{
    int todoOk = 0;
    if(this != NULL && dislikes >= 0)
    {
        this->dislikes = dislikes;


        todoOk = 1;
    }

    return todoOk;
}

int getFollowers(ePost* this, int* followers)
{
    int todoOk = 0;
    if(this != NULL && followers != NULL)
    {
        *followers = this->followers;

        todoOk = 1;
    }

    return todoOk;
}

int setFollowers(ePost* this, int followers)
{
    int todoOk = 0;
    if(this != NULL && followers >= 0)
    {
        this->followers = followers;


        todoOk = 1;
    }

    return todoOk;
}

ePost* newPostParam(char* idStr,char* userStr,char* likesStr, char* dislikesStr, char* followersStr)
{
	ePost* nuevoPost = post_new();

	    if(nuevoPost!= NULL)
	    {

		if(         !(
					setId(nuevoPost, atoi(idStr)) &&
					setUser(nuevoPost, userStr) &&
					setLikes(nuevoPost, atoi(likesStr)) &&
                    setDislikes(nuevoPost, atoi(dislikesStr)) &&
                    setFollowers(nuevoPost, atoi(followersStr)))
            )
	        {

	             free(nuevoPost);
	            nuevoPost = NULL;
	        }


	    }

	  return nuevoPost;
}

ePost* post_new()
{
    ePost* nuevoPost = (ePost*) malloc(sizeof(ePost));
    if(nuevoPost != NULL)
    {
    	nuevoPost->id = 0;
        strcpy(nuevoPost->user, "");
        nuevoPost->likes = 0;
        nuevoPost->dislikes = 0;
        nuevoPost->followers = 0;

    }

    return nuevoPost;
}

int filtrarMejoresPosteos(void* pElement)
{
    int ret = 0;
    if(((ePost*) pElement)->likes > 4000)
    {
        ret = 1;
    }

    return ret;
}

int filtrarHaters(void* pElement)
{
    int ret = 0;
    if(((ePost*) pElement)->dislikes > ((ePost*) pElement)->likes)
    {
        ret = 1;
    }

    return ret;
}

int ordenarPorFollowers(void* llPostA,void* llPostB)
{
	ePost* pPostA = (ePost*) llPostA;
	ePost* pPostB = (ePost*) llPostB;

	int followersA;
	int followersB;


	getFollowers(pPostA, &followersA);
	getFollowers(pPostB, &followersB);

	if(followersA > followersB)
	{
	return 1;
	}
	if(followersA < followersB)
	{
	return -1;
	}

	return 0;
}
