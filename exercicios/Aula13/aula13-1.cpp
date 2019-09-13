#include <iostream>
#include "../../implementações/resize/conjunto.hpp"
using std::string; using std::cout; using std::cin;

int main () {
    Conjunto<double> C;
    if (C.inicializar()) return 1;
    char c;
    double num;
    do {
        cout << "\nOperações: i (inserir), (r) remover, (p) pertence, (s) parar, (m) mostrar elementos: " ; cin >> c;
        cout << '\n';
        switch (c) {
            case 'i':
                cout << "Insira o número a ser inserido: "; cin >> num;
                //if (!C.pertence(num)) {
                //    if (C.inserir(num)) return 2;
                if (C.inserir_se_nao_pertence(num)) return 2;
                //else cout << "Elemento já pertence ao conjunto. \n";
                break;

            case 'r':
                cout << "Insira o número a ser removido: "; cin >> num;
                //if (C.pertence(num)) {
                //    if (C.remover(num)) return 3;
                if (C.remover_se_pertencer(num)) return 3;
                //else cout << "Elemento não pertence ao conjunto. \n";
                break;

            case 'p':
                cout << "Pesquisar número: "; cin >> num;
                if (C.pertence(num)) cout << "Esse número pertence ao conjunto. \n";
                else cout << "Esse número não pertence ao conjunto. \n";
                break;

            //Exercício 1 da Aula 14
            case 'm':
                cout << "Mostrando conjunto... \n";
                auto fim = C.fim();
                for (auto i = C.inicio(); i != fim; ++i) cout << ' ' << *i;
                break;
        }
    } while (c != 's');
    
}