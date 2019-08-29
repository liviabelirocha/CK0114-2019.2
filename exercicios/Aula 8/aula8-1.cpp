#include <iostream>
#include <new>

using std::cout; using std::cin; using std::nothrow;

 //Situação inicial da pilha
int size = 1;
int topo = -1;

int add (int *v, int num) {
    return v[topo] = num;
}

int remove (int *v) {

}

int main () {
    int *v = new(nothrow) int [size];
    if (v == NULL) return 1;

    char c; int num;
    do {
        cout << "commands : add, remove, exit\n";
        cin >> c;
        switch (c){
            case 'add':
                if ( v[topo] == size ) {
                    size = 2*size;
                    int *newV = new(nothrow) int [size];
                    if (v == NULL) return 1;

                    for (int i = 0; i < size/2 ; i++) newV[i] = v[i];
                    topo += 1;
                }
                cout << "number to add: "; cin >> num;
                add(v, num);
                break;

            case 'remove':
            break;
        }

    } while( c != 'exit' );

    for (int i = 0; i < size; i++) cout << v[i] << ", "; 

    delete [] v;
}