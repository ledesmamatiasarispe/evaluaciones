#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
/*
Vamos a tener que realizar la estructura pais,
con:(nombreDePais,continente,CodigoTelefonico)argentina =54 , alemania= 49,
belgica =32, tailandia=66,persia=98.
*/

struct pais
{
int id;
int isEmpty;

char nombre[128];
char continente[128];
int codigoTelefonico;

}typedef pais;






int pais_list_cantidadDePais(pais* list,int len);

int pais_setId(pais* this,int id);
int pais_getId(pais* this,int* id);
int pais_setisEmpty(pais* this,int isEmpty);
int pais_getisEmpty(pais* this,int* isEmpty);
int pais_setCodigoTelefonico(pais* this,int codigoTelefonico);
int pais_getcodigoTelefonico(pais* this,int* codigoTelefonico);
int pais_setNombre(pais* this,char* nombre);
int pais_getNombre(pais* this,char* nombre);
int pais_setContinente(pais* this,char* continente);
int pais_getContinente(pais* this,char* continente);
int pais_setNewId(pais* this,int id);
int pais_cargarParametros(pais* this,char nombre[],char id[],char Continente[],char codigoTelefonico[]);




int pais_list_inicializarIsEmpty(pais* list,int len);

int pais_list_cargarLista(char patch[],pais* list,int len);

int pais_list_imprimirLista(pais* list,int len);
int pais_imprimirPais(pais* this);









#endif // PAIS_H_INCLUDED
