#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  float CalcularTotalFactura( float subtotal, int porcentajeDescuento, int porcentajeIva);
int main()
{
    ///punto1
    float subtotal = 100;
    float total;

    total = CalcularTotalFactura(subtotal,0,0);

    printf(" %f \n",total);

    ///punto2

    int array [9] = {-5,3,-4,2,1,-2,-3,-1,7};



    ordenarAray(array,9);

    printf("\n");




    ///punto3
    char cadena[] = "perro";

    printf("%s\n",cadena);

    invertirCadena(cadena,strlen(cadena));

    printf("%s\n",cadena);



    return 0;
}
/*
 Crear una función llamada CalcularTotalFactura, que tenga el siguiente prototipo.
    float CalcularTotalFactura( float subtotal, int porcentajeDescuento, int porcentajeIva);
     La función deberá retornar el total facturado, aplicando el porcentaje de descuento y luego el iva.
     Realizar la llamada desde main.
     */
float CalcularTotalFactura( float subtotal, int porcentajeDescuento, int porcentajeIva)
    {
        float total;
        if(subtotal > 0 && porcentajeDescuento >= 0 && porcentajeDescuento < 100 && porcentajeIva >= 0 && porcentajeIva < 100)
        {
            total=subtotal;
           if(porcentajeDescuento != 0)
            {
                total -= (subtotal * ((float)porcentajeDescuento / 100));
            }

            if(porcentajeDescuento != 0)
            {
                total += ((float)porcentajeIva / 100) * subtotal;
            }
        }
        return total;
    }

/*
3. Realizar una función que reciba UNICAMENTE una cadena de caracteres.
 La función deberá invertir el orden de los caracteres. Por ejemplo: si se ingresa la palabra Perro,
 la cadena deberá guardar orreP. Mostrar la cadena invertida desde el main. */

int invertirCadena(char* cadena,int len)
{
    int retorno=-1;
    if(cadena != NULL && len > 0)
    {
        retorno =0;
        char cadenaAUX[len];
        int i,j;
        for(i = len-1,j=0 ; i >= 0 ; i--,j++)
        {
            cadenaAUX[j] = cadena[i];
        }
        strncpy(cadena,cadenaAUX,len);
    }
    return retorno;
}
/*
2. Realizar una función que reciba un array de enteros,
dicha función deberá mostrar el array ordenado de la siguiente forma:
     Los negativos de forma decreciente y los positivos de forma creciente.
      Se podrán usar como máximo 4 estructuras repetitivas para resolver el ejercicio. *
*/

   int   ordenarAray(int *array,int len)
   {
        int retorno = -1;
        if(array != NULL && len > 0)
        {
            retorno= 0;
            int i,j,k,l;
            for( i=0;i<len-1;i++)
            {
                for(j = i+1;j < len;j++)
                {
                    if(array[i] > 0 && array[j]>0 && array[i] > array[j] || array[i] < array[j] )
                    {
                        SwapArray(array+i,array+j);
                    }
                }
            }
            imprimirarray(array,len);
        }
return retorno;
   }


   int SwapArray(int *varuno,int *vardos)
   {
       int retorno = -1;
       if(varuno != NULL && vardos != NULL)
       {
           retorno = 0;
           int aux;
           aux = *varuno;
           *varuno = *vardos;
           *vardos = aux;
       }
    return retorno;
   }

  void imprimirarray(int *array,int len)
  {
    int i;
    for( i=0 ; i < len ; i++)
    {

        printf("%d,",array[i]);
    }
  }
