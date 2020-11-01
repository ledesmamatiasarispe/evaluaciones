#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "mascotas_list.h"
#include "utn.h"
int parser_mascotaFromText(FILE* pFile,int len , mascota* list)
{
    int retorno = -1;
    if(pFile!=NULL && list != NULL)
    {
        int datosEscaneados;
        char auxId[50] , auxNombre[50] ,auxEdad[50],auxSexo[50], auxTipo[50];
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxEdad,auxSexo,auxTipo) == 5)
        {
            if
            (
                esNumerico(auxId) == 1
            )
            {
                rewind(pFile);
            }
        }
        int i = 0;
        while(!feof(pFile) && i < len)
        {
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxEdad,auxSexo,auxTipo);

            if(datosEscaneados == 5)
            {
               mascotas_cargarParametros(list+i,auxEdad,auxId,auxNombre,auxSexo,auxTipo);
            }
            i++;
        }
    }
    return retorno;
}
