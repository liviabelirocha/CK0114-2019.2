#include <new>
using namespace std;

template <typename T>
struct Deque {
    struct Noh {
        T v[5];
        Noh *ant, *prox;
        int index;
    };

    Noh *esq, *dir;
    int elements;

    void inicializar() { 
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->index = -1; n->ant = nullptr; n->prox = nullptr;
        esq = n; dir = n; elements = 0; 
    }
    
    bool vazia() { return elements == 0; }

    bool inserir_esq(T e) {
        
    }
};