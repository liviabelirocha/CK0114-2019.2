#include <iostream>

using std::cout; using std::cin;

int contar_ocorrencias (double *v, int n, double x) {
    int i, cont = 0;
    for (i = 0; i < n; i++) {
        if (*v == x) cont++;
        v = v + 1;
    }
    cout << cont << '\n';
    return cont;
}

int main() {
    int i, n;
    cout << "N: "; cin >> n;
    double v[n];
    for (i = 0; i < n; i++) cin >> v[i];
    contar_ocorrencias(&v[0], n, 2); 
}