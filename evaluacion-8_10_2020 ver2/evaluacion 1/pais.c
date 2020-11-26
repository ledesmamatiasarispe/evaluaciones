#include "pais.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "razas.h"
#include "display.h"




int pais_list_cantidadDePais(pais* list,int len)
{
    int retorno = 0;
    if(list != NULL && len > 0)
    {
        int  isEmpty ;
        for(int i = 0; i<len;i ++)
        {
            if(pais_getisEmpty(list+i,&isEmpty)==0)
            {
                if(isEmpty == 0)
                {
                    retorno ++;
                }
            }
        }
    }
    return retorno;
}


int pais_setId(pais* this,int id)
{
    int retorno = -1;

    if(this!=NULL && id >= 0)
    {

        retorno = 0;
        this->id = id;
    }
    return retorno;
}
int pais_getId(pais* this,int* id)
{
    int retorno = -1;
    if(this!=NULL && id != NULL)
    {
        retorno = 0;
       *id = this->id  ;
    }
    return retorno;
}


int pais_setisEmpty(pais* this,int isEmpty)
{
    int retorno = -1;

    if(this!=NULL && (isEmpty == 0 || isEmpty == 1) )
    {

        retorno = 0;
        this->isEmpty = isEmpty;
    }
    return retorno;
}
int pais_getisEmpty(pais* this,int* isEmpty)
{
    int retorno = -1;
    if(this!=NULL && isEmpty != NULL)
    {
        retorno = 0;
       *isEmpty = this->isEmpty  ;
    }
    return retorno;
}



int pais_setCodigoTelefonico(pais* this,int codigoTelefonico)
{
    int retorno = -1;

    if(this!=NULL && codigoTelefonico >= 0)
    {

        retorno = 0;
        this->codigoTelefonico = codigoTelefonico;
    }
    return retorno;
}
int pais_getcodigoTelefonico(pais* this,int* codigoTelefonico)
{
    int retorno = -1;
    if(this!=NULL && codigoTelefonico != NULL)
    {
        retorno = 0;
       *codigoTelefonico = this->codigoTelefonico  ;
    }
    return retorno;
}



int pais_setNombre(pais* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        utn_nombreAformatoCorrecto(nombre);
        retorno = 0;
        strncpy(this->nombre,nombre,40);
    }
    return retorno;
}
int pais_getNombre(pais* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        retorno = 0;
        strncpy(nombre,this->nombre,128);
    }
    return retorno;
}



int pais_setContinente(pais* this,char* continente)
{
    int retorno = -1;
    if(this!=NULL && continente != NULL)
    {
        utn_nombreAformatoCorrecto(continente);
        retorno = 0;
        strncpy(this->continente,continente,40);
    }
    return retorno;
}
int pais_getContinente(pais* this,char* continente)
{
    int retorno = -1;
    if(this!=NULL && continente != NULL)
    {
        retorno = 0;
        strncpy(continente,this->continente,128);
    }
    return retorno;
}




int pais_setNewId(pais* this,int id)
{

    int retorno = -1 ;
    static int maxId = 0;
    if(this!=NULL)
    {
        retorno = 1;
        if(id<=maxId)
        {
                maxId++;
                pais_setId(this,maxId);
                retorno = 0;

        }else{
                maxId = id;
                pais_setId(this,maxId);
                retorno = 0;
         }
    }else
     {
        if(id == -1)
        {
            maxId = 0;
        }
     }
return retorno;
}









int pais_cargarParametros(pais* this,char nombre[],char id[],char Continente[],char codigoTelefonico[])
{
  int retorno = -1;
    if(this != NULL && nombre != NULL && id != NULL && Continente != NULL && codigoTelefonico > 0)
    {

        if
        (
            pais_setNewId(this ,atoi(id)) == 0 &&

            pais_setisEmpty(this ,0)== 0 &&

            pais_setNombre(this ,nombre)== 0 &&
            pais_setContinente(this ,Continente)== 0 &&
            pais_setCodigoTelefonico(this ,atoi(codigoTelefonico))== 0
        )
        {

           retorno = 0;
        }
    }
return retorno;
}




/***********************/


int pais_list_inicializarIsEmpty(pais* list,int len)
{
  int retorno = -1;
    if(list != NULL && len > 0 )
    {
        int i ;
        for(i = 0 ;i<len;i++)
        {
            pais_setisEmpty((list + i),1);
        }
    }
return retorno;
}

int pais_list_cargarLista(char patch[],pais* list,int len)
{
    int retorno = -1;
    if(patch != NULL && list != NULL && len > 0)
    {

        FILE* pfile;
        pfile = fopen(patch,"r");
        if(pfile != NULL)
        {

            parser_paisFromText(pfile,len,list);

        }
        fclose(pfile);
    }
    return retorno;
}



int pais_list_imprimirLista(pais* list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len;i ++)
        {
            if(i == 0)
            display_imprimirCabeceraPais();

            pais_imprimirPais(list+i);
            retorno = 0;
        }
    }
    return retorno;
}

int pais_imprimirPais(pais* this)
{
    int retorno = -1 ;
    if(this != NULL)
    {

        retorno = 1;
        int auxId,auxIsEmpty,auxCodigoTelefonico;
    char auxContinente[128],auxNombre[128];

        pais_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {
            if
            (
                pais_getId(this,&auxId) == 0 &&

                pais_getNombre(this,auxNombre)== 0 &&
                pais_getContinente(this,auxContinente)== 0 &&
                pais_getcodigoTelefonico(this,&auxCodigoTelefonico)== 0

            )
            {
                retorno =0;
                printf("\n%10d, %10s , %10s , %10d  ",auxId,auxNombre,auxContinente,auxCodigoTelefonico);
            }
    }

       }
return retorno;
}


/************************funciones de comparacion*////////////////
