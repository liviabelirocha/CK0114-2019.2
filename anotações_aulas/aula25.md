# Aula 25 - 16/10/2019

## Tabelas de Dispersão

1. Introdução<br>
    a. A ideia central é armazenas uma chave numa posição de vetor que guarde alguma relação com a chave, e não numa posição puramente circunstancial. Mais especificamente, nś desejamos **calcular** a posição a partir da chave.<br>
    b. Tecnicamente, nós chamamos o mapeamento das chaves nas posições do vetor de `função de dispersão`. 
    Um exemplo simoles é o `método da divisão`: se a chave é um número natural c e o vetor (tabela) possui `m` posições, então a posição de "c" é `h(c) = c % m` "h" de "**hash** function").
    <br>
2. Observações sobre o tipo das chaves:<br>
    a. Muitas vezes, as chaves já são números naturais (como o CPF). 
    Em outras, é fácil criar, artificialmente, chaves que são números naturais (como o número de matrícula: antes de entrar na UFC, o aluno não possui um número de matrícula, mas ganha um ao entrar).<br>
    b. Quando a chave não é um número natural, será necessário convertê-la em um. Nesse sentido, cabe lembrar que, num computador digital moderno, tudo dado é armazenado em dígitos binários, logo tal conversão em princípio é possível e até já existe **de alguma forma**. Uma string, por exemplo, pode ser entendida como uma grande sequência de dígitos na base 2, um como um número numa base em que cada símbolo é um dígito.<br>
    c. De forma geral, é importante que a função de dispersão consiga utilizar o que há de **diferente** entre as chaves, de forma a conseguir espalhá-las na tabela.
    Assim, por exemplo, se as chaves forem as matrículas de alunos que entraram num mesmo curso da UFC num mesmo período letivo, então os dígitos iniciais serão provavelmente os mesmos, e os dígitos finais serão aqueles que fornecerão a maior `variação`.
    <br>
3. Resolução de colisões: tipicamente, uma função de dispersão será uma função `h: U -> {0, ... , m-1}` em que |U| é muito maior que "m". Logo, haverá `colisões`.
Uma maneira de resolver colisões é fazer um `encadeamento externo`: uma lista encadeada para cada posição `i` da tabela, contendo as chaves `c` tais que `h(c) = i`.
<br>
4. Exemplo: abaixo, ilustraremos uma tabela com dispersão pelo método da divisão, resolução de colisões via encadeamento externo, e redimensionamento para o dobro ou metade:
