# Aula 38 - 22/11/2019

## Filas de Prioridades

### 1. Introduçãr
A **fila de prioridades** é um TAD no qual estamos sempre interessados no **maior** (ou num máximo) dentre os elementos correntemente armazenados. As operações principais são:

#### a) Inserir(F, e)
Insere o elemento `e` na fila de prioridades `F`.

#### b) Consultar_Max(F)
Retorna, sem remover, um elemento máximo de `F`.

#### c) Remover_Max(F)
Remove um elemento máximo de `F`.

### 2. Implementações Possíveis

|Estrutura *(Limitada)*                   |Inserção|Consulta|Remoção|
|-----------------------------------------|--------|--------|-------|
|Vetor não ordenado*                      |O(1)    |O(1)    |O(n)   |
|Vetor ordenado                           |O(n)    |O(1)    |O(1)   |
|Lista encadeada não ordenada*            |O(1)    |O(1)    |O(n)   |
|Lista encadeada ordenada                 |O(n)    |O(1)    |O(1)   |
|Tabela de dispersão Encadeamento Externo*|O(1)    |O(1)    |O(n)   |
|Tabela de dispersão Encadeamento Aberto* |O(n)    |O(1)    |O(n)   |
|Árvore binária de busca*                 |O(n)    |O(1)    |O(n)   |
|Árvore AVL                               |O(lg n) |O(1)    |O(lg n)|

`* Manter o índice no máximo.`