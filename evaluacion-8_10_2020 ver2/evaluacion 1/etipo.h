#ifndef ETIPO_H_INCLUDED
#define ETIPO_H_INCLUDED

struct etipo
{
    int id;
    char descripcion[128];
    int isEmpty;

}typedef etipo;

int etipo_setdescripcion(etipo* this,char descripcion[]);
int etipo_getdescripcion(etipo* this,char* descripcion);



#endif // ETIPO_H_INCLUDED
