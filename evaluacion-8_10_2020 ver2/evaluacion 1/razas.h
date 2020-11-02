#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED
/*#Tenemos un listado de razas(descripción,tamanio{chico ,mediano o grande},país de
origen)*/

struct raza
{
int id;
int isEmpty;

char descripcion[128];
char tamanio[128];
char paisDeOrigen[128];
}typedef raza;







#endif // RAZAS_H_INCLUDED
