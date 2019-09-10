#Aula 12 - 06/09/2019

#Conjuntos Dinâmicos

1. Introdução: o TAD Conjunto dinâmico é também um contêiner, assim como pilhas e filas. Um conjunto dinâmico se difere dos conjuntos "matemáticos" por estes últimos serem estáticos, no sentido de que não têm seus elementos alterados (assim, por exemplo, na teoria dos conjuntos se C = A U {x} e x !e A (x não pertence a A), então C, que é o resultado da "inserção" de de x em A, é outro conjunto: C != A).

    Conjuntos dinâmicos têm uma diferença crucial em relação a pilhas e filas: neles, qualquer elemento armazenado pode ser removido. Além disso, é possível consultar se um elemento qualquer está ou não no conjunto.

    As seguintes operações são, então, essenciais em conjuntos dinâmicos:

        1. Inserir(C, e): insere o elemento e no conjunto C.
        2. Pertence(C, e): informa se e pertence a C ou não.
        3. Remover(C, e): remove e de C.

    O percurso dos elementos de um conjunto será estudado na próxima aula; outras operações, como a união e a interseção, são típicas, mas omitiremos.


2. Uma implementação:

    a) Especificação:

    ```cpp
    template <typename T>
    struct Conjunto {
        ...campos/dados...
        bool inicializar() {...} //true <-> erro de alocação

        //Pré-condição: "e" não pertence.
        bool inserir(T e) {...} //true <-> erro de alocação
        bool pertence(T e) {...} //true <-> pertence

        //Pré-condição: "e" pertence.
        bool remover(T e) {...}
        //Você vai precisar de "redimensionar"
    };
    ```
