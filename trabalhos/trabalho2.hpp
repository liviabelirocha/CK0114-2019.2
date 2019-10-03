#ifndef TRABALHO2_HPP
#define TRABALHO2_HPP

#include <new>
using namespace std;

struct SimulAloc {
    struct Noh {  
        int ini, tam; Noh *prox;  
    };

    Noh *prim;

    bool inicializar (int ini, int tam) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return true;
        n->ini = ini; n->tam = tam; n->prox = nullptr;
        prim = n;
        return false;
    }

    int alocar(int tam) {
        if (prim == nullptr) return -1;
        Noh *i = prim, *j = nullptr;
        while(i != nullptr) {
            int ini;
            if ((*i).tam > tam) {
                ini = ((*i).ini + (*i).tam) - tam;
                (*i).tam -= tam;
                return ini;
            }

            if((*i).tam == tam) {
                if (j == nullptr) {
                Noh *n = prim;
                ini = (*n).ini;
                prim = (*prim).prox;
                delete n;
                return ini;
                } else {
                Noh *n = i;
                (*j).prox = (*i).prox;
                ini = (*i).ini;
                i = (*i).prox;
                delete n;
                return ini;
                }
            }
            j = i;
            i = (*i).prox;
        }
        return -1;
    }

    bool desalocar(int ini, int tam) {
        if(prim == nullptr) {
            Noh *n = new(nothrow) Noh;

            if(n == nullptr) return true;

            (*n).ini = ini;
            (*n).tam = tam;
            prim = n;
            return false;
        }


        Noh *i = prim;
        while(i != nullptr) {
            if (((*i).ini + (*i).tam) == ini) {
                (*i).tam += tam;
                if ((*i).prox != nullptr) {
                    Noh *pr = (*i).prox;
                    if (((*i).ini + (*i).tam) == (*pr).ini) {
                        (*i).tam += (*pr).tam;
                        (*i).prox = (*pr).prox;
                        delete pr;
                    }
                }
                return false;
            }
            if ((ini + tam) == (*i).ini) {
                (*i).ini = ini;
                (*i).tam += tam;
                return false;
            }
            if (ini + tam < (*i).ini) {
                Noh *n = new(nothrow) Noh;
                if (n == nullptr) return true;
                (*n).ini = ini;
                (*n).tam = tam;
                (*n).prox = i;
                prim = n;
                return false;
            }
            if (ini > (*i).ini + (*i).tam) {
                if ((*i).prox == nullptr) {
                    Noh *n = new(nothrow) Noh;

                    if (n == nullptr) return true;

                    (*n).ini = ini;
                    (*n).tam = tam;
                    (*n).prox = nullptr;
                    (*i).prox = n;
                    return false;
                }

                Noh *pr = (*i).prox;
                if (ini + tam < (*pr).ini) {
                    Noh *n = new(nothrow) Noh;

                    if (n == nullptr) return true;

                    (*n).ini = ini;
                    (*n).tam = tam;
                    (*n).prox = (*i).prox;
                    (*i).prox = n;
                    return false;
                }
                i = (*i).prox;
            }
        }
        return true;
    }

    void terminar() {
        while(prim != nullptr) {
            Noh *n = prim;
            prim = prim->prox;
            delete n;
        }
    }
};

#endif