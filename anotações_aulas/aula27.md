# Aula 27 - 21/10/2019

## Método da Multiplicação (continuação)

1. Implementação:

    <br>a) Passo 1: não representar `A` em ponto flutuante, mas sim por meio de um inteiro sem sinal `s` tal que `A = s/(2^w)`, sendo `w` o número de bit da palavra de memória (**"word"**).<br>
    Exemplo: A = (0,101) = s + 0,125 = 0,625
    s = 0,101<br>
    b) Passo 2: para calcular `c.A - piso[c.A]`, observar que o resultado está em `c.s`, faltando apenas dividir por `2^w`.<br>
    c) Passo 3: para multiplicar por `m` e tirar o piso, observe que isso é muito mais fácil se `m=w^p`, para algum `p`.
    Além disso, tirar o piso do resultado significa considerar apenas os p bits mais significativos do resultado, e isso é o mesmo que deslocar `c.s` à direito por `w-p` bits (com p!= 0).<br>
    d) Em resumo: fazendo

        * A = s/(2^w), sendo s > 1
        * m = 2^p, sendo p != 0 (m != 1),
    Então `piso[(c.A - piso[c.A]).m]` pode ser computado via `(c.s) >> (w-p)`.<br>
    e) Observações: 
        
        1. s ímpar (evitar fator 2 comum entre c.s e w-p, tendo em vista que ">> w-p" é o mesmo que / 2^(w-p)).
        2. p != 0, isto é, m != 1, pois ">> w" é "undefined behavior" em C++.
        3. Knuth sugere A ~= (sqrt(5)-1)/2, isto é, 0,6180339887. Em 32 bits, então, s = 2654435769.
        4. Se s for escolhido aleatóriamente, então o método da multiplicação gera uma coleção universal de funções de dispersão.

## Endereçamento Aberto

2. Introdução: o método de resolução de colisões por `endereçamento aberto` leva a ideia de "calcular a posição das chaves" um passo adiante: se uma chave não estiver na posição inicialmente esperada, então nós **calculamos** a próxima posição a consultar.<br>
Mais especificamente, o endereçamento aberto utiliza uma `função de sondagem` tal que `h(c,i)` dá a i-ésima posição onde a chave c pode estar, com `i ∈ [0...m-1]`.