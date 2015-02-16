#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


class Cadena
{
public:
    Cadena(char *cad);
    Cadena() : cadena(NULL) {};
    Cadena operator=(const Cadena &c);
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

Cadena &Cadena::operator=(const Cadena &c)
{
    if(this != &c)
    {
        delete[] cadena;
        if(c.cadena)
        {
            cadena = new char[strlen(c.cadena)+1];
            strcpy(cadena, c.cadena);
        }
        else cadena = NULL;

    }
    return *this;
}
