
#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"
#include "controler.h"
#include "mascotas_raza.h"
#include "utn.h"
#include "display.h"


int controler_BajaMascota(mascota* list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        int id;
        mascota* element;
        if
        (
            mascota_list_imprimirLista(list,len) == 0
        )
        {
            if
            (

                (id = display_GetInt("\ningrese el id de la mascota a eliminar\n","ingrese el id : ",
                           "error! intente denuevo",len,1,3)) > 0
            )
            {

                if (( element = mascota_getBYId(list,len,id)) != NULL )
                {


                    display_imprimirCabeceraMascota();
                    mascota_imprimirMascota(element);
                    if( mascota_bajaLogica(list,len,id) == 0 )
                    retorno = 0 ;
                }
            }
        }
    }
    return retorno;
}



int controler_BajaRaza(mascota* listmascota,int lenmascota,raza *listRaza,int lenraza,pais *listpais,int lenpais)
{
    int retorno = -1;
    if(listmascota != NULL && lenmascota > 0 && listRaza != NULL && lenraza > 0)
    {
        int id;
        if
        (
            raza_list_imprimirLista(listRaza,lenraza,listpais,lenpais) == 0
        )
        {
            if
            (

                (id = display_GetInt("\ningrese el id de la raza a eliminar\n","ingrese el id : ",
                           "error! intente denuevo",lenraza,1,3)) > 0
            )
            {
                    if( raza_bajaLogica(listRaza,lenraza,id) == 0 )
                    {
                            mascota_bajaIfIdrazaIs(listmascota,lenmascota,id);
                    }

            }
        }
    }
    return retorno;
}

void controler_opcion12_imprimirPorTamanioYpeso(mascota* mascotalist,raza* razalist,int mascotaslen,int razalen,pais *listapais,int lenpais)
{
    int retorno = -1;
    if(mascotalist!= NULL &&razalist != NULL && mascotaslen >0 && razalen>0 && listapais != NULL && lenpais>0 )
    {


        int input;
        char tamanioValido[20];
        getValidInt("\ningrese el tamaño: \n 1- chico \n 2- mediano \n 3- grande \n","error! intente nuevamente",&input,1,3,3);
        switch(input)
        {
            case 1 :
                strcpy(tamanioValido,"chico");
                retorno = 0;
                break;

            case 2:
                strcpy(tamanioValido,"mediano");
                retorno = 0;
                break;
            case 3:
                strcpy(tamanioValido,"grande");
                retorno = 0;
                break;
        }
        mascota__raza_imprimirListaPorTamanioYpeso(tamanioValido,mascotalist,razalist,mascotaslen,razalen,listapais,lenpais);
    }
}


void controler_opcion13_imprimirPorTipoYpeso(mascota* mascotalist,raza* razalist,int mascotaslen,int razalen,pais *listapais,int lenpais)
{
    int retorno = -1;
    if(mascotalist!= NULL &&razalist != NULL && mascotaslen >0 && razalen>0 && listapais != NULL && lenpais>0 )
    {
          mascota__raza_imprimirListaPorTipoYpeso("gato",mascotalist,razalist,mascotaslen,razalen,listapais,lenpais);
          mascota__raza_imprimirListaPorTipoYpeso("perro",mascotalist,razalist,mascotaslen,razalen,listapais,lenpais);
          mascota__raza_imprimirListaPorTipoYpeso("raro",mascotalist,razalist,mascotaslen,razalen,listapais,lenpais);
    }
}


















