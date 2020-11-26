#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

int display_PrintEmployeeOnConsole(void* this);

void display_divisorCabezera(void);

void employee_imprimirLaCabezeraDeLista();

void display_imprimirElFinalDeTabla(void);

void display_topTabla(void);

void display_imprimirUnCharVariasVeces(int caracter, int cantidad);

void imprimirProgreso(int progresoActual,int cantidadTotal);

void imprimirOpciones(char opciones[]);
int display_GetInt(char mensaje[],char pregunta[],char mensajeError[],int max,int min,int intentos);
void display_imprimirCabeceraMascota();
void display_imprimirCabeceraPais();
void display_imprimirCabeceraRaza();
#endif // DISPLAY_H_INCLUDED
