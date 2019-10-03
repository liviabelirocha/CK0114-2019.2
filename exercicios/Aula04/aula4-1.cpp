#include <iostream>
#include <cmath>

using std::cin; using std::cout; using std::abs; 

double media(double *v, int n) {
    double m = 0;
    for (int i; i < n; i++) m += v[i];
    return m/n;
}

int main () {
    int n; double dif;
    cout << "Número de alunos: "; cin >> n; cout << "\n\n";
    double *v = new double [n];
    for (int i = 0; i < n; i++) {
        cout << "Nota do aluno " << i+1 << ": "; cin >> v[i];
    }
    cout << "\nA média da turma foi " << media(v, n) << "\n\n";
    for (int j = 0; j < n; j++) {
        dif = v[j] - media(v, n);
        if (dif < 0) cout << "O aluno " << j+1 << " está " << abs(dif) << " abaixo da média \n";
        if (dif >= 0) cout << "O aluno " << j+1 << " está " << dif << " acima da média \n";
    }
    delete [] v;
}