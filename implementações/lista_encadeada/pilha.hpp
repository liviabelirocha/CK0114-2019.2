#include <new>
using namespace std;

template <typename T>
struct Pilha {

    struct Noh {
        T elem;
        Noh *prox;
    };

    Noh *topo;

    void inicializar() { topo = nullptr; }

    bool vazia() { return topo == nullptr; }

    T consultarTopo() { return topo->elem; }

    bool empilhar(T e) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->prox = topo; n->elem = e;
        topo = n;
        return false;
    }

    T desempilhar() {
        T elem = topo->elem;
        topo = topo->prox;
        return elem;
    }

    void terminar() {
        while (topo != nullptr) {
            Noh *n;
            n = topo->prox;
            free(topo);
            topo = n;
        }
    }
};