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

    controller_printList(llConcursantes,conc_printConcursante);

    return 0;
}
