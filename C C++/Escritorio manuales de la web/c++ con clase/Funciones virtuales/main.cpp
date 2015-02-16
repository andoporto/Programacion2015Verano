#include <iostream.h>
#include <stdlib.h>
class ClaseA {
public:
ClaseA() : datoA(10) {}
int LeerA() const {return datoA;}
void Mostrar() {cout << "a = " << datoA << endl;}
protected:
int datoA;
};

class ClaseB : public ClaseA {
public:
ClaseB() : datoB(20) {}
int LeerB() const {return datoB;}
void Mostrar() {cout << "a = " << datoA << ", b = " << datoB <<endl;}
protected:
int datoB;
};

int main()
{
ClaseB objeto;
objeto.Mostrar();
objeto.ClaseA::Mostrar();
system("pause");
return 0;
}
