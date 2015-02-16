#include <iostream>
using namespace std;

struct ejemplo {
    ejemplo(int v, ejemplo* e);
    int valor;
    ejemplo *esto;
};

ejemplo::ejemplo(int v, ejemplo *e) : valor(v), esto(e) {}

int main() {
    ejemplo e1(19, &e1);

    cout << &e1 << "  " << (void*)e1.esto << endl;
    return 0;
}
