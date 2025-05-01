#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>

using namespace std;

double f(double x) {
    return 4.0 / (1.0 + x * x);
}

int main() {
    // Pedimos el número de subdivisiones
    cout << "Ingrese el numero de subdivisiones n: ";
    long long n;
    cin >> n;
    double step = 1.0 / (double)n;
    double sum = 0.0;

    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < n; i++) {
        double x = (i + 0.5) * step;
        sum += f(x);
    }

    double pi = step * sum;

    double end = omp_get_wtime();
    double time_spent = end - start;

    printf("Paralelo: pi ≈ %.15f\n", pi);
    printf("Tiempo de ejecución: %f segundos\n", time_spent);

    return 0;
}
