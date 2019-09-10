#include <iostream>
#include "../../implementações/pilha.hpp"

using std::cin;  using std::cout;

int main () {
    Pilha<double> numbers;
    Pilha<char> operands;

    if (numbers.inicializar()) return 1;
    if (operands.inicializar()) return 2;

    char c;
    cout << "Expressão: ";

    for (;;) {
        cin.get(c);

        if (c == '\n') break;
        else if (c == '(' || c == ' ') continue;
        else if (c >= '0' && c <= '9') {
            int num = 0;
            do {
                num = num*10 + (c - '0');  cin.get(c);
            } while ( c >= '0' && c <= '9');
            cin.unget();
            if(numbers.empilhar(num)) return 3;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if(operands.empilhar(c)) return 4;
        } else if (c == ')') {
            double res, esq, dir = numbers.topo();

            if (numbers.desempilhar()) return 5;
            esq = numbers.topo();

            switch (operands.topo()) {
                case '+': res = esq+dir; break;
                case '-': res = esq-dir; break;
                case '*': res = esq*dir; break;
                case '/': res = esq/dir; break;
            };

            if (numbers.desempilhar()) return 6;
            if (numbers.empilhar(res)) return 7;
            if (operands.desempilhar()) return 8;
        } else return 9;
    }

    cout << "Resultado = " << numbers.topo() << '\n';

    numbers.terminar();
    operands.terminar();
}