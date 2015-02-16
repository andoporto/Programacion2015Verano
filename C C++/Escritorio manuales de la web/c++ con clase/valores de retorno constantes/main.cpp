#include <iostream>
#include <string.h>

using namespace std;

class cadena {
   public:
      cadena();        // Constructor por defecto
      cadena(const char *c); // Constructor desde cadena c
      cadena(int n); // Constructor para cadena de n caracteres
      cadena(const cadena &);   // Constructor copia
      ~cadena();       // Destructor

      void Asignar(const char *dest);
      char *Leer(char *c) {
         strcpy(c, cad);
         return c;
      }
   private:
      char *cad;       // Puntero a char: cadena de caracteres
};

int main() {
   cadena Cadena1("hola");

    cout << Cadena1 << endl; // Legal
//   Cadena1.Leer() = cadena2;       // Ilegal
   //Cadena1.Leer()[1] = 'O';        // Ilegal
}
