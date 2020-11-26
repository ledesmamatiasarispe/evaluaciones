#include <string.h>
#include "etipo.h"
#include <stdio.h>
#include <stdlib.h>

int etipo_cargarLista(char patch[],etipo* list,int len)
{
    int retorno = -1;
    if(patch != NULL && list != NULL && len > 0)
    {

        FILE* pfile;
        pfile = fopen(patch,"r");
        if(pfile != NULL)
        {

            parser_etipoFromText(pfile,len,list);

        }
        fclose(pfile);
    }
    return retorno;
}


int etipo_setid(etipo* this,int id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        this->id = id;
    }
    return retorno;
}

int etipo_getId(etipo* this,int* id)
{
    int retorno = -1;
    if(this!=NULL && id != NULL)
    {
        retorno = 0;
       *id = this->id ;
    }
    return retorno;
}


int etipo_setdescripcion(etipo* this,char descripcion[])
{
    int retorno = -1;
    if(this!=NULL && descripcion != NULL)
    {
        retorno = 0;
        strncpy(this->descripcion,descripcion,128);
    }
    return retorno;
}
int etipo_getdescripcion(etipo* this,char* descripcion)
{
    int retorno = -1;
    if(this!=NULL && descripcion != NULL)
    {
        retorno = 0;
        strncpy(descripcion,this->descripcion,128);
    }
    return retorno;
}

int etipo_setisEmpty(etipo* this,int isEmpty)
{
    int retorno = -1;

    if(this!=NULL && (isEmpty == 0 || isEmpty == 1) )
    {

        retorno = 0;
        this->isEmpty = isEmpty;
    }
    return retorno;
}
int etipo_getisEmpty(etipo* this,int* isEmpty)
{
    int retorno = -1;
    if(this!=NULL && isEmpty != NULL)
    {
        retorno = 0;
       *isEmpty = this->isEmpty  ;
    }
    return retorno;
}




int etipo_list_inicializarIsEmpty(etipo* list,int len)
{
  int retorno = -1;
    if(list != NULL && len > 0 )
    {
        int i ;
        for(i = 0 ;i<len;i++)
        {
            etipo_setisEmpty((list + i),1);
        }
    }
return retorno;
}







int etipo_cargarParametros(etipo* this,char descripcion[],char id[])
{
  int retorno = -1;
    if(this != NULL && descripcion != NULL && id )
    {

        if
        (
            etipo_setid(this ,atoi(id)) == 0 &&

            etipo_setisEmpty(this ,0)== 0 &&

            etipo_setdescripcion(this ,descripcion)== 0
        )
        {

           retorno = 0;
        }
    }
return retorno;
}



int etipo_imprimirLista(etipo *list,int len)
{
    int retorno = -1;

    if(list != NULL && len > 0 )
    {
        for(int i = 0; i<len;i ++)
        {
            int isempty;
            if(etipo_getisEmpty(list+i,&isempty) == 0 && isempty == 0);
            {
                if(etipo_imprimirUnTipo(list+i) != 0)
                {
                    retorno = 0;
                }

            }

        }
    }
    return retorno;
}

int etipo_imprimirUnTipo(etipo *this)
{
    if(this != NULL)
    {
        int id;
        char descripcion[128];

        etipo_getdescripcion(this,descripcion);
        etipo_getId(this,&id);



        printf("\n %10d | %10s ",id,descripcion);



    }




}
