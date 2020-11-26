#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void clearStdin(void);
float getFloat(char* mensaje);
char getChar(char* mensaje);
void getString(char mensaje[],char input[]);
int getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumericoFlotante(char str[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int esUnNombre(char str[]);

int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getStringName(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidFloats(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,int attemps);
int getValidNames(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidSex(char* mensaje,char* mensajeError,char* output,int reintentos);
#endif // UTN_H_INCLUDED

