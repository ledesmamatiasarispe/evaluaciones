#include <stdio.h>
#include "display.h"
#include "utn.h"


void employee_imprimirLaCabezeraDeLista()
{
      int ll = 186;
        display_topTabla();
        printf("%c %-10s %c %-20s %c %-10s %c %-20s %c \n",ll,"ID",ll,"Nombre",ll,"Sueldo",ll,"Horas Trabajadas",ll);
        display_divisorCabezera();
}

void display_divisorCabezera(void)
{
display_imprimirUnCharVariasVeces(204,1);
display_imprimirUnCharVariasVeces(205,12);/*primer int */
display_imprimirUnCharVariasVeces(206,1);
display_imprimirUnCharVariasVeces(205,22);/*nombre */
display_imprimirUnCharVariasVeces(206,1);
display_imprimirUnCharVariasVeces(205,12);/*segundo int */
display_imprimirUnCharVariasVeces(206,1);
display_imprimirUnCharVariasVeces(205,22);/*tercer int */
display_imprimirUnCharVariasVeces(185,1);

display_imprimirUnCharVariasVeces(10,1);
}

void display_imprimirElFinalDeTabla(void)
{
display_imprimirUnCharVariasVeces(200,1);
display_imprimirUnCharVariasVeces(205,12);/*primer int */
display_imprimirUnCharVariasVeces(202,1);
display_imprimirUnCharVariasVeces(205,22);/*nombre */
display_imprimirUnCharVariasVeces(202,1);
display_imprimirUnCharVariasVeces(205,12);/*segundo int */
display_imprimirUnCharVariasVeces(202,1);
display_imprimirUnCharVariasVeces(205,22);/*tercer int */
display_imprimirUnCharVariasVeces(188,1);

display_imprimirUnCharVariasVeces(10,1);
}

void display_topTabla(void)
{
display_imprimirUnCharVariasVeces(10,1);
display_imprimirUnCharVariasVeces(201,1);
display_imprimirUnCharVariasVeces(205,12);/*primer int */
display_imprimirUnCharVariasVeces(203,1);
display_imprimirUnCharVariasVeces(205,22);/*nombre */
display_imprimirUnCharVariasVeces(203,1);
display_imprimirUnCharVariasVeces(205,12);/*segundo int */
display_imprimirUnCharVariasVeces(203,1);
display_imprimirUnCharVariasVeces(205,22);/*tercer int */
display_imprimirUnCharVariasVeces(187,1);

display_imprimirUnCharVariasVeces(10,1);
}

void display_imprimirUnCharVariasVeces(int caracter, int cantidad)
{
    int i=0;
    for(;i < cantidad;i++){
        printf("%c",caracter);
    }
}


void imprimirOpciones(char opciones[])
{

    printf("\n %s \n " , opciones);

}

void imprimirProgreso(int progresoActual,int cantidadTotal)
{
    if( progresoActual % (cantidadTotal/20) == 0 || progresoActual == cantidadTotal-2)
    {
        clearScreen();
        int porcentajeDeProgreso = (progresoActual*100)/cantidadTotal+1;

        printf(" %d %c  ",porcentajeDeProgreso,37);
        display_imprimirUnCharVariasVeces(220,porcentajeDeProgreso);
        display_imprimirUnCharVariasVeces(32,(100-porcentajeDeProgreso));
        display_imprimirUnCharVariasVeces(219,1);
    }
}


int display_GetInt(char mensaje[],char pregunta[],char mensajeError[],int max,int min,int intentos)
{
    int retorno;
    if(mensaje != NULL && pregunta != NULL && mensajeError != NULL)
    {
        imprimirOpciones(mensaje);
        if( getValidInt(pregunta,mensajeError,&retorno,min,max,intentos) != 0)
        {
            retorno = min - 1;
        }
    }
return retorno;
}


void display_imprimirCabeceraMascota()
{
    printf("\n%10-s, %10-s , %10-s , %10-s , %10-s , %10-s ","Id","IdRaza","Edad","Nombre","Sexo","Tipo");
}

int display_imprimirUnaMascota(int auxId,int auxIdRaza,int auxEdad, char auxNombre[],char auxSexo[],char auxTipo[])
{

    int retorno = -1;
    if(auxid > 0 && auxIdRaza > 0 && auxEdad > 0 && auxNombre != NULL&& auxSexo != NULL&& auxTipo != NULL)
    {
        printf("\n%10d, %10d , %10d , %10s , %10s , %10s ",auxId,auxIdRaza,auxEdad,auxNombre,auxSexo,auxTipo);
        retorno = 0;
    }

    return retorno;
}







