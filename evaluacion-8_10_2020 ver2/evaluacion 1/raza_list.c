#include "razas.h"
#include "raza_list.h"
#include "parser.h"

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

int raza_list_imprimirLista(raza* list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len;i ++)
        {
            raza_imprimirRaza(list+i);
        }
    }
    return retorno;
}









