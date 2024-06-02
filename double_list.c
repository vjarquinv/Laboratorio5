// Laboratorio 5 -- Listas -- Valeria Jarquin Vargas, B83986
#include <stdio.h>
#include <stdlib.h>

// Estructura 
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Para utilizar solo Node el resto del codigo
typedef struct Node Node;

// Funcion para insertar nodo al inicio
void insertBeginnig(int data, Node** cabeza){
    // Reservar en memoria para el nuevo nodo
    Node* newNode = (Node* )malloc(sizeof(Node));
    // Revisa si malloc no fallo
    if (newNode == NULL){
        printf("Fallo reservando memoria\n");
        return;
    }

    newNode->data = data;
    // Como no existen se inicializan en NULL
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*cabeza != NULL) {
        (*cabeza)->prev = newNode;
        newNode->next = *cabeza;
    }

    *cabeza = newNode;
}

// Funcion para recorrer los datos de la lista
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Funcion para liberar memoria
void freeList(Node* head){
    Node* actual = head;
    Node* next;
    while(actual != NULL){
        next = actual->next;
        free(actual);
        actual = next;

    }
}

int main(){
    Node* head = NULL;
    // Agregar nodo al inicio
    insertBeginnig(5, &head);
    insertBeginnig(6, &head);
    // Prueba de funcionamiento
    printf("Prueba nodo al inicio:\n");
    printList(head);
    //free
    freeList(head);

}