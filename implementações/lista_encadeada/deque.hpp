#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <new>
using namespace std;

template <typename T>
struct Deque {
    struct Noh {
        T elem;
        Noh *ant, *prox;
    };

    Noh *esq, *dir;

    void inicializar() { esq = dir = nullptr; }
    
    bool vazia() { return (esq == nullptr && dir == nullptr); }

    T consultar_esq() { return esq->elem; }
    T consultar_dir() { return dir->elem; }

    bool inserir_esq(T e) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->ant = nullptr; n->elem = e; n->prox = esq;
        if (vazia()) dir = n;
        else esq->ant = n;
        esq = n;
        return false;
    }

    bool inserir_dir(T e) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->ant = dir; n->elem = e; n->prox = nullptr;
        if (vazia()) esq = n;
        else dir->prox = n;
        dir = n;
        return false;
    }

    T remover_esq() {
        Noh *n = esq; T e = n->elem;
        esq = n->prox;
        if (esq != nullptr) esq->ant = nullptr;
        else dir = nullptr;
        delete n; return e;
    }

    T remover_dir() {
        Noh *n = dir; T e = n->elem;
        dir = n->ant;
        if (dir != nullptr) dir->prox = nullptr;
        else esq = nullptr;
        delete n; return e;
    }

    void terminar() { while (!vazia()) { remover_dir(); } }
};

#endif