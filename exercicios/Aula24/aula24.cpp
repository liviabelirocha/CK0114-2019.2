#include <cstdlib>
#include <iostream>
using namespace std;

double elemento_aleatorio (double *v, int n) {
    int rand_index = rand()%n;
    return v[rand_index];
}

void permutacao_aleatoria (double *v, int n, double *p) {
    int rep = n;
    for (int i = 0; i < rep; i++) {
        int rand_index = rand()%n;
        p[i] = v[rand_index];
        v[rand_index] = v[n-1];
        n--;
    }
}

int main () {
    double v[8] = {0, 1, 2, 3, 4, 5, 6, 7}, 
           p[8];

    for (int i = 0; i < 8; i++) cout << elemento_aleatorio(v, 8);
    cout << endl;

    permutacao_aleatoria(v, 8, p);
    for (int i = 0; i < 8; i++) cout << p[i];
    cout << endl;
}