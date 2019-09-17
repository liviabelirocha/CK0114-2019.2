#include <iostream>
#include "aula16-1.hpp"
using namespace std;

int main () {
    Pilha<double> P;
    P.inicializar();
    char c;
    double num;
    do {
        cout << "\nOperações: (e) empilhar, (d) desempilhar, (t) topo, (v) vazia, (p) parar, (n) número de elementos: " ; cin >> c; cout << '\n';
        switch (c) {
            case 'e': {
                cout << "Insira o número a ser inserido: "; cin >> num;
                if(P.empilhar(num)) return 1;
                else cout << "Número inserido. \n";
            } break;

            case 'd': {
                if (P.vazia()) cout << "ERRO! Pilha vazia!\n";
                else cout << "Número desempilhado: " << P.desempilhar() << endl;
            } break;

            case 't': {
                if (P.vazia()) cout << "ERRO! Pilha vazia!\n";
                else cout << "Topo da pilha: " << P.consultarTopo() << endl;
            } break;

            case 'v': {
                if (P.vazia()) cout << "Pilha vazia \n";
                else cout << "Pilha não vazia \n";
            } break;

            case 'n': {
                cout << "A pilha tem " << P.numElements() << " elementos. \n";
            } break;
            
        }
    } while (c != 'p');
    P.terminar();
}