#include <stdio.h>
#include<stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "concursante.h"
#include "utn.h"
int parser_loadConcursanteFromText(FILE* pFile, LinkedList* pArrayList)
{

    int retorno = -1;
    if(pFile!=NULL && pArrayList != NULL)
    {
        char auxNumeroconcursante[128],auxAnio[128],auxNombre[128],auxDni[10],auxFechaPresentacion[128],
             auxTemaPresentacion[128],auxPuntajePrimeraRonda[128];
        retorno = 1;
        if
        (

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                   auxNumeroconcursante,auxAnio,auxNombre,auxDni,auxFechaPresentacion,
                   auxTemaPresentacion,auxPuntajePrimeraRonda) == 7
        )
        {

            if
            (
                esNumerico(auxNumeroconcursante) == 1 &&
                esNumerico(auxAnio) == 1
            )
            {

                rewind(pFile);
            }
        }

        concursante *this;
        while(!feof(pFile))
        {
            /**numeroConcursante,anio,nombre,dni,fechapresentacion,temaPresentacion,puntaje*/
            if
            (
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                       auxNumeroconcursante,auxAnio,auxNombre,auxDni,auxFechaPresentacion,
                       auxTemaPresentacion,auxPuntajePrimeraRonda) == 7
            )
            {
                if
                (
                    (this = conc_newConcursanteParametros(auxNumeroconcursante,auxAnio,
                            auxNombre,auxDni,auxFechaPresentacion,
                            auxTemaPresentacion,auxPuntajePrimeraRonda))!=NULL
                )
                {
                    ll_add(pArrayList,this);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int parser_ConcursanteFromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = -1;

    if(pFile!=NULL && pArrayList != NULL)
    {
        concursante* this;
        retorno = 1;
        while(!feof(pFile))
        {
            this = conc_newConcursante();
            if(fread(this,sizeof(concursante),1,pFile))
            {
                retorno = 0;
                ll_add(pArrayList,this);
            }
        }
    }
    return retorno;
}


