// Laboratorio 5 -- Interfaz -- Valeria Jarquin Vargas, B83986

#ifndef DOUBLE_LIST
#define DOUBLE_LIST

// Estructura 
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Para utilizar solo Node el resto del codigo
typedef struct Node Node;

Node* crearNode(int data); // Crea el nodo
void insertBeginnig(int data, Node** cabeza); // Inserta nodo al inicio de la lista
void insertEnd(int data, Node** cabeza); // Inserta nodo al final de la lista
void insertPosition(int data, int position, Node** head); // Inserta nodo en una posiscion especifica de la lista
void deleteNode(int data, Node** head); // Elimina un nodo
Node* searchNode(int data, Node* head); // Busca un nodo en la lista
void printList(Node* head); // Imprime la lista hacia adelante
void printListBack(Node* head); // Imprime la lista hacia atras
void freeList(Node* head); // Libera la memoria

#endif