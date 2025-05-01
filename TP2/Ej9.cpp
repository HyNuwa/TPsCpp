#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <omp.h>

using namespace std;

bool esPrimo(int num)
{
    if (num < 2)
        return false;
    for (int j = 2; j <= sqrt(num); j++)
    {
        if (num % j == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Ingresa el número de primos a calcular: ";
    cin >> n;

    // Estimar un límite superior usando la aproximación del n-ésimo primo.
    int limite = static_cast<int>(n * (log(n) + log(log(n))));

    vector<int> primos;
    primos.reserve(n);

    auto inicio = chrono::high_resolution_clock::now();

    #pragma omp parallel for schedule(dynamic)
    for (int i = 2; i <= limite; i++){
        if (esPrimo(i)){
            // Sección crítica para evitar condiciones de carrera
            #pragma omp critical
            {
                primos.push_back(i);
            }
            //cout << i << endl; //Descomentar para 
        }
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;

    cout << fixed << setprecision(10);
    cout << "Tiempo de ejecución paralelo: " << duracion.count() << " segundos" << endl;

    return 0;
}
