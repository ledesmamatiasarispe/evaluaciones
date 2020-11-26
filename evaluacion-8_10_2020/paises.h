#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED


struct{
int isEmpty;
int idPais;

char nombre[51];
char continente[51];
int codigoTelefonico;

}typedef ePais;


//hardcodeo;
int initPaiz(ePais* list, int len);
void hardcodearPais( ePais lista[]);
//baja


//mostrar

//alta
//asinga el dato a el primer espacio nuevo


//imprimen
int imprimirUnPais(ePais* pais,int mostrarEncabezado);
int imprimirTodosLosPaises(ePais* lista,int lenght);
//secundarias
int pais_SetId(ePais* pais,int id);

#endif // PAISES_H_INCLUDED
