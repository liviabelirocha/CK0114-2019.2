#include <iostream>
#include "../../implementações/lista_encadeada/deque.hpp"
using namespace std;

int main () {
    Deque<double> D;
    D.inicializar();
    char c;
    double num;
    do {
        cout << "\nOPERAÇÕES\n(e) inserir a esquerda, (d) inserir a direita\n(r) remover da esquerda, (f) remover da direita\n(t) consultar esquerda, (g) consultar direita\n(v) vazia, (p) parar: " ; cin >> c; cout << '\n';
        switch (c) {
            case 'e': {
                cout << "Insira o número a ser inserido na esquerda: "; cin >> num;
                if(D.inserir_esq(num)) return 1;
                else cout << "Número inserido. \n";
            } break;

            case 'd': {
                cout << "Insira o número a ser inserido na direita: "; cin >> num;
                if(D.inserir_dir(num)) return 1;
                else cout << "Número inserido. \n";
            } break;

            case 'r': {
                if (D.vazia()) cout << "ERRO! Deque vazio!\n";
                else cout << "Número removido: " << D.remover_esq() << endl;
            } break;

            case 'f': {
                if (D.vazia()) cout << "ERRO! Deque vazio!\n";
                else cout << "Número removido: " << D.remover_dir() << endl;
            } break;

            case 't': {
                if (D.vazia()) cout << "ERRO! Deque vazio!\n";
                else cout << "Elemento da esquerda: " << D.consultar_esq() << endl;
            } break;

            case 'g': {
                if (D.vazia()) cout << "ERRO! Deque vazio!\n";
                else cout << "Elemento da direita: " << D.consultar_dir() << endl;
            } break;

            case 'v': {
                if (D.vazia()) cout << "Deque vazio \n";
                else cout << "Deque não vazio \n";
            } break;
            
        }
    } while (c != 'p');
    D.terminar();
}