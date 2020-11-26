#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pList);
int controller_loadConcursanteFromBinary(char* path, LinkedList* pList);
int controller_generarSegundaNota(LinkedList *list);


#endif // CONTROLLER_H_INCLUDED
