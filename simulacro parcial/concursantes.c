#include "concursante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



concursante *conc_newConcursante()
{
    concursante *newConcursante;
    newConcursante = malloc(sizeof(concursante));
    return newConcursante;
}

concursante *conc_newConcursanteParametros(char *Numeroconcursante,char *Anio,char *Nombre,char *Dni,
        char *FechaPresentacion,char *TemaPresentacion,char *PuntajePrimeraRonda)
{
    concursante* this = NULL;
    if(Numeroconcursante != NULL && Anio != NULL && Nombre != NULL && Dni != NULL && FechaPresentacion!= NULL && TemaPresentacion!= NULL && PuntajePrimeraRonda != NULL)
    {
        if((this = conc_newConcursante())!= NULL)
        {
            if(this!=NULL)
            {
                if /**numeroConcursante,anio,nombre,dni,fechapresentacion,temaPresentacion,puntaje*/
                (
                    conc_setNewId(this,atoi(Numeroconcursante)) != 0 ||
                    conc_setAnioDeNacimiento(this,atoi(Anio)) != 0 ||
                    conc_setNombre(this,Nombre) != 0 ||
                    conc_setDni(this,Dni) != 0 ||
                    conc_setFechaPresentacion(this,FechaPresentacion) != 0 ||
                    conc_setTemaPresentacion(this,TemaPresentacion)!= 0 ||
                    conc_setPuntajePrimeraRonda(this,atoi(PuntajePrimeraRonda)) != 0


                )
                {

                    free(this);
                    this = NULL;
// TODO (arisp#1#): si fallo el ingreso de datos, liberar el nodo

                }

            }
        }
    }
    return this;

}











/**************************numeroConcursante**********************/
int conc_getNumeroconcursante(concursante *this,int *numero)
{
    int retorno = -1;
    if(this != NULL && numero != NULL )
    {
        retorno = 0;
        *numero = this->numeroConcursante;
    }
    return retorno;
}

int conc_setNumeroconcursante(concursante *this,int numero)
{
    int retorno = -1;
    if(this != NULL /*&& numero != NULL*/ )
    {
        retorno = 0;
        this->numeroConcursante = numero;
    }
    return retorno;
}

/**************************añonacimiento**********************/

int conc_getAnioDeNacimiento(concursante *this,int *anioDeNacimiento)
{
    int retorno = -1;
    if(this != NULL && anioDeNacimiento != NULL )
    {
        retorno = 0;
        *anioDeNacimiento = this->anioDeNacimiento;
    }
    return retorno;
}


int conc_setAnioDeNacimiento(concursante *this,int anioDeNacimiento)
{
    int retorno = -1;
    if(this != NULL /*&& anioDeNacimiento != NULL */)
    {
        retorno = 0;
        this->anioDeNacimiento = anioDeNacimiento ;
    }
    return retorno;
}



/**************************nombre**********************/

int conc_getNombre(concursante *this,char *nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL )
    {
        retorno = 0;
        strcpy(nombre, this->nombre);
    }
    return retorno;
}


int conc_setNombre(concursante *this,char *nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL )
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}


/**************************dni**********************/
int conc_getDni(concursante *this,char *dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL )
    {
        retorno = 0;

        strcpy(dni,this->dni);

    }
    return retorno;
}

int conc_setDni(concursante *this,char *dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL )
    {
        retorno = 0;

        strncpy( this->dni, dni,9 );
    }
    return retorno;
}

/**************************fechadepresentacion**********************/
int conc_getFechaPresentacion(concursante *this,char *fechaPresentacion)
{
    int retorno = -1;
    if(this != NULL && fechaPresentacion != NULL )
    {
        retorno = 0;
        strcpy(fechaPresentacion, this->fechaPresentacion);
    }
    return retorno;
}

int conc_setFechaPresentacion(concursante *this,char *fechaPresentacion)
{
    int retorno = -1;
    if(this != NULL /*&& fechaPresentacion*/ )
    {
        retorno = 0;
        strncpy(this->fechaPresentacion, fechaPresentacion,11 );
    }
    return retorno;
}

/**************************temapresentaicon**********************/
int conc_getTemaPresentacion(concursante *this,char *temaPresentacion)
{
    int retorno = -1;
    if(this != NULL && temaPresentacion != NULL )
    {
        retorno = 0;
        strcpy(temaPresentacion, this->temaPresentacion);
    }
    return retorno;
}

int conc_setTemaPresentacion(concursante *this,char *temaPresentacion)
{
    int retorno = -1;
    if(this != NULL && temaPresentacion != NULL )
    {
        retorno = 0;
        strcpy(this->temaPresentacion,temaPresentacion);
    }
    return retorno;
}
/**************************puntaje 1ra ronda**********************/
int conc_getPuntajePrimeraRonda(concursante *this,int *puntajePrimeraRonda)
{
    int retorno = -1;
    if(this != NULL && puntajePrimeraRonda != NULL )
    {
        retorno = 0;
        *puntajePrimeraRonda = this->puntajePrimeraRonda;
    }
    return retorno;
}

int conc_setPuntajePrimeraRonda(concursante *this,int puntajePrimeraRonda)
{
    int retorno = -1;
    if(this != NULL /*&& puntajePrimeraRonda != NULL*/ )
    {
        retorno = 0;
        this->puntajePrimeraRonda = puntajePrimeraRonda ;
    }
    return retorno;
}



/**************************puntajeSegundaRonda**********************/
int conc_getPuntajeSegundaRonda(concursante *this,int *numero)
{
    int retorno = -1;
    if(this != NULL && numero != NULL )
    {
        retorno = 0;
        *numero = this->puntajeSegundaRonda;
    }
    return retorno;
}

int conc_setPuntajeSegundaRonda(concursante *this,int numero)
{
    int retorno = -1;
    if(this != NULL /*&& numero != NULL*/ )
    {
        retorno = 0;
        this->puntajeSegundaRonda = numero;
    }
    return retorno;
}




/**************************promedioPuntaje**********************/
int conc_getPromedioPuntaje(concursante *this,int *numero)
{
    int retorno = -1;
    if(this != NULL && numero != NULL )
    {
        retorno = 0;
        *numero = this->promedioPuntaje;
    }
    return retorno;
}

int conc_setPromedioPuntaje(concursante *this,int numero)
{
    int retorno = -1;
    if(this != NULL /*&& numero != NULL*/ )
    {
        retorno = 0;
        this->promedioPuntaje = numero;
    }
    return retorno;
}


int getMaxIdFromBIN(char patch[], int *maxId)
{
    int retorno = -1;
    FILE* pfile;
    if((pfile = fopen(patch,"rb")) != NULL)
    {
        if(fread(maxId,sizeof(int),1,pfile) == 1)
        {
            retorno = 0;
        }
    }
    else
    {
        *maxId = 0;
    }
    fclose(pfile);
    return retorno;
}

int saveMaxIdtoBin(char patch[], int maxId)
{
    int retorno = -1;
    FILE* pfile;
    if((pfile = fopen(patch,"wb")) != NULL)
    {
        if(fwrite(&maxId,sizeof(int),1,pfile) != 1)
        {
            retorno = 2;
        }
    }
    fclose(pfile);
    return retorno;
}




int conc_setNewId(concursante* this,int id)
{
    int retorno = -1 ;

    if(this!=NULL)
    {
        int maxId = 0;
        if( getMaxIdFromBIN("maxID.bin", &maxId) == 0)
        {
            retorno = 1;
            if(id<=maxId)
            {
                maxId++;
            }
            else
            {
                maxId = id;
            }
            conc_setNumeroconcursante(this,maxId);
            retorno = 0;
        }
        saveMaxIdtoBin("maxID.bin", maxId);
    }
    return retorno;
}


int conc_printConcursante(concursante *this)
{
    int retorno = -1;
    if(this != NULL)
    {
        char Nombre[128],Dni[128],FechaPresentacion[128],TemaPresentacion[128];
        int Numeroconcursante,Anio,PuntajePrimeraRonda;
        if(
            conc_getNumeroconcursante(this,&Numeroconcursante) ==0 &&
            conc_getAnioDeNacimiento(this,&Anio) ==0 &&
            conc_getNombre(this,Nombre) ==0 &&
            conc_getDni(this,Dni) ==0 &&
            conc_getFechaPresentacion(this,FechaPresentacion) ==0 &&
            conc_getTemaPresentacion(this,TemaPresentacion) ==0 &&
            conc_getPuntajePrimeraRonda(this,&PuntajePrimeraRonda) ==0
        )
        {
            printf("| %10d | %10d | %10s | %10s | %10s | %40s | %10d | \n",
                   Numeroconcursante,Anio,Nombre,Dni,FechaPresentacion,
                   TemaPresentacion,PuntajePrimeraRonda);
            retorno = 0;
        }
    }
    return retorno;
}

