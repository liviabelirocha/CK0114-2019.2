#include <iostream>
#include <new>
using std::nothrow; using std::cout;

template <typename T>
struct Conjunto {
    T *v;
    int pointer, size;

    bool inicializar() {
        v = new(nothrow) T [1];
        if (v == nullptr) return true;
        pointer = -1; size = 1;
        return false;
    } //true <-> erro de alocação

    bool vazia() { return ( pointer == -1); }

    bool redimensionar(int new_size) {
        T* w = new(nothrow) T [new_size];
        if (w == nullptr) return true;
        for (int i = 0; i <= pointer; i += 1) w[i] = v[i];
        delete [] v;
        v = w;
        size = new_size;
        return false;
    }

    //Pré-condição: "e" não pertence.
    bool inserir(T e) {
        if (pointer == size - 1) {
            if (redimensionar(size*2)) return true;
        }
        pointer++;
        v[pointer] = e;
        return false;
    } //true <-> erro de alocação
    bool pertence(T e) {
        for (int i = 0; i <= pointer; i += 1) {
            if ( e == v[i] ) return true;
        }
        return false;
    } //true <-> pertence

    //Pré-condição: "e" pertence.
    bool remover(T e) {
        int i = 0;
        while (v[i] != e) i++;
        v[i] = v[pointer];
        pointer--;

        if ( !vazia() && 4*(pointer+1) <= size) {
            if ( redimensionar(size/2) ) return true;
        }

        return false;
    }

    //Exercício 2 da Aula 13

    bool inserir_se_nao_pertence(T e) {
        if (pertence(e)) cout << "Elemento já pertence ao conjunto.\n";
        if (pointer == size - 1) {
            if (redimensionar(size*2)) return true;
        }
        pointer++;
        v[pointer] = e;
        return false;
    }

    bool remover_se_pertencer(T e) {
        if(!pertence(e)) cout << "Elemento não pertence ao conjunto.\n";
        int i = 0;
        while (v[i] != e) i++;
        v[i] = v[pointer];
        pointer--;

        if(!vazia() && 4*(pointer+1) <= size) {
            if (redimensionar(size/2)) return true;
        }

        return false;
    }

    //Exercício 1 da Aula 14

    struct Iterador {
        T *p;
        bool operator!= (const Iterador &j) { return (p != j.p); }
        T& operator*() { return *p; }
        Iterador& operator++() {
            ++p;
            return *this;
        }
    };

    Iterador inicio() {
        Iterador i;
        i.p = v; // i.p = &v[0];
        return i;
    }

    Iterador fim() {
        Iterador i;
        i.p = &(v[pointer+1]);
        return i;
    }
};