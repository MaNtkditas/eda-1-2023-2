#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

// Función para crear una nueva lista ligada doble circular
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

// Función para insertar un elemento al inicio de la lista
void insertAtBeginning(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        list->head = newNode;
    } else {
        Node* lastNode = list->head->prev;
        newNode->prev = lastNode;
        newNode->next = list->head;
        list->head->prev = newNode;
        lastNode->next = newNode;
        list->head = newNode;
    }
}

// Función para insertar un elemento al final de la lista
void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        list->head = newNode;
    } else {
        Node* lastNode = list->head->prev;
        newNode->prev = lastNode;
        newNode->next = list->head;
        list->head->prev = newNode;
        lastNode->next = newNode;
    }
}

// Función para eliminar un elemento de la lista
void deleteNode(DoublyLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;

    while (current->next != list->head) {
        if (current->data == data) {
            if (previous == NULL) {
                list->head = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            printf("Elemento eliminado.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    if (current->data == data) {
        if (previous == NULL) {
            list->head = NULL;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        printf("Elemento eliminado.\n");
        return;
    }

    printf("El elemento no existe en la lista.\n");
}

// Función para imprimir los elementos de la lista
void printList(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Node* current = list->head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("\n");
}

// Función para liberar la memoria ocupada por la lista
void freeList(DoublyLinkedList* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }

    Node* current = list->head;

    do {
        Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != list->head);

    free(list);
}

int main() {
    DoublyLinkedList* list = createDoublyLinkedList();

    int option, data;
    while (1) {
        printf("Seleccione una opción:\n");
        printf("1. Insertar elemento al inicio\n");
        printf("2. Insertar elemento al final\n");
        printf("3. Eliminar elemento\n");
        printf("4. Imprimir lista\n");
        printf("5. Salir\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &data);
                insertAtBeginning(list, data);
                printf("Elemento insertado al inicio.\n");
                break;
            case 2:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &data);
                insertAtEnd(list, data);
                printf("Elemento insertado al final.\n");
                break;
            case 3:
                printf("Ingrese el elemento a eliminar: ");
                scanf("%d", &data);
                deleteNode(list, data);
                break;
            case 4:
                printf("Elementos en la lista: ");
                printList(list);
                break;
            case 5:
                freeList(list);
                printf("Programa finalizado.\n");
                return 0;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }

        printf("\n");
    }
}
