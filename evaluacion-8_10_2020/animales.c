#include "animales.h"
#include "utn.h"
#include <string.h>

void hardcodearAnimales(eAnimales lista[])
{
  int  arrayEdades[5]={10,11,5,1,6};
  int  arrayidRaza[5]={1,3,2,4,2};
   char arrayNombres[5][51]={"michifus","anborgesa","firulais","rocky","perro"};
   char arraySexo[5]={'M','F','M','F','M'};
   char arrayTipo[5][20]={"gato","gato","perro","perro","perro"};


    int iAnimales;
    for(iAnimales=0 ; iAnimales<5 ; iAnimales++)
    {
        lista[iAnimales].idRaza=arrayidRaza[iAnimales];

       lista[iAnimales].edad = arrayEdades[iAnimales];
        lista[iAnimales].sexo = arraySexo[iAnimales];

        strcpy(lista[iAnimales].tipo,arrayTipo[iAnimales]);
        strcpy( lista[iAnimales].nombre,arrayNombres[iAnimales]);

        ani_SetId((lista+iAnimales),-1);
        //lista[iAnimales].iDAnimales=iAnimales+1;
        lista[iAnimales].isEmpty=0;
    }
}

int ani_SetId(eAnimales* Animales,int id)
{
    int retorno =-1;
    static unsigned int  maxIdAnimales=0;
    if(Animales != NULL)
    {
        retorno = 0;
        if(id < 0)
        {
            maxIdAnimales++;
            Animales->iDAnimales = maxIdAnimales;
        }
    }else if(id > maxIdAnimales )
    {
        maxIdAnimales = id;
        Animales->iDAnimales = maxIdAnimales;
    }

    return retorno;
}


int initAnimales(eAnimales* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;
            list[i].iDAnimales=0;
        }
        return 0;
    }
return -1;
}

int findById(eAnimales* list, int len,int id)
{
    int i;
    int returnIndex = -1;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(id==list[i].iDAnimales&&list[i].isEmpty==FALSE)
            {
                returnIndex = i;
                break;
            }
        }
    }

return returnIndex;
}

//***************************************************************************************************************************************
//***************************************************************************************************************************************

/**
*2.4 Función removeAnimal
*\brief Remove a Animal by Id (changes isEmpty Flag to 1)
*
* \param list *
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if no index has been found - [1] if the slected id is succesfuly set as (isempty = TRUE)
*
*/
 int removeAnimal(eAnimales* list, int len, int id)
{
int retorno=-1;
    if(list!=NULL && len>0 && id > 0 && id < 1000)
    {
        int index;
        index = findById(list,len,id);
        if(index != -1)
        {
            printf("el Animal a borrar es : \n");
            imprimirUnAnimal(list,1);
            if(getChar("\npara confirmar el borrado ingrese 'S' ") == 'S' )
            {
                list[index].isEmpty=TRUE;
                retorno = 1;
            }
        }else
        {
            retorno = 0 ;
            printf("no existe ninguna mascota en el indice %d \n",id);
        }
    }
return retorno;
}


int imprimirUnAnimal(eAnimales* animal,int mostrarEncabezado)
{
    int retorno =-1;
    if(animal != NULL )
    {
        retorno=0;

        if(mostrarEncabezado == 0)
        {
            printf("\n|%-11s | %-20s | %-6s | %-5s | %-10s |","id animal","nombre","edad","sexo","tipo");
        }

        printf("\n|%11d | %20s | %6d | %5c | %10s | ",animal->iDAnimales,animal->nombre,animal->edad,animal->sexo,animal->tipo);
    }

    return retorno;
}


int imprimirTodosLosAnimales(eAnimales* animal,int lenghtAnimales)
{
    int retorno =  -1 ;
    if(animal!=NULL && lenghtAnimales>0)
        {
            int i;
            for(i=0;i<lenghtAnimales;i++)
            {
                if((animal+i)->isEmpty == 0 )
                {
                   imprimirUnAnimal(animal+i,i);
                }
            }

        }
    return retorno;
}



/** \brief
 *
 * \param list eAnimales*
 * \param lenghtAnimales int
 * \param ValoresNuevos eAnimales*
 * \return int
 *
 */
int asginarDatosMascota(eAnimales* list,int lenghtAnimales,eAnimales* ValoresNuevos)
{

    int retorno=-1;
    int auxEmptyIndex;
    if(list!=NULL && lenghtAnimales>0 )
    {
        imprimirUnAnimal(ValoresNuevos,1);
        if(getChar("\nquiere guardar el animal ingresado?(S/n)\n [ ]\b\b")=='n')
        {
            retorno=0;
        }else
         {
             retorno=1;
            getFirstEmptyIndex(list,lenghtAnimales,&auxEmptyIndex);
            *(list+auxEmptyIndex) = *ValoresNuevos;
         }
    }
return retorno;
}

int getFirstEmptyIndex(eAnimales* list, int len,int* emptyIndex)
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

int swapearAnimales(eAnimales* list,int lenghtAnimales,int indexA,int indexB)
{
    int retorno =-1;

    if(list != NULL && lenghtAnimales > 0 && indexA >= 0 && indexB >= 0 && indexB < lenghtAnimales && indexA < lenghtAnimales)
    {
       if(list[indexA].isEmpty == 1 || list[indexB].isEmpty == 1 )
       {
           retorno=0;
       }else
        {
            retorno = 1;
        }

       eAnimales auxSwapeo;
       auxSwapeo = list[indexA];
       list[indexA] = list[indexB];
       list[indexB] = auxSwapeo;

    }
    return retorno;
}



