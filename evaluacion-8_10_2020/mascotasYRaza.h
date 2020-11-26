#ifndef MASCOTASYRAZA_H_INCLUDED
#define MASCOTASYRAZA_H_INCLUDED

#include "animales.h"
#include "raza.h"
#include "paises.h"
//imprimir datos que estan entre 2 estructuras
int mostrarMascotasConRazaYPaisDeOrigen(eAnimales listaAnimales[],eRaza listaRaza[],int lenghtAnimales,
                                        int lenghtRaza,ePais listaPais[],int lenghtpais);
//relaciones entre estructuras
eRaza getRaza(int idRaza,eRaza listaRaza[],int lenghtRaza);
ePais getpais(int idABuscar,ePais lista[],int lenght);
//ordena una estructura en base a otra
int ordenarPorPaisDeOrigen(eAnimales* listaAnimales,eRaza listaRaza[],int lenghtAnimales,int lenghtRaza);

/*crea una  animal de eAnimales nueva y la ingresa en el primer espacio libre
del array       */
int altaAnimal(eRaza* listaRaza,int lenghtRaza,eAnimales* listaAnimales,int lenghtAnimales);


/*crea una  raza de eRaza nueva y la ingresa en el primer espacio libre
del array      */
int altaRaza(eRaza* listaRaza,int lenghtRaza,eAnimales listapaises[],int lenghtPais);
/*
permite el ingreso validado de el idRaza en la estructura Animales
toma una int idRaza ,lo valida entre max y min y luego valida que ese id exista

*/
int ingrezarRazaDelAnimal(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,
                          int attemps,eRaza* listaRaza,int lenghtRaza);

int validarRazaIngresada(int idRaza,eRaza listaRaza[],int lenghtRaza);



int ingrezarPaisDeOrigen(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,
                          int attemps,eRaza* listaPaises,int lenghtPaiz);

int validarPaisIngresado(int idPais,ePais listaPaises[],int lenght);

int getTipoDeAnimal(char requestMessage[],char errorMessage[],char output[],int lowLimit, int hiLimit,int attemps);

int mostrarRazasYsusAnimales(eAnimales listaAnimales[],eRaza listaRaza[],int lenghtAnimales,int lenghtRaza);
 int  getAnimalesDeUnaRaza(int idRaza,int lenghtAnimales,eAnimales listaAnimales[],eAnimales arrayAnimalesDeRaza[]);


int modificarDatosMascota(eRaza* listaRaza,int lenghtRaza,eAnimales* listaAnimales,int lenghtAnimales);
#endif // MASCOTASYRAZA_H_INCLUDED
