#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED
/*#Tenemos un listado de razas(descripción,tamanio{chico ,mediano o grande},país de
origen)*/
#include "pais.h"

struct raza
{
int id;
int isEmpty;
int idPais;
char descripcion[128];
char tamanio[128];
char paisDeOrigen[128];
}typedef raza;

typedef int (*pRaza_setInt)(raza* , int );
typedef int (*pRaza_setString)(raza* , char*);

typedef  int(*raza_pcomparar)(raza* ,raza*);




raza* raza_getBYId(raza* list, int len,int id);
int comparebyPaisDeOrigen(raza* element1,raza* element2);

int razas_cargarParametros(raza* this,char descripcion[],char id[],char tamanio[],char auxIdPais[]);

int raza_list_inicializarIsEmpty(raza* list,int len);
int raza_list_cargarLista(char patch[],raza* list,int len);
int raza_list_cantidadDeRazas(raza* list,int len);
int raza_list_imprimirLista(raza* list,int len,pais* listPaises,int lenpais);

int raza_imprimirRaza(raza* this,pais* paisActual);
int raza_setId(raza* this,int id);
int raza_getId(raza* this,int* id);
int raza_setisEmpty(raza* this,int isEmpty);
int raza_getisEmpty(raza* this,int* isEmpty);
int raza_setidPais(raza* this,int idPais);
int raza_getidPais(raza* this,int* idPais);
int raza_setDescripcion(raza* this,char* descripcion);
int raza_getDescripcion(raza* this,char* descripcion);
int raza_setTamanio(raza* this,char* tamanio);
int raza_setValidTamanio(raza* this,int tipo);
int raza_getTamanio(raza* this,char* tamanio);
int raza_setNewId(raza* this,int id);
raza* raza_getEmptyElement(raza* list, int len);
int raza_ingresarString(char mensaje[],raza* this,pRaza_setString punteroSet);
int raza_ingresarInt(char mensaje[],int max,int min,raza* this,pRaza_setInt punteroSet);
pais* raza_getpaisbyId(pais* list,int len,int idpais);
pais* raza_getpais(pais* list,int len,raza *this);
int raza_alta(raza* list,int len,pais* listPaises,int lenpais);



int pais_pcompararCodigoTelefonico(pais *pais1,pais *pais2);
int pais_pcompararPorPais(pais *pais1,pais *pais2);
#endif // RAZAS_H_INCLUDED
