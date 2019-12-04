#include "trabalho3.hpp"
#include <iostream>

int main() {
    double a;
    DicioDisp<int, double> d;
    d.inicializar();
    d.inserir(1,2);
    d.remover(1);
    if (d.procurar(1, a)) cout << "y";
    else cout << "N";
    d.terminar();
}