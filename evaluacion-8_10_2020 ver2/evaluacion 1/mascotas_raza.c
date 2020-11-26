
#include "mascotas_raza.h"

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


raza* mascota_raza_getRazaOfMascota(mascota* this,raza* list,int len)
{
    raza* retorno;

    if(this != NULL &&list != NULL && len > 0)
    {
        int auxIdRaza;
        if
        (
            mascota_getIdRaza(this,&auxIdRaza) == 0

        )
        {
           retorno = mascota_raza_getRazabyIdRaza(list,len,auxIdRaza)  ;
        }
    }
    return retorno;
}



int mascota__raza_imprimirMascotaConRaza(mascota* this,raza* razalist,int razalen,pais* paislist,int paislen)
{
    int retorno = -1 ;
    if(this != NULL && razalist != NULL && razalen > 0 && paislist != NULL && paislen > 0)
    {
        retorno = 1;
        raza* thisRaza;
        pais* thisPais;
        int auxId,auxIsEmpty,auxIdRaza,idPais,auxCodigoTelefonico,auxPeso;
        char auxNombre[128],auxDescripcion[128] ,auxTamanio[128],auxPaisDeOrigen[128];
        char auxContinente[128];
        mascota_getisEmpty(this,&auxIsEmpty);
        if(auxIsEmpty == 0)
        {

              if
              (
                mascota_getId(this,&auxId)  == 0 &&
                mascota_getIdRaza(this,&auxIdRaza) ==0&&
                mascota_getPeso(this,&auxPeso) == 0&&
                mascota_getNombre(this,auxNombre) == 0 &&

                (thisRaza = mascota_raza_getRazabyIdRaza(razalist,razalen,auxIdRaza)) != NULL &&

                raza_getDescripcion(thisRaza ,auxDescripcion) == 0 &&
                raza_getTamanio(thisRaza ,auxTamanio) == 0 &&
                raza_getidPais(thisRaza,&idPais) == 0 &&

                (thisPais = raza_getpaisbyId(paislist,paislen,auxIdRaza)) != NULL &&
                pais_getNombre(thisPais,auxPaisDeOrigen) == 0 &&
                pais_getContinente(thisPais,auxContinente) == 0 &&
                pais_getcodigoTelefonico(thisPais,&auxCodigoTelefonico) == 0


              )
              {

                retorno =0;
                printf("\n%10d | %10s | %10s | %10s | %10s | %10s | %15d | %10d \n",
                       auxId,auxNombre,auxDescripcion,auxTamanio,auxPaisDeOrigen,auxContinente,auxCodigoTelefonico,auxPeso);
              }
        }

    }
return retorno;
}

int mascota__raza_imprimirLista(mascota* mascotalist,raza* razalist,int mascotaslen,int razalen,pais *listapais,int lenpais)
{
    int retorno = -1;

    if(mascotalist != NULL && razalist != NULL && mascotaslen > 0 && razalen > 0)
    {
        for(int i = 0; i<mascotaslen;i ++)
        {
            if(mascota__raza_imprimirMascotaConRaza(mascotalist+i,razalist,razalen,listapais,lenpais) != 0)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

/*
#-Opción Listar por TAMAÑO y PESO:

-Sabiendo que solo hay tres tamaños(tamaño{chico ,mediano o grande}),pedir
el ingreso al usuario de un tamaño válido y mostrar el listado de mascotas de este
tamaño con sus países de origen peso y la suma total del peso entre estas mascotas.
*/

int mascota__raza_imprimirListaPorTamanioYpeso(char tamanio[128],mascota* mascotalist,raza* razalist,int mascotaslen,int razalen,pais *paisList,int paisLen)
{
    int retorno = -1;

    if(mascotalist != NULL && razalist != NULL && mascotaslen > 0 && razalen > 0)
    {
        raza *RazaActual;
        char tamanioActual[150];
        int acumuladorPesos=0,pesoActual,isEmpty;
        for(int i = 0; i<mascotaslen;i ++)
        {
            if(mascota_getisEmpty(mascotalist+i,&isEmpty)== 0 && isEmpty == 0)
            {
                if((RazaActual = mascota_raza_getRazaOfMascota(mascotalist+i,razalist,razalen)) != NULL)
                {

                   if( raza_getTamanio(RazaActual,tamanioActual) == 0 && strcmp(tamanioActual,tamanio) == 0)
                   {
                        mascota_getPeso(mascotalist+i,&pesoActual);
                        acumuladorPesos += pesoActual;
                        mascota__raza_imprimirMascotaConRaza(mascotalist+i,razalist,razalen,paisList,paisLen);

                   }
                }
            }
        }
        printf("\nel peso total es : %d",acumuladorPesos);
    }
    return retorno;
}


int mascota__raza_imprimirListaPorTipoYpeso(char tipo[128],mascota* mascotalist,raza* razalist,int mascotaslen,int razalen,pais *paisList,int paisLen,etipo *lista, int etipoLen)
{
    int retorno = -1;

    if(mascotalist != NULL && razalist != NULL && mascotaslen > 0 && razalen > 0)
    {
        printf("|\nel tipo es : %s \n",tipo);
        display_imprimirCabeceraMascotaWrazaYpais();
        char tipoActual[150];
        int acumuladorPesos=0 , pesoActual , isEmpty , contadorMascotas = 0,promedioPeso;
        for(int i = 0; i<mascotaslen;i ++)
        {
            if(mascota_getisEmpty(mascotalist+i,&isEmpty)== 0 && isEmpty == 0)
            {
                if( mascota_getDescripcionTipo(mascotalist+i,tipoActual,lista,etipoLen) == 0 && strcmp(tipoActual,tipo) == 0)
                {
                        mascota_getPeso(mascotalist+i,&pesoActual);
                        acumuladorPesos += pesoActual;
                        contadorMascotas++;
                        mascota__raza_imprimirMascotaConRaza(mascotalist+i,razalist,razalen,paisList,paisLen);
                }

            }
        }
        if(acumuladorPesos == 0)
        {
            printf("\nno existe ninguna mascota de este tipo.\n");
        }else
        {

            promedioPeso = acumuladorPesos / contadorMascotas;
            printf("\nel peso total es : %d\n y el promedio es: %d",acumuladorPesos,promedioPeso);
        }
    }
    return retorno;
}

int ordenarmascotasPorPais(mascota* mascotaslist,int mascotaslen,raza* razalist,int razalen,pais *paislist,int paislen,pais_pcomparar pfComparar)
{
    int retorno = -1;
    if(mascotaslist != NULL && mascotaslen > 0 && razalist != NULL && razalen >0 && paislist != NULL && paislen >0 &&  pfComparar != NULL)
    {
        int i,j;
       int isEmptyi,isEmptyj;
        raza *razai,*razaj;

        for(i = 0 ; i < mascotaslen-1;i++ )
        {
            for(j = mascotaslen ; j > i;j--)
            {

                if
                (
                     mascota_getisEmpty(mascotaslist+i,&isEmptyi) == 0 &&
                    isEmptyi == 0 &&
                    mascota_getisEmpty(mascotaslist+j,&isEmptyj) == 0 && isEmptyj == 0 &&
                    (razai = mascota_raza_getRazaOfMascota(mascotaslist+i,razalist,razalen)) != NULL &&
                    (razaj = mascota_raza_getRazaOfMascota(mascotaslist+j,razalist,razalen)) != NULL
                )
                {
                    pais *paisi,*paisj;
                    if
                    (
                            (paisi = raza_getpais(paislist,paislen,razai)) !=  NULL &&
                            (paisj = raza_getpais(paislist,paislen,razaj)) != NULL
                    )
                    {
                        if(pfComparar(paisi,paisj) < 0)
                        {
                            mascota_list_swap(mascotaslist+i,mascotaslist+j);
                            system("cls");
                            mascota__raza_imprimirLista(mascotaslist,razalist,mascotaslen,razalen,paislist,paislen);
                            system("pause");
                        }
                    }
                }
            }
        }
    }
    return retorno;
}


int ordenarMascotas(mascota* mascotaslist,int mascotaslen,raza* razalist,int razalen,pais *paislist,int paislen,mascota_pcomparar pfComparar)
{
    int retorno = -1;
    if(mascotaslist != NULL && mascotaslen > 0 && razalist != NULL && razalen >0 && paislist != NULL && paislen >0 &&  pfComparar != NULL)
    {
        int i,j;
       int isEmptyi,isEmptyj;

        for(i = 0 ; i < mascotaslen-1;i++ )
        {
            for(j = mascotaslen ; j > i;j--)
            {

                if
                (
                    mascota_getisEmpty(mascotaslist+i,&isEmptyi) == 0 && isEmptyi == 0 &&
                    mascota_getisEmpty(mascotaslist+j,&isEmptyj) == 0 && isEmptyj == 0
                )
                {

                 if(pfComparar(mascotaslist+i,mascotaslist+j) > 0)
                   {
                            mascota_list_swap(mascotaslist+i,mascotaslist+j);
                            system("cls");
                            mascota__raza_imprimirLista(mascotaslist,razalist,mascotaslen,razalen,paislist,paislen);
                            system("pause");
                   }

                }
            }
        }
    }
    return retorno;
}



int mascota_alta(mascota* mascotalist,int mascotalen,raza* razalist,int razalen,pais* listPaises,int lenpais,etipo *listetipo,int lenetipo)
{
    int retorno = -1;

    if(mascotalist != NULL && mascotalen> 0 && razalist != NULL && razalen > 0 && listPaises != NULL && lenpais >0)
    {

        mascota *this, auxMascota;
        int cantidadDeRazas;
        cantidadDeRazas = raza_list_cantidadDeRazas(razalist,razalen);
        if((this =  mascota_getEmptyElement(mascotalist,mascotalen)) != NULL)
        {
             if
             (
                mascota_setisEmpty(&auxMascota ,0)  == 0 &&
                mascota_setNewId(&auxMascota ,0)  == 0 &&
                mascota_ingresarInt("\ningrese la edad \n",200,0,&auxMascota,mascota_setEdad)  == 0 &&

                raza_list_imprimirLista(razalist,razalen,listPaises,lenpais)  == 0&&
                mascota_ingresarInt("\ningrese la id de la raza \n",cantidadDeRazas,1,&auxMascota,mascota_setIdRaza)  == 0 &&

                mascota_ingresarString("\ningrese el nombre \n",&auxMascota,mascota_setNombre)  == 0 &&

                mascota_ingresarInt("\ningrese el sexo: \n 1- macho \n 2- hembra \n",2,1,&auxMascota,mascota_setValidSexo)  == 0 &&
// TODO (arisp#1#): ingresar tipo
                etipo_imprimirLista(listetipo,lenetipo) == 0 &&
                mascota_ingresarInt("\ningrese el tipo: \n 1- perro \n 2-gato \n 3- raro\n",3,1,&auxMascota,mascota_setidTipo)  == 0
             )
             {
                *this = auxMascota;
                retorno = 0;
            }

        }
    }
    return retorno;
}




int mascota_modificar(mascota* mascotalist,int mascotalen,raza* razalist,int razalen,pais* listPaises,int lenpais)
{
    int retorno = -1;

    if(mascotalist != NULL && mascotalen> 0 && razalist != NULL && razalen > 0 && listPaises != NULL && lenpais >0)
    {
        mascota *this;
        int cantidadDeRazas =  0;
        int opcionIngresada = 0;
        int idIngresada;
        mascota_list_imprimirLista(mascotalist,mascotalen);
        if((idIngresada = display_GetInt("ingrese el id de la mascota a modificar ","\nid :","error! intente nuevamente",999,1,3)) > 0 )
        {
            if((this =  mascota_getBYId(mascotalist,mascotalen,idIngresada)) != NULL)
            {

                opcionIngresada = display_GetInt(
                                "\n 1- nombre"
                                "\n 2- raza"
                                "\n 3- sexo"
                                "\n 4- tipo"
                                "\n 5- edad"
                                "\n 6- salir",
                            "\ningrese una opcion","\nerror!,intente nuevamente",6,1,3);
                switch(opcionIngresada)
                {

                    case 1:
                         if( 0 == mascota_ingresarString("\ningrese el nombre \n",this,mascota_setNombre))
                         retorno = 0;
                        break;
                    case 2:
                        if
                        (
                            cantidadDeRazas = raza_list_cantidadDeRazas(razalist,razalen) > 0 &&
                            raza_list_imprimirLista(razalist,razalen,listPaises,lenpais) == 0 &&
                            mascota_ingresarInt("\ningrese la id de la raza \n",cantidadDeRazas,1,this,mascota_setIdRaza) == 0
                        )
                        retorno = 0;
                        break;
                    case 3:
                        if( 0 ==  mascota_ingresarInt("\ningrese el sexo: \n 1- macho \n 2- hembra \n",2,1,this,mascota_setValidSexo))
                        retorno = 0;
                        break;
                    case 4:
//                         if( 0 ==  mascota_ingresarInt("\ningrese el tipo: \n 1- perro \n 2-gato \n 3- raro\n",3,1,this,mascota_setValidTipo))
                         retorno = 0;
                        break;
// TODO (arisp#1#): ingresar tipo
                    case 5:
                        if( 0 ==  mascota_ingresarInt("\ningrese la edad \n",200,0,this,mascota_setEdad) )
                        retorno = 0;
                        break;
                }
            }
        }
    }
    return retorno;
}






int mascota__raza_imprimirRazaConMascotas(mascota* listMascota,raza* listRaza,int lenMascota,int lenraza,pais* listpais,int lenpais)
{
    int retorno = -1 ;
    if(listRaza != NULL && listMascota != NULL && lenraza > 0 && lenMascota > 0 && listpais != NULL && lenpais > 0 )
    {
        pais* paisActual;
        int  idRaza,idpais,i ,isEmptyraza;
        for(i = 0 ; i<lenraza ; i++)
        {
            raza_getisEmpty(listRaza+i,&isEmptyraza);
            if(isEmptyraza == 0)
            {


                   if( raza_getidPais(listRaza+i,&idpais) == 0 )
                   {

                        if((paisActual = raza_getpaisbyId(listpais,lenpais,idpais)) != NULL )
                        {
                            if( raza_imprimirRaza(listRaza+i,paisActual) == 0)
                            {
                                raza_getId(listRaza+i,&idRaza);
                                mascota_printIfIdrazaIs(listMascota,lenMascota,idRaza);
                            }
                        }
                   }
            }
        }
    }
return retorno;
}

int mascota_printIfIdrazaIs(mascota *list ,int len,int id)
{
    int retorno = -1 ;
    if(list != NULL && len > 0 && id > 0)
    {
        display_imprimirCabeceraMascota();
        int i,idraza;
        for( i = 0 ; i<len;i++)
        {
            if(mascota_getIdRaza(list+i,&idraza) == 0)
            {

                if(idraza == id)
                {
                    mascota_imprimirMascota(list+i);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


int mascota_bajaIfIdrazaIs(mascota *list ,int len,int id)
{
    int retorno = -1 ;
    if(list != NULL && len > 0 && id > 0)
    {

        int i,idraza;
        for( i = 0 ; i<len;i++)
        {
            if(mascota_getIdRaza(list+i,&idraza) == 0)
            {

                if(idraza == id)
                {

                    mascota_bajaLogica(list,len,i);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

