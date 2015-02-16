#include <iostream>
#include <cstring>
using namespace std;

class cadena {
  public:
   cadena();        // Constructor por defecto
   cadena(const char *c); // Constructor desde cadena c
   cadena(int n);   // Constructor de cadena de n caracteres
   cadena(const cadena &);   // Constructor copia
   ~cadena();       // Destructor

   void Asignar(const char *dest);
   char *Leer(char *c);
  private:
   char *cad;       // Puntero a char: cadena de caracteres
};

cadena::cadena() : cad(NULL) {}

cadena::cadena(const char *c) {
   cad = new char[strlen(c)+1];// Reserva memoria para cadena
   strcpy(cad, c);             // Almacena la cadena
}

cadena::cadena(int n) {
   cad = new char[n+1]; // Reserva memoria para n caracteres
   cad[0] = 0;          // Cadena vacía
}

cadena::cadena(const cadena &Cad) {
   // Reservamos memoria para la nueva y la almacenamos
   cad = new char[strlen(Cad.cad)+1];
   // Reserva memoria para cadena
   strcpy(cad, Cad.cad);             // Almacena la cadena
}

cadena::~cadena() {
   delete[] cad;        // Libera la memoria reservada a cad
}

void cadena::Asignar(const char *dest) {
   // Eliminamos la cadena actual:
   delete[] cad;
   // Reservamos memoria para la nueva y la almacenamos
   cad = new char[strlen(dest)+1];
   // Reserva memoria para la cadena
   strcpy(cad, dest);              // Almacena la cadena
}

char *cadena::Leer(char *c) {
   strcpy(c, cad);
   return c;
}

int main() {
   cadena Cadena1("Cadena de prueba");
   cadena Cadena2(Cadena1);   // Cadena2 es copia de Cadena1
   cadena *Cadena3;           // Cadena3 es un puntero
   char c[256];

   // Modificamos Cadena1:
   Cadena1.Asignar("Otra cadena diferente");
   // Creamos Cadena3:
   Cadena3 = new cadena("Cadena de prueba nº 3");

   // Ver resultados
   cout << "Cadena 1: " << Cadena1.Leer(c) << endl;
   cout << "Cadena 2: " << Cadena2.Leer(c) << endl;
   cout << "Cadena 3: " << Cadena3->Leer(c) << endl;

   delete Cadena3;  // Destruir Cadena3.
   // Cadena1 y Cadena2 se destruyen automáticamente

   return 0;
}
