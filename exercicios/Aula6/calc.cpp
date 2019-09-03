#include <iostream>
#include <new>

using std::cin;  using std::cout; using std::nothrow;

int main () {
   int n; do { cout << "n: ";  cin >> n; } while (n <= 0);
   char c;  cin.get(c);

   double *vnum = new(nothrow) double[n];
   if (vnum == nullptr) return 1;

   char *vop = new(nothrow) char[n];
   if (vop == nullptr) return 2;

   cout << "Expressão: ";
   int ultnum = -1, ultop = -1;

   for(;;) {
      cin.get(c);

      if (c == '\n') break;
      else if (c == '(' || c == ' ') continue;
      else if ('0' <= c && c <= '9') {
         int num = 0;

         do{
            num = num*10 + (c - '0');  cin.get(c);
           } while ('0' <= c && c <= '9'); 

         cin.unget();

         ++ultnum; vnum[ultnum] = num;
        }
      else if (c == '+' || c == '-' || c == '*' || c == '/') {
        ++ultop; vop[ultop] = c;
        }
      else if (c == ')') {
        double r, e, d = vnum[ultnum];

        --ultnum; 
        e = vnum[ultnum];

        switch(vop[ultop]) {
            case '+': r = e+d; break;
            case '-': r = e-d; break;
            case '*': r = e*d; break;
            case '/': r = e/d; break;
           }

         vnum[ultnum] = r; --ultop;
        }
      else return 3; 
     }

   cout << "resultado: " << vnum[ultnum] << '\n';

   delete[] vnum;  delete[] vop;
  }