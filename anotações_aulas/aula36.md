# Aula 36 - 18/11/2019

## Remoção AVL

### 1. Introdução:

a) Observe primeiramente que a remoção em árvores binárias de busca gerais tem 3 casos:

* O nó é folha.
* O nó tem 1 filho.
* O nó tem 2 filhos.

b) Em seguida, observe, independentemente do caso, há um nó da árvore que é realmente removido (no 3º caso, por exemplo, o nó do elemento que é removido *não* é realmente removido, pois o elemento é substituido pelo seu sucessor ou predecessor); são os ancestrais desse nó que analisaremos e, se necessário, corrigiremos.

c) Assim como na inserção, nós, por simetria, só analisaremos alteração de altura à direita.

d) Assim como na inserção, há casos triviais:
1. Ok, mas h(A*) < h(A)
2. OK, e h(A*) = h(A)

e) A seguir, os casos não triviais.

### 2. Casos Não-Triviais da Remoção

O caso remanescente é:

3.  A → Ex = h+2, Dx = h+1
    A* → Ex = h+2, Dx = h

Observe que Ex != ø, isto é:

      y
     / \
    Ey Dy

Logo:

        x
       / \
      y  Dx'
     / \
    Ey Dy
Proposta:

      y
     / \
    Ey  x
       / \
      Dy  Dx'
* Caso 3.1: h(Ey) = h(Dy) + 1 

    ```
    A':
              x
             / \
    (h+2)   y  Dx' (h)
           / \
    (h+1) Ey Dy (h)
    ```
    Nesse caso:
    ```
    A'':
              y (h+2)
             / \
      (h+1) Ey  x (h+1)
               / \
          (h) Dy Dx' (h)
    ```
    Ok, mas h(A*) < h(A)
    <br>
* Caso 3.2: h(Ey) = h(Dy) 

    ```
    A':
              x
             / \
    (h+2)   y  Dx' (h)
           / \
    (h+1) Ey Dy (h+1)
    ```
    Nesse caso:
    ```
    A'':
              y (h+3)
             / \
      (h+1) Ey  x (h+2)
               / \
        (h+1) Dy Dx' (h)
    ```
    Ok, e h(A*) = h(A)
    <br>
* Caso 3.3: h(Dy) = h(Ey) + 1

    ```
    A':
              x
             / \
    (h+2)   y  Dx' (h)
           / \
      (h) Ey Dy (h+1)
    ```
    Nesse caso:
    ```
    A'':
              y (h+3)
             / \
        (h) Ey  x (h+2)
               / \
        (h+1) Dy Dx' (h)
    ```
    Desbalanceado, não funciona!<br>
    Proposta 2: Observe que Dy != ø, logo:

        Dy:
              z
             / \
            Ez Dz
    Logo:

        A':
                    x
                   / \
          (h+2)   y  Dx (h)
                 / \
            (h) Ey  z (h+1)
                   / \
          (h/h+1) Ez Dz (h/h+1)
    Então:

        A'':
                     z (h+2)
                   /   \
            (h+1) y     x (h+1)
                 / \   / \
            (h) Ey Ez Dz  Dx
                  (h/h-1)