#include <iostream>
#include "../../implementações/lista_encadeada/fila.hpp"
using namespace std;

int main () {
    Fila<double> F;
    F.inicializar();
    char c;
    double num;
    do {
        cout << "\nOperações: (e) enfilar, (d) desenfilar, (i) inicio, (v) vazia, (p) parar: " ; cin >> c; cout << '\n';
        switch (c) {
            case 'e': {
                cout << "Insira o número a ser inserido: "; cin >> num;
                if(F.enfilar(num)) return 1;
                else cout << "Número inserido. \n";
            } break;

            case 'd': {
                if (F.vazia()) cout << "ERRO! Fila vazia!\n";
                else cout << "Número desenfilado: " << F.desenfilar() << endl;
            } break;

            case 'i': {
                if (F.vazia()) cout << "ERRO! Fila vazia!\n";
                else cout << "Início da fila: " << F.primeiro() << endl;
            } break;

            case 'v': {
                if (F.vazia()) cout << "Fila vazia \n";
                else cout << "Fila não vazia \n";
            } break;
            
        }
    } while (c != 'p');
    F.terminar();
}