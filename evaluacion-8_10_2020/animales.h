#ifndef ANIMALES_H_INCLUDED
#define ANIMALES_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

struct{
int iDAnimales;
int idRaza;
int isEmpty;

char nombre[51];
int edad;
char sexo;
char tipo[15];

}typedef eAnimales;
//hardcodeo
void hardcodearAnimales(eAnimales lista[]);
int initAnimales(eAnimales* list, int len);

//baja
int removeAnimal(eAnimales* list, int len, int id);
//mostrar

//asinga el dato a el primer espacio nuevo
int asginarDatosMascota(eAnimales* list,int lenghtAnimales,eAnimales* ValoresNuevos);

//imprimen
int imprimirUnAnimal(eAnimales* animal,int MostrarEncabezado);
int imprimirTodosLosAnimales(eAnimales* animal,int lenghtAnimales);

//secundarias
int getFirstEmptyIndex(eAnimales* list, int len,int* emptyIndex);
int ani_SetId(eAnimales* Animales,int id);
int findById(eAnimales* list, int len,int id);
int swapearAnimales(eAnimales* list,int lenghtAnimales,int indexA,int indexB);
int ani_SetId(eAnimales* Animales,int id);
#endif // ANIMALES_H_INCLUDED

















