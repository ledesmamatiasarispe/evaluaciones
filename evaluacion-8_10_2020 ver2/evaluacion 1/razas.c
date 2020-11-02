#include "razas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>





int razas_cargarParametros(raza* this,char descripcion[],char id[],char tamanio[],char paisDeOrigen[])
{
  int retorno = -1;
    if(this != NULL && descripcion != NULL && id != NULL && tamanio != NULL && paisDeOrigen > 0)
    {
        if
        (
            raza_setNewId(this ,atoi(id)) == 0 &&

            raza_setisEmpty(this ,0)== 0 &&

            raza_setDescripcion(this ,descripcion)== 0 &&
            raza_setTamanio(this ,tamanio)== 0 &&
            raza_setPaisDeOrigen(this ,paisDeOrigen)== 0
        )
        {

           retorno = 0;
        }
    }
return retorno;
}


int raza_setId(raza* this,int id)
{
    int retorno = -1;

    if(this!=NULL && id >= 0)
    {

        retorno = 0;
        this->id = id;
    }
    return retorno;
}
int raza_getId(raza* this,int* id)
{
    int retorno = -1;
    if(this!=NULL && id != NULL)
    {
        retorno = 0;
       *id = this->id  ;
    }
    return retorno;
}



int raza_setisEmpty(raza* this,int isEmpty)
{
    int retorno = -1;

    if(this!=NULL && (isEmpty == 0 || isEmpty == 1) )
    {

        retorno = 0;
        this->isEmpty = isEmpty;
    }
    return retorno;
}
int raza_getisEmpty(raza* this,int* isEmpty)
{
    int retorno = -1;
    if(this!=NULL && isEmpty != NULL)
    {
        retorno = 0;
       *isEmpty = this->isEmpty  ;
    }
    return retorno;
}

int raza_setDescripcion(raza* this,char* descripcion)
{
    int retorno = -1;
    if(this!=NULL && descripcion != NULL)
    {
        retorno = 0;
        strncpy(this->descripcion,descripcion,40);
    }
    return retorno;
}
int raza_getDescripcion(raza* this,char* descripcion)
{
    int retorno = -1;
    if(this!=NULL && descripcion != NULL)
    {
        retorno = 0;
        strncpy(descripcion,this->descripcion,128);
    }
    return retorno;
}

int raza_setTamanio(raza* this,char* tamanio)
{
    int retorno = -1;
    if(this!=NULL && tamanio != NULL)
    {
        retorno = 0;
        strncpy(this->tamanio,tamanio,40);
    }
    return retorno;
}
int raza_getTamanio(raza* this,char* tamanio)
{
    int retorno = -1;
    if(this!=NULL && tamanio != NULL)
    {
        retorno = 0;
        strncpy(tamanio,this->tamanio,40);
    }
    return retorno;
}

int raza_setPaisDeOrigen(raza* this,char* paisDeOrigen)
{
    int retorno = -1;
    if(this!=NULL && paisDeOrigen != NULL)
    {
        retorno = 0;
        strncpy(this->paisDeOrigen,paisDeOrigen,40);
    }
    return retorno;
}
int raza_getPaisDeOrigen(raza* this,char* paisDeOrigen)
{
    int retorno = -1;
    if(this!=NULL && paisDeOrigen != NULL)
    {
        retorno = 0;
        strncpy(paisDeOrigen,this->paisDeOrigen,40);
    }
    return retorno;
}




int raza_imprimirRaza(raza* this)
{
    int retorno = -1 ;
    if(this != NULL)
    {
        retorno = 1;

        char auxDescripcion[50] ,auxTamanio[50],auxPaisDeOrigen[50];
        int auxId,auxIsEmpty;

        raza_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {

            if
            (
                raza_getId(this ,&auxId) == 0 &&
                raza_getDescripcion(this ,auxDescripcion)== 0 &&
                raza_getTamanio(this ,auxTamanio)== 0 &&
                raza_getPaisDeOrigen(this ,auxPaisDeOrigen)== 0
            )
            {

                retorno =0;
                printf("\n %10d, %10s , %10s , %10s  ",auxId,auxDescripcion,auxTamanio,auxPaisDeOrigen);
            }
    }

       }
return retorno;
}



int raza_setNewId(raza* this,int id)
{

    int retorno = -1 ;
    static int maxId = 0;
    if(this!=NULL)
    {
        retorno = 1;
        if(id<=maxId)
        {
                maxId++;
                raza_setId(this,maxId);
                retorno = 0;

        }else{
                maxId = id;
                raza_setId(this,maxId);
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
