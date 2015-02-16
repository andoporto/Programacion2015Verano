// Clase tonta
// (C) 2009 Con Clase
// Salvador Pozo

#include <iostream>

using namespace std;

class tonta {
    public:
        tonta();
        tonta(int);
        tonta(const tonta&);
        ~tonta();
        int Modifica(int);
        int Lee();
    private:
        int valor;
};

tonta::tonta() : valor(0) {
    cout << "Constructor sin parámetros (0)" << endl;
}

tonta::tonta(int v) : valor(v) {
    cout << "Constructor con un parámetro (" << v << ")" << endl;
}

tonta::tonta(const tonta &t) : valor(t.valor) {
    cout << "Constructor copia (" << t.valor << ")" << endl;
}

tonta::~tonta() {
    cout << "Destructor (" << valor << ")" << endl;
}

int tonta::Modifica(int v) {
    int retval = valor;

    cout << "Modificar valor (" << valor << ") -> (" << v << ")" << endl;
    valor = v;
    return retval;
}

int tonta::Lee() {
    return valor;
}

int main() {
    tonta obj1;
    tonta *obj2;
    tonta obj3 = obj1;

    obj2 = new tonta(2);

    obj1.Modifica(3);
    cout << "Objeto1: " << obj1.Lee() << endl;
    cout << "Objeto2: " << obj2->Lee() << endl;
    cout << "Objeto3: " << obj3.Lee() << endl;

    delete obj2;

    return 0;
}
