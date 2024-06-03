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

Node* crearNode(int data){
    // Reservar en memoria para el nuevo nodo
    Node* newNode =(Node* )malloc(sizeof(Node));
        // Revisa si malloc no fallo
        if (newNode == NULL){
        printf("Fallo reservando memoria\n");
        return NULL;
    }

    newNode->data = data;
    // Como no existen se inicializan en NULL
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode; 
}

// Funcion para insertar nodo al inicio
void insertBeginnig(int data, Node** cabeza){

    Node* newNode = crearNode(data);
    if (newNode == NULL) {
        return;
    }

    // Si la lista esta vacia, el nuevo nodo sera la cabeza
    if (*cabeza != NULL) {
        (*cabeza)->prev = newNode;
        newNode->next = *cabeza;
    }

    *cabeza = newNode;
}

void insertEnd(int data, Node** cabeza) {
    
    Node* newNode = crearNode(data);
    if (newNode == NULL) {
        return;
    }

    // Si la lista esta vacia, el nuevo nodo sera la cabeza
    if (*cabeza == NULL) {
        *cabeza = newNode;
        return;
    }

    // De lo contrario, recorre la lista hasta el final
    Node* temp = *cabeza;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Actualiza los punteros para insertar el nuevo nodo al final
    temp->next = newNode;
    newNode->prev = temp;
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
    insertEnd(7, &head);
    insertEnd(78, &head);
    // Prueba de funcionamiento
    printf("Prueba nodo al inicio y  final:\n");
    printList(head);
    //free
    freeList(head);

}