#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"

int parser_mascotaFromText(FILE* pFile,int len , mascota* list);

int parser_razaFromText(FILE* pFile,int len , raza* list);
