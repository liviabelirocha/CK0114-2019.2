#include <iostream>
#include "../../implementações/lista_encadeada/pilha.hpp"
using namespace std; using std::cin;

int main () {
    Pilha<double> P;
    P.inicializar();
    char c;
    double num;
    do {
        cout << "\nOperações: e (empilhar), (d) desempilhar, (t) topo, (v) vazia, (p) parar: " ; cin >> c; cout << '\n';
        switch (c) {
            case 'e': {
                cout << "Insira o número a ser inserido: "; cin >> num;
                if(P.empilhar(num)) return 1;
                else cout << "Número inserido. \n";
            } break;

            case 'd': {
                if (P.vazia()) cout << "ERRO! Pilha vazia!";
                else cout << "Número desempilhado: " << P.desempilhar() << endl;
            } break;

            case 't': {
                if (P.vazia()) cout << "ERRO! Pilha vazia!";
                else cout << "Topo da pilha: " << (P.topo)->elem << endl;
            } break;

            case 'v': {
                if (P.vazia()) cout << "Pilha vazia \n";
                else cout << "Pilha não vazia \n";
            } break;
            
        }
    } while (c != 'p');
    P.terminar();
}