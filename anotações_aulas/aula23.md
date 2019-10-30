# Aula 23

1. Exercício: expresse, em termos de "n", a complexidade assintótica do tempo de execução da função abaixo:

```cpp
double soma(double *v, int n) {
    double s = 0;
    for(int i = 0. i < n; i++) s+= v[i];
    return s;
}
```

Solução: Podemos separar o tempo de execução da função em:
    
    a:
        * inicialização da função
        * double s = 0
        * i = 0
    b -> n vezes:
        *i < n
        *S += v[i]
        *++1
    c:
        *i < n (último teste)
        *return S
        *finalização da função
    
    tempo de execução = n.b + a + c = O(n)

2. Exercício: qual é a complexidade do tempo de execução desta função::

```cpp
int buscar_linear(double *v, int n, double e) {
    for (int i = 0; i < n; ++i) {
        if (v[i] == e return i);
    }
    return -1;
}
``` 

Solução:

    É fácil observar que o tempo de execução da função não depende só de "n", mas também de "v" e "e". 
    Porém, para expressar o tempo de execução em termos da notação "O" aplicada a alguma função g(n), podemos considerar uma função f(n) que dê o tempo de execução da função no pior caso, e nesse caso encontrar g(n), tal que f = O(g).
    Nesse caso, é evidente que, assim como no exercício anterior, existem constante "a" e "b" tais que f(n) = an + b.
    Além disso, é o caso que f(n) = O(n).
    Logo, nós dizemos que o tempo de execução do algoritmo é O(n).

3. Exercício: qual é o tempo de execução do algoritmo abaixo?

```cpp
//Pré-condição: ∀ i ∈ (0, ... , n - 2), v[i+1] = v[i] + 1
double soma(double *v, int n) {
    return (v[0] + v[n-1] * n/2);
}
```

Resposta curta:

    A função executa em tempo constante (Independente de "n"), e portanto executa em tempo O(1).

Resposta mais longa:

    É fácil ver que existe uma constante positiva "a" tal que o tempo de execução da função é f(n) = a.
    Como f(n) = O(1), então a função executa em tempo O(1).
    Obs: ∀ a ∈ N*, a = O(1)
    Prova: sejam m = 1, c = a e n >= m; Temos:
        0 <= a <= c.n

4. Tempo de Execução das Implementações via Vetor:

    |----------|Consulta|Inserção                          |Remoção                           |
    |----------|--------|----------------------------------|----------------------------------|
    |Pilha     |O(1)    |O(n): pior caso / O(1): amortizado|O(n): pior caso / O(1): amortizado| 
    |Fila      |O(1)    |O(n): pior caso / O(1): amortizado|O(n): pior caso / O(1): amortizado|
    |Deque     |O(1)    |O(n): pior caso / O(1): amortizado|O(n): pior caso / O(1): amortizado|
    |Conjunto  |O(n)    |O(n): pior caso / O(1): amortizado|O(n)                              |
    |Dicionário|O(n)    |O(n): pior caso / O(1): amortizado|O(n)                              |

5. Tempo de Execução das Implementações via Lista Encadeada

    |----------|Consulta|Inserção|Remoção|
    |----------|--------|--------|-------|
    |Pilha     |O(1)    |O(1)    |O(1)   | 
    |Fila      |O(1)    |O(1)    |O(1)   |
    |Deque     |O(1)    |O(1)    |O(1)   |
    |Conjunto  |O(n)    |O(1)    |O(1)   |
    |Dicionário|O(n)    |O(1)    |O(1)   |