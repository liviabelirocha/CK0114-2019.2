#ifndef TRABALHO3_HPP
#define TRABALHO3_HPP

#include <new>
#include <iostream>
using namespace std;

struct TD {
    unsigned int m;
    void registrar_tam(unsigned int tamTabela) { m = tamTabela; }
    unsigned int dispersao(unsigned int c) { return c%m; }
};

//template <typename TC, typename TV, typename TD>
template <typename TV>
struct DicioDisp {
    
    struct node {
        //TC key;
        unsigned int key;
        TV value;
        node *prox;
    };

    int numElem, vecSize;
    node **v; TD table;
    
    bool inicializar() {
        v = new(nothrow) node* [1];
        if (v == nullptr) return true;
        numElem = 0; vecSize = 1;
        table.registrar_tam(vecSize);
        return false;
    }

    bool redimensionar(int newSize) {
        node** newVec = new(nothrow) node* [newSize];
        if (newVec == nullptr) return true;
        for(int i = 0; i < newSize; i += 1) newVec[i] = nullptr;

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

    //bool inserir(TC key, TV value) {
    bool inserir(unsigned int key, TV value) {
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

    //bool procurar(TC key, TV &value) {
    bool procurar(unsigned int key, TV &value) {
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

    //bool remover(TC key) {
    bool remover(unsigned int key) {
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

#endif