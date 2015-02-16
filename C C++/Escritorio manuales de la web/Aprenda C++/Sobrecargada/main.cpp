// Ejemplo de función sobrecargada
#include <iostream>
#include <string.h>

using namespace std;

void string_copy(char *, const char *,const int);


void string_copy(char *copia, const *original, const int longitud)
{
strncpy(copia, original, longitud);
}
static char string_a[20], string_b[20];

int main(void)
{
string_copy(string_a, "Aquello");
string_copy(string_b, "Esto es una cadena", 4);
cout << string_b << " y " << string_a;
// La última sentencia es equivalente a un printf() de C
// y se explica en un próximo apartado de este manual
}
