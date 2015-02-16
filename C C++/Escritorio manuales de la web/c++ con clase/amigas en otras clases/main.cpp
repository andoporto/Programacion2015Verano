#include <iostream>
using namespace std;

class A; // Declaración previa (forward)

class B {
   public:
    B(int i=0) : b(i) {}
    void Ver() { cout << b << endl; }
    bool EsMayor(A Xa);  // Compara b con a
   private:
    int b;
};

class A {
   public:
    A(int i=0) : a(i) {}
    void Ver() { cout << a << endl; }
   private:
    // Función amiga tiene acceso
    // a miembros privados de la clase A
    friend bool B::EsMayor(A Xa);
    int a;
};

bool B::EsMayor(A Xa) {
   return b > Xa.a;
}

int main() {
   A Na(10);
   B Nb(12);

   Na.Ver();
   Nb.Ver();
   if(Nb.EsMayor(Na)) cout << "Nb es mayor que Na" << endl;
   else cout << "Nb no es mayor que Na" << endl;

   return 0;
}
