
#include "raza.h"
#include <string.h>

void hardcodearRaza(eRaza lista[])
{

char arrayDescripcion[6][51]={"siames","doberman","persa","pastor_belga","dogo","pastor_aleman"};
char arraytamanio[6][51]={"chico","grande","mediano","grande","mediano","mediano" };
 int  arrayidPais[6]={1,2,3,4,5,2};

    int iRaza;
    for(iRaza=0 ; iRaza<6 ; iRaza++)
    {
        //lista[iRaza].idRaza=arrayId[iRaza];
        raz_SetId(lista+iRaza,-1);
        lista[iRaza].idPais=arrayidPais[iRaza];
        strcpy(lista[iRaza].descripcion,arrayDescripcion[iRaza]);
        strcpy(lista[iRaza].tamanio,arraytamanio[iRaza]);
         lista[iRaza].isEmpty=0;
    }
}

int initRaza(eRaza* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;
            list[i].idRaza=0;
        }
        return 0;
    }
return -1;
}


int imprimirUnaRaza(eRaza* raza,int mostrarEncabezado)
{
    int retorno =-1;
    if(raza != NULL )
    {
        retorno=0;
        if(mostrarEncabezado == 0)
        {
            printf("\n_________________________________________________________");
            printf("\n%-12s | %-20s | %-20s |","id Raza","descripcion","tamanio");
        }

        if(raza->isEmpty==0)
        {
            printf("\n%12d | %20s | %20s |",raza->idRaza,raza->descripcion,raza->tamanio);
        }
    }
    return retorno;
}



int imprimirTodasLasRazas(eRaza* listaRaza,int lenghtRaza)
{
    int retorno =  -1 ;
    /*if(listaRaza!=NULL&&lenghtRaza>0)
        {*/
            int i;
            for(i=0;i<lenghtRaza;i++)
            {
                if((listaRaza+i)->isEmpty == 0 )
                {
                   imprimirUnaRaza(listaRaza+i,i);
                }
            }

        //}
    return retorno;
}

int asginarDatosRaza(eRaza* list,int lenght,eRaza* ValoresNuevos)
{

    int retorno=-1;
    int auxEmptyIndex;
    if(list!=NULL && lenght>0 )
    {
        imprimirUnaRaza(ValoresNuevos,0);
        if(getChar("\nquiere guardar la raza ingresada?(S/n)\n [ ]\b\b")=='n')
        {
            retorno=0;
        }else
         {
             retorno=1;
            raza_getFirstEmptyIndex(list,lenght,&auxEmptyIndex);
            *(list+auxEmptyIndex) = *ValoresNuevos;
         }
    }
return retorno;
}

int raz_SetId(eRaza* raza,int id)
{
    int retorno =-1;
    static unsigned int  maxIdRaza=0;
    if(raza != NULL)
    {
        retorno = 0;
        if(id < 0)
        {
            maxIdRaza++;
            raza->idRaza = maxIdRaza;
        }
    }else if(id > maxIdRaza )
    {
        maxIdRaza = id;
        raza->idRaza = maxIdRaza;
    }

    return retorno;
}


int raza_getFirstEmptyIndex(eRaza* list, int len,int* emptyIndex)
{

    if(list != NULL&&len > 0 &&emptyIndex!=NULL )
    {
        int i;
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==TRUE)
            {
               *emptyIndex = i;
               return 1;
            }
        }
        return 0;
    }
    return -1;
}
