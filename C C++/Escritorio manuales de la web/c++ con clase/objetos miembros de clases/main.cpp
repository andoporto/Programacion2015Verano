#include <iostream.h>
#include <stdlib.h>

class ClaseA {
public:
ClaseA(int a) : datoA(a) {cout << "Constructor de A" << endl;}
int LeerA() const {return datoA;}
protected:
int datoA;
};
class ClaseB {
public:
ClaseB(int a, int b) : cA(a), datoB(b) {cout << "Constructor de B" << endl;}
int LeerB() const {return datoB;}
int LeerA() const {return cA.LeerA();}
protected:
int datoB;
ClaseA cA;
};
int main()
{
ClaseB objeto(5,15);
cout << "a = " << objeto.LeerA() << ", b = " << objeto.LeerB() <<
endl;
system("pause");
return 0;
}
