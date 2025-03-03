#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 1000
#define COLUMNAS 1000

// Funci�n para llenar la matriz con n�meros aleatorios ordenados
void llenarArreglo(int **arr) {
    srand(time(NULL)); // Inicializar la semilla aleatoria
    int i, j;
    for (i = 0; i < FILAS; i++) {
        int valor = rand() % 10; // Comenzar con un valor aleatorio base
        for (j = 0; j < COLUMNAS; j++) {
            valor += rand() % 10; // Asegurar que los n�meros sean crecientes
            arr[i][j] = valor;
        }
    }
}

// Funci�n de b�squeda binaria en una fila espec�fica
int busquedaBinaria(int arr[], int tamanio, int x) {
    int inicio = 0, fin = tamanio - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == x)
            return medio; // Elemento encontrado
        else if (arr[medio] < x)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1; // Elemento no encontrado
}

int main() {
    // Asignar memoria din�mica para la matriz
    int **matriz = (int **)malloc(FILAS * sizeof(int *));
    for (int i = 0; i < FILAS; i++) {
        matriz[i] = (int *)malloc(COLUMNAS * sizeof(int));
    }

    if (matriz == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    llenarArreglo(matriz); // Llenar la matriz con n�meros aleatorios ordenados

    int x;
    printf("Introduce el n�mero a buscar: ");
    scanf("%d", &x);

    clock_t inicioTiempo = clock(); // Capturar timestamp antes de la b�squeda

    int encontrado = 0; // Variable para verificar si se encontr� el n�mero
    for (int i = 0; i < FILAS; i++) {
        int resultado = busquedaBinaria(matriz[i], COLUMNAS, x);
        if (resultado != -1) {
            printf("N�mero %d encontrado en fila %d, columna %d\n", x, i, resultado);
            encontrado = 1;
        }
    }

    clock_t finTiempo = clock(); // Capturar timestamp despu�s de la b�squeda
    double tiempoEjecutado = ((double)(finTiempo - inicioTiempo)) / CLOCKS_PER_SEC * 1000; // Convertir a ms

    if (!encontrado) {
        printf("N�mero %d no encontrado en la matriz.\n", x);
    }

    printf("Tiempo de ejecuci�n: %.4f ms\n", tiempoEjecutado);

    // Liberar memoria
    for (int i = 0; i < FILAS; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
