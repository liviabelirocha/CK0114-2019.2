#include <new>
using std::nothrow;

template <typename T>
struct Fila {
    T *v;
    int head, tale, tam_v, num;

    bool inicializar() {
        v = new(nothrow) T [1];
        if (v == nullptr) return 1;
        head = -1; tam_v = 1; tale = -1; num = 0;
        return false;
    }

    void terminar() { delete [] v;}

    bool vazia() { return (num == 0); }

    T primeiro() { return v[head]; }

    bool redimencionar(int tam_w) {
        T *w = new(nothrow) T [tam_w];
        if ( w == nullptr ) return true;
        for (int i = 0; i < tam_v; i += 1) {
            if ( tale < head ) {
                if ( head >= tam_v ) head = 0;
            }
            w[i] = v[head];
            head += 1;
        }
        delete [] v;
        v = w;
        tam_v = tam_w;
        head = 0; tale = num;
        return false;
    }

    bool enfilar(T e) {
        //Checa se a fila está cheia
        if ( ( head == tale + 1 ) || ( head == 0 && tale == tam_v - 1 )) {
            if ( redimencionar(tam_v*2) ) return true;
        }

        //Se a fila está vazia, tanto o head quanto o tale estarão no 0
        if ( vazia() ) {
            head = 0; tale = 0;
        } else { 
            tale += 1; //Caso a fila não esteja vazia, incrementa o tale
            if ( tale >= tam_v ) tale = 0; //Caso o tale seja maior ou igual ao tamanho do vetor, volta pro zero
        }

        v[tale] = e;
        num += 1;
        return false;
    }

    //Pré-condição: pilha não vazia
    bool desenfilar() {
        head += 1;
        if ( !vazia() && 4*(num) <= tam_v) {
            if ( redimencionar(tam_v/2) ) return true;
        }
        if ( head >= tam_v ) head = 0;
        num -= 1;
        return false;
    }
};