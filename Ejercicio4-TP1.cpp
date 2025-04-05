#define _USE_MATH_DEFINES


#include <iostream>
#include <chrono>
#include <cmath>    // para std::abs si se desea calcular error
#include <iomanip>  // para std::setprecision
#include <numbers> // std::numbers

using namespace std;

int main() {
    // Pedimos el número de subdivisiones
    cout << "Ingrese el numero de subdivisiones n: ";
    long long n;
    cin >> n;

    // Variables para la integración
    double h = 1.0 / static_cast<double>(n); // ancho de cada subintervalo
    double suma = 0.0;
    
    // Tomamos el tiempo inicial
    auto inicio = chrono::high_resolution_clock::now();

    // Realizamos la suma de Riemann (Regla del punto izquierdo)
    for (long long i = 0; i < n; ++i) {
        // x_i: extremo izquierdo de cada subintervalo
        long double x_i = i * h;
        long double f_xi = 4.0 / (1.0 + x_i * x_i);
        suma += f_xi;
    }

    // Multiplicamos por el ancho de cada subintervalo para obtener la aproximacion
    long double pi_aprox = h * suma;

    // Tomamos el tiempo final
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;

    // Mostramos los resultados
    cout << fixed << setprecision(10);
    cout << "Aproximacion de pi = " << pi_aprox << endl;
    // Si se desea, podemos calcular el error respecto a M_PI (definida en <cmath>):
    cout << "Error absoluto     = " << fabs(pi_aprox - M_PI) << endl;
    cout << "Tiempo de ejecucion (segundos) = " << duracion.count() << endl;

    return 0;
}
