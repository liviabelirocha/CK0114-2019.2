#include <new>
using std::nothrow;

template<typename X, typename Y>
struct Par {X x; Y y;};

template<typename TC, typename TD>
struct Dicionario {
    Par<TC, TD> *v;
    int ult, tam_v;

    bool inicializar() {
        v = new(nothrow) Par<TC, TD> [1];
        if (v == nullptr) return true;
        ult = -1; tam_v = 1;
        return false;
    }

    void terminar() { delete [] v; }

    bool vazio() { return (ult == -1); }

    Par<bool, TD> procurar(TC c) {
        Par<bool, TD> p;
        for (int i = 0; i <= ult; i += 1) {
            if (v[i].x = c) {
                p.x = true; p.y = v[i].y;
                return p;
            }
        }
        p.x = false; 
        return p;
    }

    bool redimensionar (int tam_w) {
        Par<TC, TD> *w = new(nothrow) Par<TC, TD> [tam_w];
        if ( w == nullptr ) return true;
        for (int i; i <= ult; i += 1) w[i] = v[i];
        delete [] v;
        v = w;
        tam_v = tam_w;
        return false;
    }

    Par<bool, bool> inserir(TC c, TD d) {
        Par<bool, TD> p = procurar(c);
        Par <bool, bool> r;
        if (p.x == true) {
            r.x = true; //c pertence a D
            return r;
        }
        if (ult = tam_v-1) {
            if (redimensionar(tam_v*2)) {
                r.x = false; r.y = true;
                return r;
            }
        }
        ult++;
        v[ult].x = c; v[ult].y = d;
        r.x = false; r.y = false;
        return r;
    }

    Par <bool,bool> remover (TC c) {
        Par<bool, TD> p = procurar(c);
        Par <bool, bool> r;
        if (p.x == false) {
            r.x = true;
            return r;
        }
        int i = 0;
        while (v[i].x != c) i++;
        v[i].x = v[ult].x;
        ult--;
        if ( !vazio() && 4*(ult+1) <= tam_v) {
            if ( redimensionar(tam_v/2) ) {
                r.x = false; r.y = true;
                return r;
            }
        }
        r.x = false; r.y = false;
        return r;
    }
};