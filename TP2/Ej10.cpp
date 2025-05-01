#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <omp.h>

int main() {
    int n;
    std::cout << "Ingrese el tamano del vector de numeros a ordenar: ";
    std::cin >> n;

    std::vector<int> numeros(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 1000000);

    for (int i = 0; i < n; ++i) {
        numeros[i] = distrib(gen);
    }

    auto inicio = std::chrono::high_resolution_clock::now();

    // Odd-Even Transposition Sort paralelo
    for (int phase = 0; phase < n; ++phase) {
        if (phase % 2 == 0) { // Fase par
            #pragma omp parallel for
            for (int i = 0; i < n - 1; i += 2) {
                if (numeros[i] > numeros[i + 1]) {
                    std::swap(numeros[i], numeros[i + 1]);
                }
            }
        } else { // Fase impar
            #pragma omp parallel for
            for (int i = 1; i < n - 1; i += 2) {
                if (numeros[i] > numeros[i + 1]) {
                    std::swap(numeros[i], numeros[i + 1]);
                }
            }
        }
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Tiempo transcurrido (paralelo): " << duracion.count() << " segundos" << std::endl;

    return 0;
}