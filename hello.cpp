// ejemplo.cpp
// --------------------------------------------------------------------
// Resumen de conceptos y funciones más usados en C++:
//
// 1. main(): Función principal, punto de entrada del programa.
// 2. std::cout y std::cin: Para salida y entrada de datos por consola.
// 3. std::string: Para manipulación de cadenas de texto.
// 4. Funciones personalizadas: Permiten modularizar el código, por ejemplo,
//    funciones para sumar, restar, multiplicar y dividir.
// 5. Operadores aritméticos: Usados para realizar operaciones matemáticas.
// 6. Manejo de errores: Ejemplo, verificación de división por cero.
// --------------------------------------------------------------------

#include <iostream>
#include <string>

// Declaración de variables globales de diferentes tipos
int entero = 10;                 // Variable entera
double doble = 3.14;             // Variable de tipo doble (precisión doble)
float flotante = 2.718f;         // Variable de tipo flotante
char caracter = 'A';             // Variable de tipo carácter
bool booleano = true;            // Variable booleana
std::string cadena = "Hola, Mundo!"; // Variable de tipo cadena
const double PI = 3.14159; // Constante de tipo doble

// Prototipos de funciones
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
double dividir(int a, int b);

int main() {
    // Mostrando variables
    std::cout << "Variables:" << std::endl;
    std::cout << "entero: " << entero << std::endl;
    std::cout << "doble: " << doble << std::endl;
    std::cout << "flotante: " << flotante << std::endl;
    std::cout << "caracter: " << caracter << std::endl;
    std::cout << "booleano: " << (booleano ? "true" : "false") << std::endl;
    std::cout << "cadena: " << cadena << std::endl;
    
    std::cout << "\nFunciones:" << std::endl;
    int a = 20, b = 5;
    std::cout << "Sumar (" << a << " + " << b << "): " << sumar(a, b) << std::endl;
    std::cout << "Restar (" << a << " - " << b << "): " << restar(a, b) << std::endl;
    std::cout << "Multiplicar (" << a << " * " << b << "): " << multiplicar(a, b) << std::endl;
    std::cout << "Dividir (" << a << " / " << b << "): " << dividir(a, b) << std::endl;

    // Ordenar el vector en orden ascendente
    //std::sort(numeros.begin(), numeros.end());
    // Ordenar el vector en orden descendente
    // std::sort(numeros.rbegin(), numeros.rend());
    // Alternativa: std::sort(numeros.begin(), numeros.end(), std::greater<int>());

    

    return 0;
}

// Definición de funciones

// Función para sumar dos enteros
int sumar(int a, int b) {
    return a + b;
}

// Función para restar dos enteros
int restar(int a, int b) {
    return a - b;
}

// Función para multiplicar dos enteros
int multiplicar(int a, int b) {
    return a * b;
}

// Función para dividir dos enteros, verificando división por cero
double dividir(int a, int b) {
    if(b != 0) {
        return static_cast<double>(a) / b;
    } else {
        std::cerr << "Error: Division por cero." << std::endl;
        return 0;
    }
}
