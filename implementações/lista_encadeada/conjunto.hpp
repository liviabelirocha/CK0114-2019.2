#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP

#include <new>
using namespace std;

template <typename T>
struct Conjunto {
    struct Noh {
        T elem;
        Noh *ant, *prox;
    };

    Noh sentinel;

    void inicializar() { sentinel.ant = sentinel.prox = &sentinel; }

    bool vazio() { return (sentinel.ant == &sentinel); }

    struct Iterator {
        Noh *p;
        bool operator!=(Iterator j) { return p != j.p; }
        bool operator==(Iterator j) { return p == j.p; }
        T operator*() { return p->elem; }
        void operator++() { p = p->prox; };
    };

    Iterator fim() {
        Iterator i;
        i.p = &sentinel;
        return i;
    }

    Iterator inicio() {
        Iterator i;
        i.p = sentinel.prox;
        return i;
    }

    Iterator inserir(T e) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return fim();
        n->elem = e; n->ant = &sentinel; n->prox = sentinel.prox;
        sentinel.prox = n;
        n->prox->ant = n;
        Iterator i;
        i.p = n;
        return i;
    }

    void remover(Iterator i) {
        Noh *n = i.p;
        n->ant->prox = n->prox;
        n->prox->ant = n->ant;
        delete n;
    }

    Iterator procurar(T e) {
        Noh *look = sentinel.prox;
        while (look != &sentinel) {
            if (look->elem == e) {
                Iterator i;
                i.p = look;
                return i;
            }
            look = look->prox;
        }
        return fim();
    }

    Iterator procurar2(T e) {
        Noh *look = sentinel.prox;
        sentinel.elem = e;
        while(look->elem != e) look = look->prox;
        Iterator i; i.p = look; return i;
    }

    bool pertence(T e) { return (procurar(e) != fim()); }

    void terminar() {
        T remove;
        Iterator i;
        while (!vazio()) {
            remove = (sentinel.prox)->elem;
            i = procurar(remove);
            remover(i);
        }
    }

    void terminar2() {
        Noh *n = sentinel.prox;
        while (n != &sentinel) {
            Noh *ant = n;
            n = n->prox;
            delete ant;
        }
    }
};

#endif