# Aula 33 - 08/11/2019

## Árvore Binárias de Busca Balanceadas

1. O que fazer para evitar árvores assim:

    ```
    2
     \
      5
       \
        8
         \
          16
            \
             21
               \
                34
    ```

2. O Critério de Balanceamento AVL:
    Uma árvore binária de busca `A` é AVL sse, para toda subárvore 
    ```
                r
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
    de A, `| h(esqu) - h(dire) | <= 1`.
    <br>
3. Exercício: para cada altura `h`, qual é o menor número `n` de vértices de uma árvore AVL de altura h?

    |h  |nmin|nmax|
    |---|----|----|
    |0  |0   |0   |
    |1  |1   |1   |
    |2  |2   |3   |
    |3  |4   |7   |
    |4  |7   |15  |
    |5  |12  |32  |
    |6  |20  |63  |
    |7  |33  |127 |
    |8  |54  |255 |
    |9  |88  |511 |
    |...|... |... |
    