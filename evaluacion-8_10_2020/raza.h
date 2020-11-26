#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0


struct{
int idRaza;
int idPais;
char descripcion[51];
char tamanio[20];
char paisDeOrigen[51];
int isEmpty;
}typedef eRaza;



//hardcodeo
int initRaza(eRaza* list, int len);
void hardcodearRaza(eRaza lista[]);

//baja

//mostrar

//asinga el dato a el primer espacio nuevo
int asginarDatosRaza(eRaza* list,int lenght,eRaza* ValoresNuevos);
//imprimen
int imprimirUnaRaza(eRaza* raza,int mostrarEncabezado);
int imprimirTodasLasRazas(eRaza* listaRaza,int lenghtRaza);
//secundarias
int raza_getFirstEmptyIndex(eRaza* list, int len,int* emptyIndex);
int raz_SetId(eRaza* raza,int id);
#endif // RAZA_H_INCLUDED
