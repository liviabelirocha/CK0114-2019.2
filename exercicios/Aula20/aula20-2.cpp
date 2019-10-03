#include <iostream>
#include "../../implementações/lista_encadeada/conjunto.hpp"
using namespace std;

int main () {
    Conjunto<double> C;
    C.inicializar();
    double num; int i;
    auto end = C.fim();
    do {
        cout << "\nOperações: (1) inserir, (2) remover, (3) procurar, (4) parar: " ; cin >> i; cout << '\n';
        switch (i) {
            case 1: {
                cout << "Insira o número a ser inserido: "; cin >> num;
                if (C.pertence(num)) cout << "Erro! Número pertence ao conjunto \n";
                else if (C.inserir(num) != end) cout << "Número inserido\n";
                else cout << "Erro de alocação. \n";
            } break;

            case 2: {
                if (C.vazio()) cout << "ERRO! Conjunto vazio!\n";
                else {
                    cout << "Insira o número a ser retirado: "; cin >> num;
                    auto remove = C.procurar(num);
                    if (!C.pertence(num)) cout << "Erro! Número não pertence ao conjunto \n";
                    else {
                        (C.remover(remove));
                        cout << "Número removido\n";
                    }
                }
            } break;

            case 3: {
                if (C.vazio()) cout << "ERRO! Conjunto vazio!\n";
                cout << "Insira o número a ser procurado: "; cin >> num;
                auto look = C.procurar(num);
                if (look == end) cout << "Não pertence ao conjunto\n";
                else cout << "Pertence ao conjunto\n";
            } break;
        }
    } while (i != 4);
    C.terminar();
}