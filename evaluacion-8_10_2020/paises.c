
#include "paises.h"
#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0

int initPaiz(ePais* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;
            list[i].idPais=0;
        }
        return 0;
    }
return -1;
}


void hardcodearPais( ePais lista[])
{
char arrayPaisDeOrigen[6][51]={"tailandia","alemania","persia","belgica","argentina"};
char arrayDescripcion[6][51]={"Asia","Europa","medioOriente","Europa","america"};
int arrayCodigoTelefonico[6]={66,49,98,32,54};

    int i;
    for(i=0 ; i<5 ; i++)
    {
        pais_SetId(lista+i,-1);
        strcpy(lista[i].nombre,arrayPaisDeOrigen[i]);
        strcpy(lista[i].continente,arrayDescripcion[i]);
        lista[i].codigoTelefonico=arrayCodigoTelefonico[i];
        lista[i].isEmpty=0;
    }
}



int pais_SetId(ePais* pais,int id)
{
    int retorno =-1;
    static unsigned int  maxIdPais=0;
    if(pais != NULL)
    {
        retorno = 0;
        if(id < 0)
        {
            maxIdPais++;
            pais->idPais = maxIdPais;
        }
    }else if(id > maxIdPais )
    {
        maxIdPais = id;
        pais->idPais = maxIdPais;
    }

    return retorno;
}




/** \brief
 *
 * \param raza eRaza*
 * \param mostrarEncabezado int poniendo el indice de el array que se esta imprimiendo , cuando imprima el indice 0 tambien
 va a imprimir el encabezado de la lista
 * \return int
 *
 */
int imprimirUnPais(ePais* pais,int mostrarEncabezado)
{
    int retorno =-1;
    if(pais != NULL )
    {
        retorno=0;
        if(mostrarEncabezado == 0)
        {
            printf("\n_________________________________________________________");
            printf("\n%-12s | %-20s | %-20s | %-20s |","id Pais","nombre","continente","codigoTelefonico");
        }

        if(pais->isEmpty==0)
        {
            printf("\n%12d | %20s | %20s | %20d |",pais->idPais,pais->nombre,pais->continente,pais->codigoTelefonico);
        }
    }
    return retorno;
}



int imprimirTodosLosPaises(ePais* lista,int lenght)
{
    int retorno =  -1 ;
    if(lista!=NULL&&lenght>0)
        {
            int i;
            for(i=0;i<lenght;i++)
            {
                if((lista+i)->isEmpty == 0 )
                {
                   imprimirUnPais(lista+i,i);
                }
            }

         }
    return retorno;
}
