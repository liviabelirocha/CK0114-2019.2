#include <iostream>
using std::cin; using std::cout;

#include "fila.hpp"

int main () {
    Fila<double> F;
    if(F.inicializar()) return 1;
    for(;;) {
        cout << "Digite um número (negativo para parar): \n";
        double num; cin >> num;
        if(num < 0) break;
        if(F.enfilar(num)) return 2;
    }
    cout << "Aqui estão os números: ";
    while(!F.vazia()) {
        cout << ' ' << F.primeiro();
        if(F.desenfilar()) return 3;
    }
    cout << '\n';
    F.terminar();
}