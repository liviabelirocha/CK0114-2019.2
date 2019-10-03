# Aula 18 - 23/09/2019

## Conjunto Dinâmica via Lista Encadeada

1. Objetivos:

    a) Desejamos implementar as operações `inserir(C, e)`, `pertence(C, e)`, `remover(C, e)` e também de percurso.
    b) Diferentemente de antes, a operação de remoção receberá um iterados para o elemento a ser removido (útil em aplicações nas quais são guardadas "referências" (ponteiros, iteradores, etc) aos elementos do conjunto).
    c) Devido ao item anterior, as operações de inserção e consulta retornam iteradoes (apontando para o fim, em caso de erro ou de não pertencimento).