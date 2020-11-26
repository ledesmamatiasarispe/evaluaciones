#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    if(this != NULL && nodeIndex >= 0 )
    {
        int len;
        if((len = ll_len(this)) > 0 && nodeIndex < len)
        {
            if(((pNode = this -> pFirstNode) != NULL))
            {
                int i ;
                for(i = 0 ; i < nodeIndex ; i ++)
                {
                    pNode = pNode->pNextNode;
                }
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}



/** \brief Crea un nuevo nodo en memoria de manera dinamica
 *
 *  \param void
 *  \return Node* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Node* ll_newNode(void* element)
{
    Node* this;

    this = (Node*) malloc(sizeof(Node));
    if(this!=NULL)
    {
        this->pElement = element;
        this->pNextNode = NULL;
    }

    return this;
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;


    if(this != NULL && nodeIndex >= 0/* && pElement != NULL */)
    {
        Node* prev;
        Node* next;
        Node* nuevoNodo;
        int len;


        if((len = ll_len(this)) >= 0 &&  nodeIndex <= len )
        {

            if( (nuevoNodo = ll_newNode(pElement)) != NULL )
            {
                if(nodeIndex == 0)
                {
                    next = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;

                }else
                 {
                    if((prev = getNode(this,nodeIndex-1)) != NULL)
                    {
                        next = prev->pNextNode;
                        prev->pNextNode = nuevoNodo;
                    }else
                     {
                         free(nuevoNodo);
                        return -1;
                     }
                 }
                this->size ++;
                nuevoNodo->pNextNode = next;
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) >= 0)
        {
            if(addNode(this,len,pElement) == 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) > 0)
        {
            if(index >=0 && index < len)
            {
                Node *nodeActual;
                if((nodeActual =  getNode(this,index)) != NULL)
                {
                    returnAux = nodeActual->pElement;
                }
            }
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) > 0 &&  index < len && index >= 0 )
        {
            Node *nodeActual;
            if((nodeActual =  getNode(this,index)) != NULL)
            {
                nodeActual->pElement = pElement;
                returnAux = 0;
            }
        }
    }
     return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) > 0 &&  index < len && index >= 0 )
        {
            Node *nextNode , *prevNode ,*actualNode ;

            if(( actualNode = getNode(this,index)) != NULL)
            {
                nextNode = actualNode->pNextNode;
                actualNode->pNextNode = NULL;
                if(index == 0)
                {

                    this->pFirstNode = nextNode;
                }else//index != 0
                 {

                    if(( prevNode = getNode(this,index-1)) != NULL)
                    {
                        prevNode->pNextNode = nextNode;
                    }
                 }
                free(actualNode);
                returnAux = 0;
                this->size --;


            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) > 0 )
        {
            int i;

            for(i= len -1;i >= 0 ; i--)
            {
                if(ll_remove(this,i)==0)
                {
                    returnAux = 0;
                }
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {
        if(ll_clear(this) == 0)
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) > 0 )
        {
            int i;
            for(i = 0;i < len ; i++)
            {
                if(ll_get(this,i) == pElement)
                {
                    returnAux = i;
                    break;
                }
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;
        if( ll_len(this))
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) >= 0  &&  index <= len && index >= 0 )
        {
            if(addNode(this,index,pElement) == 0 )
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief desconecta el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente, ¡¡aunque pElement puede ser valido aún siendo NULL.!!
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) > 0 &&  index < len && index >= 0 )
        {
            returnAux = ll_get(this,index);
            ll_remove(this,index);
        }
    }
    return returnAux;
}

// TODO (arisp#1#): revisar ll_contains

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        int len;
        if((len = ll_len(this)) >= 0)
        {
            returnAux = 0;
            int i;
            for(i = 0 ; i<len ; i++)
            {

                if(pElement == ll_get(this,i))
                {
                    returnAux = 1;
                    break;
                }

            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)//arreglar el for
{
    int returnAux = -1;
    if(this != NULL && this2 != NULL )
    {
        int len , len2;
        if(((len = ll_len(this)) >= 0) && ((len2 = ll_len(this2)) >= 0))
        {

            int i;
            void *pElementfromThis2;

            returnAux = 1;

            for(i=0 ; i< len2 ; i++)
            {
                if((pElementfromThis2 = ll_get(this2,i)) )
                {
                   if( ll_contains(this,pElementfromThis2) == 0)
                   {
                        returnAux = 0;
                        break;
                   }
                }
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL && from >= 0 &&   to > from )
    {
        int len;
        if((len = ll_len(this)) > 0 && to <= len)
        {
            int i ;
            LinkedList* auxLinkedList;
             if((auxLinkedList = ll_newLinkedList()) != NULL)
             {
                void *PelementCopiado;
                int cantidadDeElementosCopiados = 0;

                for(i= from; i < to; i++)
                {
                   PelementCopiado = ll_get(this,i);
                   if(ll_add(auxLinkedList,PelementCopiado) == 0)
                   {
                       cantidadDeElementosCopiados++;
                   }
                }
                   cloneArray = auxLinkedList;
            }
        }
    }

    return cloneArray;// borrar todo si sale mal
}
/*
    El test 1 de sublist verifica si la  funcion ll_sublist retorna el puntero a la nueva lista. el problema es que para hacer esto,
     utiliza una lista que contiene solo un node y la funcion ll_sublist la llama con los paramteros ll_sublist(list,0,1). pidiendole que copia una lista de 2 nodos: 0 y 1.
      desde  una lista con un solo nodo. por lo tanto provoca que no pase de la segunda verificacion de parametros  => "to < len".



*/


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        int len;
        len = ll_len(this);
        cloneArray =  ll_subList(this,0,len);
    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        int i,j,condDeOrdenamiento;
        void *element1, *element2;
        int len;
        if((len = ll_len(this)) > 0)
        {
            for(i = 0 ; i < len-1;i++)
            {
                for(j= i+1 ; j<len ; j++)
                {
                    element1 = ll_get(this,i);
                    element2 = ll_get(this,j);

                    condDeOrdenamiento = pFunc(element1,element2);
                    if((condDeOrdenamiento < 0 && order == 0 ) || (condDeOrdenamiento > 0 && order == 1 ))
                    {
                        ll_set(this,j,element1);
                        ll_set(this,i,element2);
                    }
                }
            }
            returnAux = 0;
        }
    }
    return returnAux;
}



/** \brief La función map ejecutará la función recibida como parámetro por cada item de la lista, y le pasará en
cada llamada, uno de los items.
 *
 * \param LinkedList* lista : Puntero a la lista

 * \return int ll_map(LinkedList* lista,int : la función pasada como parámetro (función criterio) podrá realizar el cálculo aleatorio de
    un puntaje (entre 1 y 10) y se lo asignará al atributo puntajeSegundaRonda del concursante pasado como
    parámetro.


 * @return  (-1) Error: si el puntero a la listas es NULL
            (1) Error: si la funcion pasada como parametro falla
            ( 0) Si ok
 */
int ll_map(LinkedList* lista,int (*pFunc)(void*))
{
    int retorno = -1;
    if(lista != NULL && pFunc != NULL)
    {
        int len;
        if((len = ll_len(lista)) > 0)
        {
            int i;
            retorno = 0;
            for(i = 0; i<len;i++)
            {
               if(pFunc(ll_get(lista,i)) != 0)
               {
                   retorno = 1;
                   break;
               }
            }
        }
    }
    return retorno;
}


/**

Por otro lado dicha función criterio, también se encargará de calcular el promedio de las dos notas
    obtenidas (para la primera ronda y para la segunda)

   *  @return (-1) Error: si el puntero a el elemento es NULL
                                ( 0) Si ok

*/












