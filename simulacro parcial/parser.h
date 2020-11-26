#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int parser_loadConcursanteFromText(FILE* pFile, LinkedList* pArrayList);
int parser_ConcursanteFromBinary(FILE* pFile, LinkedList* pArrayList);

#endif // PARSER_H_INCLUDED
