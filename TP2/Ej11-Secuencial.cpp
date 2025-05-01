#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    clock_t start = clock();

    for (long i = 0; i < n; i++) {
        double x = (i + 0.5) * step;
        sum += f(x);
    }

    double pi = step * sum;

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Secuencial: pi ≈ %.15f\n", pi);
    printf("Tiempo de ejecución: %f segundos\n", time_spent);

    return 0;
}
