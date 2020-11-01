#include "mascotas.h"
#include "mascotas_list.h"
#include "parser.h"
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
            mascota_imprimirMascota(list+i);
        }
    }
    return retorno;
}



















