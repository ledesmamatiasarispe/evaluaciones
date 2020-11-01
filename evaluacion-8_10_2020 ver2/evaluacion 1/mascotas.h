#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct mascota{

int id;
int isEmpty;

char nombre[128];
int edad;
char sexo [20];
char tipo [20];

}typedef mascota;




/** \brief
 *
 * \param this mascotas*
 * \param id int
 * \return int -1 .  0 todo bien
 *
 */
int mascota_setNombre(mascota* this,char* nombre);

/** \brief
 *
 * \param this mascotas*
 * \param id int
 * \return int -1 .  0 todo bien
 *
 */
 int mascotas_cargarParametros(mascota* element,char edad [],char id [],char nombre[],char sexo[],char tipo[]);

int mascota_getNombre(mascota* this,char* nombre);

int mascota_setId(mascota* this,int id);
int mascota_getId(mascota* this,int* id);

int mascota_setisEmpty(mascota* this,int isEmpty);
int mascota_getisEmpty(mascota* this,int* isEmpty);

int mascota_setEdad(mascota* this,int edad);
int mascota_getEdad(mascota* this,int* edad);

int mascota_setSexo(mascota* this,char sexo[]);
int mascota_getsexo(mascota* this,char* sexo);

int mascota_setTipo(mascota* this,char tipo[]);
int mascota_getTipo(mascota* this,char* tipo);

int mascota_nombreAformatoCorrecto(char* this);


int mascota_imprimirMascota(mascota* element);







#endif // MASCOTAS_H_INCLUDED
