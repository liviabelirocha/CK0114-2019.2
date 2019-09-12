# Aula 14 - 11/09/2019

# Iteradores (cont.)

1. Continuação da implementação de Conjunto:

```cpp
//Conjunto
Iterador inicio() {
    Iterador i;
    i.p = v; // i.p = &v[0];
    return i;
}

Iterador fim() {
    Iterador i;
    i.p = &(v[ult+1]);
    return i;
}; //Conjunto
```

# Dicionários

2. Introdução: Um dicionário é um contêiner, assim como um conjunto, mas a operação de busca é diferente da operação "pertence": ao invés de receber um elemento inteiro, recebe apenas uma chave, que identidica um elemento de forma única, e então retorna os dados-satélite ("informações complementares") correspondentes. As principais operações de um dicionário são:
    a) inserir(D, c, d): insere a chave c o o dado-satélite d como um novo par no dicionário D.
    b) procurar(D, c): retorna o dado-satélite correspondente à chave c no dicionário D.
    c) remover(D, c): remove de D o par/elemento de chave c.

3. Uma implementação ("dicionario.hpp")

```cpp
//Guardas de inclusão...
#include <new>
using std::nothrow;

template<typename X, typename Y>
struct Par {X x; Y y;};

template<typename TC, typename TD>
struct Dicionario {
    Par<TC, TD> *v;
    int ult, tam_v;

    bool inicializar() {
        v = new(nothrow) Par<TC, TD> [1]
        if (v == nullptr) return true;
        ult = -1; tam_v = 1;
        return false;
    }

    void terminar() { delete [] v; }

    bool vazio() { return (ult == -1); }

    Par<bool, TD> procurar(TC c) {
        Par<bool, TD> p;
        for (int i = 0; i <= ult; i += 1) {
            if (v[i].x = c) {
                p.x = true; p.y = v[i].y;
                return p;
            }
        }
        p.x = false; 
        return p;
    }

    Par<bool, bool> inserir(TC c, TD d) {
        Par<bool, TD> p = procurar(c);
        if (p.x == true) {
            Par <bool, bool> r;
            r.x = true; //c pertence a D
            return r;
        }
        if (ult = tam_v-1) {
            if (redimensionar(tam_v*2)) {
                Par <bool, bool> r;
                r.x = false; r.y = true;
                return r;
            }
        }
        ult++;
        v[ult].x = c; v[ult].y = d;
        Par <bool, bool> r;
        r.x = false; r.y = false;
        return r;
    }
}
```