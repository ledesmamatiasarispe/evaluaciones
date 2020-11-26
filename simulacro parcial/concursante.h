#ifndef CONCURSANTE_H_INCLUDED
#define CONCURSANTE_H_INCLUDED
/*
Concursante

● numeroConcursante (int)
● año de nacimiento
● nombre (string, 50)
● dni (string, 8, valor entre 9.000.000 y 45.000.000)
● fechaPresentacion (Date)
● temaPresentacion (string, 30)
● puntajePrimeraRonda(int)
Los datos van a estar cargados en un archivo .CSV
*/

struct concursante
{

    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    char dni[9];
    char fechaPresentacion[12];
    char temaPresentacion[128];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    int promedioPuntaje;

} typedef concursante;

concursante *conc_newConcursante();
concursante *conc_newConcursanteParametros(char Numeroconcursante[],char Anio[],char Nombre[],char Dni[],
        char FechaPresentacion[],char TemaPresentacion[],char PuntajePrimeraRonda[]);
int conc_getNumeroconcursante(concursante *this,int *numero);
int conc_setNumeroconcursante(concursante *this,int numero);

int conc_getAnioDeNacimiento(concursante *this,int *anioDeNacimiento);
int conc_setAnioDeNacimiento(concursante *this,int anioDeNacimiento);


int conc_getNombre(concursante *this,char *nombre);
int conc_setNombre(concursante *this,char *nombre);


int conc_getDni(concursante *this,char *dni);
int conc_setDni(concursante *this,char *dni);

int conc_getFechaPresentacion(concursante *this,char *fechaPresentacion);
int conc_setFechaPresentacion(concursante *this,char *fechaPresentacion);

int conc_getTemaPresentacion(concursante *this,char *temaPresentacion);
int conc_setTemaPresentacion(concursante *this,char *temaPresentacion);

int conc_getPuntajePrimeraRonda(concursante *this,int *puntajePrimeraRonda);
int conc_setPuntajePrimeraRonda(concursante *this,int puntajePrimeraRonda);


int getMaxIdFromBIN(char patch[], int *maxId);
int saveMaxIdtoBin(char patch[], int maxId);
int conc_setNewId(concursante* this,int id);


int conc_printConcursante(concursante *this);
#endif // CONCURSANTE_H_INCLUDED
