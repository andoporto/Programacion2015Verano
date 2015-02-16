
#include <iostream>
using namespace std;

class Numero {
  public:
   Numero(int v = 0);

   void Modifica(int v) { Valor = v; }
   int LeeValor() const { return Valor; }
   int LeeDeclaraciones() const { return ObjetosDeclarados; }
   static void Reset() { ObjetosDeclarados = 0; }

  private:
   int Valor;
   static int ObjetosDeclarados;
};

Numero::Numero(int v) : Valor(v) {
   ObjetosDeclarados++;
}

int Numero::ObjetosDeclarados = 0;

int main() {
   Numero A(6), B(3), C(9), D(18), E(3);
   Numero *X;

   cout << "INICIAL" << endl;
   cout << "Objetos de la clase Numeros: "
        << A.LeeDeclaraciones() << endl;

   Numero::Reset();
   cout << "RESET" << endl;
   cout << "Objetos de la clase Numeros: "
        << A.LeeDeclaraciones() << endl;

   X = new Numero(548);
   cout << "Cuenta de objetos dinamicos declarados" << endl;
   cout << "Objetos de la clase Numeros: "
        << A.LeeDeclaraciones() << endl;

   delete X;
   X = new Numero(8);
   cout << "Cuenta de objetos dinamicos declarados" << endl;
   cout << "Objetos de la clase Numeros: "
        << A.LeeDeclaraciones() << endl;

   delete X;
   return 0;
}
