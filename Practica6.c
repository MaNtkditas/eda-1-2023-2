#include <stdio.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

void enqueueFront(struct Deque* deque, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }

    deque->front = newNode;
}

void enqueueRear(struct Deque* deque, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
}

char dequeueFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("El deque está vacío.\n");
        return '\0';
    }

    struct Node* temp = deque->front;
    char data = temp->data;

    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }

    free(temp);
    return data;
}

char dequeueRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("El deque está vacío.\n");
        return '\0';
    }

    struct Node* temp = deque->rear;
    char data = temp->data;

    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }

    free(temp);
    return data;
}

int isPalindrome(char* palabra) {
    struct Deque* deque = createDeque();

    int longitud = 0;
    while (palabra[longitud] != '\0') {
        longitud++;
    }

    for (int i = 0; i < longitud; i++) {
        enqueueRear(deque, palabra[i]);
    }

    while (deque->front != deque->rear && deque->front->prev != deque->rear) {
        if (dequeueFront(deque) != dequeueRear(deque)) {
            free(deque);
            return 0;  // No es un palíndromo
        }
    }

    free(deque);
    return 1;  // Es un palíndromo
}

int main() {
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    if (isPalindrome(palabra)) {
        printf("%s es un palíndromo.\n", palabra);
    } else {
        printf("%s no es un palíndromo.\n", palabra);
    }

    return 0;
}
