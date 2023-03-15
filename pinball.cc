#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;
long long unsigned int busquedaInm(int p, int i, int nodo) {
    if (p == 1) {
        return nodo;
    }
    else {
        if (i % 2 != 0) {
            return busquedaInm(p-1, ceil(i / 2.0), nodo * 2);
        }
        else {
            return busquedaInm(p-1, ceil(i / 2.0), nodo * 2 + 1);
        }
    }
}

long long unsigned int busqueda(int p, int i) {
    return busquedaInm(p, i, 1);
}

int main(int argc, char* argv[]) {
    int p, n;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int total_ns = 0;
    ifstream f;
    f.open(argv[1]);
    if (f.is_open()) {
        ofstream g;
        g.open(argv[2],ios::trunc);
        if (g.is_open()) {
            while (!f.eof()) {
                f >> p >> n;
                if (n > pow(2, p-1)) {
                    g << "Prueba inválida, n mayor que número de hojas" << endl;
                }
                else {
                    g << "Búsqueda con p = " << p << " y n = " << n << endl;
                    for (int i = 1; i <= n; i++) {
                        start = std::chrono::system_clock::now();
                        g << "Bola " << i << " -> " << busqueda(p, i);
                        end = std::chrono::system_clock::now();
                        std::chrono::duration<double> elapsed_seconds = end - start;
                        auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_seconds);
                        g << "  Tiempo: " << nanoseconds.count() << "ns\n";
                        total_ns += nanoseconds.count();
                    }
                    g << "----- TIEMPO TOTAL " << total_ns << "ns -----\n";
                    g << endl;
                }
            }
        }
        g.close();
    }
    f.close();
}

    
    
     
  
             
