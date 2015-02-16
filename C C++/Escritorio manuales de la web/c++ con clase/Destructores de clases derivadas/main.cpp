#include <iostream.h>
#include <stdlib.h>

class ClaseA {
public:
ClaseA() : datoA(10) {cout << "Constructor de A" << endl;}
~ClaseA() {cout << "Destructor de A" << endl;}
int LeerA() const {return datoA;}
protected:
int datoA;
};

class ClaseB : public ClaseA {
public:
ClaseB() : datoB(20) {cout << "Constructor de B" << endl;}
~ClaseB() {cout << "Destructor de B" << endl;}
int LeerB() const {return datoB;}
protected:
int datoB;
};

int main()
{
ClaseB objeto;
cout << "a = " << objeto.LeerA() << ", b = " << objeto.LeerB() <<
endl;
system("pause");
return 0;
}
