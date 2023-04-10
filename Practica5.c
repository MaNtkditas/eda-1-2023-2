//Sistema de turnos

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Una estructura de la pila
int pila[SIZE+1];

//Agregar dato
int push() {
    static int tope = 0;
    if (tope >= SIZE) {
        printf("Ya no hay turnos disponibles... \n");
        //exit(1);
    }
    else 
        printf ("\nTiene el turno %i\n\n", tope+1);
    for (int i = 1; i <= SIZE; i++) {
        int cont = (SIZE - i + 1);
    }
    pila[++tope] = *pila;
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

void menu (){

    int opcion = 0;

    printf("\n\tBienvenido, como lo podemos ayudar?\n");
    printf("\nElegir una opción:\n");
    printf("1) Formarse\n2) Salir.\n");
    printf("\n->");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            push();
            //pop();
            menu ();
            break;
            return 0;
        case 2:
            pop ();
            printf ("\nTenga buen dia\n\n");
            break;
            return 0;
        default:
            printf("Opción no válida.");
    }
}

int main(){

    //int opcion = 0;
    
    /*printf("\n\tBienvenido, como lo podemos ayudar?\n");
    printf("\nElegir una opción:\n");
    printf("1) Formarse\n2) Salir.\n");
    printf("\n->");
    scanf("%d", &opcion);*/
    menu ();
    
    /*switch(opcion){
        case 1:
            push();
            //pop();
            break;
            return 0;
        case 2:
            pop ();
            printf ("\nTenga buen dia\n\n");
            break;
            return 0;
        default:
            printf("Opción no válida.");
    }*/
    return 0;
}
