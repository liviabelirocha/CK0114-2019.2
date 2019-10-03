#include <iostream>

using std::cout; using std::cin;

void inverter (double *primeiro, double *ultimo) {
    double temp;
    temp = *primeiro; 
    *primeiro = *ultimo;
    *ultimo = temp;
}

int main() {
    int n; 
    cout << "N: "; cin >> n;
    double v[n];
    for (int a = 0; a < n; a++) cin >> v[a];
    for (int i = 0; i < n/2; i++) inverter(&v[i], &v[n-1-i]);
    for (int j = 0; j < n; j++) cout << v[j] << ' ';
    cout << '\n';
}