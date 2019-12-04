#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iostream>

#include "../arvore_binaria/heap.hpp"

template <typename T>
void heapsort(T *v, int n) {
    Heap<T> M;

    M.inicializar(v, n);

    for(int i = 0; i < n; i++) M.inserir(v[i]);

    for (int i = n-1; i > 0; i--) v[i] = M.remover_max();

    for (int i=0;i<n;i++) std::cout << v[i] << ' , ';
    std::cout << endl;
}

template <typename T>
void inverse_heapsort(T *v, int n) {
    Heap<T> M;

    M.inicializar(v, n);

    for (int i = M.pai(n-1); i >= 0; i--) M.descer(i); 

    for (int i = n-1; i > 0; i--) v[i] = M.remover_max();

    for (int i=0;i<n;i++) std::cout << v[i] << ' , ';
    std::cout << endl;
}

#endif