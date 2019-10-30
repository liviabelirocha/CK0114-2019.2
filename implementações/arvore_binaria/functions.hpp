#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
using namespace std;

template <typename T>
struct Noh {
    T elem;
    Noh<T> *fesq, *fdir;
};

//numero de nos
template <typename T>
int num_nos(Noh<T> *raiz) {
    if (raiz == nullptr) return 0;
    return 1 + num_nos(raiz->fesq) + num_nos(raiz->fdir);
}

//print em ordem crescente
template <typename T>
void print_crescente(Noh<T> *raiz) { 
    if (raiz == nullptr) return;
    print_crescente(raiz->fesq);
    cout << ", " << raiz->elem;
    print_crescente(raiz->fdir);
}

#endif