# Aula 34 - 11/11/2019

## Revisão sobre Árvores AVL

1. Definição: uma árvore binária de busca **A** é AVL sse, para toda subárvore
    ```
                x
               / \
              /   \
             /     \
            /       \
           /         \
          /           \
         /\           /\
        /  \         /  \
       / ex \       / dx \
      /______\     /______\
    ```
    de **A**, `| h(ex) - h(dx) | <= 1`.
    <br>
2. Árvores de Fibonacci (AVL de menor **n** para cada **h**):

    h = 0 → ø
    h = 1 → ·
    h = 2 → 
    ```
        ·
         \
          ·
    ```
    h = 3 →
    ```
        ·
       / \
      ·   ·
           \
            ·
    ```
    h = 4 →
    ```
        ·
       / \
      /   ·
     ·   / \  
     \  ·   · 
      ·      \
              ·      
    ```
    h = 5 →
    ```
        ·
       / \
    A(4)  A(3)
    ```
    <br>
3. Teorema: toda árvore de Fibonacci de altura **h >=1** e **n** nós tal que **n >= 2^(piso[h/2])**.

    Prova: por indução em **h**:
        - Base: 
        · h = 1: 2^(piso[h/2]) = 2^(piso[1/2]) = 1, *CQD*
        · h = 2: 2^(piso[h/2]) = 2^(piso[2/2]) = 2, *CQD*
        - Passo: considere uma árvore de Fibonacci de altura **h+2**, com **h >= 1**
        
              ·
             / \
            /   \
           /     \
        h{...  ...}h+1

    e seja **n(h)** o número de nós de uma árvore de Fibonacci de altura **h**. Temos então:

        n(h+2) = 1 + n(h) + n(h+1) //pela definição de árvore de Fibonacci
               > 1 + 2.n(h) //n(h+1) > n(h)
               > 2.n(h)
               > 2.2^(piso[h/2]) //pela hipótese de indução

    Analisemos a paridade de **h**:
    1. Se h for par: logo **h = 2k** para algum **k >= 1**. Temos:
        ```
        n(h+2) >= 2.2^(piso[h/2]) = 2.2^(piso[2k/2]) 
                                  = 2.2^k 
                                  = 2^(k+1)
                                  = 2^(piso[(2k+2)/2]), CQD
        ```
    2. Se h for ímpar: logo, **h = 2k + 1** para algum **k >= 0**. Temos:
        ```
        n(h+2) >= 2.2^(piso[h/2]) = 2.2^(piso[2k+1/2]) 
                                  = 2.2^k 
                                  = 2^(k+1)
                                  = 2^(piso[((2k+1)+2)/2]), CQD
        ```
        Logo, o passo está provado, concluindo a prova.
<br>
4. Corolário: toda árvore AVL de altura **h >= 1** e **n** nós é tal que **n >= 2^(piso[h/2])**.

    Prova: segue de lema anterior, uma vez que toda árvore AVL de altura **h** possui pelo menos o número de nós de uma árvore de Fibonacci de altura **h**.
<br>
5. Teorema: para árvores AVL, sendo **h** a altura e **n** o número de nós, **h = O(lg n)**.

    Prova: pelo corolário anterior,

          2^(piso[h/2]) <= n
        → piso[h/2] <=  lg n
        → h/2 <= 1 + lg n
        → h <= 2 + 2lg n
        → h = O(lg n)

## Inserção em Árvores AVL

6. Inserção AVL:
    a) Árvore Vazia:
    ```
          raiz
    ø ->   ↓
           n
    ```
    b) Árvore Não-Vazia:
    ```
                x
               / \
              /   \
             /     \
            /       \
           /         \
          /           \
         /\           /\
        /  \         /  \
       / EX \       / DX \
      /______\     /______\
    ```
    Suponha, sem perda de generalidade (pela simetria), que a inserção do novo elemento aconteceu à direita, transformando **DX** em **DX'**.
    ```
                x
               /  \
              /    \
             /      \
            /        \
           /          \
          /            \
         /\           / \
        /  \         /   \
       / EX \       / DX` \
      /______\     /_______\
    ```
    São 2 casos:<br>
        **b.1)** h(DX') = h(DX): nesse caso, nada mais precisa ser feito e a altura da árvore enraizada em x não mudou.<br>
        **b.2)** h(DX') = h(DX) + 1: São 3 casos:<br>
        *b.2.1)* h(EX) = h + 1 = h(DX) + 1:nesse caso, nada mais precisa ser feito, e a altura da subárvore em x não mudou.
        *b.2.2)* h(EX) = h = h(DX): nesse caso, a árvore continua AVL, mas a altura aumentou!
        *b.2.3)* h(DX) = h + 1 = h(EX) + 1: nesse caso, a árvore precisará de tratamento. (Aula seguinte)