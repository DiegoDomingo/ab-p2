#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

unsigned long long busquedaInm(int p, int i, unsigned long long nodo) {
    if (p == 1) {
        return nodo;
    }
    else {
        if (i % 2 != 0) {
            return busquedaInm(p - 1, (i + 1) / 2, nodo * 2);
        }
        else {
            return busquedaInm(p - 1, i / 2, nodo * 2 + 1);
        }
    }
}

unsigned long long busqueda(int p, int i) {
    return busquedaInm(p, i, 1);
}

int main(int argc, char* argv[]) {
    int p, n;
    time_point<high_resolution_clock> start, end;
    ifstream f;
    f.open(argv[1]);
    if (f.is_open()) {
        ofstream g;
        g.open(argv[2],ios::trunc);
        if (g.is_open()) {
            while (!f.eof()) {
                f >> p >> n;
                if (n > pow(2, p - 1)) {
                    g << "Prueba inválida, n mayor que número de hojas" << endl;
                }
                else {
                    g << "Búsqueda con p = " << p << " y n = " << n << endl;
                    double media = 0.0;
                    for (int i = 1; i <= n; i++) {
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
