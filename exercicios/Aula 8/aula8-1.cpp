#include <iostream>
#include <new>

using std::cout; using std::cin; using std::nothrow;

template <typename T>
struct Pilha {
    T *v;
    int ult, tam_v;

    bool inicializar() {
        v = new(nothrow) T [1];
        if( v == nullptr ) return true;
        ult = -1;
        tam_v = 1;
        return false;
    }

    void terminar() { delete [] v; }

    bool vazia() {
        return ( ult == -1 );
    }

    //Pré-condição: pilha não vazia
    T topo() { return v[ult]; }

    //Pré-condição: ult+1 <= tam_w 
    bool redimensionar(int tam_w) {
        T *w = new(nothrow) T [tam_w];
        if ( w == nullptr ) return true;
        for (int i; i <= ult; i += 1) w[i] = v[i];
        return false;
    }

    bool empilhar(T e) {
        if ( ult == tam_v - 1 ) {
            if ( redimensionar(tam_v*2) ) return true;
        }
        ult += 1;
        v[ult] = e;
        return false;
    }

    //Pré-condição: pilha não vazia
    bool desempilhar() {
        ult -= 1;
        if ( !vazia() && 4*(ult+1) <= tam_v ) {
            if ( redimensionar(tam_v/2) ) return true;
        }
        delete [] v;
        v = w;
        tam_v = tam_w;
        return false;
    }
};

int main () {
    Pilha<double> pilha;
    if ( pilha.inicializar() ) return 1;
    char* command;
    cout << "Entre o comando (adicionar, remover, sair): "; cin >> command;
    while (command != "sair") {
        if (command == "adicionar") {
            double num;
            cout << "Entre o número a ser adicionado: "; cin >> num;
            if ( pilha.empilhar(num) ) return 2;
        } else if ( command == "remover") {
            if ( pilha.desempilhar() ) return 3;
        } else cout << "Entre um comando válido";
    }
    pilha.terminar();
}