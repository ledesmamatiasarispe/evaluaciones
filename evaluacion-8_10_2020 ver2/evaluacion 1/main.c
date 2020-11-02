#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"
#include "controller.h"
#include "raza_list.h"
#include "mascotas_list.h"
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

--------------parte 2----------------------------------------------------------
#Borrado lógico de una mascota del listado
#-Se debe mostrar un listado de mascotas ordenadas por país de origen.
*/

#define LENMASCOTAS 10
#define LENRAZA 5

int main()
{


    mascota listMascotas[LENMASCOTAS];
    raza listRazas[LENRAZA];

    mascotas_list_inicializarIsEmpty(listMascotas,LENMASCOTAS);
    mascotas_list_cargarLista("mascotas.csv",listMascotas,LENMASCOTAS);

    raza_list_inicializarIsEmpty(listRazas,LENRAZA);

    raza_list_cargarLista("razas.csv",listRazas,LENRAZA);


    printf("evaluacion 1 !\n");
    int opcionIngresada;
    do{
    opcionIngresada = display_GetInt("\n 1-alta mascota\n"
                                     "\n 2-baja de mascotas\n"
                                     "\n 3-listar mascotas\n"
                                     "\n 4-listar razas\n"
                                     "\n 5- punto (1) listar mascotas sus razas\n"
                                     "\n 6-salir\n",
                        "\ningrese una opcion","\nerror!,algo salio mal",6,1,3);

    switch(opcionIngresada)
    {
        case 2:
            // estba por agregar un confirm para revisar si quiere eliminar la mascota de veritas
           controler_BajaMascota(listMascotas,LENMASCOTAS);
           break;
        case 3:
            mascota_list_imprimirLista(listMascotas,LENMASCOTAS);
            break;
        case 4:
            raza_list_imprimirLista(listRazas,LENRAZA);
            break;
        case 5:
            mascota__raza_imprimirLista(listMascotas,listRazas,LENRAZA,LENMASCOTAS);
            break;




    }


    }while(opcionIngresada != 6);


    return 0;
}
