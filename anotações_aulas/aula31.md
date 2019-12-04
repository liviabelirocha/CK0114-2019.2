# Aula 31 - 01/11/2019
<br>
1. Função para calcular o número de nós de uma árvore
```cpp
template <typename T>
int num_nos(Noh<T> *raiz) {
    if (raiz == nullptr) return 0;
    return 1 + num_nos(raiz->fesq) + num_nos(raiz->fdir);
}
```
<br>
2. Printar a árvore em ordem crescente
```cpp
template <typename T>
void print_crescente(Noh<T> *raiz) { 
    if (raiz == nullptr) return;
    print_crescente(raiz->fesq);
    cout << " " << raiz->elem;
    print_crescente(raiz->fdir);
}
```
<br>
3. Função de pertence
```cpp
template <typename T>
bool pertence(Noh<T> *raiz, T e) {
    if (raiz == nullptr) return false;
    if (raiz->elem == e) return true;
    if (raiz->elem > e) return pertence(raiz->fesq, e);
    return pertence(raiz->fdir, e);
}
```
<br>
4. Altura de uma árvore
```cpp
template <typename T>
int altura(Noh<T> *raiz) {
    if (raiz == nullptr) return 0;
    altura(raiz->fdir) >= altura(raiz->fesq) ? 
        return 1 + altura(raiz->fdir) : return 1 + altura(raiz->fesq);
}
```
<br>
5. Imprimir profundidades de uma árvore
```cpp
template <typename T>
int imprimir_alturas(Noh<T> *raiz) {
    if (raiz == nullptr) return 0;
    int hE = imprimir_alturas(raiz->fesq),
        hD = imprimir_alturas(raiz->fdir),
        h;
    if (hE < hD) h = 1 + hD;
    else h = 1 + hE;
    cout << "h(" << raiz->elem << "): " << h << endl;
}
```