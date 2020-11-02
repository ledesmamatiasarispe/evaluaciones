
#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "listasEstaticas.h"
#include "controller.h"
#include "mascotas_list.h"
#include "utn.h"
#include "display.h"


int controler_BajaMascota(mascota* list,int len)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        int id;
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

                if( mascota_bajaLogica(list,len,id) == 0 )
                retorno = 0 ;
            }
        }
    }
    return retorno;
}

