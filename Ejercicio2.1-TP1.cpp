#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cout << "Ingrese el número de números a ordenar: ";
    std::cin >> n;

    std::vector<int> numeros;
    numeros.reserve(n);

    std::cout << "Ingrese " << n << " números:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numeros.push_back(num);
    }

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

    std::cout << "Vector ordenado:\n";
    for (const int& num : numeros) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}
