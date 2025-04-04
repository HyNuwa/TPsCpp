#include <iostream>
#include <cmath>

// Función que calcula la aproximación de π utilizando la regla del punto medio
double calcular_pi(int n) {
    double ancho_subintervalo = 1.0 / n;
    double suma = 0.0;

    for (int i = 0; i < n; ++i) {
        double x_medio = (i + 0.5) * ancho_subintervalo;
        suma += 4.0 / (1.0 + x_medio * x_medio);
    }

    return suma * ancho_subintervalo;
}

int main() {
    int n;
    std::cout << "Ingrese el numero de subintervalos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "El número de subintervalos debe ser mayor que cero." << std::endl;
        return 1;
    }

    double pi_aproximado = calcular_pi(n);
    std::cout << "Aproximacion de PI con " << n << " subintervalos: " << pi_aproximado << std::endl;

    return 0;
}
