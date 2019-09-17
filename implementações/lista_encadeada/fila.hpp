#ifndef FILA_HPP
#define FILA_HPP

#include <new>
using namespace std;

template <typename T>
struct Fila {
    struct Noh {
        T elem;
        Noh *prox;
    };
    
    Noh *inicio, *fim;

    void inicializar() { inicio = nullptr; }

    bool vazia() { return inicio == nullptr; }

    T primeiro() { return inicio->elem; }

    bool enfilar(T e) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->prox = nullptr; n->elem = e;    //passa nulo para o ponteiro prox e passa "e" para elem
        if (vazia()) inicio = fim = n;    //se a fila está vazia, inicio e fim são nulos
        else { fim->prox = n; fim = n; } //senão, o ponteiro prox recebe o novo nó, depois fim recebe o mesmo
        return false;
    }

    T desenfilar() {
        Noh *n = inicio;
        T elem = primeiro();
        inicio = inicio->prox;
        delete n;
        return elem;
    }

    void terminar() {
        while (!vazia()) {
            desenfilar();
        }
    }
};

#endif