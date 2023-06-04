#include <stdio.h>

#define BOARD_SIZE 8

// Función para imprimir el tablero
void imprimirTablero(int tablero[BOARD_SIZE][BOARD_SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

// Función para marcar un movimiento en el tablero
void marcarMovimiento(int tablero[BOARD_SIZE][BOARD_SIZE], int fila, int columna, char pieza) {
    tablero[fila][columna] = pieza;
}

// Función para calcular los movimientos del rey
void movimientosRey(int tablero[BOARD_SIZE][BOARD_SIZE], int fila, int columna) {
    int movimientosFila[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int movimientosColumna[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    char pieza = 'K';  // Rey

    for (int i = 0; i < 8; i++) {
        int nuevaFila = fila + movimientosFila[i];
        int nuevaColumna = columna + movimientosColumna[i];

        // Verificar si el movimiento está dentro del tablero
        if (nuevaFila >= 0 && nuevaFila < BOARD_SIZE && nuevaColumna >= 0 && nuevaColumna < BOARD_SIZE) {
            marcarMovimiento(tablero, nuevaFila, nuevaColumna, pieza);
        }
    }
}

// Función para calcular los movimientos de la reina
void movimientosReina(int tablero[BOARD_SIZE][BOARD_SIZE], int fila, int columna) {
    char pieza = 'Q';  // Reina

    // Movimientos en diagonal (arriba-izquierda, arriba-derecha, abajo-izquierda, abajo-derecha)
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (fila - i >= 0 && columna - i >= 0)
            marcarMovimiento(tablero, fila - i, columna - i, pieza);
        if (fila - i >= 0 && columna + i < BOARD_SIZE)
            marcarMovimiento(tablero, fila - i, columna + i, pieza);
        if (fila + i < BOARD_SIZE && columna - i >= 0)
            marcarMovimiento(tablero, fila + i, columna - i, pieza);
        if (fila + i < BOARD_SIZE && columna + i < BOARD_SIZE)
            marcarMovimiento(tablero, fila + i, columna + i, pieza);
    }

    // Movimientos horizontales y verticales
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i != fila)
            marcarMovimiento(tablero, i, columna, pieza);  // Movimientos verticales
        if (i != columna)
            marcarMovimiento(tablero, fila, i, pieza);  // Movimientos horizontales
    }
}

int main() {
    int tablero[BOARD_SIZE][BOARD_SIZE];

    // Inicializar el tablero con espacios en blanco
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            tablero[i][j] = ' ';
        }
    }

    // Coordenadas de la posición actual
    int fila, columna;
    char pieza;

    // Pedir al usuario la posición de la pieza
    printf ("\nEn que posicion quieres empezar: ");
    printf("\n\tFila (1-%d): ", BOARD_SIZE);
    scanf("%d", &fila);
    printf("\tColumna (1-%d): ", BOARD_SIZE);
    scanf("%d", &columna);

    // Validar coordenadas ingresadas
    if (fila < 1 || fila > BOARD_SIZE || columna < 1 || columna > BOARD_SIZE) {
        printf("Coordenadas inválidas.\n");
        return 0;
    }

    // Pedir al usuario la pieza de ajedrez
    printf("Elija la pieza de ajedrez:\n");
    printf("1- Rey\n");
    printf("2- Reina\n");
    int opcion;
    printf ("-> ");
    scanf("%d", &opcion);

    // Validar opción ingresada
    if (opcion < 1 || opcion > 2/*4*/) {
        printf("Opción inválida.\n");
        return 0;
    }

    // Marcar la posición de la pieza en el tablero
    marcarMovimiento(tablero, fila - 1, columna - 1, '*');

    // Calcular y marcar los movimientos posibles según la opción seleccionada
    switch (opcion) {
        case 1:
            movimientosRey(tablero, fila - 1, columna - 1);
            break;
        case 2:
            movimientosReina(tablero, fila - 1, columna - 1);
            break;
    }

    // Imprimir el tablero con los movimientos posibles
    imprimirTablero(tablero);

    return 0;
}
