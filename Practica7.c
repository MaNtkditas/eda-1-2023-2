#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int search(struct Node* last, int term) {
    if (last == NULL) {
        printf("La lista está vacía.\n");
        return 0;
    }

    struct Node* p = last->next;
    int index = 1;
    do {
        if (p->data == term) {
            printf("El término %d se encontró en la posición %d.\n", term, index);
            return 1;
        }
        p = p->next;
        index++;
    } while (p != last->next);

    printf("El término %d no se encontró en la lista.\n", term);
    return 0;
}

struct Node* addToEmpty(struct Node* last, int data) {
    if (last != NULL) return last;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    last = newNode;
    last->next = last;

    return last;
}

struct Node* addFont(struct Node* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

struct Node* addEnd(struct Node* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    return last;
}

struct Node* addAfter(struct Node* last, int data, int item) {
    if (last == NULL) return NULL;

    struct Node* newNode, *p;
    p = last->next;

    do {
        if (p->data == item) {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;

            return last;
        }

        p = p->next;
    } while (p != last->next);

    printf("\nEl nodo dado no está presente en la lista.\n");
    return last;
}

void traverse(struct Node* last) {
    struct Node* p;

    if (last == NULL) {
        printf("\nLa lista está vacía.\n");
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
    last = addFont(last, 2);

    last = addAfter(last, 10, 2);

    traverse(last);

    int term;
    printf("\nIngrese el término que desea buscar: ");
    scanf("%d", &term);
    search(last, term);

    return 0;
}
