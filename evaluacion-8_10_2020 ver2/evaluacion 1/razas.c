
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "display.h"
#include "mascotas.h"
#include "razas.h"
#include "pais.h"
#include "utn.h"
#include "parser.h"

int pais_pcompararPorPais(pais *pais1,pais *pais2)
{
    int retorno = 0;
    if(pais1 != NULL && pais2 != NULL )
    {


            char nombre1[130],nombre2[130];
            if
            (
                pais_getNombre(pais1,nombre1) == 0 &&
                pais_getNombre(pais2,nombre2) == 0
            )
            {
               //printf(" %s ",nombre1);
                //printf(" %s ",nombre2);

                retorno = strcasecmp(nombre1,nombre2);
               // printf("retorno %d \n",retorno);
            }

    }
    return retorno ;
}


int pais_pcompararCodigoTelefonico(pais *pais1,pais *pais2)
{
    int retorno = 0;
    if(pais1 != NULL && pais2 != NULL )
    {
        int numero1,numero2;
            if
            (
                pais_getcodigoTelefonico(pais1,&numero1) == 0 &&
                pais_getcodigoTelefonico(pais2,&numero2) == 0
            )
            {
                retorno = numero1 - numero2;
            }

    }
    return retorno ;
}


















int razas_cargarParametros(raza* this,char descripcion[],char id[],char tamanio[],char auxIdPais[])
{
  int retorno = -1;
    if(this != NULL && descripcion != NULL && id != NULL && tamanio != NULL && auxIdPais !=NULL)
    {
        if
        (
            raza_setNewId(this ,atoi(id)) == 0 &&

            raza_setisEmpty(this ,0)== 0 &&

            raza_setDescripcion(this ,descripcion)== 0 &&
            raza_setTamanio(this ,tamanio)== 0 &&

            raza_setidPais(this,atoi(auxIdPais)) == 0

        )
        {

           retorno = 0;
        }
    }
return retorno;
}

//pk

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

//isempty

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

//sk pais

int raza_setidPais(raza* this,int idPais)
{
    int retorno = -1;

    if(this!=NULL && idPais >= 0)
    {

        retorno = 0;
        this->idPais = idPais;
    }
    return retorno;
}

int raza_getidPais(raza* this,int* idPais)
{
    int retorno = -1;
    if(this!=NULL && idPais != NULL)
    {
        retorno = 0;
       *idPais = this->idPais  ;
    }
    return retorno;
}



//descripcion

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

// tamanio

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
int raza_setValidTamanio(raza* this,int tipo)
{
    int retorno = -1;
    if(this!=NULL && tipo >= 1 && tipo<= 3)
    {
          switch(tipo)
        {
            case 1 :
                raza_setTamanio(this,"chico");
                retorno = 0;
                break;

            case 2:
                raza_setTamanio(this,"mediano");
                retorno = 0;
                break;
            case 3:
                raza_setTamanio(this,"grande");
                retorno = 0;
                break;
        }
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



int raza_bajaLogica(raza* list,int len,int id)
{
    int retorno = -1;
    raza *element;
    if(list != NULL && len > 0 && id > 0)
    {

        if((element =  raza_getBYId(list,len,id)) != NULL)
       {
           if(raza_setisEmpty(element,1) == 0)
           {
               retorno = 0;
           }
       }
    }
    return retorno;
}





int raza_imprimirRaza(raza* this,pais* paisActual)
{
    int retorno = -1 ;
    if(this != NULL && paisActual != NULL)
    {
        retorno = 1;

        char auxDescripcion[128] ,auxTamanio[128],auxPaisDeOrigen[128];
        int auxId,auxIsEmpty;

        raza_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {

            if
            (
                raza_getId(this ,&auxId) == 0 &&
                raza_getDescripcion(this ,auxDescripcion)== 0 &&
                raza_getTamanio(this ,auxTamanio)== 0 &&
                pais_getNombre(paisActual,auxPaisDeOrigen) == 0
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





raza* raza_getEmptyElement(raza* list, int len)
{
    raza* retorno = NULL;
    if( list != NULL && len > 0)
    {

        int i,isEmpty;
        for(i = 0; i< len;i++)
        {

            if( raza_getisEmpty(list+i,&isEmpty) == 0)
            {
                if(isEmpty == 1)
                {
                    retorno = (list+i);
                    break;
                }
            }
        }

    }
return retorno;
}




int raza_ingresarString(char mensaje[],raza* this,pRaza_setString punteroSet)
{
    int retorno = -1;
    if(this!=NULL && punteroSet != NULL )
    {
        char auxInput[1024];
        retorno = 1;
        if
        (
            getValidString(mensaje,"Error! reintente nuevamente",
                           "Error! limite de caracteres superado",auxInput,40,3)==0 &&
            punteroSet(this,auxInput) == 0
        )
        {
          retorno = 0;
        }
    }
    return retorno;
}


int raza_ingresarInt(char mensaje[],int max,int min,raza* this,pRaza_setInt punteroSet)
{
    int retorno = -1;
    if(this!=NULL && punteroSet != NULL )
    {
        int auxInput;
        retorno = 1;

        if(
            getValidInt(mensaje,"Error! reintente nuevamente",&auxInput,min,max,3)==0 &&
            punteroSet(this,auxInput) == 0
        )
        {
          retorno = 0;
        }
    }
    return retorno;
}


/*getters de pais*/

pais* raza_getpaisbyId(pais* list,int len,int idpais)
{
    pais* retorno;

    if(list != NULL && len > 0 && idpais > 0)
    {
        int i, id ;
        for(i=0;i<len;i++)
        {
            pais_getId(list+i,&id);
            if(idpais == id)
            {
                retorno = (list+i);
                break;
            }
        }
    }
    return retorno;
}







pais* raza_getpais(pais* list,int len,raza *this)
{
    pais* retorno;

    if(list != NULL && len > 0 && this != NULL)
    {
        int id ;
        if( raza_getidPais(this,&id) == 0 )
        if( (retorno =  raza_getpaisbyId(list,len,id) ) == NULL )
        retorno = NULL;
    }
    return retorno;
}












/*alta-baja-modificacion*/



int raza_alta(raza* list,int len,pais* listPaises,int lenpais)
{
    int retorno = -1;

    if(list != NULL && len > 0 && listPaises != NULL && lenpais > 0)
    {

        raza *this, auxraza;
        int cantidadDePaises;

        cantidadDePaises = pais_list_cantidadDePais(listPaises,lenpais);

        if((this =  raza_getEmptyElement(list,len)) != NULL)
        {
            printf("nueva raza :");
             if
             (
                raza_setisEmpty(&auxraza ,0)  == 0 &&
                raza_setNewId(&auxraza ,0)  == 0 &&

                raza_ingresarString("\ningrese la descripcion \n",&auxraza,raza_setDescripcion)  == 0 &&

                raza_ingresarInt("\ningrese el tamaño: \n 1- chico \n 2- mediano \n 3- grande \n",3,1,&auxraza,raza_setValidTamanio)  == 0 &&

                pais_list_imprimirLista(listPaises,lenpais) == 0 &&
                raza_ingresarInt("\ningrese id Del pais \n",cantidadDePaises,1,&auxraza,raza_setidPais)  == 0

             )
             {
                *this = auxraza;
                retorno = 0;
            }

        }
    }
    return retorno;
}


/*

int raza_bajaLogica(raza* list,int len,int id)
{
    int retorno = -1;
    raza* element;
    if(list != NULL && len > 0 && id > 0)
    {

        if((element =  raza_get(list,len,id)) != NULL)
       {
           if(raza_setisEmpty(element,1) == 0)
           {
               retorno = 0;
           }
       }
    }
    return retorno;
}


int controler_Bajaraza(raza* list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        int id;
        raza* element;
        if
        (
            raza_list_imprimirLista(list,len) == 0
        )
        {
            if
            (

                (id = display_GetInt("\ningrese el id de la raza a eliminar\n","ingrese el id : ",
                           "error! intente denuevo",len,1,3)) > 0
            )
            {

                if (( element = raza_getBYId(list,len,id)) != NULL )
                {


                    display_imprimirCabeceraRaza();
                    raza_imprimirRaza(element);
                    if( raza_bajaLogica(list,len,id) == 0 )
                    retorno = 0 ;
                }
            }
        }
    }
    return retorno;
}


*/
//lista

int raza_list_inicializarIsEmpty(raza* list,int len)
{
  int retorno = -1;
    if(list != NULL && len > 0 )
    {
        int i ;
        for(i = 0 ;i<len;i++)
        {
            raza_setisEmpty((list + i),1);
        }
    }
return retorno;
}

int raza_list_cargarLista(char patch[],raza* list,int len)
{
    int retorno = -1;
    if(patch != NULL && list != NULL && len > 0)
    {

        FILE* pfile;
        pfile = fopen(patch,"r");
        if(pfile != NULL)
        {

            parser_razaFromText(pfile,len,list);

        }
        fclose(pfile);
    }
    return retorno;
}

int raza_list_imprimirLista(raza* list,int len,pais* listPaises,int lenpais)
{
    int retorno = -1;
    if(list != NULL && len > 0 && listPaises != NULL && lenpais >0)
    {
        int id;
        pais* paisActual;
        for(int i = 0; i<len;i ++)
        {
            if(i == 0)
            {
                display_imprimirCabeceraRaza();
            }

            if(raza_getId(list+i,&id)==0)
            if((paisActual = raza_getpaisbyId(listPaises,lenpais,id)) != NULL )
            raza_imprimirRaza(list+i,paisActual);

            retorno = 0;
        }
    }
    return retorno;
}




int raza_list_cantidadDeRazas(raza* list,int len)
{
    int retorno = 0;
    if(list != NULL && len > 0)
    {
        int  isEmpty ;
        for(int i = 0; i<len;i ++)
        {
            if(raza_getisEmpty(list+i,&isEmpty)==0)
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




raza* raza_getBYId(raza* list, int len,int id)
{
    raza* retorno = NULL;
    if( list != NULL && id > 0 && len > 0)
    {
        int i,idActual,isEmpty;
       for(i = 0; i< len;i++)
       {
          if( raza_getisEmpty(list+i,&isEmpty) == 0 )
          {
             if(raza_getId(list+i,&idActual) == 0 )
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

