#include <iostream>
using namespace std;

class Ejemplo2 {
  public:
   Ejemplo2(int a = 0) : A(a) {}
   void Modifica(int a) { A = a; }
   int Lee() const { return A; }

  private:
   int A;
};

int main() {
   Ejemplo2 X(6);

   cout << X.Lee() << endl;
   X.Modifica(2);
   cout << X.Lee() << endl;

   return 0;
}
