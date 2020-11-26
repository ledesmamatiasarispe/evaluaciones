#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pais.h"
#include "etipo.h"

struct mascota{

int id;
int isEmpty;
int idRaza;
int idTipo ;

char nombre[128];
int edad;
char sexo [20];

int peso;
}typedef mascota;


typedef int (*pMascota_setInt)(mascota* , int );
typedef int (*pMascota_setString)(mascota* , char*);

typedef  int(*mascota_pcomparar)(mascota* ,mascota*);

typedef  int(*pais_pcomparar)(pais * ,pais *);

int mascota_ingresarString(char mensaje[],mascota* this,pMascota_setString punteroSet);
int mascota_ingresarInt(char mensaje[],int max,int min,mascota* this,pMascota_setInt punteroSet);
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
 int mascotas_cargarParametros(mascota* this,char edad [],char id [],char idRaza [] ,char nombre[],char sexo[],char tipo[],char peso[]);

int compararPorTipoYPeso(mascota* mascota1,mascota* mascota2,etipo *lista,int etipoLen);
int mascota_getNombre(mascota* this,char* nombre);

int mascota_setId(mascota* this,int id);
int mascota_getId(mascota* this,int* id);

int mascota_setIdRaza(mascota* this,int idRaza);
int mascota_getIdRaza(mascota* this,int* idRaza);

int mascota_setisEmpty(mascota* this,int isEmpty);
int mascota_getisEmpty(mascota* this,int* isEmpty);

int mascota_setEdad(mascota* this,int edad);
int mascota_getEdad(mascota* this,int* edad);

int mascota_setSexo(mascota* this,char sexo[]);
int mascota_getsexo(mascota* this,char* sexo);

int mascota_setValidSexo(mascota* this,int sexo);

/*********************/
int mascota_setidTipo(mascota* this,int tipo);
int mascota_setTipo(mascota* this,char tipo[]);
int mascota_getDescripcionTipo(mascota* this,char* tipo,etipo *lista,int etipoLen);

int mascota_setValidTipo(mascota* this,int tipo);

/************************/

mascota* mascota_getBYId(mascota* list, int len,int id);


int mascota_imprimirMascota(mascota* this);
int mascota_setNewId(mascota* this,int id);

mascota* mascota_getEmptyElement(mascota* list, int len);

int mascotas_list_inicializarIsEmpty(mascota* list,int len);
int mascotas_list_cargarLista(char patch[],mascota* list,int len);
int mascota_list_imprimirLista(mascota* list,int len);

int mascota_bajaLogica(mascota* list,int len,int id);

int mascota_list_swap(mascota* element1,mascota* element2);
#endif // MASCOTAS_H_INCLUDED
