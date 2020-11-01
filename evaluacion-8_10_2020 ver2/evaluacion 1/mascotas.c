#include "mascotas.h"
#include <ctype.h>


int mascotas_cargarParametros(mascota* element,char edad [],char id [],char nombre[],char sexo[],char tipo[])
{
  int retorno = -1;
    if(element != NULL && nombre != NULL && sexo != NULL && tipo != NULL && id > 0 && edad > 0)
    {
        if
        (
            mascota_setEdad(element ,atoi(edad)) == 0 &&
            mascota_setId(element ,atoi(id)) == 0 &&
            mascota_setisEmpty(element ,0)== 0 &&
            mascota_setNombre(element ,nombre)== 0 &&
            mascota_setSexo(element ,sexo)== 0 &&
            mascota_setTipo(element ,tipo)== 0
        )
        {

           retorno = 0;
        }
    }
return retorno;
}





int mascota_setNombre(mascota* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        mascota_nombreAformatoCorrecto(nombre);
        retorno = 0;
        strncpy(this->nombre,nombre,40);
    }
    return retorno;
}
int mascota_getNombre(mascota* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        retorno = 0;
        strncpy(nombre,this->nombre,128);
    }
    return retorno;
}


int mascota_setId(mascota* this,int id)
{
    int retorno = -1;

    if(this!=NULL && id >= 0)
    {

        retorno = 0;
        this->id = id;
    }
    return retorno;
}
int mascota_getId(mascota* this,int* id)
{
    int retorno = -1;
    if(this!=NULL && id != NULL)
    {
        retorno = 0;
       *id = this->id  ;
    }
    return retorno;
}



int mascota_setisEmpty(mascota* this,int isEmpty)
{
    int retorno = -1;

    if(this!=NULL && (isEmpty == 0 || isEmpty == 1) )
    {

        retorno = 0;
        this->isEmpty = isEmpty;
    }
    return retorno;
}
int mascota_getisEmpty(mascota* this,int* isEmpty)
{
    int retorno = -1;
    if(this!=NULL && isEmpty != NULL)
    {
        retorno = 0;
       *isEmpty = this->isEmpty  ;
    }
    return retorno;
}





int mascota_setEdad(mascota* this,int edad)
{
    int retorno = -1;

    if(this!=NULL && edad >= 0)
    {

        retorno = 0;
        this->edad = edad;

    }
    return retorno;
}
int mascota_getEdad(mascota* this,int* edad)
{
    int retorno = -1;
    if(this!=NULL && edad != NULL)
    {
        retorno = 0;
       *edad = this->edad  ;
    }
    return retorno;
}




int mascota_setSexo(mascota* this,char sexo[])
{
    int retorno = -1;
    if(this!=NULL && sexo != NULL)
    {
        retorno = 0;
        strncpy(this->sexo,sexo,20);
    }
    return retorno;
}
int mascota_getsexo(mascota* this,char* sexo)
{
    int retorno = -1;
    if(this!=NULL && sexo != NULL)
    {
        retorno = 0;
        strncpy(sexo,this->sexo,20);
    }
    return retorno;
}


int mascota_setTipo(mascota* this,char tipo[])
{
    int retorno = -1;
    if(this!=NULL && tipo != NULL)
    {
        retorno = 0;
        strncpy(this->tipo,tipo,20);
    }
    return retorno;
}
int mascota_getTipo(mascota* this,char* tipo)
{
    int retorno = -1;
    if(this!=NULL && tipo != NULL)
    {
        retorno = 0;
        strncpy(tipo,this->tipo,20);
    }
    return retorno;
}


int mascota_imprimirMascota(mascota* this)
{
    if(this != NULL)
    {
        int auxId,auxIsEmpty,auxEdad;
    char auxNombre[128],auxSexo[50], auxTipo[50];

        mascota_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {
            mascota_getId(this,&auxId);

            mascota_getNombre(this,auxNombre);
            mascota_getEdad(this,&auxEdad);
            mascota_getTipo(this,auxTipo);
            mascota_getsexo(this,auxSexo);
            printf("\n id %d, %d , %s , %s , %s ",auxId,auxEdad,auxNombre,auxSexo,auxTipo);
    }

       }
return 0;
}







int mascota_nombreAformatoCorrecto(char* this)
{
    if(this != NULL)
    {
        int i;
        for(i=0; *(this+i) != '\0';i++)
        {
            if(i == 0)/* la primer letra la transformo en mayuscula */
            {
               *this = toupper(*this);
            }else
             {
                *(this+i) = tolower(*(this+i));/* en el caso contrario la transformo en minuscula*/
             }


            if( *(this + i) != ' ' && (*(this + i) <'a' || *(this + i) > 'z') && (*(this + i) <'A' || *(this + i) > 'Z'))
            {
                *(this+i) = ' ';/* si hay un caracter raro lo transformo en espacio*/
            }

            if( *(this+i-1) == ' ')
            {
                *(this+i) =toupper(*(this+i)); /* si antes hay un espacio lo transformo en mayuscula */
            }
        }
    }
return 0;
}
