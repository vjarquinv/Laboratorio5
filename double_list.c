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

// Funcion para insertar nodo al final
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

// Funcion para insertar nodo en una posicion especifica
void insertPosition(int data, int position, Node** cabeza){

    // Si la posicion es 0, agregar al inicio
    if(position == 0){
        insertBeginnig(data, cabeza);
        return;
    }

    Node* newNode = crearNode(data);
    if (newNode == NULL) {
        return;
    }

    Node* temp = *cabeza;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Si la posicion es mayor que la longitud de la lista, agregar al final
    if (temp == NULL || temp->next == NULL) {
        insertEnd(data, cabeza);
        return;
    }

    // Actualiza los punteros para insertar el nuevo nodo en la posicion deseada
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteNode(int data, Node** cabeza){
    Node* temp = *cabeza;

    // Si la lista esta vacia
    if(temp == NULL){
        printf("La lista esta vacia\n");
        return;
    }
    // Recorre la lista para buscar el nodo que se quiere eliminar
    while(temp != NULL && temp->data != data){
        temp = temp->next;
    }
    // En caso que no encuentre el nodo
    if(temp == *cabeza){
        *cabeza = temp->next;
    }
    // Actualiza los punteros del nodo anterior
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    // Actualiza los punteros del nodo siguiente
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    // Se libera el nodo
    free(temp);
    printf("Nodo %d eliminado. \n", data);
}

// Funcion para encontrar un nodo en la lista
Node* searchNode(int  data, Node* cabeza){
    Node* temp = cabeza;

    while (temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
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
    insertBeginnig(7, &head);
     // Agregar nodo al final
    insertEnd(7, &head);
    insertEnd(78, &head);

    // Prueba de funcionamiento
    printf("Lista original:\n");
    printList(head);

    // Agregar nodo en posicion especifica
    insertPosition(9, 2, &head);
    printf("Despues de insertar 9 en la posición 2:\n");
    printList(head);

    // Eliminar un nodo
    deleteNode(7, &head);
    printf("Despues de eliminar el nodo 7:\n");
    printList(head);

    // Buscar nodo
    int searchVal = 7;
    Node* searchRes = searchNode(searchVal, head);
    if (searchRes != NULL) {
        printf("Nodo con valor %d encontrado.\n", searchVal);
    } else {
        printf("Nodo con valor %d no encontrado.\n", searchVal);
    }

    //free
    freeList(head);

}