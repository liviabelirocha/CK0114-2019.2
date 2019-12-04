#ifndef HEAP_CPP
#define HEAP_CPP

template <typename T>
struct Heap {
    
    T *v;
    int n, tam_v;
    
    void inicializar(T *vetor, int tam) {
        v = vetor;
        n = 0;
        tam_v = tam;
    }

    int fesq(int i) { return 2*i + 1; }
    int fdir(int i) { return 2*i + 2; }
    int pai(int i) { return (i-1)/2; }

    bool vazio() { return (n == 0);}
    bool cheio() { return (n == tam_v); }

    //pré-condição: vetor não vazio
    T consultar_max { return v[0]; }

    /*v[0...n] é "quase um monte", a única excessão sendo 
    a possibilidade de que "i > 0" e "v[pai(i)] < v[i]"*/
    void subir(int i) { //versão iterativa
        int elem = v[i];
        while (i != 0) {
            if (v[pai(i)] >= elem) break;
            v[i] = v[pai(i)];
            i = pai(i);
        }
        v[i] = elem;
    }
    
    /*
    void subir(int i) { //versão recursiva
        if (i == 0) return;
        if (v[pai(i)] < v[i]) {
            T aux = v[pai(i)];
            v[pai(i)] = v[i];
            v[i] aux;
            subir(pai(i));
        }
    }
    */

   void descer(int i) {
       T elem = v[i];
       for (;;) {
            int fmax = fesq(i);
            if (n <= fmax) break; //não tem filhos
            int fd = fmax + 1;
            if (fd < n && v[fmax] < v[fd]) fmax = fd;
            if (e >= v[fmax]) break;
            v[i] = v[fmax];
            i = fmax;
       }
       v[i] = e;
   }

    //pré-condição: vetor não está cheio
    void inserir(T e) {
        v[n] = e;
        subir(n);
        n++;
    }

    T remover_max() {
        T elem = v[0];
        n--;
        if (n != 0) {
            v[0] = v[n];
            descer(0);
        }
        return elem;
    }
};

#endif