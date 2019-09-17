#include <new>
using namespace std;

template <typename T>
struct Pilha {

    struct Noh {
        T v[100];
        Noh *prox;
        int index;
    };

    Noh *topo; 
    int elements;

    bool inicializar() {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->index = -1; n->prox = nullptr;
        topo = n; elements = 0;
        return false;
    }

    bool vazia() { return elements == 0; }

    T consultarTopo() { return topo->v[topo->index]; }

    int i(Noh *x) { return x->index; }

    int numElements() { return elements; }

    bool empilhar(T e) {
        if (i(topo) == 99) {
            Noh *n = new(nothrow) Noh;
            if (n == nullptr) return true;
            n->prox = topo; n->index = 0; n->v[i(n)] = e;
            topo = n;
        } else {
            topo->index += 1;
            topo->v[i(topo)] = e;
        }
        elements++;
        return false;
    }

    T desempilhar() {
        T elem = topo->v[i(topo)];
        if (i(topo) == 0 && topo->prox != nullptr) {
            Noh *n = topo;
            topo = topo->prox;
            delete n;
        } else { topo->index -= 1; }
        elements--;
        return elem;
    }

    void terminar() {
        while (!vazia()) desempilhar();
    }

};