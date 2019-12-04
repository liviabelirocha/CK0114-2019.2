# Aula 39 - 25/11/2019

## Montes ("Heaps") Binários

### 1. Recapitulando:
O **monte binário** é a estrutura de dados que aprenderemos para implementar **filas de prioridades**. Um monte (binário) consiste numa implementação específica de árvore binária (**não de busca!**) usando vetor. Nós estudaremos **montes de máximo** em que os maiores elementos ficam acima, mas a implementação dos **montes de mínimo** é análoga.

Exemplo:

``` 
       34
    /      \
   12      27
  /  \    /  \ 
 10   10 25  18
 /\   /
7  1 9
```

Representação:

```
  0    1    2    3    4    5    6    7   8   9
| 34 | 12 | 27 | 10 | 10 | 25 | 18 | 7 | 1 | 9 |
```

As vizinhanças são dadas por:

* `filho_esq(i) = 2i + 1`
* `filho_dir(i) = 2i + 2`
* `pai(i) = piso[(i-1)/2]`