#include "razas.h"
#include "mascotas.h"


raza* mascota_raza_getRazabyIdRaza(raza* list,int len,int idRaza)
{
    raza* retorno;

    if(list != NULL && len > 0 && idRaza > 0)
    {
        int i, id ;
        for(i=0;i<len;i++)
        {
            raza_getId(list+i,&id);
            if(idRaza == id)
            {
                retorno = (list+i);
                break;
            }
        }
    }
    return retorno;
}



int mascota__raza_imprimirMascotaConRaza(mascota* this,raza* list,int len)
{
    int retorno = -1 ;
    if(this != NULL && list != NULL && len > 0)
    {
        retorno = 1;
        raza* thisRaza;
        int auxId,auxIsEmpty,auxIdRaza;
    char auxNombre[128],auxDescripcion[128] ,auxTamanio[128],auxPaisDeOrigen[128];

        mascota_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {

            if
            (
                mascota_getId(this,&auxId) == 0 &&
                mascota_getIdRaza(this,&auxIdRaza)==0&&

                mascota_getNombre(this,auxNombre)== 0 &&

                (thisRaza = mascota_raza_getRazabyIdRaza(list,len,auxIdRaza)) != NULL &&

                raza_getDescripcion(thisRaza ,auxDescripcion)== 0 &&
                raza_getTamanio(thisRaza ,auxTamanio)== 0 &&
                raza_getPaisDeOrigen(thisRaza ,auxPaisDeOrigen)== 0
            )
            {

                retorno =0;
                printf("\n %10d , %10s ,%10s , %10s , %10s \n",auxId,auxNombre,auxDescripcion,auxTamanio,auxPaisDeOrigen);
            }
    }

       }
return retorno;
}

int mascota__raza_imprimirLista(mascota* mascotalist,raza* razalist,int mascotaslen,int razalen)
{
    int retorno = -1;
    if(mascotalist != NULL && razalist != NULL && mascotaslen > 0 && razalen > 0)
    {
        for(int i = 0; i<mascotaslen;i ++)
        {
            if(mascota__raza_imprimirMascotaConRaza(mascotalist+i,razalist,razalen) != 0)
                break;
        }
    }
    return retorno;
}





