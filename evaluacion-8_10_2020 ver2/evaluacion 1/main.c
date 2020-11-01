#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "listasEstaticas.h"
#include "controller.h"

/*
*Arispe Matias
evaluacion 1;
-memoria estatica solamente-

#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas pero tengo lugar para 10.

#Tenemos un listado de razas(descripci�n,tama�o{chico ,mediano o grande},pa�s de
origen)
listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, b�lgica

las 5 mascotas est�n formadas por los siguientes datos:
a- 2 gatos
b- 3 perros

c- los dem�s datos de estas 5 mascotas deben ser hardcodeados por el alumno.


1-Se debe mostrar un listado de mascotas con sus razas y pa�ses de origen .

*el harcodeo debe estar en funciones separadas .

*la funci�n de listar mascota debe estar modularizada, �sea debe llamar a otras
funciones y no realizar dos for.
*/

#define LENMASCOTAS 10


int main()
{

    printf("evaluacion 1 !\n");



    mascota listMascotas[LENMASCOTAS];

    mascotas_list_inicializarIsEmpty(listMascotas,LENMASCOTAS);

    mascotas_list_cargarLista("mascotas.csv",listMascotas,LENMASCOTAS);

    mascota_list_imprimirLista(listMascotas,LENMASCOTAS);






    return 0;
}
