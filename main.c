#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_1D 1000
#define SIZE_2D 1000
#define SIZE_3D 1000

int main() {
    int choice;
    printf("Selecciona el tamaño del arreglo:\n");
    printf("1. Arreglo de 1000 elementos (1D)\n");
    printf("2. Arreglo de 1000x1000 elementos (2D)\n");
    printf("3. Arreglo de 1000x1000x1000 elementos (3D)\n");
    printf("Opción: ");
    scanf("%d", &choice);

    clock_t start, end;
    volatile int temp; // Evita optimización del compilador
    srand(time(NULL)); // Inicializa la semilla de números aleatorios

    if (choice == 1) {
        // 1D Array
        int *array1D = (int *)malloc(SIZE_1D * sizeof(int));
        if (!array1D) {
            printf("Error al asignar memoria.\n");
            return 1;
        }

        // Inicialización con números aleatorios
        printf("Inicializando arreglo...\n");
        for (int i = 0; i < SIZE_1D; i++) {
            array1D[i] = rand();
        }

        printf("Recorriendo arreglo...\n");
        start = clock(); // Medición empieza después de la inicialización
        for (int i = 0; i < SIZE_1D; i++) {
            temp = array1D[i]; // Recorrido sin modificaciones
        }
        end = clock(); // Medición termina después del recorrido

        free(array1D);
    }
    else if (choice == 2) {
        // 2D Array
        int **array2D = (int **)malloc(SIZE_2D * sizeof(int *));
        if (!array2D) {
            printf("Error al asignar memoria.\n");
            return 1;
        }
        for (int i = 0; i < SIZE_2D; i++) {
            array2D[i] = (int *)malloc(SIZE_2D * sizeof(int));
            if (!array2D[i]) {
                printf("Error al asignar memoria.\n");
                return 1;
            }
        }

        // Inicialización con números aleatorios
        printf("Inicializando arreglo...\n");
        for (int i = 0; i < SIZE_2D; i++) {
            for (int j = 0; j < SIZE_2D; j++) {
                array2D[i][j] = rand();
            }
        }

        printf("Recorriendo arreglo...\n");
        start = clock();
        for (int i = 0; i < SIZE_2D; i++) {
            for (int j = 0; j < SIZE_2D; j++) {
                temp = array2D[i][j]; // Recorrido sin modificaciones
            }
        }
        end = clock();

        for (int i = 0; i < SIZE_2D; i++) {
            free(array2D[i]);
        }
        free(array2D);
    }
    else if (choice == 3) {
        // 3D Array
        int ***array3D = (int ***)malloc(SIZE_3D * sizeof(int **));
        if (!array3D) {
            printf("Error al asignar memoria.\n");
            return 1;
        }
        for (int i = 0; i < SIZE_3D; i++) {
            array3D[i] = (int **)malloc(SIZE_3D * sizeof(int *));
            if (!array3D[i]) {
                printf("Error al asignar memoria.\n");
                return 1;
            }
            for (int j = 0; j < SIZE_3D; j++) {
                array3D[i][j] = (int *)malloc(SIZE_3D * sizeof(int));
                if (!array3D[i][j]) {
                    printf("Error al asignar memoria.\n");
                    return 1;
                }
            }
        }

        // Inicialización con números aleatorios
        printf("Inicializando arreglo...\n");
        for (int i = 0; i < SIZE_3D; i++) {
            for (int j = 0; j < SIZE_3D; j++) {
                for (int k = 0; k < SIZE_3D; k++) {
                    array3D[i][j][k] = rand();
                }
            }
        }

        printf("Recorriendo arreglo...\n");
        start = clock();
        for (int i = 0; i < SIZE_3D; i++) {
            for (int j = 0; j < SIZE_3D; j++) {
                for (int k = 0; k < SIZE_3D; k++) {
                    temp = array3D[i][j][k]; // Recorrido sin modificaciones
                }
            }
        }
        end = clock();

        for (int i = 0; i < SIZE_3D; i++) {
            for (int j = 0; j < SIZE_3D; j++) {
                free(array3D[i][j]);
            }
            free(array3D[i]);
        }
        free(array3D);
    }
    else {
        printf("Opción inválida.\n");
        return 1;
    }

    // Imprimir el tiempo de ejecución
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de recorrido: %.10f segundos\n", elapsed_time);

    return 0;
}
