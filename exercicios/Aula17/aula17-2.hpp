#include <new>
using namespace std;

//dont know if its completely working
template <typename T>
struct Deque {
    struct Noh {
        T v[5];
        Noh *ant, *prox;
        int index;
    };

    Noh *esq, *dir;

    void inicializar() { esq = dir = nullptr; }
    
    bool vazia() { return esq == nullptr && dir == nullptr; }

    T consultar_esq() { return esq->v[esq->index]; }
    T consultar_dir() { return dir->v[dir->index]; }

    int i(Noh *x) { return x->index; }

    bool inserir_esq(T e) {
        if (vazia()) {
            Noh *n = new(nothrow) Noh;
            if (n == nullptr) return true;
            n->ant = n->prox = nullptr;
            esq = dir = n;
            n->index = 0; n->v[i(n)] = e;
        } else if (i(esq) == 4) {
            Noh *n = new (nothrow) Noh;
            if (n == nullptr) return true;
            n->ant = nullptr; n->prox = esq; 
            n->index = 0; n->v[i(n)] = e;
            esq->prox = n;
            esq = n;
        } else {
            esq->index += 1;
            esq->v[i(esq)] = e;
        }
        return false;
    }

    bool inserir_dir(T e) {
        if (vazia()) {
            Noh *n = new(nothrow) Noh;
            if (n == nullptr) return true;
            n->ant = n->prox = nullptr;
            esq = dir = n;
            n->index = 0; n->v[i(n)] = e;
        } else if (i(dir) == 4) {
            Noh *n = new (nothrow) Noh;
            if (n == nullptr) return true;
            n->ant = dir; n->prox = nullptr; 
            n->index = 0; n->v[i(n)] = e;
            dir->prox = n;
            dir = n;
        } else {
            dir->index += 1;
            dir->v[i(dir)] = e;
        }
        return false;
    }

    T remover_esq() {
        T elem = esq->v[i(esq)];
        if (i(esq) == 0) {
            Noh *n = esq;
            esq = n->prox;
            delete n;
        } else { esq->index -= 1; }
        return elem;
    }

    T remover_dir() {
        T elem = dir->v[i(dir)];
        if (i(dir) == 0) {
            Noh *n = dir;
            dir = n->ant;
            delete n;
        } else { dir->index -= 1; }
        return elem;
    }

    void terminar() {
        
    }
};