#include <new>

template <typename T>
struct Noh {
    T elem;
    Noh<T> *esq, *dir;
};

template <typename T>
struct Arvore {
    Noh<T> *raiz;
};

template <typename T>
bool inserir(Arvore<T> &A, T e) {
    if (A.raiz == nullptr) {
        A.raiz->elem = e;
        A.raiz->dir = A.raiz->esq = nullptr;
        return false;
    }

    Noh *aux = A.raiz;
    while (aux != nullptr) {
        if (e > aux->elem) aux = aux->dir;
        else aux = aux->esq;
    }

    Noh *n = new(std::nothrow) Noh;
    if (n == nullptr) return true;

    n->elem = e;
    n->dir = n->esq = nullptr;

    return false;
}

template <typename T>
void remover(Arvore<T> &A, T e) {
    if (A.raiz->elem == e && A.raiz->dir == nullptr && A.raiz->esq == nullptr) {
        Noh *n = raiz;
        delete n;
        raiz = nullptr;
        return;
    }

    Noh *aux = A.raiz, *parent;
    while (aux->elem != e) {
        parent = aux;
        if (e > aux->elem) aux = aux->dir;
        else aux = aux->esq;
    }

    if (aux->dir == nullptr && aux->esq == nullptr) {
        if (e > parent->elem) parent->dir = nullptr;
        else parent->esq = nullptr;
        delete aux;
        return;
    }

    if (aux->dir != nullptr) {
        parent->dir = aux->dir;
        delete aux;
        return;
    }

    if (aux->esq != nullptr) {
        parent->esq = aux->esq;
        delete aux;
        return;
    }

    Noh *n = aux, parent2;
    aux = aux->dir;
    while (aux != nullptr) {
        parent2 = aux;
        aux = aux->esq;
    }
    parent2->esq = nullptr;
    parent->dir = aux;
    delete n;
    return;
}