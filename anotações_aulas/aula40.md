# Aula 40 -  27/11/2019

## Ordenação por Monte ("Heapsort")

### 1. Introdução

O algoritmo de ordenação por seleção começa percorrendo o vetor para localizar o maior elemento, colocando-o na última posição; em seguida, percorre o vetor novamente, mas só até a penúltima posição, e colocar o 2º maior elemento na penúltima posição do vetor; e assim sucessivamente. Como, em média, cada percurso tem tamanho `n/2`, então o custo médio dos percursos é *theta*(n), isto é, tanto O(n) quando *omega*(n).

Mas agora que sabemos que montes binários obtêm o máximo de forma mais eficiente que um percurso linear, nós podemos usá-los para obter um algoritmo de ordenação mais rápido?

### 2. Implementação

[Implementação de Heapsort](../implementações/ordenação/heapsort.hpp)