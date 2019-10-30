# Aula 26 - 18/10/2019

## Funções de Dispersão

1. Observações sobre o Método da Divisão:<br>
    a) Se `m=2^p`, para algum p (ou seja, m potência de 2), então nem todos os `w` bits da chave serão usados: só serão os `p` bits menos significativos.<br>
    **01011100**
    |multiplo de 2^4|resto |
    |---------------|------|
    |0101           |1100  |
    |são ignorados  |usados|
    **p = 4, w = 8**
    <br>Essa situação tende a ser ruim, pois os `w - p` bits mais à esquerda poderiam ajudar a fornecer variação entre as chaves.<br>
    b) Além disso, se as chaves e m tiverem um fator comum k, então apenas as posições da tabela que são múltiplo de k serão preenchidas.<br>
    c) Para evitar a possibilidades de haver fatores comuns entre m e as chaves, o método da divisão é tipicamente acompanhado pela escolha de números `primos` para m, os quais na prática são pré-computados e inseridos diretamente no código.<br>
    d)Por fim, são escolhidos primos "longe" de potências de 2, ou seja, próximos de `(2^i + 2^(i+1))/2`, para algum i.
    <br>

2. Método da Multiplicação:<br>
    **a) Definição Matemática:**
    `h(c) = piso[(c.A - piso[c.A]).m]`,
    para algum 0 < A < 1.
    **Ou seja, os passos são:**
    1. Multiplicar "c" e "A".
    2. Pegar a parte fracionária do resultado(descartar a parte inteira): c.a - piso[c.a].
    3. Multiplicar por m.
    4. Obter o piso.
    
    **b) Intuição: podemos observar que, partindo de uma representação de A na base 2:**
    * Os dígitos 1 de A correspondem a cópias de c no algoritmo "matemático" de multiplicação.
    * As posições desses 1's dirão os deslocamentos à esquerda das cópias de c.
    De forma geral, a intenção com multiplicar por A é somar c consigo mesmo algumas vezes, de forma "imprevisível/desordenada", devido aos deslocamentos à esquerda.
    Depois disso, "c.A - piso[c.A]" é um número de 0 a 1, e multiplicar por m é uma maneira de obter algo no intervalo das chaves ([0,...,m]).O piso final é apenas uma maneira de garantir um número natural.
    
    **c) Computação na Prática:** 
    * Passo 1, representação de A:
        `A = s/(2^w)`, onde `w` é o número de bits da palavra de memória e `s` ∈ {1, ..., 2^w - 1}.
