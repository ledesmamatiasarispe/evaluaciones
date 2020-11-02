#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"
#include "mascotas_list.h"
#include "utn.h"
int parser_mascotaFromText(FILE* pFile,int len , mascota* list)
{
    int retorno = -1;
    if(pFile!=NULL && list != NULL)
    {
        int datosEscaneados;
        char auxId[50] ,auxIdRaza[50] , auxNombre[50] ,auxEdad[50],auxSexo[50], auxTipo[50];
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdRaza,auxNombre,auxEdad,auxSexo,auxTipo) == 6)
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
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdRaza,auxNombre,auxEdad,auxSexo,auxTipo);

            if(datosEscaneados == 6)
            {
               mascotas_cargarParametros(list+i,auxEdad,auxId,auxIdRaza,auxNombre,auxSexo,auxTipo);
            }
            i++;
        }
    }
    return retorno;
}

int parser_razaFromText(FILE* pFile,int len , raza* list)
{
    int retorno = -1;
    if(pFile!=NULL && list != NULL)
    {
        int datosEscaneados;

        char auxId[50] , auxDescripcion[50] ,auxTamanio[50],auxPaisDeOrigen[50];
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxTamanio,auxPaisDeOrigen) == 4)
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
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxTamanio,auxPaisDeOrigen);

            if(datosEscaneados == 4)
            {
               razas_cargarParametros(list+i,auxDescripcion,auxId,auxTamanio,auxPaisDeOrigen);
            }
            i++;
        }
    }
    return retorno;
}
