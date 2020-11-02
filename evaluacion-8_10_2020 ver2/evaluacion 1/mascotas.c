#include "mascotas.h"
#include <ctype.h>


int mascotas_cargarParametros(mascota* this,char edad [],char id [],char idRaza [] ,char nombre[],char sexo[],char tipo[])
{
  int retorno = -1;
    if(this != NULL && nombre != NULL && sexo != NULL && tipo != NULL && id > 0 && edad > 0)
    {
        if
        (
            mascota_setEdad(this ,atoi(edad)) == 0 &&
            mascota_setNewId(this ,atoi(id)) == 0 &&
            mascota_setIdRaza(this,atoi(idRaza))== 0 &&
            mascota_setisEmpty(this ,0)== 0 &&
            mascota_setNombre(this ,nombre)== 0 &&
            mascota_setSexo(this ,sexo)== 0 &&
            mascota_setTipo(this ,tipo)== 0
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




int mascota_setIdRaza(mascota* this,int idRaza)
{
    int retorno = -1;

    if(this!=NULL && idRaza >= 0)
    {

        retorno = 0;
        this->idRaza = idRaza;
    }
    return retorno;
}
int mascota_getIdRaza(mascota* this,int* idRaza)
{
    int retorno = -1;
    if(this!=NULL && idRaza != NULL)
    {
        retorno = 0;
       *idRaza = this->idRaza  ;
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
    int retorno = -1 ;
    if(this != NULL)
    {

        retorno = 1;
        int auxId,auxIsEmpty,auxEdad,auxIdRaza;
    char auxNombre[128],auxSexo[50], auxTipo[50];

        mascota_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {

            if
            (
                mascota_getId(this,&auxId) == 0 &&
                mascota_getIdRaza(this,&auxIdRaza)==0&&
                mascota_getNombre(this,auxNombre)== 0 &&
                mascota_getEdad(this,&auxEdad)== 0 &&
                mascota_getTipo(this,auxTipo)== 0 &&
                mascota_getsexo(this,auxSexo)== 0
            )
            {

                retorno =0;
                printf("\n%10d, %10d , %10d , %10s , %10s , %10s ",auxId,auxIdRaza,auxEdad,auxNombre,auxSexo,auxTipo);
            }
    }

       }
return retorno;
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


int mascota_setNewId(mascota* this,int id)// codigo repetido pero no se como hacer para reutilizarlo
{

    int retorno = -1 ;
    static int maxId = -1;
    if(this!=NULL)
    {
        retorno = 1;
        if(id<=maxId)
        {
                maxId++;
                mascota_setId(this,maxId);
                retorno = 0;

        }else{
                maxId = id;
                mascota_setId(this,maxId);
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


mascota* mascota_getBYId(mascota* list, int len,int id)
{
    mascota* retorno = NULL;
    if( list != NULL && id > 0,len > 0)
    {
        int i,idActual,isEmpty;
       for(i = 0; i< len;i++)
       {
          if( mascota_getisEmpty(list+i,&isEmpty) == 0 )
          {
             if(mascota_getId(list+i,&idActual) == 0 )
             {
                if( idActual== id )
                {
                    retorno = list +i;
                    break;
                }
             }
          }
       }
    }
return retorno;
}

int mascota_bajaLogica(mascota* list,int len,int id)
{
    int retorno = -1;
    mascota* element;
    if(list != NULL && len > 0 && id > 0)
    {

        if((element =  mascota_getBYId(list,len,id)) != NULL)
       {
           if(mascota_setisEmpty(element,1) == 0)
           {
               retorno = 0;
           }
       }
    }
    return retorno;
}








