#include <iostream>
#include <cmath> // Para sqrt()
#include <chrono>

using namespace std;

int main() {
    
    int n, i = 2, contador_primos = 0;
    cin >> n;
    
    auto inicio = std::chrono::high_resolution_clock::now();

    while (contador_primos < n) {
        bool es_primo = true;
        // Optimización: Verificar divisores hasta la raíz cuadrada de i
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                es_primo = false;
                break; // No es primo, salir del ciclo
            }
        }
        if (es_primo) {
            cout << i << " ";
            contador_primos++;
        }
        i++;
    }
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo transcurrido: " << duracion.count() << " segundos" << std::endl;

    return 0;
}