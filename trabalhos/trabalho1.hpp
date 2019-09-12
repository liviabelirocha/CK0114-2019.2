#include <iostream>
#include <new>
using namespace std;

template <typename T>
struct Deque {
    T *v; T* w;
    int left, right, size, elements;
};

template <typename T>
bool inicializar (Deque<T> &D) {
    D.v = new(nothrow) T [1];
    if( D.v == nullptr ) return true;
    D.right = 0;
    D.left = 0;
    D.size = 1;
    D.elements = 0;
    return false;
}

template <typename T> 
void terminar (Deque<T> &D) { delete [] D.v; }

template <typename T> 
bool vazio (Deque<T> &D) { return (D.elements == 0); }

template <typename T>
bool redimensionar (Deque<T> &D, int newSize) {
    T* w = new(nothrow) T [newSize];
    if (w == nullptr) return true;
    int oldLeft = D.left;
    D.left = (newSize - D.elements)/2;
    D.right = D.left + D.elements -1;
    for (int i = D.left; i <= D.right; i += 1) {
        w[i] = (D.v)[oldLeft];
        oldLeft++;
    }
    delete [] (D.v); (D.v) = w;
    D.size = newSize;
    return false;
}

template <typename T>
bool inserir_esq (Deque<T> &D, T e) {
    if (D.left == 0) { if (redimensionar(D, D.size*2)) return true; }
    D.left--; D.elements++;
    (D.v)[D.left] = e;
    return false;
}

template <typename T>
bool inserir_dir (Deque<T> &D, T e) {
    if (D.right == D.size-1) { if (redimensionar(D, D.size*2)) return true; }
    D.right++; D.elements++;
    D.v[D.right] = e;
    return false;
}

template <typename T>
T remover_esq (Deque<T> &D) {
    T value = D.v[D.left];
    D.left++; D.elements--;
    return value;
}

template <typename T>
T remover_dir (Deque<T> &D) {
    T value = D.v[D.right];
    D.right--; D.elements--;
    return value;
}