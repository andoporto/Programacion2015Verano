// Clase fracción
// (C) 2009 Con Clase
// Salvador Pozo

#include <iostream>

using namespace std;

class fraccion {
    public:
        fraccion(int n=0, int d=0) : numerador(n), denominador(d) {
            Simplificar();
        }
        void Simplificar();
        void Sumar(fraccion);
        void Mostrar();
    private:
        int numerador;
        int denominador;
        int MCD(int, int);
};

void fraccion::Simplificar() {
    int mcd = MCD(numerador, denominador);
    numerador /= mcd;
    denominador /= mcd;
}

void fraccion::Sumar(fraccion f2) {
    numerador = numerador*f2.denominador+denominador*f2.numerador;
    denominador = denominador*f2.denominador;
    Simplificar();
}

void fraccion::Mostrar() {
    cout << numerador << "/" << denominador << endl;
}

int fraccion::MCD(int a, int b) {
    if(a < b) return MCD(b,a);
    if(b == 0) return a;
    return MCD(b, a % b);
}

int main() {
    fraccion f1(234, 2238);
    fraccion f2(64, 1024);

    f1.Mostrar();
    f2.Mostrar();

    f1.Sumar(f2);
    f1.Mostrar();

    return 0;
}
