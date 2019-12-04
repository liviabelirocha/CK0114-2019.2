#include <new>
#include <iostream>
using namespace std;

template <typename TC, typename TV, typename TD>
struct DicioDisp {
    
    struct node {
        TC key;
        TV value;
        node *prox;
    };

    int numElem, vecSize;
    node **v; TD table;
    
    bool inicializar() {
        v = new(nothrow) node* [2];
        if (v == nullptr) return true;
        numElem = 0; vecSize = 2;
        table.registrar_tam(vecSize);
        v[0] = v[1] = nullptr;
        return false;
    }

    bool redimensionar(int newSize) {
        node** newVec = new(nothrow) node* [newSize];
        if (newVec == nullptr) return true;
        for(int i = 0; i < newSize; i++) newVec[i] = nullptr;

        table.registrar_tam(newSize);
        node *n, *next;
        for (int i = 0; i < vecSize; i++) {
            n = v[i];
            while(n != nullptr) {
                unsigned int index = table.dispersao(n->key);
                next = n->prox;
                n->prox = newVec[index];
                newVec[index] = n;
                n = next;
            }
        }
        
        delete [] v;
        v = newVec; vecSize = newSize;
        return false;
    }

    bool inserir(TC key, TV value) {
        if ( numElem == vecSize ) {
            if (redimensionar(vecSize*2)) return true;
        }
        node *n = new(nothrow) node;
        if (n == nullptr) return true;
        n->key = key; n->value = value;
        unsigned int index = table.dispersao(key);
        n->prox = v[index];
        v[index] = n;
        numElem++;
        return false;
    }

    bool procurar(TC key, TV &value) {
        unsigned int index = table.dispersao(key);
        node *n = v[index];
        while (n != nullptr) {
            if (n->key == key) {
                value = n->value;
                return true;
            }
            n = n->prox;
        }
        return false;
    }

    bool remover(TC key) {
        unsigned int index = table.dispersao(key);
        node *run = v[index];
        if (run == nullptr) return false;
        if (run->key == key){
            v[index] = run->prox;
            delete run; numElem--;
        } else {
            while (run->prox != nullptr) {
                if (run->prox->key == key) {
                    node *n = run->prox;
                    run->prox = n->prox;
                    delete n; numElem--;
                    break;
                }
                run = run->prox;
            }
        }
        if (( numElem > 0) && (4*numElem <= vecSize)) return redimensionar(vecSize/2);
        return false;
    }

    void terminar() {
        for (int i = 0; i < vecSize; i++) {
            while(v[i] != nullptr) {
                node *n = v[i];
                v[i] = n->prox;
                delete n;
            }
        }
        delete [] v;
    }

    void print() {
        node *n;
        for (int i = 0; i < vecSize; i++) {
            n = v[i];
            cout << i << ": ";
            while (n != nullptr) {
                cout << n->key << ", ";
                n = n->prox;
            }
            cout << endl;
        }
    }

};