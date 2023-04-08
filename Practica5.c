//Sistema de turnos

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
/*
struct Pila {
	int top;
  unsigned capacity;;
	int* array;
};
*/
// Una estructura de la pila
int pila[SIZE+1];

//Agregar dato
void push(int dato) {
    static int tope = 0;
    if (tope >= SIZE) {
        printf("Ya no hay turnos disponibles... \n");
        exit(1);
    }
    for (int i = 1; i <= SIZE; i++) {
        push(SIZE - i + 1);
    }
    pila[++tope] = dato;
}

//Borrar dato
int pop() {
    static int tope = 1;
    if (tope > SIZE) {
        printf("Error: la pila está vacía\n");
        exit(1);
    }
    return pila[tope++];
}
/*
// Funcion para asignar capacidad.
struct Pila* crearPila(unsigned capacity)
{
	struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
	pila->capacity = SIZE;
	pila->top = -1;
	pila->array = (int*)malloc(pila->capacity * sizeof(int));
	return pila;
}

// Pila llena
int isFull(struct Pila* pila)
{
	return pila->top == pila->capacity - 1;
}

// Pila vacia 
int isEmpty(struct Pila* pila)
{
	return pila->top == -1;
}

// Agregar un elemento a la pila
void push(struct Pila* pila, int item)
{
	if (isFull(pila))
		return;
	pila->array[++pila->top] = item;
	printf("%d Push a la pila\n", item);
}

// Quitar un elemento
int pop(struct Pila* pila)
{
	if (isEmpty(pila))
		return INT_MIN;
	return pila->array[pila->top--];
}
*/


int main(){

    char nombre;
    int opcion = 0;
    
    printf("\n\tBienvenido, como lo podemos ayudar?\n");
    printf("\nElegir una opción:\n");
    printf("1) Formarse\n2) Salir.\n");
    printf("\n->");
    scanf("%d", &opcion);
    
    switch(opcion){
        case 1:
          push ();
          break;
          printf ("\nTiene el turno &i", pila->tope);
        case 2:
          pop ();
          printf ("\nTenga buen dia\n\n");
          return 0;
        default:
          printf("Opción no válida.");
    }
        
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int pila[TAM+1]; // Pila de tamaño 11 (el índice 0 no se utiliza)

void push(int dato) {
    static int tope = 0;
    if (tope >= TAM) {
        printf("Error: la pila está llena\n");
        exit(1);
    }
    pila[++tope] = dato;
}

int pop() {
    static int tope = 1;
    if (tope > TAM) {
        printf("Error: la pila está vacía\n");
        exit(1);
    }
    return pila[tope++];
}

void sacar_de_pila() {
    int tope = 10;
    
    // Inicializar la pila
    for (int i = 1; i <= TAM; i++) {
        push(TAM - i + 1);
    }
    
    // Sacar elementos de la pila
    while (tope >= 2) {
        int dato = pop();
        printf("Elemento sacado: %d\n", dato);
    }
}

int main() {
    sacar_de_pila();
    return 0;
}*/
