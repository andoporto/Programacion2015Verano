#include <iostream.h>
#include <stdlib.h>

class ClaseA {
public:
void Incrementar() {cout << "Suma 1" << endl;}
void Incrementar(int n) {cout << "Suma " << n << endl;}
};

class ClaseB : public ClaseA {
public:
void Incrementar() {cout << "Suma 2" << endl;}
};

int main(int argc, char *argv[])
{
ClaseB objeto;
objeto.Incrementar();
// objeto.Incrementar(10);
objeto.ClaseA::Incrementar();
objeto.ClaseA::Incrementar(10);
system("pause");
return 0;
}
