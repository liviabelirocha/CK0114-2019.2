#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <new>
#include <iostream>
using namespace std;

template <typename T>
struct Noh {
    T elem;
    Noh *fesq, *fdir;
};

template <typename T>
int num_nos(Noh<T> *root) {
    if (root == nullptr) return 0;
    return 1 + num_nos(root->fesq) + num_nos(root->fdir);
}

template <typename T>
bool pertence(Noh<T> *root, T e) {
    if (root == nullptr) return false;
    if (root->elem == e) return true;
    if (root->elem > e) return pertence(root->fesq, e);
    return pertence(root->fdir, e);
}

template <typename T>
int altura(Noh<T> *root) {
    if (root == nullptr) return 0;
    int hE = altura(root->fesq),
        hD = altura(root->fdir);
    if ( hE < hD ) return 1 + hD;
    else return 1 + hE;
}

template <typename T>
void print_crescente(Noh<T> *root) { 
    if (root == nullptr) return;
    print_crescente(root->fesq);
    cout << " " << root->elem;
    print_crescente(root->fdir);
}

template <typename T>
int imprimir_alturas(Noh<T> *root) {
    if (root == nullptr) return 0;
    int hE = imprimir_alturas(root->fesq),
        hD = imprimir_alturas(root->fdir),
        h;
    if (hE < hD) h = 1 + hD;
    else h = 1 + hE;
    cout << "h(" << root->elem << "): " << h << endl;
}

#endif