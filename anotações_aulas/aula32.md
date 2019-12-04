# Aula 32 - 04/11/2019

## Operações em Árvores Binárias de Busca

1. Resumo dos percursos completos estudados:<br>
    a) Percurso em Ordem:
    -> Se árvore vazia: *fim*
    -> Senão:

        1. Percorra a sub-árvore esquerda em ordem
        2. Visite a raíz
        3. Percorra a sub-árvore direita em ordem

    b) Percurso Pré-Ordem:
    -> Se árvore vazia: *fim*
    -> Senão:

        1. Visita a raiz.
        2. Percorra a sub-árvore esquerda em pré-ordem.
        3. Percorra a sub-árvore direita em pré-ordem.

    c) Percurso Pós-Ordem:
    -> Se árvore vazia: *fim*
    -> Senão:

        1. Percorra a sub-árvore esquerda em pós-ordem.
        2. Percorra a sub-árvore direita em pós-ordem.
        3. Visite a raiz.

2. Remoção em Árvores Binárias de Busca:<br>
    ```
                n
               / \
              /   \
             /     \
            /       \
           /         \
          /           \
         /\           /\
        /  \         /  \
       /    \       /    \ 
      / esqu \     / dire \  
     /________\   /________\   
    ```
    a) Se E = D = NULL, a remoção é trivial.
    b) Se E != NULL = D, então colocar "E" no lugar de n. (Idem p/ E = NULL != D).
    c) SE E != NULL != D, basta encontrar o *sucessor* `s` de n (que é o menor de `D`), removê-lo e colocá-lo no lugar de n.<br>
    Observe que `s` necessariamente não tem filho esquerdo.
    Observe que o antecessor de n também serve (é possível alternar).

3. Custo das Operações

    |Operação|Custo|
    |--------|-----|
    |Busca   |O(h) |
    |Inserção|O(h) |
    |Remoção |O(h) |