#include <iostream>

using std::cout; using std::cin;

int main() {
    double v[7], temp; int i;

    for (i = 0; i < 7; i++) cin >> v[i];
    for (i = 0; i < 7; i++) cout << v[i] << " "; cout << '\n';

    for (i = 0; i < 3; i++) {
        temp = v[i];
        v[i] = v[6-i];
        v[6-i] = temp;
    }

    for (i = 0; i < 7; i++) cout << v[i] << " "; cout << '\n';
}