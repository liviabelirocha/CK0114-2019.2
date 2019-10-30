# Aula 28 - 23/10/2019

## Endereçamento Aberto

1. Introdução:<br>
    a) Ideia central: resolver colisões não via listas encadeadas, mas sim calculando uma 2ª, 3ª, 4ª, ... ,  (m-1)ª posições para cada chave, e usando-as quando necessário.<br>
    b) No caso geral, `h(c,t)`, dá a `t`-ésima posição possível para a chave `c`, com `t ∈ [0...m-1]`.<br>
    c) Nesse caso, as chaves/elementos ficam na própria tabela (vetor), e algumas posições possuirão chaves e outras não.<br>
    d) A expansão da tabela se dá quando `α = n/m`, o `fator de carga`, ultrapassa um certo limite `αmax`, havendo contração quando `0 != α < αmin`.
    <br>
2. Sondagem Linear:
    `h(c,t) = (h'(c)+t)%m`
    <br>
3. Como representar "vazio" e "apagado:<br>
    a)Valores especiais: se houver 2 valores do tipo T dos elementos da tabelas que não correspondam a chaves, então eles podem ser usados para representar "vazio" e "apagado". Exemplo: se as chaves têm tipo `unsigned int` e todas são menores que `UINT_MAX - 1`, então: `UINT_MAX` -> "vazio" e `UINT_MAX - 1` -> "apagado".