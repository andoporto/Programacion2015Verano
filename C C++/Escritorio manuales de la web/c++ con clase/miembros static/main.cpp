#include <iostream>
using namespace std;

class Numero {
  public:
   Numero(int v = 0);
   ~Numero();

   void Modifica(int v);
   int LeeValor() const { return Valor; }
   int LeeCuenta() const { return Cuenta; }
   int LeeMedia() const { return Media; }

  private:
   int Valor;
   static int Cuenta;
   static int Suma;
   static int Media;

   void CalculaMedia();
};

Numero::Numero(int v) : Valor(v) {
   Cuenta++;
   Suma += Valor;
   CalculaMedia();
}

Numero::~Numero() {
   Cuenta--;
   Suma -= Valor;
   CalculaMedia();
}

void Numero::Modifica(int v) {
   Suma -= Valor;
   Valor = v;
   Suma += Valor;
   CalculaMedia();
}

// Definición e inicialización de miembros estáticos
int Numero::Cuenta = 0;
int Numero::Suma = 0;
int Numero::Media = 0;

void Numero::CalculaMedia() {
   if(Cuenta > 0) Media = Suma/Cuenta;
   else Media = 0;
}

int main() {
   Numero A(6), B(3), C(9), D(18), E(3);
   Numero *X;

   cout << "INICIAL" << endl;
   cout << "Cuenta: " << A.LeeCuenta() << endl;
   cout << "Media:  " << A.LeeMedia() << endl;

   B.Modifica(11);
   cout << "Modificamos B=11" << endl;
   cout << "Cuenta: " << B.LeeCuenta() << endl;
   cout << "Media:  " << B.LeeMedia() << endl;

   X = new Numero(548);
   cout << "Nuevo elemento dinamico de valor 548" << endl;
   cout << "Cuenta: " << X->LeeCuenta() << endl;
   cout << "Media:  " << X->LeeMedia() << endl;

   delete X;
   cout << "Borramos el elemento dinamico" << endl;
   cout << "Cuenta: " << D.LeeCuenta() << endl;
   cout << "Media:  " << D.LeeMedia() << endl;

   return 0;
}
