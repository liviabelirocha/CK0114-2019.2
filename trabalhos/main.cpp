#include "trabalho3.hpp"

int main() {
    DicioDisp<int> d;
    d.inicializar();
    d.print();
    d.inserir(4, 2);
    d.print();
    d.inserir(3,2);
    d.print();
    d.inserir(7,2);
    d.print();
    d.inserir(5,2);
    d.print();
    d.inserir(2,2);
    d.print();
    d.inserir(8,2);
    d.print();
    d.inserir(6,2);
    d.print();
    d.inserir(10,2);
    d.print();
    d.inserir(11,2);
    d.print();
    d.inserir(18,2);
    d.print();
    d.remover(2);
    d.remover(4);
    d.remover(3);
    d.remover(7);
    d.remover(5);
    d.remover(2);
    d.remover(8);
    d.print();
}