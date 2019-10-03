#include "trabalho2.hpp"

int main () {
    SimulAloc SA;
    SA.inicializar(10, 50);
    SA.printSimul();
    SA.alocar(15);
    SA.printSimul();
    SA.alocar(20);
    SA.printSimul();
    SA.alocar(30);
    SA.printSimul();
    SA.desalocar(45, 15);
    SA.printSimul();
    SA.alocar(5);
    SA.printSimul();
    SA.desalocar(20, 5);
    SA.printSimul();
    SA.desalocar(25, 20);
    SA.printSimul();
    SA.terminar();
}