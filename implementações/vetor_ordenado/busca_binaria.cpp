#include <iostream>

template <typename T>
int buscaBinaria(T *v, int n, T e) {
    int intervalo = n,
        inicio = 0, 
        fim = n-1;

    while (inicio <= fim) {
        intervalo = inicio + (fim-inicio)/2;
        if (v[intervalo] == e) return intervalo;
        else if (v[intervalo] > e) fim = intervalo - 1;
        else inicio = intervalo + 1;
    }
    
    return -1;
}