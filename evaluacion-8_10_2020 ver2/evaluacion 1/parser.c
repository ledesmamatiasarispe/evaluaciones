#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int parser_mascotaFromText(FILE* pFile,int len , mascota* list)
{
    int retorno = -1;
    if(pFile!=NULL && list != NULL)
    {

        int datosEscaneados;
        char auxId[128] ,auxIdRaza[128] , auxNombre[128] ,auxEdad[128],auxSexo[128], auxTipo[128],auxPeso[128];
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdRaza,auxNombre,auxEdad,auxSexo,auxTipo,auxPeso) == 7)
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
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdRaza,auxNombre,auxEdad,auxSexo,auxTipo,auxPeso);

            if(datosEscaneados == 7)
            {
               mascotas_cargarParametros(list+i,auxEdad,auxId,auxIdRaza,auxNombre,auxSexo,auxTipo,auxPeso);
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

        char auxId[50] , auxDescripcion[50] ,auxTamanio[50],auxIdPais[50];
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxTamanio,auxIdPais) == 4)
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
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxTamanio,auxIdPais);

            if(datosEscaneados == 4)
            {
               razas_cargarParametros(list+i,auxDescripcion,auxId,auxTamanio,auxIdPais);
            }
            i++;
        }
    }
    return retorno;
}





int parser_paisFromText(FILE* pFile,int len , pais* list)
{
    int retorno = -1;
    if(pFile!=NULL && list != NULL)
    {
        int datosEscaneados;

        char auxId[50] , auxNombre[50] ,auxContinente[50],auxCodigoTelefonico[50];
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxContinente,auxCodigoTelefonico) == 4)
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
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxContinente,auxCodigoTelefonico);

            if(datosEscaneados == 4)
            {
               pais_cargarParametros(list+i,auxNombre,auxId,auxContinente,auxCodigoTelefonico);
            }
            i++;
        }
    }
    return retorno;
}





int parser_etipoFromText(FILE* pFile,int len , etipo* list)
{
    int retorno = -1;
    if(pFile!=NULL && list != NULL)
    {
        int datosEscaneados;

        char auxId[50] , auxNombre[50] ;
        retorno = 1;
        if(fscanf(pFile,"%[^,],%[^\n]\n",auxId,auxNombre) == 2)
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
            datosEscaneados = fscanf(pFile,"%[^,],%[^\n]\n",auxId,auxNombre);

            if(datosEscaneados == 2)
            {
               etipo_cargarParametros(list+i,auxNombre,auxId);
            }
            i++;
        }
    }
    return retorno;
}
