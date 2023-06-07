#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) {
    if (last != NULL) return last;

    // Asignar memoria al nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Asignar dato al nuevo nodo
    newNode->data = data;

    // Asignar como last al nuevo nodo
    last = newNode;

    // Crear enlace a sí mismo
    last->next = last;

    return last;
}

struct Node* addFront(struct Node* last, int data) {
    // Revisar si la lista está vacía
    if (last == NULL) return addToEmpty(last, data);

    // Asignar memoria al nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Agregar dato al nuevo nodo
    newNode->data = data;

    // Guardar la dirección del nodo siguiente al nodo actual en el nuevo nodo
    newNode->next = last->next;

    // Hacer al nuevo nodo como la cabeza
    last->next = newNode;

    return last;
}

struct Node* addEnd(struct Node* last, int data) {
    // Revisar si el nodo está vacío
    if (last == NULL) return addToEmpty(last, data);

    // Asignar memoria al nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Agregar dato al nuevo nodo
    newNode->data = data;

    // Almacenar la dirección del nodo cabeza al siguiente del nuevo nodo
    newNode->next = last->next;

    // Apuntar el actual último nodo al nuevo nodo
    last->next = newNode;

    // Hacer al nuevo nodo como el último nodo
    last = newNode;

    return last;
}

struct Node* addAfter(struct Node* last, int data, int item) {
    // Revisar si la lista está vacía
    if (last == NULL) return NULL;

    struct Node* newNode, *p;
    p = last->next;

    do {
        // Si se encontró el elemento, colocar el nuevo nodo después de él
        if (p->data == item) {
            // Asignar memoria al nuevo nodo
            newNode = (struct Node*)malloc(sizeof(struct Node));

            // Agregar dato al nuevo nodo
            newNode->data = data;

            // Hacer que el siguiente nodo del nuevo nodo sea el nodo siguiente del actual
            newNode->next = p->next;

            // Hacer al nuevo nodo como el siguiente del nodo actual
            p->next = newNode;

            if (p == last) {
                last = newNode;
            }

            return last;
        }

        p = p->next;

    } while (p != last->next);

    printf("\nEl nodo dado no está presente en la lista");
    return last;
}

void deleteNode(struct Node** last, int key) {
    // Si la lista ligada está vacía
    if (*last == NULL) return;

    // Si la lista contiene solo un nodo
    if ((*last)->data == key && (*last)->next == *last) {
        free(*last);
        *last = NULL;
        return;
    }

    struct Node* temp = *last, *d;

    // Si se va a eliminar el último nodo
    if ((*last)->data == key) {
        // Encontrar el nodo antes del último nodo
        while (temp->next != *last) temp = temp->next;

        // Apuntar el nodo temporal al siguiente del último, es decir, al primer nodo
        temp->next = (*last)->next;
        free(*last);
        *last = temp->next;
    }

    // Recorrer el nodo que va a ser eliminado
    while (temp->next != *last && temp->next->data != key) {
        temp = temp->next;
    }

    // Si el nodo a eliminar se encuentra
    if (temp->next->data == key) {
        d = temp->next;
        temp->next = d->next;
        free(d);
    }
}

void traverse(struct Node* last) {
    struct Node* p;

    if (last == NULL) {
        printf("\nLa lista está vacía");
        return;
    }

    p = last->next;
    do {
        printf(" %d", p->data);
        p = p->next;
    } while (p != last->next);
}

int main() {
    struct Node* last = NULL;

    last = addToEmpty(last, 6);
    last = addEnd(last, 8);
    last = addFront(last, 2);

    last = addAfter(last, 10, 2);

    traverse(last);

    int choice;
    int num;

    do {
        printf("\n\n1. Agregar un término");
        printf("\n2. Eliminar un término");
        printf("\n3. Salir");
        printf("\nIngrese su elección: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nIngrese un número para agregar a la lista: ");
                scanf("%d", &num);
                last = addEnd(last, num);
                traverse(last);
                break;
            case 2:
                printf("\nIngrese el número a eliminar de la lista: ");
                scanf("%d", &num);
                deleteNode(&last, num);
                traverse(last);
                break;
            case 3:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}


