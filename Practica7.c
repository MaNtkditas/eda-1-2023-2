#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* head;
} CircularLinkedList;

// Función para crear una nueva lista ligada circular
CircularLinkedList* createCircularLinkedList() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->head = NULL;
    return list;
}

// Función para insertar un elemento al final de la lista
void insertAtEnd(CircularLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else {
        newNode->next = list->head;
        Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Función para buscar un elemento en la lista
int searchElement(CircularLinkedList* list, int value) {
    if (list->head == NULL) {
        return 0;
    }

    Node* current = list->head;
    do {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    } while (current != list->head);

    return 0;
}

// Función para imprimir los elementos de la lista
void printList(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Node* current = list->head;
    printf("Elementos en la lista: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

// Función para liberar la memoria ocupada por la lista
void freeList(CircularLinkedList* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }

    Node* current = list->head;
    Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != list->head);

    free(list);
}

int main() {
    CircularLinkedList* list = createCircularLinkedList();

    // Valores asignados previamente a la lista
    insertAtEnd(list, 1);
    insertAtEnd(list, 2);
    insertAtEnd(list, 3);
    insertAtEnd(list, 4);
    insertAtEnd(list, 5);

    int searchValue;
    printf("Ingrese un valor para buscar en la lista: ");
    scanf("%d", &searchValue);

    if (searchElement(list, searchValue)) {
        printf("Se encontró el elemento en la estructura.\n");
    } else {
        printf("El elemento no se encuentra en la estructura.\n");
    }

    printList(list);

    freeList(list);

    return 0;
}
