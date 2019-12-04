#include <new>
using namespace std;

template <typename T>
struct Conjunto{
    struct node {
        T v[5];
        node *prox, *ant;
        int index;
    };

    node sentinel;

    void inicializar() { sentinel.prox = sentinel.ant = &sentinel; }

    bool vazio() { return sentinel.prox == &sentinel; }

    int i(node *x) { return x->index; }

    bool inserir(T e) {
        if (vazio()) {
            node *n = new (nothrow) node;
            if (n == nullptr) return true;
            n->index = 0; n->v[i(n)] = e;
            sentinel.prox = sentinel.ant = n;
            n->prox = n->ant = &sentinel;
        } else if (i(sentinel.prox) == 4) {
            node *n = new (nothrow) node;
            if (n == nullptr) return true;
            n->index = 0; n->v[i(n)] = e;
            n->ant = &sentinel; n->prox = sentinel.prox;
            sentinel.prox = n;
            n->prox->ant = n;
        } else {
            sentinel.prox.index += 1; //se der ruim pode ser aqui talvez
            sentinel.prox.v[i(sentinel.prox)] = e;
        }
        return false;
    }

    void remover(T e) {

    }
};
