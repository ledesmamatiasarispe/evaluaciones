#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "concursante.h"
#include "controller.h"

/*ext revisar si hay 2 ganadores*/

int main()
{

    LinkedList *llConcursantes;
    llConcursantes = ll_newLinkedList();
    controller_loadFromText("buenosaires.csv",llConcursantes);

    ll_map(llConcursantes,conc_printConcursante);

    ll_map(llConcursantes,conc_generarSegundaNota);
    ll_map(llConcursantes,conc_calcularPromedio);

    ll_map(llConcursantes,conc_printConcursanteConPromedio);


    return 0;
}
