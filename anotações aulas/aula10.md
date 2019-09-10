#Aula 10 - 02/09/2019

#Pilha via Vetor

1. Um exemplo de uso:

```cpp
#include <iostream>
using std::cin; using std::cout;

#include "pilha.hpp"
int main() {
    pilha<double> p;
    if (p.inicializar()) return 1;
    
    for(;;){
        cout << "Número para empilhar (negativo para terminar): ";
        double num; cin >> num;
        if (num < 0) break;
        if (p.empilhar(num)) return 2;
    }

    cout << "Os números digitados, do último para o primeiro, foram: ";

    while (!p.vazia()) { 
        cout << ' ' << p.topo();
        if ( p.desempilhar() ) return 3;      
    }

    p.terminar();
}
```

2. Uma implementação de pilha: ("pilha.hpp")

```cpp
//Omitindo guardas de inclusão...
#include <new>
using std::nothrow;

template <typename T>
struct Pilha {
    T *v; T *w;
    int ult, tam_v, tam_w;

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
        w = new(nothrow) T [tam_w];
        if ( w == nullptr ) return true;
        for (int i; i <= ult; i += 1) w[i] = v[i];
        delete [] v;
        v = w;
        tam_v = tam_w;
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
        return false;
    }
};