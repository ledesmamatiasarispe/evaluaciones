#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"
#include "controler.h"
//#include "raza_list.h"

#include "mascotas_raza.h"
#include "utn.h"
#include "display.h"
#include "pais.h"
/*
*Arispe Matias
evaluacion 1;


-memoria estatica solamente-
-no objetos-
-archivos, para evitar funciones de hardcodeo y poder guardar lo que se ingreso


#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas pero tengo lugar para 10.

#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de
origen)
listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica

las 5 mascotas están formadas por los siguientes datos:
a- 2 gatos
b- 3 perros
c- los demás datos de estas 5 mascotas deben ser hardcodeados por el alumno.
1-Se debe mostrar un listado de mascotas con sus razas y países de origen .
*el harcodeo debe estar en funciones separadas .
*la función de listar mascota debe estar modularizada, ósea debe llamar a otras
funciones y no realizar dos for.

*----------------------------------2da parte----------------------------------------------------------
#Borrado lógico de una mascota del listado
#-Se debe mostrar un listado de mascotas ordenadas por país de origen.


* --------------------------------3era parte-----------------------------------
#-Alta de mascota, se pueden cargar todos los datos y se debe mostrar el listado de
razas disponibles, teniendo en cuenta que ya tengo 5 mascotas cargadas y que el
máximo es 10
#-Se debe mostrar un listado de RAZAS con las mascotas que pertenecen a esa
raza
*---------------------------------4ta parte-------------------------------------
#Modificación de una mascotas(todo menos el id).

#Menú de opciones
#-Alta de RAZA (20 razas máximo)

#-Se debe mostrar el país de origen que tenga más mascotas en nuestra
veterinaria. falta

------------------------------------------------5ta parte------------------------
excluyente :
#Menú de opciones,con todas las opciones pedidas en las partes anteriores
Se nos agregaron dos mascotas más , un dogo argentino y un pastor alemán,
debemos hardcodear las nuevas razas.

Vamos a tener que realizar la estructura pais,
con:(nombreDePais,continente,CodigoTelefonico)argentina =54 , alemania= 49,
belgica =32, tailandia=66,persia=98.

se deben modificar las estructuras y las funcionalidades,
no se pueden tener campos de la versión anterior en las estructuras.

debemos tener hardcodeado los datos de las 7 mascotas
incluyendo los países y la relación con la raza y el atributo peso


#Opción del menú Alta de RAZA:
dar de alta una raza, mostrando el listado de países disponibles.

#-Opción del menú Listar mascota con la raza y los datos del pais (nombrePais,
CodigoTelefonico)

#-Opción del menú ordenar mascotas por el Código Telefónico del país, de mayor
a menor.

********************************6ta parte
#-Opción Listar por TAMAÑO y PESO:

-Sabiendo que solo hay tres tamaños(tamaño{chico ,mediano o grande}),pedir
el ingreso al usuario de un tamaño válido y mostrar el listado de mascotas de este
tamaño con sus países de origen peso y la suma total del peso entre estas mascotas.


******************************** 7ma parte
#Opción borrar RAZA:
borrado en cascada de una raza, al borrar una raza , se borran todas las
mascotas de esa raza

#-Opción Listar por TIPO y PESO:
Sabiendo que solo hay tres tipos de mascotas (tipo{gato ,perro o raro}),
informar el peso total de cada tipo, la cantidad de mascotas por tipo y el promedio de
peso por tipo.Estos tres datos en una tabla bien hecha.











------------------falta

#-Se debe mostrar el país de origen que tenga más mascotas en nuestra
veterinaria.

#-Se debe mostrar un listado de mascotas ordenadas por país de origen. esta en opcion 8 pero no funciona

*/

#define LENMASCOTAS 15
#define LENRAZA 10
#define LENPAIS 10
#define LENTIPO 3
int main()
{

    mascota listMascotas[LENMASCOTAS];
    raza listRazas[LENRAZA];
    pais listPaises[LENPAIS];
    etipo listTipo[LENTIPO];

    mascotas_list_inicializarIsEmpty(listMascotas,LENMASCOTAS);
    mascotas_list_cargarLista("mascotas.csv",listMascotas,LENMASCOTAS);

    raza_list_inicializarIsEmpty(listRazas,LENRAZA);
    raza_list_cargarLista("razas.csv",listRazas,LENRAZA);

    pais_list_inicializarIsEmpty(listPaises,LENPAIS);
    pais_list_cargarLista("paises.csv",listPaises,LENPAIS);

    etipo_list_inicializarIsEmpty(listTipo,LENTIPO);
    etipo_cargarLista("tipos.csv",listTipo,LENTIPO);
    printf("evaluacion 1 !\n");
    int opcionIngresada;
    do{

            //clearScreen();
            opcionIngresada = display_GetInt(
                                    "\n 1-  alta mascota"
                                    "\n 2-  modificar mascota"
                                    "\n 3-   baja de mascotas"
                                    "\n 4-  listar mascotas"
                                    "\n 5-  listar razas"
                                    "\n 6-  ordenar por codigo telefonico"
                                    "\n 5-  listar razas"
                                    "\n 7-   listar mascotas su raza"
                                    "\n 8-   ordenar mascotas por su pais de origen"
                                    "\n 9-   alta de raza"
                                    "\n 10-  listar paises"
                                    "\n 11-  baja raza "
                                    "\n 12-  imprimir por tamanio y peso"
                                    "\n 13- imprimir por tipo y peso"
                                    "\n 20- salir\n",
                        "\ningrese una opcion","\nerror!,algo salio mal",20,1,3);
            switch(opcionIngresada)
            {

                case 1 :
                    mascota_alta(listMascotas,LENMASCOTAS,listRazas,LENRAZA,listPaises,LENPAIS,listTipo,LENTIPO);
                    break;
                case 2:
                    mascota_modificar(listMascotas,LENMASCOTAS,listRazas,LENRAZA,listPaises,LENPAIS);
                    break;

                case 3:
                    // estba por agregar un confirm para revisar si quiere eliminar la mascota de veritas
                    controler_BajaMascota(listMascotas,LENMASCOTAS);
                    break;
                case 4:
                    mascota__raza_imprimirLista(listMascotas,listRazas,LENMASCOTAS,LENRAZA,listPaises,LENPAIS);
                    break;
                case 5:
                    raza_list_imprimirLista(listRazas,LENRAZA,listPaises,LENPAIS);
                    break;
                case 6:
                          ordenarmascotasPorPais(listMascotas,LENMASCOTAS,listRazas,LENRAZA,listPaises,LENPAIS,pais_pcompararCodigoTelefonico);
                    break;


                case 7://falta que quede lindo
                    mascota__raza_imprimirRazaConMascotas(listMascotas,listRazas,LENMASCOTAS,LENRAZA,listPaises,LENRAZA);
                    break;

                case 8:
                    ordenarmascotasPorPais(listMascotas,LENMASCOTAS,listRazas,LENRAZA,listPaises,LENPAIS,pais_pcompararPorPais);
                    break;
                case 9:
                    raza_alta(listRazas,LENRAZA,listPaises,LENPAIS);
                    break;
                case 10:
                   pais_list_imprimirLista(listPaises,LENPAIS);
                    break;
                case 11:
                    controler_BajaRaza(listMascotas,LENMASCOTAS,listRazas,LENRAZA,listPaises,LENPAIS);

                    break;
                case 12:
                    controler_opcion12_imprimirPorTamanioYpeso(listMascotas,listRazas,LENMASCOTAS,LENRAZA,listPaises,LENRAZA);
                    break;
                case 13:
                    controler_opcion13_imprimirPorTipoYpeso(listMascotas,listRazas,LENMASCOTAS,LENRAZA,listPaises,LENRAZA);
                    break;
                case 14:
                    ordenarMascotas(listMascotas,LENMASCOTAS,listRazas,LENRAZA,listPaises,LENPAIS,compararPorTipoYPeso);
                    break;
                case 15:

                    break;
                case 16:
                        etipo_imprimirLista(listTipo,LENTIPO);
                    break;
            }

            pause();
        }while(opcionIngresada != 20);


    return 0;
}
