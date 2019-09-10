#O TAD Fila

1. Introdução: uma fila é, assim como uma pilha, um contêiner, de forma que elementos podem nela ser inseridos e removidos. A diferença essencial entre as duas é que, enquanto numa pilha a operação de remoção remove o último elemento inserido, numa fila a remoção retira o primeiro elemento inserido (dentre aqueles ainda presentes na estrutura).

2. Exemplos:

    | Operações      | Fila      | *            |
    |----------------|-----------|--------------| 
    | Inicializar()  |   < >     | (fila vazia) |
    | Enfilar(A)     |   < A >   |              |
    | Enfilar(B)     |  < A B >  |              |
    | Enfilar(C)     | < A B C > |              |
    | Desenfilar()   |  < B C >  | (A saiu)     |
    | Enfilar(D)     | < B C D > |              |
    | Desenfilar()   |  < C D >  | (B saiu)     |
    | Desenfilar()   |   < D >   | (C saiu)     |
    | Desenfilar()   |   < >     | (D saiu)     |

3. Estratégia:

    a) Usar índices "circulares" para utilizar o vetor inteiro sempre.
    b) Ao expandir ou contrair, copiar os elementos para o início do novo vetor, na ordem de enfilamento.
    c) Fila vazia <-> início = -1.

4. Exemplo de uso de uma fila ("main.cpp")

```cpp
#include <iostream>
using std::cin; using std::cout;

#include "Fila.hpp"

int main () {
    Fila<double> F;
    if(F.inicializar()) return 1;
    for(;;) {
        cout << "Digite um número (negativo para parar): \n";
        double num; cin >> num;
        if(num < 0) break;
        if(F.enfilar(num)) return 2;
    }
    cout << "Aqui estão os números: ";
    while(!F.vazia()) {
        cout << ' ' << F.primeiro();
        if(F.desenfilar()) return 3;
    }
    cout << '\n';
    F.terminar();
}
```