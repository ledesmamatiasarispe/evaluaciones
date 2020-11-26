
#include "mascotas.h"
#include <ctype.h>


int mascota_setNombre(mascota* this,char* nombre)
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


int mascota_setPeso(mascota* this,int peso)
{
    int retorno = -1;

    if(this!=NULL && peso >= 0)
    {

        retorno = 0;
        this->peso = peso;
    }
    return retorno;
}
int mascota_getPeso(mascota* this,int* peso)
{
    int retorno = -1;
    if(this!=NULL && peso != NULL)
    {
        retorno = 0;
       *peso = this->peso  ;
    }
    return retorno;
}

int mascota_setNewId(mascota* this,int id)
{

    int retorno = -1 ;
    static int maxId = 0;
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



int mascota_setValidSexo(mascota* this,int sexo)
{
    int retorno = -1;
    if(this!=NULL && sexo >= 1 && sexo <= 2)
    {
        switch(sexo)
        {
            case 1 :
                mascota_setSexo(this,"macho");
                retorno = 0;
                break;

            case 2:
                mascota_setSexo(this,"hembra");
                retorno = 0;
                break;
        }
    }
    return retorno;
}


/*************TIPO*******************/


etipo* mascota_getTipobyId(etipo* list,int len,int idtipo)
{
    etipo* retorno;

    if(list != NULL && len > 0 && idtipo > 0)
    {
        int i, id ;
        for(i=0;i<len;i++)
        {
            etipo_getId(list+i,&id);
            if(idtipo == id)
            {
                retorno = (list+i);
                break;
            }
        }
    }
    return retorno;
}





int mascota_setidTipo(mascota* this,int tipo)
{
    int retorno = -1;
    if(this!=NULL )
    {
        retorno = 0;
         this->idTipo = tipo ;
    }
    return retorno;
}


int mascota_getidTipo(mascota *this,int *tipo)
{
    int retorno = -1;
    if(this!=NULL && tipo != NULL )
    {
        retorno = 0;
        *tipo = this->idTipo;
    }
    return retorno;
}


int mascota_getDescripcionTipo(mascota* this,char* tipo,etipo *lista,int etipoLen)
{
    int retorno = -1;

    if(this!=NULL && tipo != NULL && lista != NULL && etipoLen >0)
    {
        int idtipo;
        etipo * tipoActual;
        mascota_getidTipo(this,&idtipo);
        tipoActual = mascota_getTipobyId(lista,etipoLen,idtipo);

        retorno = 0;
        strncpy(tipo,tipoActual->descripcion,20);
    }
    return retorno;
}


/************************************************/

int mascota_imprimirMascota(mascota* this)
{
    int retorno = -1 ;
    if(this != NULL)
    {

        retorno = 1;
        int auxId,auxIsEmpty,auxEdad;
    char auxNombre[128],auxSexo[50], auxTipo[50];

        mascota_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {
            if
            (
                mascota_getId(this,&auxId) == 0 &&
                mascota_getNombre(this,auxNombre)== 0 &&
                mascota_getEdad(this,&auxEdad)== 0 &&
                mascota_getsexo(this,auxSexo)== 0
            )
            {

                retorno =0;
                printf("\n%10d, %10d , %10s , %10s , %10s ",auxId,auxEdad,auxNombre,auxSexo,auxTipo);
            }
    }

       }
return retorno;
}



int mascotas_cargarParametros(mascota* this,char edad [],char id [],char idRaza [] ,char nombre[],char sexo[],char tipo[],char peso[])
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
            mascota_setidTipo(this ,atoi(tipo))== 0 &&
            mascota_setPeso(this,atoi(peso))== 0
        )
        {

           retorno = 0;
        }
    }
return retorno;
}



mascota* mascota_getBYId(mascota* list, int len,int id)
{
    mascota* retorno = NULL;
    if( list != NULL && id > 0 && len > 0)
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


mascota* mascota_getEmptyElement(mascota* list, int len)
{
    mascota* retorno = NULL;
    if( list != NULL && len > 0)
    {

        int i,isEmpty;
        for(i = 0; i< len;i++)
        {

            if( mascota_getisEmpty(list+i,&isEmpty) == 0)
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






int mascota_ingresarString(char mensaje[],mascota* this,pMascota_setString punteroSet)
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


int mascota_ingresarInt(char mensaje[],int max,int min,mascota* this,pMascota_setInt punteroSet)
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





int mascotas_list_inicializarIsEmpty(mascota* list,int len)
{
  int retorno = -1;
    if(list != NULL && len > 0 )
    {
        int i ;
        for(i = 0 ;i<len;i++)
        {
            mascota_setisEmpty((list + i),1);
        }
    }
return retorno;
}

int mascotas_list_cargarLista(char patch[],mascota* list,int len)
{
    int retorno = -1;
    if(patch != NULL && list != NULL && len > 0)
    {

        FILE* pfile;
        pfile = fopen(patch,"r");
        if(pfile != NULL)
        {

            parser_mascotaFromText(pfile,len,list);

        }
        fclose(pfile);
    }
    return retorno;
}

int mascota_list_imprimirLista(mascota* list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len;i ++)
        {
            if(i == 0)
            display_imprimirCabeceraMascota();

            mascota_imprimirMascota(list+i);
            retorno = 0;
        }
    }
    return retorno;
}



int mascota_list_swap(mascota* element1,mascota* element2)
{
    int retorno = -1;
    if(element1 != NULL && element2 != NULL)
    {
        mascota auxElement;
        auxElement = *element1;
        *element1 = *element2;
        *element2 = auxElement;
        retorno = 0;
    }
return retorno;
}


int compararPorTipo(mascota* mascota1,mascota* mascota2,etipo *lista,int etipoLen)
{
    int retorno = 0;
    char tipo1[128],tipo2[128];
    if(mascota1 != NULL && mascota2 != NULL )
    {
        if
        (
            mascota_getDescripcionTipo(mascota1,tipo1,lista,etipoLen) == 0 &&
            mascota_getDescripcionTipo(mascota2,tipo2,lista,etipoLen) == 0
        )
        {
           retorno = strcmp(tipo1,tipo2);
        }
    }
    return retorno;
}

int compararPorPeso(mascota* mascota1,mascota* mascota2)
{
    int retorno = 0;
    int peso1,peso2;
    if(mascota1 != NULL && mascota2 != NULL )
    {
        if
        (
            mascota_getPeso(mascota1,&peso1) == 0 &&
            mascota_getPeso(mascota2,&peso2) == 0
        )
        {
           retorno = peso1 - peso2 ;
        }
    }
    return retorno;
}

int compararPorTipoYPeso(mascota* mascota1,mascota* mascota2,etipo *lista,int etipoLen)
{
    int retorno = 0;
    if(mascota1 != NULL && mascota2 != NULL )
    {
        if
        (
           compararPorTipo(mascota1,mascota2,lista,etipoLen) > 0 || (compararPorTipo(mascota1,mascota2,lista,etipoLen) == 0 && compararPorPeso(mascota1,mascota2) > 0)
        )
        {
          retorno = 1;
        }
    }
    return retorno;
}

