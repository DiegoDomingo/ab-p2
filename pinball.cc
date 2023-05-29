/*
* AUTORES:     Diego Domingo Ralla (818637)
*              Simón Alonso Gutiérrez (821038)
* ASIGNATURA:  Algoritmia Básica
* FECHA:       19 abril 2023
* FICHERO:     pinball.cc
* DESCRIPCIÓN: Programa que simula una máquina de pinball dejando caer una 
*              cantidad de n bolas y calcula la posición de parada de cada bola
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

// Busca el nodo en el que caerá la i-ésima bola en un árbol de profundidad p
// Pre:  i <= 2^(p-1) ∧ nodo <= 2^p - 1
// Post: devuelve el número del siguiente nodo por el que pasará la bola i
unsigned long long busquedaInm(int p, unsigned long long i, unsigned long long nodo) {
    if (p == 1) {
        return nodo;
    }
    else {
        // Si la bola es impar, se busca por el subárbol izquierdo
        if (i % 2 != 0) {
            return busquedaInm(p - 1, (i + 1) / 2, nodo * 2);
        }
        // Si es par, se busca por el subárbol derecho
        else {
            return busquedaInm(p - 1, i / 2, nodo * 2 + 1);
        }
        // En ambos casos se recalcula el índice de la bola para el subárbol
        // correspondiente
    }
}

// Busca el nodo en el que caerá la i-ésima bola en un árbol de profundidad p
// Pre:  i <= 2^(p-1) 
// Post: devuelve el número de nodo donde caerá la bola i
unsigned long long busqueda(int p, int i) {
    return busquedaInm(p, i, 1);
}

int main(int argc, char* argv[]) {
    int p;
    unsigned long long n;
    time_point<high_resolution_clock> start, end;
    ifstream f;

    if (argc != 3) {
        cerr << "Uso: pinball.cc pruebas.txt resultados.txt" << endl;
        return 1;
    }

    f.open(argv[1]);
    if (f.is_open()) {
        ofstream g;
        g.open(argv[2], ios::trunc);
        if (g.is_open()) {
            while (!f.eof()) {
                f >> p >> n;
                if (n > pow(2, p - 1)) {
                    g << "Prueba inválida, n mayor que número de hojas" << endl;
                }
                else {
                    g << "Búsqueda con p = " << p << " y n = " << n << endl;
                    double media = 0.0;
                    for (unsigned long long i = 1; i <= n; i++) {
                        start = high_resolution_clock::now();
                        g << "Bola " << i << " -> " << busqueda(p, i);
                        end = high_resolution_clock::now();
                        auto tiempo = duration_cast<nanoseconds>(end - start).count();
                        g << "  Tiempo: " << tiempo << "ns\n";
                        media += tiempo;
                    }
                    g << "----- TIEMPO MEDIO BÚSQUEDA " << media / n << "ns -----\n";
                    g << endl;
                }
            }
        }
        g.close();
    }
    f.close();
}
