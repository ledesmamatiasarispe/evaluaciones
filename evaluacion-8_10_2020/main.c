#include <stdio.h>
#include <stdlib.h>
#define lenAnimales 10
#define lenRaza 20
#define lenPaises 10
#include "utn.h"
#include "mascotasYRaza.h"
#include "paises.h"


/*
Soy un veterinario que necesita atender a las mascotas de sus clientes,
 para tener el control vamos a tener un sistema ....el sistema debe realizar
 las siguientes funcionalidades.(los datos deben ser hardcodeados).
******************************** 1era parte
#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas ​pero tengo lugar para 10.
#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de origen)
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
*la función de listar mascota debe estar modularizada, ósea debe llamar a otras funciones y no realizar dos for.

******************************** 2da parte
#Borrado lógico de una mascota del listado
#-Se debe mostrar un listado de mascotas ordenadas por país de origen.


 ******************************** 3era parte
#-Alta de mascota, se pueden cargar todos los datos y se debe mostrar
 el listado de razas disponibles, teniendo en cuenta que ya tengo 5 mascotas cargadas y que el máximo es 10
#-Se debe mostrar un listado de RAZAS con las mascotas que pertenecen a esa raza

******************************** 4ta parte
#Modificación de una mascotas(todo menos el id).
#Menú de opciones
#-Alta de RAZA (20 razas maximo)
#-Se debe mostrar el país de origen que tenga más mascotas en nuestra veterinaria.
******************************** 5ta parte
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
*/

int main()
{
     eAnimales listaDeAnimales[lenAnimales];
     eRaza listaDeRazas[lenRaza];
     ePais listaDePaises[lenPaises];

    initAnimales(listaDeAnimales,lenAnimales);
    initRaza(listaDeRazas,lenRaza);
    initPaiz(listaDePaises,lenPaises);

    hardcodearAnimales(listaDeAnimales);
    hardcodearRaza(listaDeRazas);
    hardcodearPais(listaDePaises);
    int auxIndex;
int opcionSeleccionada;
    do{

        system("cls");
        menuDisplay();
        getValidInt("\nelija una opcion\n","error,intente de nuevo",&opcionSeleccionada,1,9,3);

        switch(opcionSeleccionada)
        {
            case 1:

            altaAnimal(listaDeRazas,lenRaza,listaDeAnimales,lenAnimales);

                 break;
            case 2:
                system("cls");
                 if( modificarDatosMascota(listaDeRazas,lenRaza,listaDeAnimales,lenAnimales)==-2)
                 {
                    printf("\nno existe ningun animal econ ese id\n");
                 }


            system("pause");
                 break;
            case 3://borrar mascota
            getValidInt("\ningrese el id de la mascota a eliminar","\nerror valor ingresado invalido.",&auxIndex,0,lenAnimales,2);
            removeAnimal(listaDeAnimales,lenAnimales,auxIndex);
                break;
            case 4://mostrar listado de mascotas ordenadas por país de origen

                mostrarMascotasConRazaYPaisDeOrigen(listaDeAnimales,listaDeRazas,lenAnimales,lenRaza,listaDePaises,lenPaises);
                printf("\n");
                system("pause");
                break;
            case 5:
                mostrarRazasYsusAnimales(listaDeAnimales,listaDeRazas,lenAnimales,lenRaza);
                system("pause");
                break;
            case 6:
                altaRaza(listaDeRazas,lenRaza,listaDePaises,lenPaises);
                break;
            case 7:
                ordenarPorPaisDeOrigen(listaDeAnimales,listaDeRazas,lenAnimales,lenRaza);
                break;
        }
    }while(opcionSeleccionada!=9);

    return 0;
}
