#include <iostream>
using namespace std;

class pareja {
   public:
      // Constructor
      pareja(int a2=0, int b2=0) : a(a2), b(b2) {}
      // Constructor copia:
      pareja(const pareja &p);

      // Funciones miembro de la clase "pareja"
      void Lee(int &a2, int &b2);
      void Guarda(int a2, int b2);
   private:
      // Datos miembro de la clase "pareja"
      int a, b;
};

// Definición del constructor copia:
pareja::pareja(const pareja &p) : a(p.a), b(p.b) {}

int main() {
   pareja par1(12, 32);
   pareja par2(par1); // Uso del constructor copia: par2 = par1


   par2.Lee(x, y);


   cout << "Valor de par2.a: " << x << endl;
   cout << "Valor de par2.b: " << y << endl;

   return 0;
}
