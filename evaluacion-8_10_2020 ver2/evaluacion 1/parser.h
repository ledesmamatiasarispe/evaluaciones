#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "mascotas.h"
#include "razas.h"
#include "utn.h"
#include "pais.h"



int parser_mascotaFromText(FILE* pFile,int len , mascota* list);

int parser_razaFromText(FILE* pFile,int len , raza* list);

int parser_paisFromText(FILE* pFile,int len , pais* list);
