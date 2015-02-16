#include <iostream>
#include "complejo.h"

using namespace std;


void main(void)
 {
// se crean dos complejos con el constructor general
complejo c1(1.0, 1.0);
complejo c2(2.0, 2.0);
// se crea un complejo con el constructor por defecto
complejo c3;
// se da valor a la parte real e imaginaria de c3
c3.SetReal(5.0);
 c3.SetImag(2.0);
// se crea un complejo con el valor por defecto (0.0) del 2� argumento
 complejo c4(4.0);
// se crea un complejo a partir del resultado de una expresi�n
// se utiliza el constructor de copia
 complejo suma = c1 + c2;
// se crean tres complejos con el constructor por defecto
complejo resta, producto, cociente;
// se asignan valores con los operadores sobrecargados
resta = c1 - c2;
producto = c1 * c2;
cociente = c1 / c2;
// se imprimen los n�meros complejos con el operador << sobrecargado
cout << c1 << ", " << c2 << ", " << c3 << ", " << c4 << endl;
cout << "Primer complejo: " << c1 << endl;
 cout << "Segundo complejo: " << c2 << endl;
 cout << "Suma: " << suma << endl;
 cout << "Resta: " << resta << endl;
cout << "Producto: " << producto << endl;
cout << "Cociente: " << cociente << endl;
