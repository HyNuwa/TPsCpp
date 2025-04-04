#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para std::sort

int main() {
    int n;
    std::cout << "Ingrese el numero de numeros a ordenar: ";
    std::cin >> n;

    std::vector<int> numeros;
    numeros.reserve(n);

    std::cout << "Ingrese " << n << " numeros:\n";

    // Leer n números desde la entrada estándar
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numeros.push_back(num);
    }

    // Ordenar el vector en orden ascendente
    //std::sort(numeros.begin(), numeros.end());
    // Ordenar el vector en orden descendente
    // std::sort(numeros.rbegin(), numeros.rend());
    // Alternativa: std::sort(numeros.begin(), numeros.end(), std::greater<int>());

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

    // Mostrar el vector ordenado
    std::cout << "Vector ordenado:\n";
    for (const int& num : numeros) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}
