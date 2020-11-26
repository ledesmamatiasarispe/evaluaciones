#include "parser.h"
#include "LinkedList.h"
#include <stdio.h>
#include<stdlib.h>

int controller_loadFromText(char* path, LinkedList* pList)
{
    int retorno = -1 ;
    if(path!=NULL && pList != NULL)
    {
        FILE* pFile;
        retorno=1;
        if( (pFile = fopen(path,"r")) != NULL)
        {
            retorno=2;
            if(parser_loadConcursanteFromText(pFile,pList) == 0)
            {
                retorno = 0;
            }
        }
        fclose(pFile);
    }
    return retorno;
}


int controller_loadConcursanteFromBinary(char* path, LinkedList* pList)
{
    int retorno = -1 ;
    if(path!=NULL && pList != NULL)
    {
        FILE* pFile;
        retorno=1;

        if( (pFile = fopen(path,"rb")) != NULL)
        {

            retorno=2;

            if(parser_ConcursanteFromBinary(pFile,pList) == 0)
            {
                retorno = 0;
            }
          }
        fclose(pFile);
    }
    return retorno;
}

int controller_printList(LinkedList *list,int (*pFunc)(void*))
{
    int retorno = -1;
    if(list != NULL && pFunc != NULL)
    {
        retorno = 0;
        ll_map(list,pFunc);
    }
    return retorno;
}
