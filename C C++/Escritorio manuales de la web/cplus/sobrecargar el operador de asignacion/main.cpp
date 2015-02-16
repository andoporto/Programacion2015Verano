#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


class Cadena
{
public:
    Cadena(char *cad);
    Cadena() : cadena(NULL) {};
    ~Cadena()
    {
        delete[] cadena;
    };
    void Mostrar() const;
private:
    char *cadena;
};

Cadena::Cadena(char *cad)
{
    cadena = new char[strlen(cad)+1];
    strcpy(cadena, cad);
}

void Cadena::Mostrar() const
{
    cout << cadena << endl;
}

int main ()
{
    Cadena C1("Cadena de prueba");
    C1.Mostrar();
    return 0;
}
