# Aula 41 - 29/11/2019

## Árvores B

### 1. Motivação

O modo de funcionamento dos discos rígidos, baseado em partes móveis, faz a **latência** no acesso aos dados do disco ser da ordem de milissegundos (10^(-3)s), enquanto o acesso à memória RAM é da ordem de nanossegundos (10^(-9)s). Assim, as estruturas de dados para a memória secundária são especificamente pensadas para essa memória.
Mais especificamente, a **árvore B** leva em consideração que a unidade de leitura e escrita em um disco é um **bloco**, que tipicamente armazena mais de mil bytes (com o intuito natural de aumentar a **vazão** das operações)

### 2. Estrutura da Árvore B

Dado um natural positivo *k*, a árvore B é tal que:

a) Todas as folhas têm a mesma profundidade, isto é, estão no mesmo nível.
b) Cada nó tem de *k* a *2k* chaves, exceto que a **raiz** pode ter menos que k.
c) Se um nó tem *x* chaves, então ele ou é folha ou possui exatamente *x + 1* filhos