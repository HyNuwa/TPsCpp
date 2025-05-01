#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "El tamaño del vector debe ser un número positivo.\n");
        return 1;
    }

    // Declaramos un arreglo de longitud variable (VLA)
    int vector[n];

    // Inicializar el generador de números aleatorios
    srand(time(NULL));
    // Llenar el vector con números aleatorios entre 0 y n
    for (int i = 0; i < n; i++) {
        vector[i] = rand() % n;
    }

    long suma = 0;
    clock_t inicio = clock();

    // Esta directiva se comporta de forma paralela si compilamos con -fopenmp
    #pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < n; i++) {
        suma += vector[i];
    }

    clock_t fin = clock();
    double tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;

    printf("La suma total es: %ld\n", suma);
    printf("Tiempo de ejecución: %f segundos\n", tiempo);

    return 0;
}
