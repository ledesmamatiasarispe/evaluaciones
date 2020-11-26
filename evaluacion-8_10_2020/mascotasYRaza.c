
#include "mascotasYRaza.h"


int mostrarMascotasConRazaYPaisDeOrigen(eAnimales listaAnimales[],eRaza listaRaza[],int lenghtAnimales,
                                        int lenghtRaza,ePais listaPais[],int lenghtpais)
{
       int retorno = -1;
        if(listaAnimales!=NULL&&listaRaza!=NULL)
        {
            clearScreen();
            int i;
            eRaza aux;
            ePais auxPais;
          for(i=0;i<lenghtAnimales;i++)
          {
              if(listaAnimales[i].isEmpty==FALSE)
              {
                  aux = getRaza(listaAnimales[i].idRaza,listaRaza,lenghtRaza);
                 auxPais = getpais(aux.idPais,listaPais,lenghtpais);
                  printf("\n");
                   printf("%20d | %20s | %20s | %20s",listaAnimales[i].iDAnimales,listaAnimales[i].nombre,aux.descripcion,auxPais.nombre);


              }
          }
        }
return retorno;
    }


eRaza getRaza(int idRaza,eRaza listaRaza[],int lenghtRaza)
{
    eRaza aux;
    if(listaRaza!=NULL&&idRaza>-1&&lenghtRaza)
        {
            int i;
            for(i=0;i<lenghtRaza;i++)
            {
                if(idRaza==listaRaza[i].idRaza)
                {
                    aux = listaRaza[i];
                    break;
                }
            }

        }
    return aux;
}

ePais getpais(int idABuscar,ePais lista[],int lenght)
{
    ePais aux;
    if(lista!=NULL&&idABuscar>-1&&lenght)
        {
            int i;
            for(i=0;i<lenght;i++)
            {
                if(idABuscar==lista[i].idPais)
                {
                    aux = lista[i];
                    break;
                }
            }
        }
    return aux;
}

int ordenarPorPaisDeOrigen(eAnimales* listaAnimales,eRaza listaRaza[],int lenghtAnimales,int lenghtRaza)
{

    int retorno=-1;

    if(listaAnimales != NULL && listaRaza != NULL && lenghtAnimales >0 && lenghtRaza >0)
    {
        retorno=0;


        eRaza auxRazaDelAnimal_i, auxRazaDelAnimal_j;
        int j,i;

        for(i=0;i<lenghtAnimales;i++)
        {
           if(listaAnimales[i].isEmpty==1)
           {
                continue;
           }
             for(j=0;j<lenghtAnimales;j++)
             {
                  if(listaAnimales[j].isEmpty==1)
                {
                    continue;
                }else
                 {
                    auxRazaDelAnimal_i = getRaza(listaAnimales[i].idRaza,listaRaza,lenghtRaza);
                    auxRazaDelAnimal_j = getRaza(listaAnimales[j].idRaza,listaRaza,lenghtRaza);

                    if(strcmp(auxRazaDelAnimal_i.paisDeOrigen,auxRazaDelAnimal_j.paisDeOrigen)<0)
                    {
                      swapearAnimales(listaAnimales,lenghtAnimales,i,j);
                    }

                 }
             }
        }



    }
return retorno;
}


int altaAnimal(eRaza* listaRaza,int lenghtRaza,eAnimales* listaAnimales,int lenghtAnimales)
{

    int retorno;

    eAnimales auxAnimal;
        auxAnimal.isEmpty = 0;
        ani_SetId(&auxAnimal,-1);

    if(ingrezarRazaDelAnimal("\ningrese el id de la raza del animal","\nerror! intente denuevo",&auxAnimal.idRaza,0,10,3,listaRaza,lenghtRaza)==1 &&
        getValidNames("\ningrese el nombre de el animal","\nerror! intente denuevo","\nerror! se ha superado el limite de letras"
                      ,&auxAnimal.nombre,50,3) == 0&&
        getValidInt("\ningrese la edad del animal","\nerror! intente denuevo",&auxAnimal.edad,0,300,3) == 0 &&
        getValidSex("\ningrese el sexo del animal (f/m)","\nerror! intente denuevo",&auxAnimal.sexo,3) == 0 &&
       getTipoDeAnimal("\ningrese tipo de animal gato","\nerror! intente denuevo",auxAnimal.tipo,1,3,3) == 1
      )
        {

             retorno =  asginarDatosMascota(listaAnimales,lenghtAnimales,&auxAnimal);

        }



 return retorno;
}


int altaRaza(eRaza* listaRaza,int lenghtRaza,eAnimales listapaises[],int lenghtPais)
{

    int retorno;

    eRaza auxRaza;
        auxRaza.isEmpty = 0;
        raz_SetId(&auxRaza,-1);

    if(
        getValidNames("\ningrese la el nombre de la raza","\nerror! intente denuevo","\nerror! se ha superado el limite de letras"
                      ,auxRaza.descripcion,50,3) == 0&&
       getValidNames("\ningrese el tamanio de la raza","\nerror! intente denuevo","\nerror! se ha superado el limite de letras"
                      ,auxRaza.tamanio,50,3) == 0&&
       ingrezarPaisDeOrigen("\ningrese el pais de origen de la raza","\nerror! intente denuevo"
                      ,auxRaza.paisDeOrigen,0,50,3,listapaises,lenghtPais) == 1
        )
        {
             retorno =  asginarDatosRaza(listaRaza,lenghtRaza,&auxRaza);
        }



 return retorno;
}


/** @brief
 *
 * @param
 * @param
 * @return retorna -1 si no validaron los parametros o se pasaron los reintentos, 0 si valido el numero ingreado y 1 si la raza ingresada existe
 *
 */
int ingrezarRazaDelAnimal(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,
                          int attemps,eRaza* listaRaza,int lenghtRaza)
{
    int retorno=-1;
    if(requestMessage != NULL && errorMessage != NULL && input != NULL && lowLimit <= hiLimit && attemps >0 &&listaRaza!=NULL/*&&lenghtRaza>0*/)
    {
         imprimirTodasLasRazas(listaRaza,lenghtRaza);
        if(getValidInt(requestMessage, errorMessage, input , lowLimit, hiLimit,attemps)==0)
        {
              retorno = 0;
              if(validarRazaIngresada(*input,listaRaza,lenghtRaza)==0)
              {
                  retorno = 1;
              }
        }
    }
    return retorno;
}

int ingrezarPaisDeOrigen(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,
                          int attemps,eRaza* listaPaises,int lenghtPais)
{
    int retorno=-1;

    if(requestMessage != NULL && errorMessage != NULL && input != NULL && lowLimit <= hiLimit && attemps >0 &&listaPaises!=NULL &&lenghtPais>0)
    {
         imprimirTodosLosPaises(listaPaises,lenghtPais);
        if(getValidInt(requestMessage, errorMessage, input , lowLimit, hiLimit,attemps)==0)
        {
              retorno = 0;
              if(validarPaisIngresado(*input,listaPaises,lenghtPais)==0)
              {
                  retorno = 1;
              }
        }
    }
    return retorno;
}


int validarPaisIngresado(int idPais,ePais listaPaises[],int lenght)
{
    int aux= -1 ;
    if(listaPaises!=NULL&&idPais>-1&&lenght>0)
        {
            int i;
            for(i=0;i<lenght;i++)
            {
                if(idPais==listaPaises[i].idPais)
                {
                    aux = 0;
                    break;
                }
           }
        }
    return aux;
}

int validarRazaIngresada(int idRaza,eRaza listaRaza[],int lenghtRaza)
{
    int aux= -1 ;
    if(listaRaza!=NULL&&idRaza>-1&&lenghtRaza>0)
        {
            int i;
            for(i=0;i<lenghtRaza;i++)
            {
                if(idRaza==listaRaza[i].idRaza)
                {
                    aux = 0;
                    break;
                }
           }
        }
    return aux;
}

int getTipoDeAnimal(char requestMessage[],char errorMessage[],char output[],int lowLimit, int hiLimit,int attemps)
{
    int retorno=-1;
    if(requestMessage!=NULL && errorMessage != NULL && lowLimit <= hiLimit &&attemps >0)
    {
        int inputTipo;

        retorno=0;

             getValidInt( requestMessage, errorMessage, &inputTipo, lowLimit,  hiLimit, attemps);

        switch(inputTipo)
        {
            case 1:
                strncpy(output,"perro",15);
                retorno=1;
                break;
            case 2:
                strncpy(output,"gato",15);
                retorno=1;
                break;
            case 3:
                strncpy(output,"raro",15);
                retorno=1;
                break;
        }

    }

return retorno;
}


int mostrarRazasYsusAnimales(eAnimales listaAnimales[],eRaza listaRaza[],int lenghtAnimales,int lenghtRaza)
{
       int retorno = -1;
        if(listaAnimales!=NULL&&listaRaza!=NULL)
        {
            clearScreen();
            int i;
            int largoDeListaIndex;
            eAnimales listaDeIndexDeLosAnimalesDeLaRaza[lenghtAnimales];

          for(i=0;i<lenghtRaza;i++)
          {
              if(listaRaza[i].isEmpty==0)
              {
                imprimirUnaRaza(listaRaza+i,0);

                largoDeListaIndex = getAnimalesDeUnaRaza(listaRaza[i].idRaza,lenghtAnimales,listaAnimales,listaDeIndexDeLosAnimalesDeLaRaza);

                imprimirTodosLosAnimales
                (listaDeIndexDeLosAnimalesDeLaRaza,largoDeListaIndex);
              }
          }
        }
return retorno;
    }

 /** \brief
  *
  * \param idRaza int
  * \param lenghtAnimales int
  * \param listaAnimales[] eAnimales
  * \param arrayAnimalesDeRaza[] eAnimales
  * \return int -1 param invalidos- 0 parametros correctos- >= 1 la cantidad de veces que se encuentra un animal de la raza
  *
  */
 int  getAnimalesDeUnaRaza(int idRaza,int lenghtAnimales,eAnimales listaAnimales[],eAnimales arrayAnimalesDeRaza[])
 {
     int retorno=-1;
    if(listaAnimales != NULL && lenghtAnimales >0 && arrayAnimalesDeRaza != NULL)
    {

        retorno=0;
        int i;
        int j=0;
        for( i= 0 ; i < lenghtAnimales ; i++)
        {

            if(listaAnimales[i].idRaza==idRaza && listaAnimales[i].isEmpty == 0)
            {
                arrayAnimalesDeRaza[j] = listaAnimales[i];
                j++;
            }
        }
        retorno=j;
    }
     return retorno;
 }











int modificarDatosMascota(eRaza* listaRaza,int lenghtRaza,eAnimales* listaAnimales,int lenghtAnimales)
{
    int retorno;
    int opcionSeleccionada;
    int idIngresada;
    int indexDelAnimalAModificar;
    eAnimales auxAnimal;

    getValidInt("\ingrese el id de el animal A modificar\n","error,intente de nuevo",&idIngresada,0,lenghtAnimales,3);

    indexDelAnimalAModificar = findById(listaAnimales,lenghtAnimales,idIngresada);

    if(indexDelAnimalAModificar==-1)
    {
        retorno = -2;
    }else
      {
              imprimirUnAnimal(listaAnimales+indexDelAnimalAModificar,0);

        if(getChar("\ndesea modificar este animal ?(S/n)\n [ ]\b\b")=='n')
            {
                retorno=-1;
            }else
             {
                 auxAnimal=listaAnimales[indexDelAnimalAModificar];

                 menuDisplayModificaciones();

                 getValidInt("\nelija una opcion\n","error,intente de nuevo",&opcionSeleccionada,1,5,3);

                switch(opcionSeleccionada)//"1- Raza","2- Nombre","3- Edad","4- Sexo","5- TIPO ","6- salir"
                {
                    case 1:
                        ingrezarRazaDelAnimal("\ningrese el id de la raza del animal","\nerror! intente denuevo",&auxAnimal.idRaza,0,10,3,listaRaza,lenghtRaza);
                        retorno=0;
                        break;
                    case 2:
                        getValidNames("\ningrese el nombre de el animal","\nerror! intente denuevo","\nerror! se ha superado el limite de letras"
                                  ,&auxAnimal.nombre,50,3);
                        retorno=0;
                        break;
                    case 3:
                        getValidInt("\ningrese la edad del animal","\nerror! intente denuevo",&auxAnimal.edad,0,300,3);
                        retorno=0;
                        break;
                    case 4:
                         getValidSex("\ningrese el sexo del animal (f/m)","\nerror! intente denuevo",&auxAnimal.sexo,3);
                         retorno=0;
                         break;
                    case 5:
                        getTipoDeAnimal("\ningrese tipo de animal gato","\nerror! intente denuevo",auxAnimal.tipo,1,3,3);
                        retorno=0;
                        break;
                  }


                   listaAnimales[indexDelAnimalAModificar] = auxAnimal;

                }



        }
 return retorno;
}
