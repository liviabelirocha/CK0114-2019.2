# Aula 21 - 04/10/2019

## Notação Assintótica

1. Motivação: compare estas duas otimizações que fizemos antes:

    a) Utilizar a sentinela para reduzir de 2 para 1 o númeo de comparações do laço da remoção de um conjunto via lista encadeada.

    b) Na remoção de conjunto via vetor, substituir `v[i]` por `v[ult]`.

    Qual é a mais significativa?

2. Definição: se `g: N->N`, então `O(g) = {f: N->N \ existem m ∈ N* e c ∈ R*+ tais que, ∀ n ≥ m, 0 ≤ f(n) ≤ c.g(n)}`.
(N*: naturais != 0,
 R*+: reais > 0.)
    * As constantes multiplicativas são secundárias `(c)`
    * `m` só passa a vales a partir de algum ponto do domínio.
