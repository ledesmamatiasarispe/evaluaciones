#include "control.h"


void menuDisplay(void){

    char lista[9][70]={"1- Alta Animal","2- MODIFICAR","3- BAJA","4- LISTADO Nombre de mascota,raza,pais De Origen ","5- LISTADO De mascotas por raza","6- Alta Raza","7- ordenar por pais de origen","9- salir"};

    for(int i=0; i<9 ; i++)
    {
        printf("\n %-70s", lista[i]);
    }
}

void menuDisplayModificaciones(void){

    char lista[9][70]={"1- Raza","2- Nombre","3- Edad","4- Sexo","5- TIPO ","9- salir"};

    for(int i=0; i<9 ; i++)
    {
        printf("\n %-70s", lista[i]);
    }
}

void pausarYBorrar(void)
{
    puts("\n");
    system("pause");
    system("cls");
}




