//Sistema de turnos
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Una estructura de la pila
struct Pila {
	int top;
  unsigned capacity;;
	int* array;
};

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

int main(){

char nombre;
short opcion = 0, contador;

printf("\n\tBienvenido, como lo podemos ayudar?\n");
    for (contador=0 ; contador<10; contador++)
    printf("\nElegir una opción:\n");
    printf("1) Formarse\t2) Salir.\n");
    printf("\n->");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
          printf ("\nTiene el turno &i", *Pila->top);
          break;
        case 2:
          printf ("\nTenga buen dia\n\n");
          return 0;
        default:
    printf("Opción no válida.");
    }
 }
