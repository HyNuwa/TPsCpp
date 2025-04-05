#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para std::sort (aunque en este ejemplo se usa Bubble Sort)
#include <chrono>
#include <random>    // Para generar números aleatorios
#include <iomanip> 

int main() {
    int n;
    std::cout << "Ingrese el tamano del vector de numeros a ordenar: ";
    std::cin >> n;

    std::vector<int> numeros;
    numeros.reserve(n);

    // Configurar el generador y la distribución para números entre 1 y 1,000,000
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 1000000);

    // Generar n números aleatorios
    for (int i = 0; i < n; ++i) {
        int num = distrib(gen);
        numeros.push_back(num);
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    
    // Algoritmo Bubble Sort para ordenar en forma ascendente
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numeros[j] > numeros[j + 1]) {
                // Intercambiar elementos
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Tiempo transcurrido: " << duracion.count() << " segundos" << std::endl;

    // Mostrar el vector ordenado
    /*std::cout << "Vector ordenado:\n";
    for (const int& num : numeros) {
        std::cout << num << ' ';
    }
    std::cout << '\n';*/

    return 0;
}
