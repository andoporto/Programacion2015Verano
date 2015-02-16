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
    Cadena operator+(const Cadena &);
    Cadena(const Cadena &c) { *this = c; }
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
//    Cadena C1("Cadena de prueba");
//    C1.Mostrar();

    Cadena C1, C2("Primera parte");
    C1 = C2 + " Segunda parte";
    C2.Mostrar();
    C1.Mostrar();

    return 0;
}

Cadena Cadena::operator+(const Cadena &c)
{
    Cadena temp;
    temp.cadena = new char[strlen(c.cadena)+strlen(cadena)+1];
    strcpy(temp.cadena, cadena);
    strcat(temp.cadena, c.cadena);
    return temp;
}

