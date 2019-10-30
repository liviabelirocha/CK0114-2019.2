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

    void inicializar() { sentinel.prox = &sentinel; sentinel.ant = &sentinel; }

    bool vazio() { return sentinel.prox == &sentinel; }

    
};
