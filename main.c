// Laboratorio 5 -- main -- Valeria Jarquin Vargas, B83986
#include <stdio.h>
#include "double_list.h"

int main(){
    Node* head = NULL;
    // Agregar nodo al inicio
    insertBeginnig(5, &head);
    insertBeginnig(6, &head);
    insertBeginnig(7, &head);
    printf("Prueba de insertar nodo al inicio:\n");
    printList(head);

    // Agregar nodo al final
    insertEnd(4, &head);
    printf("Prueba de insertar nodo al final:\n");
    printList(head);

    // Agregar nodo en posicion especifica
    insertPosition(5, 2, &head);
    printf("Despues de insertar el valor 5 en la posición 2:\n");
    printList(head);

    // Caso donde se elimina el primer nodo
    deleteNode(7, &head);
    printf("Despues de eliminar el nodo 7:\n");
    printList(head);

    // Caso que se elimina un nodo con un valor repetido
    deleteNode(5, &head);
    printf("Despues de eliminar el nodo 5:\n");
    printList(head);

    // Caso donde se elimina el ultimo nodo
    deleteNode(4, &head);
    printf("Despues de eliminar el nodo 4:\n");
    printList(head);

    // Se agregan mas nodos al final de la lista
    insertEnd(4, &head);
    insertEnd(3, &head);
    printf("Se insertaron mas nodos para el resto de pruebas:\n");
    printList(head);

    // Buscar nodo que no esta en la lista
    int searchVal = 7;
    searchNode(searchVal, head);
    // Buscar nodo que se encuentra en la lista
    int searchVal2 = 4;
    searchNode(searchVal2, head);
   
    // Imprime lista hacia adelante
    printf("Recorriendo la lista hacia adelante:\n");
    printList(head);

    // Imprime lista hacia atrás
    printf("Recorriendo la lista hacia atras:\n");
    printListBack(head);

    //free
    freeList(head);
}