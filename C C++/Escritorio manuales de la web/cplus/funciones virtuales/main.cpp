#include <iostream>
#include <iomanip>

using namespace std;

class A
{
public:
    A(void) {};
    virtual void sumar(void);
};
class B:public A
{
public:
    B(void):A() {};
    void sumar(void);
};
void A::sumar(void)
{
    cout<<endl<<"Es la suma de la clase A.";
}
void B::sumar(void)
{
    cout<<endl<<"Es la suma de la clase B.";
}

int main(void)
{
    A c;
    A *a;
    B b;
    a=&b;
    a->sumar(); //Llama a la funcion de la clase derivada
    a=&c;
    a->sumar(); // Llama a la funcion de la clase base;
}
