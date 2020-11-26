#ifndef MASCOTAS_RAZA_H_INCLUDED
#define MASCOTAS_RAZA_H_INCLUDED

#include "mascotas.h"
#include "razas.h"
#include "pais.h"



int mascota_alta(mascota* mascotalist,int mascotalen,raza* razalist,int razalen,pais* listPaises,int lenpais,etipo *listetipo,int lenetipo);


int mascota_bajaIfIdrazaIs(mascota *list ,int len,int id);
int mascota_printIfIdrazaIs(mascota *list ,int len,int id);
int mascota__raza_imprimirRazaConMascotas(mascota* listMascota,raza* listRaza,int lenMascota,int lenraza,pais* listpais,int lenpais);
int mascota_modificar(mascota* mascotalist,int mascotalen,raza* razalist,int razalen,pais* listPaises,int lenpais);
int ordenarmascotasPorPais(mascota* mascotaslist,int mascotaslen,raza* razalist,int razalen,pais *paislist,int paislen,pais_pcomparar pfComparar);
int mascota__raza_imprimirLista(mascota* mascotalist,raza* razalist,int mascotaslen,int razalen,pais *listapais,int lenpais);
int mascota__raza_imprimirMascotaConRaza(mascota* this,raza* razalist,int razalen,pais* paislist,int paislen);
raza* mascota_raza_getRazaOfMascota(mascota* this,raza* list,int len);
raza* mascota_raza_getRazabyIdRaza(raza* list,int len,int idRaza);
#endif // MASCOTAS_RAZA_H_INCLUDED
