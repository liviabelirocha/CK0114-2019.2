#include <iostream>
#include "../../implementações/resize/dicionario.hpp"
using namespace std; using std::cin;

int main () {
    Dicionario<char, double> D;
    if (D.inicializar()) return 1;
    char c, key;
    double num;
    do {
        cout << "\nOperações: i (inserir), (r) remover, (p) pertence, (s) parar: " ; cin >> c; cout << '\n';
        switch (c) {
            case 'i': {
                cout << "Insira a chave a ser inserida (um caractere): "; cin >> key;
                cout << "Insira o número a ser inserido: "; cin >> num;
                Par<bool, bool> r = D.inserir(key, num);
                if (r.x) cout << "Chave já pertence ao conjunto. \n";
                else if (!(r.x) && (r.y)) {
                    cout << "Erro de alocação!\n";
                } else if (!(r.x) && !(r.y)) {
                    cout << "Chave inserida!\n";
                }
            } break;

            case 'r': {
                cout << "Insira a chave a ser removida (um caractere): "; cin >> key;
                Par<bool, bool> j = D.remover(key);
                if (j.x) cout << "Chave não pertence ao conjunto. \n";
                else if (!(j.x) && (j.y)) {
                    cout << "Erro de alocação!\n";
                }
                else if (!(j.x) && !(j.y)) {
                    cout << "Chave removida!\n";
                }
            } break;

            case 'p': {
                cout << "Pesquisar chave: "; cin >> key;
                Par<bool, double> k = D.procurar(key);
                if (k.x) cout << key << ": " << k.y << '\n';
                else if (!(k.x)) cout << "Chave não encontrada. \n";
            } break;
        }
    } while (c != 's');
    D.terminar();
}